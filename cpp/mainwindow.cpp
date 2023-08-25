#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connect(&ui_Auth, SIGNAL(enter_system_clicked()),                                   //соединение сигнала кнопки авторизации экземпляра окна авторизации
            this, SLOT(authorizeUser()));                                               //со слотом-обработчиком авторизации
    connect(&ui_Auth,SIGNAL(destroyed()),                                               //соединение сигнала уничтожения экземпляра окна авторизации
            this, SLOT(show()));                                                        //с методом отображения главного окна
    connect(&ui_Auth,SIGNAL(register_button_clicked()),                                 //соединение сигнала кнопки регистрации экземпляра окна авторизации
            this,SLOT(registerWindowShow()));                                           //со слотом вызывающим окно регистрации
    connect(&ui_Reg,SIGNAL(finish_reg()),                                               //соединение кнопки регистрации экземпляра окна авторизации
            this,SLOT(registerUser()));                                                 //со слотом-обработчиком регистраци
    connect(&ui_Reg,SIGNAL(destroyed()),
            &ui_Auth, SLOT(show()));

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
int index_vec;
QString card_save;
QString cvc_code;
bool cvc_show = true;

bool USD_cash_input_bool = false;
bool EUR_cash_input_bool = false;
bool USD_deposit_input_bool = false;
bool EUR_deposit_input_bool = false;
bool USD_cash_output_bool = false;
bool EUR_cash_output_bool = false;
bool USD_deposit_output_bool = false;
bool EUR_deposit_output_bool = false;
void MainWindow::authorizeUser()
{
    QString login_enter;
    QString pass_enter;
    bool tiny_login_auth = false;
    bool tiny_pass_auth = false;
    bool login_enter_exist = false;
    bool pass_enter_exist = false;
    login_enter = ui_Auth.getLogin_Auth();
    pass_enter = ui_Auth.getPass_Auth();

    for(int i=0;i<login_data_vec.size();i++)
    {
        if(login_data_vec[i] == login_enter)
        {
            login_enter_exist = true;
            card_save = card_data_vec[i];
            break;
        }
    }

    for(int i=0;i<password_data_vec.size();i++)
    {
        if(password_data_vec[i] == pass_enter)
        {
            pass_enter_exist = true;
            break;
        }
    }

    for(int i=0;i<card_vec.size();i++)
    {
        if(card_vec[i] == card_save)
        {
            index_vec = i;
            break;
        }
    }

    if(login_enter.size()<5)
    {
        tiny_login_auth = true;
    }
    else if(pass_enter.size()<5)
    {
        tiny_pass_auth = true;
    }

    if(tiny_login_auth)
    {
        ui_Auth.error_tiny_login();
    }
    else if(tiny_pass_auth)
    {
        ui_Auth.error_tiny_pass();
    }
    else if(!login_enter_exist)
    {
        ui_Auth.error_notExistLogin();
    }
    else if(!pass_enter_exist)
    {
        ui_Auth.error_notExistPass();
    }
    else
    {
        ui_Auth.close();
        ui_Reg.close();
        this->show();

        ui->number_card->clear();
        ui->number_card->setText(card_vec[index_vec]);

        ui->name_user->clear();
        ui->name_user->setText(nameuser_card_vec[index_vec]);

        ui->data->clear();
        ui->data->setText(data_card_vec[index_vec]);

        ui->cvc->setText("***");
        cvc_code = cvc_card_vec[index_vec];

        ui->info_RUB_cash->clear();
        ui->info_RUB_cash->setText(cash_RUB_vec[index_vec]);

        ui->info_USD_cash->clear();
        if(cash_USD_vec[index_vec] == 'n')
        {
            ui->info_USD_cash->setText("Счет недоступен");
        }
        else
        {
            ui->info_USD_cash->setText(cash_USD_vec[index_vec]);
        }

        ui->info_EUR_cash->clear();
        if(cash_EUR_vec[index_vec] == 'n')
        {
            ui->info_EUR_cash->setText("Счет недоступен");
        }
        else
        {
            ui->info_EUR_cash->setText(cash_EUR_vec[index_vec]);
        }

        ui->info_RUB_deposit->clear();
        ui->info_RUB_deposit->setText(deposit_RUB_vec[index_vec]);

        ui->info_USD_deposit->clear();
        if(deposit_USD_vec[index_vec] == 'n')
        {
            ui->info_USD_deposit->setText("Депозит недоступен");
        }
        else
        {
            ui->info_USD_deposit->setText(deposit_USD_vec[index_vec]);
        }

        ui->info_EUR_deposit->clear();
        if(deposit_EUR_vec[index_vec] == 'n')
        {
            ui->info_EUR_deposit->setText("Депозит недоступен");
        }
        else
        {
             ui->info_EUR_deposit->setText(deposit_EUR_vec[index_vec]);
        }

        if(ui->info_USD_cash->text() != "Счет недоступен")
        {
            ui->open_USD_cash->hide();
            USD_cash_input_bool = true;
            USD_cash_output_bool = true;
        }
        if(ui->info_USD_deposit->text() != "Депозит недоступен")
        {
            ui->open_USD_deposit->hide();
            USD_deposit_input_bool = true;
            USD_deposit_output_bool = true;
        }
        if(ui->info_EUR_cash->text() != "Счет недоступен")
        {
            ui->open_EUR_cash->hide();
            EUR_cash_input_bool = true;
            EUR_cash_output_bool = true;
        }
        if(ui->info_EUR_deposit->text() != "Депозит недоступен")
        {
            ui->open_EUR_deposit->hide();
            EUR_deposit_input_bool = true;
            EUR_deposit_output_bool = true;
        }
    }
}
void MainWindow::registerWindowShow()
{
    QString number_card_reg;
    bool success_reg_first = false;
    bool edit_format = true;
    bool edit_size = true;
    bool edit_number = true;
    bool edit_regYet = false;
    number_card_reg = ui_Auth.getNumber_card();

    if(number_card_reg.size()!=19)
    {
        edit_size = false;
    }
    else if(number_card_reg[4] != '_' || number_card_reg[9] != '_' || number_card_reg[14] != '_')
    {
        edit_format = false;
    }
    else if(!number_card_reg[0].isNumber() || !number_card_reg[1].isNumber() ||!number_card_reg[2].isNumber() ||!number_card_reg[3].isNumber() ||
            !number_card_reg[5].isNumber() ||!number_card_reg[6].isNumber() ||!number_card_reg[7].isNumber() ||!number_card_reg[8].isNumber() ||
            !number_card_reg[10].isNumber() ||!number_card_reg[11].isNumber() ||!number_card_reg[12].isNumber() ||!number_card_reg[13].isNumber() ||
            !number_card_reg[15].isNumber() ||!number_card_reg[16].isNumber() ||!number_card_reg[17].isNumber() ||!number_card_reg[18].isNumber())
    {
        edit_number = false;
    }

    for(int i=0;i<card_data_vec.size();i++)
    {
        if(card_data_vec[i] == number_card_reg)
        {
            edit_regYet = true;
            break;
        }
    }

    if(!edit_size)
    {
        ui_Auth.error_size();
    }
    else if(!edit_format)
    {
        ui_Auth.error_format();
    }
    else if(!edit_number)
    {
        ui_Auth.error_number();
    }
    else if(edit_regYet)
    {
        ui_Auth.error_regYet();
    }
    else
    {
        for(int i=0;i<card_user_vec.size();i++)
        {
            if(card_user_vec[i] == number_card_reg)
            {
                success_reg_first = true;
                index_vec = i;
                card_save = number_card_reg;
                break;
            }
        }
        if(success_reg_first)
        {
            ui_Auth.hide();
            ui_Reg.show();
        }
        if(!success_reg_first)
        {
            ui_Auth.error_exist();
        }
    }
}
void MainWindow::registerUser()
{
    QString login_input;
    QString password_input;
    bool edit_exist = false;
    bool tiny_login = false;
    bool tiny_pass = false;
    login_input = ui_Reg.getLogin_Reg();
    password_input = ui_Reg.getPass_Reg();

    for(int i=0;i<login_data_vec.size();i++)
    {
        if(login_data_vec[i] == login_input)
        {
            edit_exist = true;
            break;
        }
    }
    if(login_input.size()<6)
    {
        tiny_login = true;
    }
    if(password_input.size()<6)
    {
        tiny_pass = true;
    }

    if(edit_exist)
    {
        ui_Reg.error_exist_login();
    }
    else if(tiny_login)
    {
        ui_Reg.error_tiny_login();
    }
    else if(tiny_pass)
    {
        ui_Reg.error_tiny_pass();
    }
    else
    {
        operation_files operation;
        QString path_to_UserData = "D:\\SUAI\\OOP\\UserData.txt";
        QFile UserDataStream(path_to_UserData);

        card_data_vec.push_back(card_save);
        login_data_vec.push_back(login_input);
        password_data_vec.push_back(password_input);
;
        operation.rec_in_files_UserDataStream(UserDataStream);
        ui_Reg.hide();
        ui_Auth.show();
    }
}
void MainWindow::display()
{
    QString path_to_UserList = "D:\\SUAI\\OOP\\UserList.txt";
    QString path_to_PassportUser = "D:\\SUAI\\OOP\\PassportUser.txt";
    QString path_to_CardList = "D:\\SUAI\\OOP\\CardList.txt";
    QString path_to_UserData = "D:\\SUAI\\OOP\\UserData.txt";
    QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";

    checking_file_existence check_file;
    operation_files operation;
    QFile UserListStream(path_to_UserList);
    QFile PassportUserStream(path_to_PassportUser);
    QFile CardListStream(path_to_CardList);
    QFile UserDataStream(path_to_UserData);
    QFile BankrollStream(path_to_Bankroll);

    check_file.check_user_list(UserListStream);
    check_file.check_passport_user(PassportUserStream);
    check_file.check_card_list(CardListStream);
    check_file.check_user_data(UserDataStream);
    check_file.check_bankroll(BankrollStream);

    operation.rec_from_files_UserListStream(UserListStream);
    operation.rec_from_files_PassportUserStream(PassportUserStream);
    operation.rec_from_files_CardListStream(CardListStream);
    operation.rec_from_files_UserDataStream(UserDataStream);
    operation.rec_from_files_BankrollStream(BankrollStream);

    for(int i=0;i<card_user_vec.size();i++)
    {
        QString str = card_user_vec[i];
        str.replace("\r","");
        str.replace("\n","");
        card_user_vec[i] = str;
    }
    for(int i=0;i<passport_vec.size();i++)
    {
        QString str = code_passport_vec[i];
        str.replace("\r","");
        str.replace("\n","");
        code_passport_vec[i] = str;
    }
    for(int i=0;i<card_vec.size();i++)
    {
        QString str = nameuser_card_vec[i];
        str.replace("\r","");
        str.replace("\n","");
        nameuser_card_vec[i] = str;
    }
    for(int i=0;i<card_data_vec.size();i++)
    {
        QString str = password_data_vec[i];
        str.replace("\r","");
        str.replace("\n","");
        password_data_vec[i] = str;
    }
    for(int i=0;i<card_bankroll_vec.size();i++)
    {
        QString str = deposit_EUR_vec[i];
        str.replace("\r","");
        str.replace("\n","");
        deposit_EUR_vec[i] = str;;
    }

    /*for(int i=0;i<name_user_vec.size();i++)
    {
        qDebug()<<name_user_vec[i]<<"\t"<<birthday_user_vec[i]<<"\t"<<addr_user_vec[i]<<"\t"
            <<phone_user_vec[i]<<"\t"<<passport_user_vec[i]<<"\t"<<card_user_vec[i];
    }
    for(int i=0;i<passport_vec.size();i++)
    {
        qDebug()<<passport_vec[i]<<"\t"<<addr_passport_vec[i]<<"\t"<<data_passport_vec[i]<<"\t"
            <<code_passport_vec[i];
    }
    for(int i=0;i<card_vec.size();i++)
    {
        qDebug()<<card_vec[i]<<"\t"<<cvc_card_vec[i]<<"\t"<<data_card_vec[i]<<"\t"
            <<nameuser_card_vec[i];
    }
    for(int i=0;i<card_data_vec.size();i++)
    {
        qDebug()<<card_data_vec[i]<<"\t"<<login_data_vec[i]<<"\t"<<password_data_vec[i];
    }
    for(int i=0;i<card_bankroll_vec.size();i++)
    {
        qDebug()<<card_bankroll_vec[i]<<"\t"<<cash_RUB_vec[i]<<"\t"<<cash_USD_vec[i]<<"\t"
            <<cash_EUR_vec[i]<<"\t"<<deposit_RUB_vec[i]<<"\t"<<deposit_USD_vec[i]<<"\t"<<deposit_EUR_vec[i];
    }*/

    ui_Auth.show();
}

void MainWindow::on_show_cvc_clicked()
{
    int c = 1;
    if(cvc_show)
    {
        ui->cvc->clear();
        ui->cvc->setText(cvc_code);
        c = 0;
    }
    else
    {
        ui->cvc->clear();
        ui->cvc->setText("***");
        c = 1;
    }
    if(c == 1)
    {
        cvc_show = true;
    }
    else
    {
        cvc_show = false;
    }
}

void MainWindow::on_open_USD_cash_clicked()
{
    operation_files operation;
    QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
    QFile BankrollStream(path_to_Bankroll);

    ui->info_USD_cash->setText("0");
    cash_USD_vec[index_vec] = '0';
    operation.rec_in_files_BankrollStream(BankrollStream);
    ui->open_USD_cash->hide();

    USD_cash_input_bool = true;
    USD_cash_output_bool = true;
}

void MainWindow::on_open_USD_deposit_clicked()
{
    operation_files operation;
    QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
    QFile BankrollStream(path_to_Bankroll);

    ui->info_USD_deposit->setText("0");
    deposit_USD_vec[index_vec] = '0';
    operation.rec_in_files_BankrollStream(BankrollStream);
    ui->open_USD_deposit->hide();

    USD_deposit_input_bool = true;
    USD_deposit_output_bool = true;
}

void MainWindow::on_open_EUR_cash_clicked()
{
    operation_files operation;
    QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
    QFile BankrollStream(path_to_Bankroll);

    ui->info_EUR_cash->setText("0");
    cash_EUR_vec[index_vec] = '0';
    operation.rec_in_files_BankrollStream(BankrollStream);

    ui->open_EUR_cash->hide();

    EUR_cash_input_bool = true;
    EUR_cash_output_bool = true;
}

void MainWindow::on_open_EUR_deposit_clicked()
{
    operation_files operation;
    QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
    QFile BankrollStream(path_to_Bankroll);


    ui->info_EUR_deposit->setText("0");
    deposit_EUR_vec[index_vec] = '0';
    operation.rec_in_files_BankrollStream(BankrollStream);

    ui->open_EUR_deposit->hide();

    EUR_deposit_input_bool = true;
    EUR_deposit_output_bool = true;

}

void MainWindow::on_RUB_input_clicked()
{
    bool ok;
    if(ui->info_input->displayText().isEmpty())
    {
        ui->error_input->setText("Введите сумму");
        ui->info_input->setText("");
    }
    else if(!ui->info_input->displayText().toInt(&ok,10))
    {
        ui->error_input->setText("Значение должно быть числом");
        ui->info_input->setText("");
    }
    else
    {
        int cash_amount;
        QString cash_str;
        cash_amount = ui->info_RUB_cash->text().toInt() + ui->info_input->text().toInt();
        cash_str = QString::number(cash_amount);

        ui->info_RUB_cash->setText(cash_str);
        ui->info_input->setText("");
        ui->error_input->setText("");

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);
        cash_RUB_vec[index_vec] = cash_str;
        operation.rec_in_files_BankrollStream(BankrollStream);
    }
}

void MainWindow::on_USD_input_clicked()
{
    bool ok;
    if(ui->info_input->displayText().isEmpty())
    {
        ui->error_input->setText("Введите сумму");
        ui->info_input->setText("");
    }
    else if(!ui->info_input->displayText().toInt(&ok,10))
    {
        ui->error_input->setText("Значение должно быть числом");
        ui->info_input->setText("");
    }
    else if(!USD_cash_input_bool)
    {
        ui->error_input->setText("Валютный счет закрыт");
        ui->info_input->setText("");
    }
    else
    {
        int cash_amount;
        QString cash_str;
        cash_amount = ui->info_USD_cash->text().toInt() + ui->info_input->text().toInt();
        cash_str = QString::number(cash_amount);

        ui->info_USD_cash->setText(cash_str);
        ui->info_input->setText("");
        ui->error_input->setText("");

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);
        cash_USD_vec[index_vec] = cash_str;
        operation.rec_in_files_BankrollStream(BankrollStream);
    }
}

void MainWindow::on_EUR_input_clicked()
{
    bool ok;
    if(ui->info_input->displayText().isEmpty())
    {
        ui->error_input->setText("Введите сумму");
        ui->info_input->setText("");
    }
    else if(!ui->info_input->displayText().toInt(&ok,10))
    {
        ui->error_input->setText("Значение должно быть числом");
        ui->info_input->setText("");
    }
    else if(!EUR_cash_input_bool)
    {
        ui->error_input->setText("Валютный счет закрыт");
        ui->info_input->setText("");
    }
    else
    {
        int cash_amount;
        QString cash_str;
        cash_amount = ui->info_EUR_cash->text().toInt() + ui->info_input->text().toInt();
        cash_str = QString::number(cash_amount);

        ui->info_EUR_cash->setText(cash_str);
        ui->info_input->setText("");
        ui->error_input->setText("");

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);
        cash_EUR_vec[index_vec] = cash_str;
        operation.rec_in_files_BankrollStream(BankrollStream);
    }
}

void MainWindow::on_RUB_output_clicked()
{
    bool ok;
    if(ui->info_output->displayText().isEmpty())
    {
        ui->error_output->setText("Введите сумму");
        ui->info_output->setText("");
    }
    else if(!ui->info_output->displayText().toInt(&ok,10))
    {
        ui->error_output->setText("Значение должно быть числом");
        ui->info_output->setText("");
    }
    else if(ui->info_output->text().toInt()>ui->info_RUB_cash->text().toInt())
    {
        ui->error_output->setText("Нельзя снять больше, \nчем есть на счете");
        ui->info_output->setText("");
    }
    else
    {
        int cash_amount;
        QString cash_str;
        cash_amount = ui->info_RUB_cash->text().toInt() - ui->info_output->text().toInt();
        cash_str = QString::number(cash_amount);

        ui->info_RUB_cash->setText(cash_str);
        ui->info_output->setText("");
        ui->error_output->setText("");

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);
        cash_RUB_vec[index_vec] = cash_str;
        operation.rec_in_files_BankrollStream(BankrollStream);
    }
}

void MainWindow::on_USD_output_clicked()
{
    bool ok;
    if(ui->info_output->displayText().isEmpty())
    {
        ui->error_output->setText("Введите сумму");
        ui->info_output->setText("");
    }
    else if(!ui->info_output->displayText().toInt(&ok,10))
    {
        ui->error_output->setText("Значение должно быть числом");
        ui->info_output->setText("");
    }
    else if(!USD_cash_output_bool)
    {
        ui->error_output->setText("Валютный счет закрыт");
        ui->info_output->setText("");
    }
    else if(ui->info_output->text().toInt()>ui->info_USD_cash->text().toInt())
    {
        ui->error_output->setText("Нельзя снять больше, \nчем есть на счете");
        ui->info_output->setText("");
    }
    else
    {
        int cash_amount;
        QString cash_str;
        cash_amount = ui->info_USD_cash->text().toInt() - ui->info_output->text().toInt();
        cash_str = QString::number(cash_amount);

        ui->info_USD_cash->setText(cash_str);
        ui->info_output->setText("");
        ui->error_output->setText("");

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);
        cash_USD_vec[index_vec] = cash_str;
        operation.rec_in_files_BankrollStream(BankrollStream);
    }
}

void MainWindow::on_EUR_output_clicked()
{
    bool ok;
    if(ui->info_output->displayText().isEmpty())
    {
        ui->error_output->setText("Введите сумму");
        ui->info_output->setText("");
    }
    else if(!ui->info_output->displayText().toInt(&ok,10))
    {
        ui->error_output->setText("Значение должно быть числом");
        ui->info_output->setText("");
    }
    else if(!EUR_cash_output_bool)
    {
        ui->error_output->setText("Валютный счет закрыт");
        ui->info_output->setText("");
    }
    else if(ui->info_output->text().toInt()>ui->info_EUR_cash->text().toInt())
    {
        ui->error_output->setText("Нельзя снять больше, \nчем есть на счете");
        ui->info_output->setText("");
    }
    else
    {
        int cash_amount;
        QString cash_str;
        cash_amount = ui->info_EUR_cash->text().toInt() - ui->info_output->text().toInt();
        cash_str = QString::number(cash_amount);

        ui->info_EUR_cash->setText(cash_str);
        ui->info_output->setText("");
        ui->error_output->setText("");

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);
        cash_EUR_vec[index_vec] = cash_str;
        operation.rec_in_files_BankrollStream(BankrollStream);
    }
}

void MainWindow::on_RUB_dep_input_clicked()
{
    bool ok;
    if(ui->info_input->displayText().isEmpty())
    {
        ui->error_input->setText("Введите сумму");
        ui->info_input->setText("");
    }
    else if(!ui->info_input->displayText().toInt(&ok,10))
    {
        ui->error_input->setText("Значение должно быть числом");
        ui->info_input->setText("");
    }
    else if(ui->info_input->text().toInt()>ui->info_RUB_cash->text().toInt())
    {
        ui->error_input->setText("Нельзя положить на депозит \nбольше, чем есть на счете");
        ui->info_input->setText("");
    }
    else
    {
        int cash_amount;
        int deposit_amount;
        QString cash_str;
        QString deposit_str;

        cash_amount = ui->info_RUB_cash->text().toInt() - ui->info_input->text().toInt();
        cash_str = QString::number(cash_amount);

        deposit_amount = ui->info_RUB_deposit->text().toInt() + ui->info_input->text().toInt();
        deposit_str = QString::number(deposit_amount);

        ui->info_RUB_cash->setText(cash_str);
        ui->info_RUB_deposit->setText(deposit_str);
        ui->info_input->setText("");
        ui->error_input->setText("");

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);
        cash_RUB_vec[index_vec] = cash_str;
        deposit_RUB_vec[index_vec] = deposit_str;
        operation.rec_in_files_BankrollStream(BankrollStream);
    }
}

void MainWindow::on_USD_dep_input_clicked()
{
    bool ok;
    if(ui->info_input->displayText().isEmpty())
    {
        ui->error_input->setText("Введите сумму");
        ui->info_input->setText("");
    }
    else if(!ui->info_input->displayText().toInt(&ok,10))
    {
        ui->error_input->setText("Значение должно быть числом");
        ui->info_input->setText("");
    }
    else if(!USD_deposit_input_bool)
    {
        ui->error_input->setText("Валютный депозит закрыт");
        ui->info_input->setText("");
    }
    else if(ui->info_input->text().toInt()>ui->info_USD_cash->text().toInt())
    {
        ui->error_input->setText("Нельзя положить на депозит \nбольше, чем есть на счете");
        ui->info_input->setText("");
    }
    else
    {
        int cash_amount;
        int deposit_amount;
        QString cash_str;
        QString deposit_str;

        cash_amount = ui->info_USD_cash->text().toInt() - ui->info_input->text().toInt();
        cash_str = QString::number(cash_amount);

        deposit_amount = ui->info_USD_deposit->text().toInt() + ui->info_input->text().toInt();
        deposit_str = QString::number(deposit_amount);

        ui->info_USD_cash->setText(cash_str);
        ui->info_USD_deposit->setText(deposit_str);
        ui->info_input->setText("");
        ui->error_input->setText("");

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);
        cash_USD_vec[index_vec] = cash_str;
        deposit_USD_vec[index_vec] = deposit_str;
        operation.rec_in_files_BankrollStream(BankrollStream);
    }
}

void MainWindow::on_EUR_dep_input_clicked()
{
    bool ok;
    if(ui->info_input->displayText().isEmpty())
    {
        ui->error_input->setText("Введите сумму");
        ui->info_input->setText("");
    }
    else if(!ui->info_input->displayText().toInt(&ok,10))
    {
        ui->error_input->setText("Значение должно быть числом");
        ui->info_input->setText("");
    }
    else if(!EUR_deposit_input_bool)
    {
        ui->error_input->setText("Валютный депозит закрыт");
        ui->info_input->setText("");
    }
    else if(ui->info_input->text().toInt()>ui->info_EUR_cash->text().toInt())
    {
        ui->error_input->setText("Нельзя положить на депозит \nбольше, чем есть на счете");
        ui->info_input->setText("");
    }
    else
    {
        int cash_amount;
        int deposit_amount;
        QString cash_str;
        QString deposit_str;

        cash_amount = ui->info_EUR_cash->text().toInt() - ui->info_input->text().toInt();
        cash_str = QString::number(cash_amount);

        deposit_amount = ui->info_EUR_deposit->text().toInt() + ui->info_input->text().toInt();
        deposit_str = QString::number(deposit_amount);

        ui->info_EUR_cash->setText(cash_str);
        ui->info_EUR_deposit->setText(deposit_str);
        ui->info_input->setText("");
        ui->error_input->setText("");

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);
        cash_EUR_vec[index_vec] = cash_str;
        deposit_EUR_vec[index_vec] = deposit_str;
        operation.rec_in_files_BankrollStream(BankrollStream);
    }
}

void MainWindow::on_RUB_dep_output_clicked()
{
    bool ok;
    if(ui->info_output->displayText().isEmpty())
    {
        ui->error_output->setText("Введите сумму");
        ui->info_output->setText("");
    }
    else if(!ui->info_output->displayText().toInt(&ok,10))
    {
        ui->error_output->setText("Значение должно быть числом");
        ui->info_output->setText("");
    }
    else if(ui->info_output->text().toInt()>ui->info_RUB_deposit->text().toInt())
    {
        ui->error_output->setText("Нельзя снять с депозита больше, \nчем есть на нем");
        ui->info_output->setText("");
    }
    else
    {
        int cash_amount;
        int deposit_amount;
        QString cash_str;
        QString deposit_str;

        deposit_amount = ui->info_RUB_deposit->text().toInt() - ui->info_output->text().toInt();
        deposit_str = QString::number(deposit_amount);

        cash_amount = ui->info_RUB_cash->text().toInt() + ui->info_output->text().toInt();
        cash_str= QString::number(cash_amount);

        ui->info_RUB_cash->setText(cash_str);
        ui->info_RUB_deposit->setText(deposit_str);
        ui->info_output->setText("");
        ui->error_output->setText("");

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);
        cash_RUB_vec[index_vec] = cash_str;
        deposit_RUB_vec[index_vec] = deposit_str;
        operation.rec_in_files_BankrollStream(BankrollStream);
    }
}

void MainWindow::on_USD_dep_output_clicked()
{
    bool ok;
    if(ui->info_output->displayText().isEmpty())
    {
        ui->error_output->setText("Введите сумму");
        ui->info_output->setText("");
    }
    else if(!ui->info_output->displayText().toInt(&ok,10))
    {
        ui->error_output->setText("Значение должно быть числом");
        ui->info_output->setText("");
    }
    else if(!USD_deposit_output_bool)
    {
        ui->error_output->setText("Валютный депозит закрыт");
        ui->info_output->setText("");
    }
    else if(ui->info_output->text().toInt()>ui->info_USD_deposit->text().toInt())
    {
        ui->error_output->setText("Нельзя снять с депозита больше, \nчем есть на нем");
        ui->info_output->setText("");
    }
    else
    {
        int cash_amount;
        int deposit_amount;
        QString cash_str;
        QString deposit_str;

        deposit_amount = ui->info_USD_deposit->text().toInt() - ui->info_output->text().toInt();
        deposit_str = QString::number(deposit_amount);

        cash_amount = ui->info_USD_cash->text().toInt() + ui->info_output->text().toInt();
        cash_str= QString::number(cash_amount);

        ui->info_USD_cash->setText(cash_str);
        ui->info_USD_deposit->setText(deposit_str);
        ui->info_output->setText("");
        ui->error_output->setText("");

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);
        cash_USD_vec[index_vec] = cash_str;
        deposit_USD_vec[index_vec] = deposit_str;
        operation.rec_in_files_BankrollStream(BankrollStream);
    }
}

void MainWindow::on_EUR_dep_output_clicked()
{
    bool ok;
    if(ui->info_output->displayText().isEmpty())
    {
        ui->error_output->setText("Введите сумму");
        ui->info_output->setText("");
    }
    else if(!ui->info_output->displayText().toInt(&ok,10))
    {
        ui->error_output->setText("Значение должно быть числом");
        ui->info_output->setText("");
    }
    else if(!EUR_deposit_output_bool)
    {
        ui->error_output->setText("Валютный депозит закрыт");
        ui->info_output->setText("");
    }
    else if(ui->info_output->text().toInt()>ui->info_EUR_deposit->text().toInt())
    {
        ui->error_output->setText("Нельзя снять с депозита больше, \nчем есть на нем");
        ui->info_output->setText("");
    }
    else
    {
        int cash_amount;
        int deposit_amount;
        QString cash_str;
        QString deposit_str;

        deposit_amount = ui->info_EUR_deposit->text().toInt() - ui->info_output->text().toInt();
        deposit_str = QString::number(deposit_amount);

        cash_amount = ui->info_EUR_cash->text().toInt() + ui->info_output->text().toInt();
        cash_str= QString::number(cash_amount);

        ui->info_EUR_cash->setText(cash_str);
        ui->info_EUR_deposit->setText(deposit_str);
        ui->info_output->setText("");
        ui->error_output->setText("");

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);
        cash_EUR_vec[index_vec] = cash_str;
        deposit_EUR_vec[index_vec] = deposit_str;
        operation.rec_in_files_BankrollStream(BankrollStream);
    }
}

void MainWindow::on_list_all_user_button_clicked()
{
    QString s_1;
    for(int i=0;i<card_user_vec.size();i++)
    {
        if(card_user_vec[i] != card_user_vec[index_vec])
        {
            s_1+=card_user_vec[i]+"\n"+name_user_vec[i]+"\n\n";
        }
    }
    ui->list_all_user_show->setText(s_1);
}

void MainWindow::on_send_button_clicked()
{
    QString card_transit;
    bool ok;
    int in_vec = 0;
    card_transit = ui->number_card_transit->text();
    if(card_transit.size()!=19)
    {
        ui->error_transit->setText("Номер карты должен быть 16-значным");
        ui->error_transit_2->setText("");
        ui->number_card_transit->setText("");
    }
    else if(card_transit[4] != '_' || card_transit[9] != '_' || card_transit[14] != '_')
    {
        ui->error_transit->setText("Формат введенной карты неверен. \nФормат XXXX_XXXX_XXXX_XXXX");
        ui->error_transit_2->setText("");
        ui->number_card_transit->setText("");
    }
    else if(!card_transit[0].isNumber() || !card_transit[1].isNumber() ||!card_transit[2].isNumber() ||!card_transit[3].isNumber() ||
            !card_transit[5].isNumber() ||!card_transit[6].isNumber() ||!card_transit[7].isNumber() ||!card_transit[8].isNumber() ||
            !card_transit[10].isNumber() ||!card_transit[11].isNumber() ||!card_transit[12].isNumber() ||!card_transit[13].isNumber() ||
            !card_transit[15].isNumber() ||!card_transit[16].isNumber() ||!card_transit[17].isNumber() ||!card_transit[18].isNumber())
    {
        ui->error_transit->setText("Номер карты должен состять из цифр");
        ui->error_transit_2->setText("");
        ui->number_card_transit->setText("");
    }
    else if(ui->info_transit->displayText().isEmpty())
    {
        ui->error_transit->setText("Введите сумму");
        ui->error_transit_2->setText("");
        ui->info_transit->setText("");
    }
    else if(!ui->info_transit->displayText().toInt(&ok,10))
    {
        ui->error_transit->setText("Значение должно быть числом");
        ui->error_transit_2->setText("");
        ui->info_transit->setText("");
    }
    else if(ui->info_transit->text().toInt()>ui->info_RUB_cash->text().toInt())
    {
        ui->error_transit->setText("Нельзя снять больше, чем есть на счете");
        ui->error_transit_2->setText("");
        ui->info_transit->setText("");
    }
    else
    {
        for(int i=0;i<card_bankroll_vec.size();i++)
        {
            if(card_bankroll_vec[i] == card_transit)
            {
                in_vec = i;
                break;
            }
        }
        QString cash_index_vec = cash_RUB_vec[index_vec];
        QString cash_in_vec = cash_RUB_vec[in_vec];
        int cash_index_vec_int = cash_index_vec.toInt();
        int cash_in_vec_int = cash_in_vec.toInt();
        cash_index_vec_int-=ui->info_transit->text().toInt();
        cash_in_vec_int+=ui->info_transit->text().toInt();
        cash_index_vec = QString::number(cash_index_vec_int);
        cash_in_vec = QString::number(cash_in_vec_int);
        ui->info_RUB_cash->setText(cash_index_vec);

        operation_files operation;
        QString path_to_Bankroll = "D:\\SUAI\\OOP\\Bankroll.txt";
        QFile BankrollStream(path_to_Bankroll);

        cash_RUB_vec[index_vec] = cash_index_vec;
        cash_RUB_vec[in_vec] = cash_in_vec;

        operation.rec_in_files_BankrollStream(BankrollStream);
        ui->error_transit_2->setText("Операция прошла успешно");
        ui->error_transit->setText("");
        ui->info_transit->setText("");
        ui->number_card_transit->setText("");
    }
}

void MainWindow::on_exitbtn_clicked()
{
    MainWindow::close();
}


void MainWindow::on_list_all_user_button_2_clicked()
{
    ui->list_all_user_show->setText(" ");
}


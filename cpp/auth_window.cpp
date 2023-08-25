#include "auth_window.h"
#include "ui_auth_window.h"

auth_window::auth_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::auth_window)
{
    ui->setupUi(this);
}

auth_window::~auth_window()
{
    delete ui;
}

void auth_window::on_number_card_textEdited(const QString &arg1)
{
    auth_window::number_card_enter_input = arg1;
}

void auth_window::on_further_login_clicked()
{
    emit register_button_clicked();
}

void auth_window::on_login_textEdited(const QString &arg1)
{
    auth_window::login_enter_input = arg1;
}

void auth_window::on_password_textEdited(const QString &arg1)
{
    auth_window::password_enter_input = arg1;
}

void auth_window::on_pushButton_clicked()
{
    emit enter_system_clicked();
}
QString auth_window::getNumber_card()
{
    return auth_window::number_card_enter_input;
}
QString auth_window::getLogin_Auth()
{
    return auth_window::login_enter_input;
}
QString auth_window::getPass_Auth()
{
    return auth_window::password_enter_input;
}
void auth_window::error_exist()
{
    ui->info_error_login->clear();
    ui->info_error_login->setText("Такой карты в системе нет. Закажите карту");
}
void auth_window::error_format()
{
    ui->info_error_login->clear();
    ui->info_error_login->setText("Формат введенной карты неверен. \nФормат XXXX_XXXX_XXXX_XXXX");
}
void auth_window::error_size()
{
    ui->info_error_login->clear();
    ui->info_error_login->setText("Номер карты должен быть 16-значным");
}
void auth_window::error_number()
{
    ui->info_error_login->clear();
    ui->info_error_login->setText("Номер карты должен состять из цифр");
}
void auth_window::error_regYet()
{
    ui->info_error_login->clear();
    ui->info_error_login->setText("Вы уже зарегистрированны в системе");
}
void auth_window::error_notExistLogin()
{
    ui->info_error_sign->clear();
    ui->info_error_sign->setText("Неверный логин");
}
void auth_window::error_notExistPass()
{
    ui->info_error_sign->clear();
    ui->info_error_sign->setText("Неверный пароль");
}
void auth_window::error_tiny_login()
{
    ui->info_error_sign->clear();
    ui->info_error_sign->setText("Логин должен содержать более 5 знаков");
}
void auth_window::error_tiny_pass()
{
    ui->info_error_sign->clear();
    ui->info_error_sign->setText("Пароль должен содержать более 5 знаков");
}


void auth_window::on_exitbtn3_clicked()
{
    auth_window::close();
}


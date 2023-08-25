#include "reg_window.h"
#include "ui_reg_window.h"

reg_window::reg_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reg_window)
{
    ui->setupUi(this);
}

reg_window::~reg_window()
{
    delete ui;
}

void reg_window::on_invent_login_textEdited(const QString &arg1)
{
    reg_window::login_reg_input = arg1;
}

void reg_window::on_invent_password_textEdited(const QString &arg1)
{
    reg_window::password_reg_input = arg1;
}

void reg_window::on_finish_login_clicked()
{
    emit finish_reg();
}
QString reg_window::getLogin_Reg()
{
    return reg_window::login_reg_input;
}
QString reg_window::getPass_Reg()
{
    return reg_window::password_reg_input;
}
void reg_window::error_exist_login()
{
    ui->info_error_final_reg->clear();
    ui->info_error_final_reg->setText("Такой логин уже занят");
}
void reg_window::error_tiny_login()
{
    ui->info_error_final_reg->clear();
    ui->info_error_final_reg->setText("Логин должен содержать более 5 знаков");
}
void reg_window::error_tiny_pass()
{
    ui->info_error_final_reg->clear();
    ui->info_error_final_reg->setText("Пароль должен содержать более 5 знаков");
}

void reg_window::on_exitbtn2_clicked()
{
    reg_window::close();
}


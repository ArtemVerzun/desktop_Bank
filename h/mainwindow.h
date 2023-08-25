#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <auth_window.h>
#include <reg_window.h>

#include <operation_files.h>
#include <checking_file_existence.h>

#include <rub_cash_p.h>
#include <rub_deposit_p.h>
#include <usd_cash_p.h>
#include <usd_deposit_p.h>
#include <eur_cash_p.h>
#include <eur_deposit_p.h>

#include <QString>
#include <QVector>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void display();

private:
    Ui::MainWindow *ui;

    auth_window ui_Auth;
    reg_window ui_Reg;

    QString number_card_reg_input;
    QString login_reg_input;
    QString password_reg_input;
    QString login_enter_input;
    QString password_enter_input;
    bool enter_succesfull;

private slots:
    void authorizeUser();
    void registerWindowShow();
    void registerUser();
    void on_show_cvc_clicked();
    void on_open_USD_cash_clicked();
    void on_open_USD_deposit_clicked();
    void on_open_EUR_cash_clicked();
    void on_open_EUR_deposit_clicked();
    void on_RUB_input_clicked();
    void on_USD_input_clicked();
    void on_EUR_input_clicked();
    void on_RUB_output_clicked();
    void on_USD_output_clicked();
    void on_EUR_output_clicked();
    void on_RUB_dep_input_clicked();
    void on_USD_dep_input_clicked();
    void on_EUR_dep_input_clicked();
    void on_RUB_dep_output_clicked();
    void on_USD_dep_output_clicked();
    void on_EUR_dep_output_clicked();
    void on_list_all_user_button_clicked();
    void on_send_button_clicked(); 
    void on_exitbtn_clicked();
    void on_list_all_user_button_2_clicked();
};
#endif // MAINWINDOW_H

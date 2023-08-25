#ifndef AUTH_WINDOW_H
#define AUTH_WINDOW_H

#include <QDialog>

namespace Ui {
class auth_window;
}

class auth_window : public QDialog
{
    Q_OBJECT

public:
    explicit auth_window(QWidget *parent = nullptr);
    ~auth_window();

    QString getNumber_card();
    QString getLogin_Auth();
    QString getPass_Auth();

signals:
    void enter_system_clicked();
    void register_button_clicked();

private slots:
    void on_number_card_textEdited(const QString &arg1);
    void on_further_login_clicked();
    void on_login_textEdited(const QString &arg1);
    void on_password_textEdited(const QString &arg1);
    void on_pushButton_clicked();
    void on_exitbtn3_clicked();

public slots:
    void error_exist();
    void error_format();
    void error_size();
    void error_number();
    void error_regYet();
    void error_notExistLogin();
    void error_notExistPass();
    void error_tiny_login();
    void error_tiny_pass();

private:
    Ui::auth_window *ui;
    friend class mainwindow;
    QString number_card_enter_input;
    QString login_enter_input;
    QString password_enter_input;
};

#endif // AUTH_WINDOW_H

#ifndef REG_WINDOW_H
#define REG_WINDOW_H

#include <QDialog>

namespace Ui {
class reg_window;
}

class reg_window : public QDialog
{
    Q_OBJECT

public:
    explicit reg_window(QWidget *parent = nullptr);
    ~reg_window();

    QString getLogin_Reg();
    QString getPass_Reg();

signals:
    void finish_reg();

private slots:
    void on_invent_login_textEdited(const QString &arg1);
    void on_invent_password_textEdited(const QString &arg1);
    void on_finish_login_clicked();
    void on_exitbtn2_clicked();

public slots:
    void error_exist_login();
    void error_tiny_login();
    void error_tiny_pass();

private:
    Ui::reg_window *ui;
    friend class mainwindow;
    QString login_reg_input;
    QString password_reg_input;
};

#endif // REG_WINDOW_H

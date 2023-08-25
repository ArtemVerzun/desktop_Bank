#ifndef USERDATA_H
#define USERDATA_H
#include <QString>
#include <QVector>

extern QVector<QString>card_data_vec;
extern QVector<QString>login_data_vec;
extern QVector<QString>password_data_vec;

class userdata
{
private:
    QString card_data;
    QString login_data;
    QString password_data;
public:
    userdata();
    QString get_card_data();
    QString get_login_data();
    QString get_password_data();
    void set_card_data(QString s_card_data);
    void set_login_data(QString s_login_data);
    void set_password_data(QString s_password_data);
};

#endif // USERDATA_H

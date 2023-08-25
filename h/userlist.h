#ifndef USERLIST_H
#define USERLIST_H
#include <QVector>
#include <QString>

extern QVector<QString>name_user_vec;
extern QVector<QString>birthday_user_vec;
extern QVector<QString>addr_user_vec;
extern QVector<QString>phone_user_vec;
extern QVector<QString>passport_user_vec;
extern QVector<QString>card_user_vec;

class userlist
{
private:
    QString name_user;
    QString birthday_user;
    QString addr_user;
    QString phone_user;
    QString passport_user;
    QString card_user;
public:
    userlist();
    QString get_name_user();
    void set_name_user(QString s_name_user);
    QString get_birthday_user();
    void set_birthday_user(QString s_birthday_user);
    QString get_addr_user();
    void set_addr_user(QString s_addr_user);
    QString get_phone_user();
    void set_phone_user(QString s_phone_user);
    QString get_passport_user();
    void set_passport_user(QString s_passport_user);
    QString get_card_user();
    void set_card_user(QString s_card_user);
};

#endif // USERLIST_H

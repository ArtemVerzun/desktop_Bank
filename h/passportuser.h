#ifndef PASSPORTUSER_H
#define PASSPORTUSER_H
#include <QString>
#include <QVector>

extern QVector<QString>passport_vec;
extern QVector<QString> addr_passport_vec;
extern QVector<QString>data_passport_vec;
extern QVector<QString>code_passport_vec;

class passportuser
{
private:
    QString passport;
    QString addr_passport;
    QString data_passport;
    QString code_passport;
public:
    passportuser();
    QString get_passport();
    void set_passport(QString s_passport);
    QString get_addr_passport();
    void set_addr_passport(QString s_addr_passport);
    QString get_data_passport();
    void set_data_passport(QString s_data_passport);
    QString get_code_passport();
    void set_code_passport(QString s_code_passport);
};

#endif // PASSPORTUSER_H

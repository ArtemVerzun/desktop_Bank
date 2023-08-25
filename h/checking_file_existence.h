#ifndef CHECKING_FILE_EXISTENCE_H
#define CHECKING_FILE_EXISTENCE_H
#include <QString>
#include <QTextStream>
#include <QFile>

#include <task_exception.h>

class checking_file_existence:public task_exception
{
public:
    checking_file_existence();
    void check_user_list(QFile& UserListStream);
    void check_passport_user(QFile& PassportUserStream);
    void check_card_list(QFile& CardListStream);
    void check_user_data(QFile& UserDataStream);
    void check_bankroll(QFile& BankrollStream);
};

#endif // CHECKING_FILE_EXISTENCE_H

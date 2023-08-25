#include "checking_file_existence.h"

checking_file_existence::checking_file_existence()
{

}

void checking_file_existence::check_user_list(QFile& UserListStream)
{
    QString path_to_UserList_h = "D:\\SUAI\\OOP\\UserList.txt";
    QString try_ = "Путь к файлу " + path_to_UserList_h + " не определен";
    if (!UserListStream.open(QIODevice::ReadOnly))
    {
        throw task_exception(try_);
    }
}

void checking_file_existence::check_passport_user(QFile& PassportUserStream)
{
    QString path_to_PassportUser_h = "D:\\SUAI\\OOP\\PassportUser.txt";
    QString try_ = "Путь к файлу " + path_to_PassportUser_h + " не определен";
    if (!PassportUserStream.open(QIODevice::ReadOnly))
    {
        throw task_exception(try_);
    }
}
void checking_file_existence:: check_card_list(QFile& CardListStream)
{
    QString path_to_CardList_h = "D:\\SUAI\\OOP\\CardList.txt";
    QString try_ = "Путь к файлу " + path_to_CardList_h + " не определен";
    if (!CardListStream.open(QIODevice::ReadOnly))
    {
        throw task_exception(try_);
    }
}
void checking_file_existence:: check_user_data(QFile& UserDataStream)
{
    QString path_to_UserData_h = "D:\\SUAI\\OOP\\UserData.txt";
    QString try_ = "Путь к файлу " + path_to_UserData_h + " не определен";
    if (!UserDataStream.open(QIODevice::ReadOnly))
    {
        throw task_exception(try_);
    }
}
void checking_file_existence:: check_bankroll(QFile& BankrollStream)
{
    QString path_to_Bankroll_h = "D:\\SUAI\\OOP\\Bankroll.txt";
    QString try_ = "Путь к файлу " + path_to_Bankroll_h + " не определен";
    if (!BankrollStream.open(QIODevice::ReadOnly))
    {
        throw task_exception(try_);

    }
}

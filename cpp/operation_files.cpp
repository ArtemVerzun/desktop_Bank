#include "operation_files.h"

QVector<QString>name_user_vec;
QVector<QString>birthday_user_vec;
QVector<QString>addr_user_vec;
QVector<QString>phone_user_vec;
QVector<QString>passport_user_vec;
QVector<QString>card_user_vec;

QVector<QString>passport_vec;
QVector<QString> addr_passport_vec;
QVector<QString>data_passport_vec;
QVector<QString>code_passport_vec;

QVector<QString>card_vec;
QVector<QString>cvc_card_vec;
QVector<QString>data_card_vec;
QVector<QString>nameuser_card_vec;

QVector<QString>card_data_vec;
QVector<QString>login_data_vec;
QVector<QString>password_data_vec;

QVector<QString>card_bankroll_vec;
QVector<QString>deposit_RUB_vec;
QVector<QString>deposit_USD_vec;
QVector<QString>deposit_EUR_vec;
QVector<QString>cash_RUB_vec;
QVector<QString>cash_USD_vec;
QVector<QString>cash_EUR_vec;
operation_files::operation_files()
{

}
void operation_files::rec_from_files_UserListStream(QFile& UserListStream)
{
    while(!UserListStream.atEnd())
    {
            QString str_for_UserListStream = UserListStream.readLine();
            QStringList lst_1 = str_for_UserListStream.split("\t");
            for(int i=0;i<lst_1.size();i++)
            {
                if(i%6 == 0)
                {
                    name_user_vec.push_back(lst_1[i]);
                }
                else if(i%6 == 1)
                {
                    birthday_user_vec.push_back(lst_1[i]);
                }
                else if(i%6 == 2)
                {
                    addr_user_vec.push_back(lst_1[i]);
                }
                else if(i%6 == 3)
                {
                    phone_user_vec.push_back(lst_1[i]);
                }
                else if(i%6 == 4)
                {
                    passport_user_vec.push_back(lst_1[i]);
                }
                else if(i%6 == 5)
                {
                    card_user_vec.push_back(lst_1[i]);
                }
            }
        }
    UserListStream.close();
}
void operation_files::rec_from_files_PassportUserStream(QFile& PassportUserStream)
{
    while (!PassportUserStream.atEnd())
    {
        QString str_for_PassportUserStream = PassportUserStream.readLine();
        QStringList lst_2 = str_for_PassportUserStream.split("\t");
        for(int i=0;i<lst_2.size();i++)
        {
            if(i%4 == 0)
            {
                passport_vec.push_back(lst_2[i]);
            }
            else if(i%4 == 1)
            {
                addr_passport_vec.push_back(lst_2[i]);
            }
            else if(i%4 == 2)
            {
                data_passport_vec.push_back(lst_2[i]);
            }
            else if(i%4 == 3)
            {
                code_passport_vec.push_back(lst_2[i]);
            }
        }
    }
    PassportUserStream.close();
}
void operation_files::rec_from_files_CardListStream(QFile& CardListStream)
{
    while (!CardListStream.atEnd())
    {
        QString str_for_CardListStream = CardListStream.readLine();
        QStringList lst_3 = str_for_CardListStream.split("\t");
        for(int i=0;i<lst_3.size();i++)
        {
            if(i%4 == 0)
            {
                card_vec.push_back(lst_3[i]);
            }
            else if(i%4 == 1)
            {
                cvc_card_vec.push_back(lst_3[i]);
            }
            else if(i%4 == 2)
            {
                data_card_vec.push_back(lst_3[i]);
            }
            else if(i%4 == 3)
            {
                nameuser_card_vec.push_back(lst_3[i]);
            }
        }
    }
    CardListStream.close();
}
void operation_files::rec_from_files_UserDataStream(QFile& UserDataStream)
{
    while (!UserDataStream.atEnd())
    {
        QString str_for_UserDataStream = UserDataStream.readLine();
        QStringList lst_4 = str_for_UserDataStream.split("\t");
        for(int i=0;i<lst_4.size();i++)
        {
            if(i%3 == 0)
            {
                card_data_vec.push_back(lst_4[i]);
            }
            else if(i%3 == 1)
            {
                login_data_vec.push_back(lst_4[i]);
            }
            else if(i%3 == 2)
            {
                password_data_vec.push_back(lst_4[i]);
            }
        }
    }
    UserDataStream.close();
}
void operation_files::rec_in_files_UserDataStream(QFile& UserDataStream)
{
    if(UserDataStream.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream out(&UserDataStream);
        for (int i = 0; i < card_data_vec.size() - 1; i++)
        {
            out << card_data_vec[i] << "\t" << login_data_vec[i] << "\t" << password_data_vec[i] << "\n";
        }
        out << card_data_vec[card_data_vec.size() - 1] << "\t" << login_data_vec[login_data_vec.size() - 1]
            << "\t" << password_data_vec[password_data_vec.size() - 1];
        UserDataStream.close();
    }
}
void operation_files::rec_from_files_BankrollStream(QFile& BankrollStream)
{
    while (!BankrollStream.atEnd())
    {
        QString str_for_BankrollStream = BankrollStream.readLine();
        QStringList lst_5 = str_for_BankrollStream.split("\t");
        for(int i=0;i<lst_5.size();i++)
        {
            if(i%7 == 0)
            {
                card_bankroll_vec.push_back(lst_5[i]);
            }
            else if(i%7 == 1)
            {
                cash_RUB_vec.push_back(lst_5[i]);
            }
            else if(i%7 == 2)
            {
                cash_USD_vec.push_back(lst_5[i]);
            }
            else if(i%7 == 3)
            {
                cash_EUR_vec.push_back(lst_5[i]);
            }
            else if(i%7 == 4)
            {
                deposit_RUB_vec.push_back(lst_5[i]);
            }
            else if(i%7 == 5)
            {
                deposit_USD_vec.push_back(lst_5[i]);
            }
            else if(i%7 == 6)
            {
                deposit_EUR_vec.push_back(lst_5[i]);
            }
        }
    }
    BankrollStream.close();
}
void operation_files::rec_in_files_BankrollStream(QFile& BankrollStream)
{
    if(BankrollStream.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QTextStream out(&BankrollStream);
        for (int i = 0; i < card_bankroll_vec.size() - 1; i++)
        {
            out << card_bankroll_vec[i] << "\t" << cash_RUB_vec[i] << "\t" << cash_USD_vec[i] << "\t" << cash_EUR_vec[i] << "\t" <<
                deposit_RUB_vec[i] << "\t" << deposit_USD_vec[i] << "\t" << deposit_EUR_vec[i] << "\n";
        }
        out << card_bankroll_vec[card_bankroll_vec.size() - 1] << "\t" << cash_RUB_vec[cash_RUB_vec.size() - 1]
            << "\t" << cash_USD_vec[cash_USD_vec.size() - 1] << "\t" << cash_EUR_vec[cash_EUR_vec.size() - 1] << "\t" <<
            deposit_RUB_vec[deposit_RUB_vec.size() - 1] << "\t" << deposit_USD_vec[deposit_USD_vec.size() - 1] << "\t" <<
            deposit_EUR_vec[deposit_EUR_vec.size() - 1];
        BankrollStream.close();
    }
}

#ifndef OPERATION_FILES_H
#define OPERATION_FILES_H

#include <QTextStream>
#include <QFile>

#include <userlist.h>
#include <passportuser.h>
#include <cardlist.h>
#include <userdata.h>
#include <bankroll.h>

class operation_files
{
public:
    operation_files();
    void rec_from_files_UserListStream(QFile& UserListStream);
    void rec_from_files_PassportUserStream(QFile& PassportUserStream);
    void rec_from_files_CardListStream(QFile& CardListStream);
    void rec_from_files_UserDataStream(QFile& UserDataStream);
    void rec_in_files_UserDataStream(QFile& UserDataStream);
    void rec_from_files_BankrollStream(QFile& BankrollStream);
    void rec_in_files_BankrollStream(QFile& BankrollStream);
};

#endif // OPERATION_FILES_H

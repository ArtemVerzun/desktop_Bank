#ifndef USD_DEPOSIT_P_H
#define USD_DEPOSIT_P_H
#include <deposit_p.h>
#include <QDebug>

class USD_deposit_p:public deposit_p
{
public:
    USD_deposit_p();
    void info()
    {
        qDebug() << "Долларовый депозит\n ";
    }
};

#endif // USD_DEPOSIT_P_H

#ifndef USD_CASH_P_H
#define USD_CASH_P_H
#include <cash_p.h>
#include <QDebug>

class USD_cash_p:public cash_p
{
public:
    USD_cash_p();
    void info()
    {
        qDebug() << "Долларовый счет\n ";
    }
};

#endif // USD_CASH_P_H

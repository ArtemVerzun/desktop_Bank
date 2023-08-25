#ifndef RUB_CASH_P_H
#define RUB_CASH_P_H
#include <cash_p.h>
#include <QDebug>

class RUB_cash_p:public cash_p
{
public:
    RUB_cash_p();
    void info()
    {
        qDebug() << "Рублевый счет\n ";
    }
};

#endif // RUB_CASH_P_H

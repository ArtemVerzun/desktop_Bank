#ifndef EUR_CASH_P_H
#define EUR_CASH_P_H
#include <cash_p.h>
#include <QDebug>

class EUR_cash_p:public cash_p
{
public:
    EUR_cash_p();
    void info()
    {
        qDebug() << "Евро счет\n ";
    }
};

#endif // EUR_CASH_P_H

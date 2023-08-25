#ifndef RUB_DEPOSIT_P_H
#define RUB_DEPOSIT_P_H
#include <deposit_p.h>
#include <QDebug>

class RUB_deposit_p:public deposit_p
{
public:
    RUB_deposit_p();
    void info()
    {
        qDebug() << "Рублевый депозит\n ";
    }
};

#endif // RUB_DEPOSIT_P_H

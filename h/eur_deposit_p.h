#ifndef EUR_DEPOSIT_P_H
#define EUR_DEPOSIT_P_H
#include <deposit_p.h>
#include <QDebug>

class EUR_deposit_p:public deposit_p
{
public:
    EUR_deposit_p();
    void info()
    {
        qDebug() << "Евро депозит\n ";
    }
};

#endif // EUR_DEPOSIT_P_H

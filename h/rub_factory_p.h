#ifndef RUB_FACTORY_P_H
#define RUB_FACTORY_P_H
#include <factory_p.h>
#include <rub_cash_p.h>
#include <rub_deposit_p.h>

class RUB_factory_p:public factory_p
{
public:
    RUB_factory_p();
    cash_p* createCash_()
    {
        return new RUB_cash_p;
    }
    deposit_p* createDeposit_()
    {
        return new RUB_deposit_p;
    }
};

#endif // RUB_FACTORY_P_H

#ifndef USD_FACTORY_P_H
#define USD_FACTORY_P_H
#include <factory_p.h>
#include <usd_cash_p.h>
#include <usd_deposit_p.h>

class USD_factory_p:public factory_p
{
public:
    USD_factory_p();
    cash_p* createCash_()
    {
        return new USD_cash_p;
    }
    deposit_p* createDeposit_()
    {
        return new USD_deposit_p;
    }
};

#endif // USD_FACTORY_P_H

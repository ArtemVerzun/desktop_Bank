#ifndef EUR_FACTORY_P_H
#define EUR_FACTORY_P_H
#include <factory_p.h>
#include <eur_cash_p.h>
#include <eur_deposit_p.h>

class EUR_factory_p:public factory_p
{
public:
    EUR_factory_p();
    cash_p* createCash_()
    {
        return new EUR_cash_p;
    }
    deposit_p* createDeposit_()
    {
        return new EUR_deposit_p;
    }
};

#endif // EUR_FACTORY_P_H

#ifndef FACTORY_P_H
#define FACTORY_P_H
#include <cash_p.h>
#include <deposit_p.h>

class factory_p
{
public:
    factory_p();
    virtual cash_p* createCash_() = 0;
    virtual deposit_p* createDeposit_() = 0;
    virtual ~factory_p() {};
};

#endif // FACTORY_P_H

#ifndef BANK_PRODUCT_CREATURE_P_H
#define BANK_PRODUCT_CREATURE_P_H
#include <factory_p.h>
#include <bank_product_contain_p.h>

class bank_product_creature_p
{
public:
    bank_product_creature_p();
    bank_product_contain_p* creatProduct(factory_p& factory) {
        bank_product_contain_p* p = new bank_product_contain_p;
        p->vcash_.push_back(factory.createCash_());
        p->vdeposit_.push_back(factory.createDeposit_());
        return p;
    }
};

#endif // BANK_PRODUCT_CREATURE_P_H

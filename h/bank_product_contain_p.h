#ifndef BANK_PRODUCT_CONTAIN_P_H
#define BANK_PRODUCT_CONTAIN_P_H
#include <cash_p.h>
#include <deposit_p.h>
#include <QVector>

class bank_product_contain_p
{
public:
    bank_product_contain_p();
    ~bank_product_contain_p() {
        int i;
        for (i = 0; i < vcash_.size(); ++i)  delete vcash_[i];
        for (i = 0; i < vdeposit_.size(); ++i)  delete vdeposit_[i];
    }
    void info() {
        int i;
        for (i = 0; i < vcash_.size(); ++i)  vcash_[i]->info();
        for (i = 0; i < vdeposit_.size(); ++i)  vdeposit_[i]->info();
    }
    QVector<cash_p*> vcash_;
    QVector<deposit_p*> vdeposit_;
};

#endif // BANK_PRODUCT_CONTAIN_P_H

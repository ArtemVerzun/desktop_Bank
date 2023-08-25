#ifndef BANKROLL_H
#define BANKROLL_H
#include <QString>
#include <QVector>

extern QVector<QString>card_bankroll_vec;
extern QVector<QString>deposit_RUB_vec;
extern QVector<QString>deposit_USD_vec;
extern QVector<QString>deposit_EUR_vec;
extern QVector<QString>cash_RUB_vec;
extern QVector<QString>cash_USD_vec;
extern QVector<QString>cash_EUR_vec;

class bankroll
{
private:
    QString card_bankroll;
    QString cash_RUB;
    QString deposit_RUB;
    QString deposit_USD;
    QString deposit_EUR;
    QString cash_USD;
    QString cash_EUR;
public:
    bankroll();
    QString get_card_bankroll();
    void set_card_bankroll(QString s_card_bankroll);
    QString get_cash_RUB();
    void set_cash_RUB(QString s_cash_RUB);
    QString get_cash_USD();
    void set_cash_USD(QString s_cash_USD);
    QString get_cash_EUR();
    void set_cash_EUR(QString s_cash_EUR);
    QString get_deposit_RUB();
    void set_deposit_RUB(QString s_deposit_RUB);
    QString get_deposit_USD();
    void set_deposit_USD(QString s_deposit_USD);
    QString get_deposit_EUR();
    void set_deposit_EUR(QString s_deposit_EUR);
};

#endif // BANKROLL_H

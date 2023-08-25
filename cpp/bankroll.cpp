#include "bankroll.h"

bankroll::bankroll()
{

}
QString bankroll::get_card_bankroll()
{
    return card_bankroll;
}
void bankroll::set_card_bankroll(QString s_card_bankroll)
{
    card_bankroll = s_card_bankroll;
}
QString bankroll::get_cash_RUB()
{
    return cash_RUB;
}
void bankroll::set_cash_RUB(QString s_cash_RUB)
{
    cash_RUB = s_cash_RUB;
}
QString bankroll::get_cash_USD()
{
    return cash_USD;
}
void bankroll::set_cash_USD(QString s_cash_USD)
{
    cash_USD = s_cash_USD;
}
QString bankroll::get_cash_EUR()
{
    return cash_EUR;
}
void bankroll::set_cash_EUR(QString s_cash_EUR)
{
    cash_EUR = s_cash_EUR;
}
QString bankroll::get_deposit_RUB()
{
    return deposit_RUB;
}
void bankroll::set_deposit_RUB(QString s_deposit_RUB)
{
    deposit_RUB = s_deposit_RUB;
}
QString bankroll::get_deposit_USD()
{
    return deposit_USD;
}
void bankroll::set_deposit_USD(QString s_deposit_USD)
{
    deposit_USD = s_deposit_USD;
}
QString bankroll::get_deposit_EUR()
{
    return deposit_EUR;
}
void bankroll::set_deposit_EUR(QString s_deposit_EUR)
{
    deposit_EUR = s_deposit_EUR;
}

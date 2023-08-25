#include "cardlist.h"

cardlist::cardlist()
{

}
QString cardlist::get_card()
{
    return card;
}
void cardlist::set_card(QString s_card)
{
    card = s_card;
}
QString cardlist::get_cvc_card()
{
    return cvc_card;
}
void cardlist::set_cvc_card(QString s_cvc_card)
{
    cvc_card = s_cvc_card;
}
QString cardlist::get_data_card()
{
    return data_card;
}
void cardlist::set_data_card(QString s_data_card)
{
    data_card = s_data_card;
}
QString cardlist::get_nameuser_card()
{
    return nameuser_card;
}
void cardlist::set_nameuser_card(QString s_nameuser_card)
{
    nameuser_card = s_nameuser_card;
}

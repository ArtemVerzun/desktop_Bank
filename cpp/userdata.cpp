#include "userdata.h"

userdata::userdata()
{

}
QString userdata::get_card_data()
{
    return card_data;
}
QString userdata::get_login_data()
{
    return login_data;
}
QString userdata::get_password_data()
{
    return password_data;
}
void userdata::set_card_data(QString s_card_data)
{
    card_data = s_card_data;
}
void userdata::set_login_data(QString s_login_data)
{
    login_data = s_login_data;
}
void userdata::set_password_data(QString s_password_data)
{
    password_data = s_password_data;
}

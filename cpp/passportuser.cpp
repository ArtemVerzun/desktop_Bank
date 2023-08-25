#include "passportuser.h"

passportuser::passportuser()
{

}
QString passportuser::get_passport()
{
    return passport;
}
void passportuser::set_passport(QString s_passport)
{
    passport = s_passport;
}
QString passportuser::get_addr_passport()
{
    return addr_passport;
}
void passportuser::set_addr_passport(QString s_addr_passport)
{
    addr_passport = s_addr_passport;
}
QString passportuser::get_data_passport()
{
    return data_passport;
}
void passportuser::set_data_passport(QString s_data_passport)
{
    data_passport = s_data_passport;
}
QString passportuser::get_code_passport()
{
    return code_passport;
}
void passportuser::set_code_passport(QString s_code_passport)
{
    code_passport = s_code_passport;
}

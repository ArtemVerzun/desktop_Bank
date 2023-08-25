#ifndef CARDLIST_H
#define CARDLIST_H
#include <QString>
#include <QVector>

extern QVector<QString>card_vec;
extern QVector<QString>cvc_card_vec;
extern QVector<QString>data_card_vec;
extern QVector<QString>nameuser_card_vec;

class cardlist
{
private:
    QString card;
    QString cvc_card;
    QString data_card;
    QString nameuser_card;
public:
    cardlist();
    QString get_card();
    void set_card(QString s_card);
    QString get_cvc_card();
    void set_cvc_card(QString s_cvc_card);
    QString get_data_card();
    void set_data_card(QString s_data_card);
    QString get_nameuser_card();
    void set_nameuser_card(QString s_nameuser_card);
};

#endif // CARDLIST_H

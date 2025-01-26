#ifndef CURRENCYDATAFIELD_H
#define CURRENCYDATAFIELD_H

#include <QString>

struct CurrencyDataField
{
    CurrencyDataField(const QString name,const QString symb):name(name),symb(symb) {}
    QString name;
    QString symb;

};


#endif // CURRENCYDATAFIELD_H

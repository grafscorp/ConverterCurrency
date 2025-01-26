#ifndef SUPPORTEDCUNRRENCY_H
#define SUPPORTEDCUNRRENCY_H

#define ERROR_CANT_READ_CURRENCY_DATA_FILE -1

#include <QMap>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>
#include <currencyDataField.h>

class SupportedCunrrency
{
public:
    SupportedCunrrency();
    QList<CurrencyDataField> getCurrencyData();
protected:
    QList<CurrencyDataField> currencyData;

    void getCurrencyDataFromFile();
};



#endif // SUPPORTEDCUNRRENCY_H

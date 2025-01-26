#include "supportedcunrrency.h"

SupportedCunrrency::SupportedCunrrency() {}

QList<CurrencyDataField> SupportedCunrrency::getCurrencyData()
{
    return currencyData;
}

void SupportedCunrrency::getCurrencyDataFromFile()
{
    QFile CurrencyDataFile("CurrencyData.json");
    if(!CurrencyDataFile.open(QIODevice::ReadOnly)) throw ERROR_CANT_READ_CURRENCY_DATA_FILE;

    QJsonDocument currencyJsonDocument = QJsonDocument::fromJson( CurrencyDataFile.readAll() );
    QJsonArray currencyJsonArray = currencyJsonDocument.array();
    currencyData.clear();
    for (int i =0; i < currencyJsonArray.size();i++)
    {
        QString name = currencyJsonArray.at(i).toObject().value("name").toString();
        QString symb = currencyJsonArray.at(i).toObject().value("symb").toString();
        currencyData.append(CurrencyDataField(name,symb));
    }
    CurrencyDataFile.close();

}

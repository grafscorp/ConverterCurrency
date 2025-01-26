#include "convertercurrencyapi.h"

ConverterCurrencyApi::ConverterCurrencyApi(QObject *parent)
    : QObject{parent}
{

    getCurrencyDataFromFile();
    manager = new QNetworkAccessManager;
    QObject::connect(manager, &QNetworkAccessManager::finished, this, &ConverterCurrencyApi::onResult);
}

void ConverterCurrencyApi::getData(const QString cur_from, const QString cur_to, const QString sum)
{
    QUrl url(QString("https://cash.rbc.ru/cash/json/converter_currency_rate/?currency_from=" +cur_from+ "&currency_to="+cur_to+"&source=cbrf&sum="+sum+"&date="));
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);
}

void ConverterCurrencyApi::onResult(QNetworkReply * reply)
{
    if(reply->error())
    {
        emit onError(reply->errorString());
        return;
    }
    QJsonDocument js = QJsonDocument::fromJson(reply->readAll());
    //qDebug()<< js.object().value("meta").toObject().value("sum_deal");
    QJsonObject jsObj = js.object();
    QJsonObject jsObjMeta = jsObj.value("meta").toObject();
    QJsonObject jsObjData = jsObj.value("data").toObject();
    QMap<QString,QVariant> result;

    result.insert("status",jsObj.value("status").toInt());

    result.insert("sum_deal",jsObjMeta.value("sum_deal").toDouble());
    result.insert("currency_from",jsObjMeta.value("currency_from").toString());
    result.insert("currency_to",jsObjMeta.value("currency_to").toString());

    result.insert("date",jsObjData.value("date").toString());
    result.insert("sum_result",jsObjData.value("sum_result").toDouble());
    result.insert("rate1",jsObjData.value("rate1").toDouble());
    result.insert("rate2",jsObjData.value("rate2").toDouble());

    emit onReady(result);
    reply->deleteLater();
}

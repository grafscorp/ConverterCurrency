#ifndef CONVERTERCURRENCYAPI_H
#define CONVERTERCURRENCYAPI_H

#include <QObject>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
class ConverterCurrencyApi : public QObject
{
    Q_OBJECT
public:
    explicit ConverterCurrencyApi(QObject *parent = nullptr);
private:
    QNetworkAccessManager * manager;

public slots:
    void getData(const QString cur_from, const QString cur_to, const QString sum);
    void onResult(QNetworkReply *reply);

signals:
    void onReady(QMap<QString,QVariant>);
    void onError(QString);
};



#endif // CONVERTERCURRENCYAPI_H

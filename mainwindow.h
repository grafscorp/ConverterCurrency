#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <convertercurrencyapi.h>
#include <currencyfield.h>
#include <QKeyEvent>
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override
    {
        if(event->key() == Qt::Key_Enter)
        {
            getDataCurrency();
            qInfo()<<"OPK";
        }
    }

private:
    Ui::MainWindow *ui;
    ConverterCurrencyApi* converterApi;
    CurrencyField *currencyInputField;
    CurrencyField *currencyOutputField;
    QPushButton *convertButton;
    void getDataCurrency();
public slots:
    void onReady(QMap<QString,QVariant>);
    void onError(QString);
    void updateData();

};
#endif // MAINWINDOW_H

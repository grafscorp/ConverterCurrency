#ifndef CURRENCYFIELD_H
#define CURRENCYFIELD_H

#include <QWidget>
#include <QDoubleValidator>
namespace Ui {
class CurrencyField;
}

class CurrencyField : public QWidget
{
    Q_OBJECT

public:
    explicit CurrencyField(QWidget *parent = nullptr);
    ~CurrencyField();

    void addElementComboBoxCurrency(QString symbCurrency);
    void setOnlyReadMode(bool);
    void setValidatorForInputLineEdit(QDoubleValidator* validator);
    void setSubLine(QString);
    void setCurrencyLine(QString);
    QString getCurrencyLine();
    QString getCurrencySymb();
    void setCurrentIndex(const int);
private:
    Ui::CurrencyField *ui;
};

#endif // CURRENCYFIELD_H

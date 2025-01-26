#include "currencyfield.h"
#include "ui_currencyfield.h"

CurrencyField::CurrencyField(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CurrencyField)
{
    ui->setupUi(this);
    //ui->inputCurrencyLineEdit->setValidator(new QDoubleValidator(0,1000000,2,this));
}

CurrencyField::~CurrencyField()
{
    delete ui;
}

void CurrencyField::addElementComboBoxCurrency(QString symbCurrency)
{
    ui->comboBox->addItem(symbCurrency);
}

void CurrencyField::setOnlyReadMode(bool onlyRead)
{
    ui->inputCurrencyLineEdit->setReadOnly(onlyRead);
}

void CurrencyField::setValidatorForInputLineEdit(QDoubleValidator *validator)
{
    ui->inputCurrencyLineEdit->setValidator(validator);
}

void CurrencyField::setSubLine(QString text)
{
    ui->outputCurrencyLineEdit->setText(text);
}

void CurrencyField::setCurrencyLine(QString text)
{
    ui->inputCurrencyLineEdit->setText(text);
}

QString CurrencyField::getCurrencyLine()
{

    return ui->inputCurrencyLineEdit->text();
}

QString CurrencyField::getCurrencySymb()
{
    return ui->comboBox->currentText();
}

void CurrencyField::setCurrentIndex(const int index)
{
    ui->comboBox->setCurrentIndex(index);
}

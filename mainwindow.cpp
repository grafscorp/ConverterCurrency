#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    converterApi = new ConverterCurrencyApi(this);
    currencyInputField = new CurrencyField(this);
    currencyOutputField = new CurrencyField(this);
    convertButton = new QPushButton("Convert",this);

    currencyOutputField->setOnlyReadMode(true);

    currencyInputField->setValidatorForInputLineEdit(new QDoubleValidator(0,1000000,2,this));
    currencyInputField->setCurrencyLine("1");
    convertButton->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);


    auto listCurrencyData = converterApi->getCurrencyData();

    for(auto currencyData:listCurrencyData)
    {
        currencyInputField->addElementComboBoxCurrency(currencyData.symb);
        currencyOutputField->addElementComboBoxCurrency(currencyData.symb);
    }
    currencyOutputField->setCurrentIndex(1);

    ui->VLayout->setAlignment(Qt::AlignCenter);
    ui->horizontalLayout->addWidget(currencyInputField);
    ui->horizontalLayout->addWidget(currencyOutputField);
    ui->buttonLayout->addWidget(convertButton);

    currencyInputField->getCurrencySymb();

    connect(converterApi,&ConverterCurrencyApi::onReady,this,&MainWindow::onReady);
    connect(converterApi,&ConverterCurrencyApi::onError,this,&MainWindow::onError);
    connect(convertButton,&QPushButton::released, this,&MainWindow::updateData);
}

MainWindow::~MainWindow()
{
    delete currencyInputField;
    delete currencyOutputField;
    delete converterApi;
    delete convertButton;
    delete ui;
}

void MainWindow::getDataCurrency()
{
    ui->statusbar->showMessage("Downloading...");

}

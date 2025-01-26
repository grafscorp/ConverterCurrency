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

}

MainWindow::~MainWindow()
{
    delete converterApi;
    delete ui;
}

void MainWindow::getDataCurrency()
{
    ui->statusbar->showMessage("Downloading...");

}

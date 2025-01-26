#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    converterApi = new ConverterCurrencyApi(this);
    getDataCurrency();
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

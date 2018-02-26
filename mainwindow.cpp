#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "quatnumber.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toDecNumberA_clicked()
{
    if (a.set(ui->numberA->text().toInt())) {
        ui->decNumberA->setText(QString::number(this->a.converse()));
    }
    else ui->numberA->setText("ERROR");
}

void MainWindow::on_toDecNumberB_clicked()
{
    if (b.set(ui->numberB->text().toInt())) {
        ui->decNumberB->setText(QString::number(this->b.converse()));
    }
    else ui->numberB->setText("ERROR");
}

void MainWindow::on_toDecResult_clicked()
{
    if (res.set(ui->operationResult->text().toInt())) {
        ui->decResult->setText(QString::number(this->res.converse()));
    }
    else ui->operationResult->setText("ERROR");
}

void MainWindow::on_operationCommit_clicked()
{
    if (!(a.set(ui->numberA->text().toInt())))
        ui->numberA->setText("ERROR");
    if (!(b.set(ui->numberB->text().toInt())))
        ui->numberB->setText("ERROR");
    if (ui->operationSelect->currentIndex() == 0) {
        ui->operationResult->setText(res.add(a, b));
    }
    else if (ui->operationSelect->currentIndex() == 1) {
        ui->operationResult->setText(res.sub(a, b));
    }
}

void MainWindow::on_clear_clicked()
{
    ui->decNumberA->setText("");
    ui->decNumberB->setText("");
    ui->decResult->setText("");
    ui->numberA->setText("");
    ui->numberB->setText("");
    ui->operationResult->setText("");
    ui->operationSelect->setCurrentIndex(0);
}

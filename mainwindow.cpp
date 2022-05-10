#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSettings>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readSettings();
    licznik =0;
}

MainWindow::~MainWindow()
{
    writeSettings();
    delete ui;
}

void MainWindow::readSettings() {
    QSettings settings("Gra","ustawienia");
    settings.beginGroup("MainWindow");
    licznik2 = settings.value("rekord").toInt();
    ui->label_2->setText(QString::number(licznik2));
    settings.endGroup();
}

void MainWindow::on_pushButton_clicked()
{
   ui->label->setText(QString::number(++licznik));
   if (licznik2>licznik) {
       ui->label_2->setText(QString::number(licznik2));
}
   else if (licznik==licznik2) {
       ui->label_2->setText(QString::number(licznik2++));
   }
}


void MainWindow::writeSettings() {
    QSettings settings("Gra","ustawienia");
    settings.beginGroup("MainWindow");
    settings.setValue("rekord",licznik);
    settings.endGroup();
}


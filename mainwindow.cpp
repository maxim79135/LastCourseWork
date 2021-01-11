//
// Created by maxim on 10.01.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->textEdit_2->setReadOnly(true);

    rsa = new RSA();

    connect(ui->action_6, SIGNAL(triggered()), this, SLOT(createKeys()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(slotEncrypt()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(slotDecrypt()));
    connect(this, SIGNAL(clicked(bool)), this, SLOT(nextCommandRSA(bool)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::createKeys() {
    if (ui->tabWidget->currentIndex() == 0) {
        rsa->show();
    }
}

void MainWindow::nextCommandRSA(bool encrypt) {
    auto in = rsa->read_bytes(ui->textEdit->toPlainText());
    rsa->gen_keys(3557, 2579);
    qDebug() << rsa->get_e() << " " << rsa->get_d() << " " << rsa->get_n();
    auto out = rsa->process_bytes(in, {encrypt ? rsa->get_e() : rsa->get_d(), rsa->get_n()}, encrypt);
    out = rsa->process_bytes(in, {static_cast<uint64_t>(encrypt ? 0x10001 : 0x4b1dc9), 0x8bf9ff}, encrypt);
    ui->textEdit_2->setText(rsa->write_bytes(out));
    //qDebug() << ui->textEdit->toPlainText() << Qt::endl << rsa->write_bytes(out);
}

void MainWindow::slotEncrypt() {
    emit clicked(true);
}

void MainWindow::slotDecrypt() {
    emit clicked(false);
}


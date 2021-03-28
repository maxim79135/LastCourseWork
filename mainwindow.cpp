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
    rsa->gen_keys(3557, 2579);

    connect(ui->action_6, SIGNAL(triggered()), this, SLOT(createKeys()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(slotEncrypt()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(slotDecrypt()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::createKeys() {
    if (ui->tabWidget->currentIndex() == 0) {
        rsa->show();
    }
}

void MainWindow::nextCommandRSA() {
}

void MainWindow::slotEncrypt() {
    std::vector<uint64_t> ret = rsa->encrypt(ui->textEdit->toPlainText().toStdString(), {rsa->get_e(), rsa->get_n() });
    QString s;
    for (auto it: ret) {
        s.append(QString::number(it) + ",");
    }
    qDebug() << s;
    ui->textEdit_2->setText(s);
}

void MainWindow::slotDecrypt() {
    QStringList sl = ui->textEdit->toPlainText().split(",");
    std::vector<uint64_t> data;
    for (auto it: sl) {
        data.push_back(it.toInt());
    }
    qDebug() << data;
    QString s = rsa->decrypt(data, {rsa->get_d(), rsa->get_n() });
    ui->textEdit_2->setText(s);
}

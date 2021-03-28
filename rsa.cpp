//
// Created by maxim on 10.01.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RSA.h" resolved

#include <QFile>
#include <iostream>

#include "rsa.h"
#include "ui_RSA.h"

RSA::RSA(QWidget *parent) :
        QWidget(parent), ui(new Ui::RSA) {
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(saveSettings()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(close()));
}

RSA::~RSA() {
    delete ui;
}

void RSA::saveSettings() {
    this->p = (int64_t) ui->lineEdit->text().toInt();
    this->q = (int64_t) ui->lineEdit_2->text().toInt();
    this->n = (int64_t) ui->lineEdit_3->text().toInt();
    this->phi = (int64_t) ui->lineEdit_4->text().toInt();
    this->e = (int64_t) ui->lineEdit_5->text().toInt();
    this->d = (int64_t) ui->lineEdit_6->text().toInt();
    this->close();
}

std::vector<uint64_t> RSA::encrypt(std::string text, key k) {
    std::vector<uint64_t> ret(text.length());
    for (uint i = 0; i < text.length(); i++) {
        ret[i] = binpow(uint64_t(text[i]), k.e, k.m);
    }
    return ret;
}

QString RSA::decrypt(std::vector<uint64_t> data, key k) {
    QString ret;
    for (uint i = 0; i < data.size(); i++) {
        ret.append((char)binpow(data[i], k.e, k.m));
    }
    return ret;
}

void RSA::gen_keys(uint64_t p, uint64_t q) {
    this->p = p;
    this->q = q;
    this->phi = (p - 1) * (q - 1);
    this->n = p * q;


    this->e = 65537;
    this->d = invmod(e, phi);
}

int64_t RSA::gcdex(int64_t a, int64_t b, int64_t &x, int64_t &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int64_t x1, y1;
    int64_t d = gcdex(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int64_t RSA::invmod(int64_t a, int64_t m) {
    int64_t x, y;
    gcdex(a, m, x, y);
    x = (x % m + m) % m;
    return x;
}

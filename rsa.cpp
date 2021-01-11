//
// Created by maxim on 10.01.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RSA.h" resolved

#include <fstream>
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

std::vector<uint8_t> RSA::read_bytes(QString text) {
    std::string textIn = text.toStdString();
    std::vector<uint8_t> ret(textIn.length());
    for (int i = 0; i < textIn.length(); i++) {
        ret[i] = (uint8_t) textIn[i];
        std::cout << ret[i];
    }

    return ret;
}

std::vector<uint8_t> RSA::process_bytes(const std::vector<uint8_t> &data, key k, bool encrypt) {
    std::vector<uint64_t> data_64(data.size());
    for (int i = 0; i < data.size(); i++)
        data_64[i] = (uint64_t) data[i];
    std::vector<uint64_t> resized_data = resize(data_64, 8, get_chunk_size(k) - encrypt); //Если мы шифруем, то размер блока K - 1, иначе K
    std::vector<uint64_t> encrypted_data(resized_data.size());
    for (int i = 0; i < resized_data.size(); i++)
        encrypted_data[i] = binpow(resized_data[i], k.e, k.m);
    std::vector<uint64_t> result_64 = resize(encrypted_data, get_chunk_size(k) - !encrypt, 8);
    std::vector<uint8_t> result(result_64.size());
    for (int i = 0; i < result_64.size(); i++) {
        result[i] = (uint8_t) result_64[i];
        //qDebug() << result[i] << " ";
    }
    return result;
}

std::vector<uint64_t> RSA::resize(const std::vector<uint64_t> &data, uint8_t in_size, uint8_t out_size) {
    std::vector<uint64_t> res;
    uint8_t done = 0;
    uint64_t cur = 0;
    for (uint64_t byte: data)
        for (uint8_t i = 0; i < in_size; i++) {
            cur = (cur << 1U) + (((uint64_t) byte & (1U << (uint64_t) (in_size - 1 - i))) != 0);
            done++;
            if (done == out_size) {
                done = 0;
                res.push_back(cur);
                cur = 0;
            }
        }

    if (done != 0)
        res.push_back(cur << (uint64_t) (out_size - done));
    return res;
}

void RSA::gen_keys(uint64_t p, uint64_t q) {
    this->p = p;
    this->q = q;
    this->phi = (p - 1) * (q - 1);
    this->n = p * q;

    //Простое число Мерсенна, обычно используется в RSA в виде открытой экспоненты для увеличения производительности
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

QString RSA::write_bytes(const std::vector<uint8_t> &data) {
    char* buf = new char[data.size()];
    for (int i = 0; i < data.size(); i++) {
        buf[i] = (char) data[i];
    }
    QString ret = QString::fromLocal8Bit(buf);
    QFile file(".\\output.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << ret;
    }
    return ret;
}

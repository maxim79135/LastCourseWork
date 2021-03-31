#include "elgamal.h"
#include "ui_elgamal.h"

elgamal::elgamal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::elgamal)
{
    ui->setupUi(this);
}

elgamal::~elgamal()
{
    delete ui;
}

void elgamal::gen_keys(uint64_t p)
{
    this->g = 123;
    this->p = p;
    this->x = 8;
    this->k = rand() % (this->p - 2) + 1;
    this->y = this->binpow(g, x, p);
}

std::vector<encrypt_data> elgamal::encrypt(std::string text) {
    std::vector<encrypt_data> ret(text.length());

    for (uint i = 0; i < text.length(); i++) {
        uint64_t a = binpow(this->g, k, this->p);
        uint64_t b = mul(binpow(this->y, k, this->p), (int) text[i], this->p);
        ret[i] = {a, b};
    }
    return ret;
}

QString elgamal::decrypt(std::vector<encrypt_data> data) {
    QString ret;
    for (uint i = 0; i < data.size(); i++) {
        ret.append((char)this->mul(data[i].b, this->binpow(data[i].a, this->p - 1 - this->x, this->p), this->p));
    }
    return ret;
}

void elgamal::lockLineEdits() {
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
}

void elgamal::clearLineEdits() {
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}

void elgamal::createTemplateKeys() {
    this->gen_keys(593);
    ui->lineEdit->setText(QString::number(this->p));
    ui->lineEdit_2->setText(QString::number(this->g));
    ui->lineEdit_3->setText(QString::number(this->x));
    ui->lineEdit_4->setText(QString::number(this->k));
    ui->lineEdit_5->setText(QString::number(this->y));
}

bool elgamal::isConfirmed() {
    if (!ui->lineEdit->text().isEmpty() &&
        !ui->lineEdit_2->text().isEmpty() &&
        !ui->lineEdit_3->text().isEmpty() &&
        !ui->lineEdit_4->text().isEmpty() &&
        !ui->lineEdit_5->text().isEmpty()) return true;
    return false;
}

QString elgamal::toString(std::vector<encrypt_data> data) {
    QString s;
    for (auto it: data) {
        s.append(QString::number(it.a) + ";" + QString::number((it.b)) + ",");
    }
    return s;
}

std::vector<encrypt_data> elgamal::toArray(QString s) {
    QStringList sl = s.split(",");
    std::vector<encrypt_data> data;

    for (auto it: sl) {
        QStringList _sl = it.split(";");
        if (_sl[0] != "") data.push_back({(uint64_t)_sl[0].toInt(), (uint64_t)_sl[1].toInt()});
    }
    return data;
}

uint64_t elgamal::mul(uint64_t a, uint64_t b, uint64_t n) {
    uint64_t sum=0;

    for(uint i = 0; i < b; i++){
        sum += a;
        if(sum>=n){
            sum -= n;
        }
    }
    return sum;
}

int64_t elgamal::gcdex(int64_t a, int64_t b, int64_t &x, int64_t &y) {
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

int64_t elgamal::invmod(int64_t a, int64_t m) {
    int64_t x, y;
    gcdex(a, m, x, y);
    x = (x % m + m) % m;
    return x;
}

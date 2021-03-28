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
    this->y = this->binpow(g, x, p);
}

std::vector<encrypt_data> elgamal::encrypt(std::string text, public_key key) {
    std::vector<encrypt_data> ret(text.length());
    uint64_t k = rand() % (key.p - 2) +1;

    for (uint i = 0; i < text.length(); i++) {
        uint64_t a = binpow(key.g, k, key.p);
        uint64_t b = mul(binpow(key.y, k, key.p), (int) text[i], key.p);
        ret[i] = {a, b};
    }
    return ret;
}

QString elgamal::decrypt(std::vector<encrypt_data> data, private_key key) {
    QString ret;
    for (uint i = 0; i < data.size(); i++) {
        ret.append((char)this->mul(data[i].b, this->binpow(data[i].a, this->p - 1 - key.x, this->p), this->p));
    }
    return ret;
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

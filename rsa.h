//
// Created by maxim on 10.01.2021.
//

#ifndef LASTCOURSEWORK_RSA_H
#define LASTCOURSEWORK_RSA_H

#include <QWidget>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class RSA; }
QT_END_NAMESPACE

typedef struct {
    uint64_t e;
    uint64_t m;
} key;

class RSA : public QWidget {
Q_OBJECT

public:
    explicit RSA(QWidget *parent = nullptr);

    ~RSA() override;
    uint64_t get_p() {return this->p; };
    uint64_t get_q() {return this->q; };
    uint64_t get_n() {return this->n; };
    uint64_t get_e() {return this->e; };
    uint64_t get_d() {return this->d; };
    uint64_t get_phi() {return this->phi; };

    std::vector<uint64_t> encrypt(std::string, key);
    QString decrypt(std::vector<uint64_t>, key);
    void gen_keys(uint64_t p, uint64_t q);

private:
    Ui::RSA *ui;
    uint64_t p, q, n, e, d, phi;
    uint64_t sqr(uint64_t x) {return x * x;}
    uint64_t binpow(uint64_t a, uint64_t e, uint64_t mod = LLONG_MAX) { return e == 0 ? 1 : (e & 1U ? a * binpow(a, e - 1, mod) % mod : sqr(binpow(a, e / 2, mod)) % mod); };
    int64_t gcdex(int64_t, int64_t, int64_t &, int64_t &);
    int64_t invmod(int64_t, int64_t);

private slots:
    void saveSettings();
};

#endif //LASTCOURSEWORK_RSA_H

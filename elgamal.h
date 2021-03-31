#ifndef ELGAMAL_H
#define ELGAMAL_H

#include <QWidget>

namespace Ui {
class elgamal;
}

typedef struct {
    uint64_t p;
    uint64_t g;
    uint64_t y;
} public_key;

typedef struct {
    uint64_t x;
} private_key;

typedef struct {
    uint64_t a;
    uint64_t b;
} encrypt_data;

class elgamal : public QWidget
{
    Q_OBJECT

public:
    explicit elgamal(QWidget *parent = nullptr);
    ~elgamal();

    uint64_t get_p() { return p; };
    uint64_t get_g() { return g; };
    uint64_t get_y() { return y; };
    uint64_t get_x() { return x; };

    void gen_keys(uint64_t p);
    std::vector<encrypt_data> encrypt(std::string);
    QString decrypt(std::vector<encrypt_data>);

    void lockLineEdits();
    void clearLineEdits();
    void createTemplateKeys();
    bool isConfirmed();
    QString toString(std::vector<encrypt_data>);
    std::vector<encrypt_data> toArray(QString);

private:
    Ui::elgamal *ui;
    uint64_t p, g, x, k, y;

    uint64_t sqr(uint64_t x) {return x * x;}
    uint64_t binpow(uint64_t a, uint64_t e, uint64_t mod = LLONG_MAX) { return e == 0 ? 1 : (e & 1U ? a * binpow(a, e - 1, mod) % mod : sqr(binpow(a, e / 2, mod)) % mod); };
    uint64_t mul(uint64_t, uint64_t, uint64_t);
    int64_t gcdex(int64_t, int64_t, int64_t &, int64_t &);
    int64_t invmod(int64_t, int64_t);
};

#endif // ELGAMAL_H

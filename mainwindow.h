//
// Created by maxim on 10.01.2021.
//

#ifndef LASTCOURSEWORK_MAINWINDOW_H
#define LASTCOURSEWORK_MAINWINDOW_H

#include <QMainWindow>
#include "rsa.h"
#include "elgamal.h"
#include "generatortask.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    RSA *rsa;
    elgamal *p_elgamal;

    std::vector<GeneratorTask*> gt;

private slots:
    void createKeys();
    void nextCommandRSA();
    void nextCommandElgamal();
    void slotEncrypt();
    void slotDecrypt();
    void slotEncryptElgamal();
    void slotDecryptElgamal();
    void slotGenerateTestKeysRSA();
    void slotGenerateTestKeysElgamal();
};

#endif //LASTCOURSEWORK_MAINWINDOW_H

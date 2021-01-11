//
// Created by maxim on 10.01.2021.
//

#ifndef LASTCOURSEWORK_MAINWINDOW_H
#define LASTCOURSEWORK_MAINWINDOW_H

#include <QMainWindow>
#include "rsa.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

signals:
    void clicked(bool);

private:
    Ui::MainWindow *ui;
    RSA *rsa;

private slots:
    void createKeys();
    void nextCommandRSA(bool);
    void slotEncrypt();
    void slotDecrypt();

};

#endif //LASTCOURSEWORK_MAINWINDOW_H

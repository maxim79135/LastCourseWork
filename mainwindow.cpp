//
// Created by maxim on 10.01.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"
#include <string>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->textElgamal->setReadOnly(true);
    this->setCentralWidget(ui->tabWidget);


    gt = new GeneratorTask();
    gt->setMaxCount(5);
    gt->generateTask();

    rsa = new RSA();
    rsa->createTemplateKeys();

    p_elgamal = new elgamal();
    p_elgamal->gen_keys(593);

    connect(ui->action_6, SIGNAL(triggered()), this, SLOT(createKeys()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(slotEncrypt()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(slotDecrypt()));

    connect(ui->pushButton_6, SIGNAL(clicked(bool)), this, SLOT(slotEncryptElgamal()));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(slotDecryptElgamal()));
    connect(ui->nextCommandRSA, SIGNAL(clicked(bool)), this, SLOT(nextCommandRSA()));
    connect(ui->generateKeys, SIGNAL(clicked(bool)), this, SLOT(slotGenerateTestKeys()));

//    ui->textEdit->setText(gt->generateRandomString(10));
    ui->title->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->title->setText(gt->getCurrentTask());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::createKeys() {
    if (ui->tabWidget->currentIndex() == 0) {
        rsa->show();
    } else if (ui->tabWidget->currentIndex() == 1) {
        p_elgamal->show();
    }
}

void MainWindow::nextCommandRSA() {
    int currentTaskType = gt->getCurrentTaskType();
    switch (currentTaskType) {
        case 0: {
            if (rsa->isConfirmed()) {
                gt->nextTask();
                ui->listWidget->addItem(QString::number(gt->getCurrentTaskIndex()));
                if (gt->isCompleted()) {
                    QMessageBox::information(this, "Успешно", "Все задания были успешно выполнены!");
                    return;
                }
                rsa->lockLineEdits();
                ui->title->setText(gt->getCurrentTask());
                int nextTaskType = gt->getCurrentTaskType();
                QString text = gt->generateRandomString(20);
                if (nextTaskType == 1)
                    ui->textEdit->setText(text);
                else if (nextTaskType == 2)
                    ui->textEdit->setText(rsa->toString(rsa->encrypt(text.toStdString(), {rsa->get_e(), rsa->get_n() })));
            } else {
                QMessageBox::information(this, "Ошибка", "Неверно указаны параметры, необходимые для генерации ключей!");
            }
            break;
        }

        case 1: {
            QString ret = ui->textEdit_2->toPlainText();
            if (!ret.isEmpty()) {
                if (ret == rsa->toString(rsa->encrypt(ui->textEdit->toPlainText().toStdString(), {rsa->get_e(), rsa->get_n() }))) {
                    gt->nextTask();
                    ui->listWidget->addItem(QString::number(gt->getCurrentTaskIndex()));
                    if (gt->isCompleted()) {
                        QMessageBox::information(this, "Успешно", "Все задания были успешно выполнены!");
                        return;
                    }
                    ui->title->setText(gt->getCurrentTask());
                    int nextTaskType = gt->getCurrentTaskType();
                    QString text = gt->generateRandomString(20);
                    if (nextTaskType == 0) {
                        rsa->clearLineEdits();
                        ui->textEdit->clear();
                        ui->textEdit_2->clear();
                    } else if (nextTaskType == 1)
                        ui->textEdit->setText(text);
                    else
                        ui->textEdit->setText(rsa->toString(rsa->encrypt(text.toStdString(), {rsa->get_e(), rsa->get_n() })));
                } else {
                    QMessageBox::information(this, "Ошибка", "Неверно зашифрован текст!");
                }
            } else {
                QMessageBox::information(this, "Ошибка", "Поле с зашифрованным сообщением не должно быть пустым!");
            }

            break;
        }

        case 2: {
            QString ret = ui->textEdit_2->toPlainText();
            if (!ret.isEmpty()) {
                if (ret == rsa->decrypt(rsa->toArray(ui->textEdit->toPlainText()), {rsa->get_d(), rsa->get_n() })) {
                    gt->nextTask();
                    ui->listWidget->addItem(QString::number(gt->getCurrentTaskIndex()));
                    if (gt->isCompleted()) {
                        QMessageBox::information(this, "Успешно", "Все задания были успешно выполнены!");
                        return;
                    }
                    ui->title->setText(gt->getCurrentTask());
                    int nextTaskType = gt->getCurrentTaskType();
                    QString text = gt->generateRandomString(20);
                    if (nextTaskType == 0) {
                        rsa->clearLineEdits();
                        ui->textEdit->clear();
                        ui->textEdit_2->clear();
                    } else if (nextTaskType == 1)
                        ui->textEdit->setText(text);
                    else
                        ui->textEdit->setText(rsa->toString(rsa->encrypt(text.toStdString(), {rsa->get_e(), rsa->get_n() })));
                } else {
                    QMessageBox::information(this, "Ошибка", "Неверно дешифрован текст!");
                }
            } else {
                QMessageBox::information(this, "Ошибка", "Поле с дешифрованным сообщением не должно быть пустым!");
            }

            break;
        }
    }
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

void MainWindow::slotEncryptElgamal() {
    std::vector<encrypt_data> ret = p_elgamal->encrypt(ui->textElgamal->toPlainText().toStdString(), {p_elgamal->get_p(), p_elgamal->get_g(), p_elgamal->get_y()});
    QString s;
    for (auto it: ret) {
        s.append(QString::number(it.a) + ";" + QString::number((it.b)) + ",");
    }
    qDebug() << s;
    ui->textElgamal_2->setText(s);
}

void MainWindow::slotDecryptElgamal() {
    QStringList sl = ui->textElgamal->toPlainText().split(",");
    std::vector<encrypt_data> data;

    for (auto it: sl) {
        QStringList _sl = it.split(";");
        if (_sl[0] != "") data.push_back({(uint64_t)_sl[0].toInt(), (uint64_t)_sl[1].toInt()});
    }
    QString s = p_elgamal->decrypt(data, {p_elgamal->get_x()});
    ui->textElgamal_2->setText(s);
}

void MainWindow::slotGenerateTestKeys() {
    rsa->createTemplateKeys();
}

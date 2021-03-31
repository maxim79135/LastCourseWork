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
    ui->textEdit->setMinimumWidth(200);
    ui->textEdit_2->setMinimumWidth(200);
    ui->textEdit_elgamal->setReadOnly(true);
    this->setCentralWidget(ui->tabWidget);


    gt.push_back(new GeneratorTask());
    gt.push_back(new GeneratorTask());
    gt[0]->setMaxCount(5);
    gt[0]->generateTask();
    gt[1]->setMaxCount(5);
    gt[1]->generateTask();

    rsa = new RSA();
    p_elgamal = new elgamal();

    connect(ui->action_6, SIGNAL(triggered()), this, SLOT(createKeys()));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(slotEncrypt()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(slotDecrypt()));

    connect(ui->encryptElgamal, SIGNAL(clicked(bool)), this, SLOT(slotEncryptElgamal()));
    connect(ui->decryptElgamal, SIGNAL(clicked(bool)), this, SLOT(slotDecryptElgamal()));
    connect(ui->nextCommandRSA, SIGNAL(clicked(bool)), this, SLOT(nextCommandRSA()));
    connect(ui->nextCommandElgamal, SIGNAL(clicked(bool)), this, SLOT(nextCommandElgamal()));
    connect(ui->generateKeys, SIGNAL(clicked(bool)), this, SLOT(slotGenerateTestKeysRSA()));
    connect(ui->generateKeysElgamal, SIGNAL(clicked(bool)), this, SLOT(slotGenerateTestKeysElgamal()));

    ui->title->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->title_2->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->title->setText(gt[0]->getCurrentTask());
    ui->title_2->setText(gt[1]->getCurrentTask());
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
    int currentTaskType = gt[0]->getCurrentTaskType();
    switch (currentTaskType) {
        case 0: {
            if (rsa->isConfirmed()) {
                gt[0]->nextTask();
                ui->listWidget->addItem(QString::number(gt[0]->getCurrentTaskIndex()));
                if (gt[0]->isCompleted()) {
                    QMessageBox::information(this, "Успешно", "Все задания были успешно выполнены!");
                    return;
                }
                rsa->lockLineEdits();
                ui->title->setText(gt[0]->getCurrentTask());
                int nextTaskType = gt[0]->getCurrentTaskType();
                QString text = gt[0]->generateRandomString(20);
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
                    gt[0]->nextTask();
                    ui->listWidget->addItem(QString::number(gt[0]->getCurrentTaskIndex()));
                    if (gt[0]->isCompleted()) {
                        QMessageBox::information(this, "Успешно", "Все задания были успешно выполнены!");
                        return;
                    }
                    ui->title->setText(gt[0]->getCurrentTask());
                    int nextTaskType = gt[0]->getCurrentTaskType();
                    QString text = gt[0]->generateRandomString(20);
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
                    gt[0]->nextTask();
                    ui->listWidget->addItem(QString::number(gt[0]->getCurrentTaskIndex()));
                    if (gt[0]->isCompleted()) {
                        QMessageBox::information(this, "Успешно", "Все задания были успешно выполнены!");
                        return;
                    }
                    ui->title->setText(gt[0]->getCurrentTask());
                    int nextTaskType = gt[0]->getCurrentTaskType();
                    QString text = gt[0]->generateRandomString(20);
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

void MainWindow::nextCommandElgamal() {
    qDebug() << "2";
    int currentTaskType = gt[1]->getCurrentTaskType();
    switch (currentTaskType) {
        case 0: {
            if (p_elgamal->isConfirmed()) {
                gt[1]->nextTask();
                ui->listWidget_3->addItem(QString::number(gt[1]->getCurrentTaskIndex()));
                if (gt[1]->isCompleted()) {
                    QMessageBox::information(this, "Успешно", "Все задания были успешно выполнены!");
                    return;
                }
                p_elgamal->lockLineEdits();
                ui->title_2->setText(gt[1]->getCurrentTask());
                int nextTaskType = gt[1]->getCurrentTaskType();
                QString text = gt[1]->generateRandomString(20);
                if (nextTaskType == 1)
                    ui->textEdit_elgamal->setText(text);
                else if (nextTaskType == 2)
                    ui->textEdit_elgamal->setText(p_elgamal->toString(p_elgamal->encrypt(text.toStdString())));
            } else {
                QMessageBox::information(this, "Ошибка", "Неверно указаны параметры, необходимые для генерации ключей!");
            }
            break;
        }

        case 1: {
            QString ret = ui->textEdit_elgamal_2->toPlainText();
            if (!ret.isEmpty()) {
                if (ret == p_elgamal->toString(p_elgamal->encrypt(ui->textEdit_elgamal->toPlainText().toStdString()))) {
                    gt[1]->nextTask();
                    ui->listWidget_3->addItem(QString::number(gt[1]->getCurrentTaskIndex()));
                    if (gt[1]->isCompleted()) {
                        QMessageBox::information(this, "Успешно", "Все задания были успешно выполнены!");
                        return;
                    }
                    ui->title_2->setText(gt[1]->getCurrentTask());
                    int nextTaskType = gt[1]->getCurrentTaskType();
                    QString text = gt[1]->generateRandomString(20);
                    if (nextTaskType == 0) {
                        p_elgamal->clearLineEdits();
                        ui->textEdit_elgamal->clear();
                        ui->textEdit_elgamal_2->clear();
                    } else if (nextTaskType == 1)
                        ui->textEdit_elgamal->setText(text);
                    else
                        ui->textEdit_elgamal->setText(p_elgamal->toString(p_elgamal->encrypt(text.toStdString())));
                } else {
                    QMessageBox::information(this, "Ошибка", "Неверно зашифрован текст!");
                }
            } else {
                QMessageBox::information(this, "Ошибка", "Поле с зашифрованным сообщением не должно быть пустым!");
            }

            break;
        }

        case 2: {
            QString ret = ui->textEdit_elgamal_2->toPlainText();
            if (!ret.isEmpty()) {
                if (ret == p_elgamal->decrypt(p_elgamal->toArray(ui->textEdit_elgamal->toPlainText()))) {
                    gt[1]->nextTask();
                    ui->listWidget_3->addItem(QString::number(gt[1]->getCurrentTaskIndex()));
                    if (gt[1]->isCompleted()) {
                        QMessageBox::information(this, "Успешно", "Все задания были успешно выполнены!");
                        return;
                    }
                    ui->title_2->setText(gt[1]->getCurrentTask());
                    int nextTaskType = gt[1]->getCurrentTaskType();
                    QString text = gt[1]->generateRandomString(20);
                    if (nextTaskType == 0) {
                        p_elgamal->clearLineEdits();
                        ui->textEdit_elgamal->clear();
                        ui->textEdit_elgamal_2->clear();
                    } else if (nextTaskType == 1)
                        ui->textEdit_elgamal->setText(text);
                    else
                         ui->textEdit_elgamal->setText(p_elgamal->toString(p_elgamal->encrypt(text.toStdString())));
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
    std::vector<encrypt_data> ret = p_elgamal->encrypt(ui->textEdit_elgamal->toPlainText().toStdString());
    QString s;
    for (auto it: ret) {
        s.append(QString::number(it.a) + ";" + QString::number((it.b)) + ",");
    }
    qDebug() << s;
    ui->textEdit_elgamal_2->setText(s);
}

void MainWindow::slotDecryptElgamal() {
    QStringList sl = ui->textEdit_elgamal->toPlainText().split(",");
    std::vector<encrypt_data> data;

    for (auto it: sl) {
        QStringList _sl = it.split(";");
        if (_sl[0] != "") data.push_back({(uint64_t)_sl[0].toInt(), (uint64_t)_sl[1].toInt()});
    }
    QString s = p_elgamal->decrypt(data);
    ui->textEdit_elgamal_2->setText(s);
}

void MainWindow::slotGenerateTestKeysElgamal() {
    p_elgamal->createTemplateKeys();
}

void MainWindow::slotGenerateTestKeysRSA() {
    rsa->createTemplateKeys();
}

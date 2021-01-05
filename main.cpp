//
// Created by maxim on 05.01.2021.
//

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto *w = new MainWindow();
    w->show();
    return QApplication::exec();
}

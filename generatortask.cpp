#include "generatortask.h"
#include <ctime>
#include <QDebug>

GeneratorTask::GeneratorTask() {
    this->countTask = 20;
    this->currentIndexTask = 0;
}

void GeneratorTask::generateTask() {
    srand(time(0));
    int countZeroState = 1, pushedValue = rand() % 3;

    this->taskArray.push_back(0);
    this->taskArray.push_back(1);
    for (int i = 0; i < this->countTask; i++) {
        while (pushedValue == 0 && countZeroState > 2) pushedValue = rand() % 3;
        if (pushedValue == 0) countZeroState++;
        this->taskArray.push_back(pushedValue);
        pushedValue = rand() % 3;
    }

}

QString GeneratorTask::generateRandomString(int length) {
    srand(time(0));
    QString ret = "";
    for (int i = 0; i < length; i++) ret += (char) (rand() % 93 + 33);
    return ret;
}

void GeneratorTask::printTaskArray() {
    for (auto it: this->taskArray) qDebug() << it;
}

void GeneratorTask::nextTask() {
    this->currentIndexTask++;
}

QString GeneratorTask::getCurrentTask() {
    switch (this->taskArray[this->currentIndexTask]) {
        case 0:
            return QString("Генерация ключей");
        case 1:
            return QString("Шифрование сообщения");
        case 2:
            return QString("Дешифрование сообщения");
    }
}

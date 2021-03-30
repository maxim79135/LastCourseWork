#include "generatortask.h"
#include <ctime>

GeneratorTask::GeneratorTask() {
    this->countTask = 20;
}

void GeneratorTask::generateTask() {
    srand(time(0));

}

QString GeneratorTask::generateRandomString(int length) {
    srand(time(0));
    QString ret = "";
    for (int i = 0; i < length; i++) ret += (char) (rand() % 93 + 33);
    return ret;
}

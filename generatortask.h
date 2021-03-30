#ifndef GENERATORTASK_H
#define GENERATORTASK_H

#include <string>
#include <QString>
#include <vector>

class GeneratorTask
{
public:
    GeneratorTask();

    void generateTask();
    static QString generateRandomString(int);
    void setMaxCount(int count) { this->countTask = count; }

    void printTaskArray();
    void nextTask();
    QString getCurrentTask();
    int getCurrentTaskType() { return this->taskArray[this->currentIndexTask]; }
    bool isCompleted() { return this->currentIndexTask == this->taskArray.size(); }

private:
    int countTask;
    std::vector<int> taskArray;
    int currentIndexTask;
};

#endif // GENERATORTASK_H

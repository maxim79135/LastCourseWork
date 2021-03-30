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

private:
    int countTask;
    std::vector<int> taskArray;
};

#endif // GENERATORTASK_H

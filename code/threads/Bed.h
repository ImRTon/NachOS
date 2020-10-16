#pragma once

#include "utility.h"
#include "callback.h"
#include "timer.h"
#include "thread.h"
#include <vector>

class Bed
{
private:
    /* data */
    int _remainTime;
    Thread* _sleepThread;
public:
    Bed(int sleepTime, Thread* thisThread);
    int getRemainTime();
    int refreshCounter();
    Thread* getThisThread();
    ~Bed();
};

class BedManager
{
private:
    /* data */
    std::vector<Bed> _beds;
public:
    BedManager(/* args */);
    ~BedManager();

    bool refresh();
    void putThreadToSleep(Thread* aThread, int time);
    int getBedsCount();
};

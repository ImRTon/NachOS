#include "Bed.h"
#include "main.h"

Bed::Bed(int sleepTime, Thread* thisThread) {
    _sleepThread = thisThread;
    _remainTime = sleepTime;
}

Bed::~Bed()
{
}

int Bed::getRemainTime() {
    return _remainTime;
}

int Bed::refreshCounter() {
    return --_remainTime;
}

Thread* Bed::getThisThread() {
    return _sleepThread;
}



BedManager::BedManager(/* args */)
{
}

BedManager::~BedManager()
{
}

bool BedManager::refresh() {
    bool isWakeSomebodyUp = 0;
    for (int i = 0; i < _beds.size(); i++) {
        if (_beds[i].refreshCounter() <= 0) { //sleep enough
            cout << "Waking up Thread!\n";
            kernel->scheduler->ReadyToRun(_beds[i].getThisThread());
            _beds.erase(_beds.begin() + i);
            i--; //for loop adjustment.
            isWakeSomebodyUp = 1;
        }
    }
    return isWakeSomebodyUp;
}

void BedManager::putThreadToSleep(Thread* aThread, int time) {
    _beds.push_back(Bed(time, aThread));
    aThread->Sleep(0);
}

int BedManager::getBedsCount() {
    return _beds.size();
}
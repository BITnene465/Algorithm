// 配合gpt完成的代码，半小时解决并且完成debug，效率大大提高 //
#include <iostream>
#include <iomanip>
#include <cstdlib>

struct Runway {
    int freeTime;
    int totalTime;
};

struct Airplane {
    int ID;
    int time;
    Airplane* next;
};

Runway runways[205];
Airplane airplane;
Airplane* landQueueHead = nullptr;
Airplane* landQueueRear = nullptr;
Airplane* offQueueHead = nullptr;
Airplane* offQueueRear = nullptr;

void createLandQueue() {
    Airplane* p = new Airplane;
    p->next = nullptr;
    p->ID = -1;
    p->time = -1;
    landQueueHead = p;
    landQueueRear = p;
}

void addLandQueue(int number, int time) {
    Airplane* p = new Airplane;
    p->next = nullptr;
    p->ID = number;
    p->time = time;
    landQueueRear->next = p;
    landQueueRear = landQueueRear->next;
}

Airplane outLandQueue() {
    Airplane* p = landQueueHead->next;
    landQueueHead->next = p->next;
    if (landQueueHead->next == nullptr)
        landQueueRear = landQueueHead;
    return *p;
}

void createOffQueue() {
    Airplane* p = new Airplane;
    p->next = nullptr;
    p->ID = -1;
    p->time = -1;
    offQueueHead = p;
    offQueueRear = p;
}

void addOffQueue(int number, int time) {
    Airplane* p = new Airplane;
    p->next = nullptr;
    p->ID = number;
    p->time = time;
    offQueueRear->next = p;
    offQueueRear = offQueueRear->next;
}

Airplane outOffQueue() {
    Airplane* p = offQueueHead->next;
    offQueueHead->next = p->next;
    if (offQueueHead->next == nullptr)
        offQueueRear = offQueueHead;
    return *p;
}

bool isEmpty(Airplane* p) {
    return (p->next == nullptr);
}

int main() {
    int totalRunways, landCost, offCost, currentTime = 0, landRequests, offRequests, endFlag = 0,
        landStart = 5001, offStart = 1, i, allRunwaysFree = 1, landWaitTime = 0, offWaitTime = 0,
        totalLandings = 0, totalTakeoffs = 0, totalTime = 0;
    
    std::cin >> totalRunways >> landCost >> offCost;
    
    createLandQueue();
    createOffQueue();
    
    std::cout << "Current Time: " << std::setw(4) << std::setfill(' ') << currentTime++ << std::endl;
    
    while (true) {
        if (!endFlag) {
            std::cin >> landRequests >> offRequests;
            if (landRequests < 0 && offRequests < 0)
                endFlag = 1;
        }
        
        for (i = 0; i < landRequests; i++) {
            addLandQueue(landStart++, currentTime);
            totalLandings++;
        }
        
        for (i = 0; i < offRequests; i++) {
            addOffQueue(offStart++, currentTime);
            totalTakeoffs++;
        }
        
        for (i = 1; i <= totalRunways; i++) {
            if (runways[i].freeTime == 0) {
                if (!isEmpty(landQueueHead)) {
                    airplane = outLandQueue();
                    runways[i].freeTime = landCost;
                    runways[i].totalTime += landCost;
                    std::cout << "airplane " << std::setw(4) << std::setfill('0') << airplane.ID
                              << " is ready to land on runway " << std::setw(2) << std::setfill('0') << i << std::endl;
                    landWaitTime += currentTime - airplane.time;
                } else if (!isEmpty(offQueueHead)) {
                    airplane = outOffQueue();
                    runways[i].freeTime = offCost;
                    runways[i].totalTime += offCost;
                    std::cout << "airplane " << std::setw(4) << std::setfill('0') << airplane.ID
                              << " is ready to takeoff on runway " << std::setw(2) << std::setfill('0') << i << std::endl;
                    offWaitTime += currentTime - airplane.time;
                }
            }
        }
        
        std::cout << "Current Time: " << std::setw(4) << std::setfill(' ') << currentTime << std::endl;
        
        allRunwaysFree = 1;
        for (i = 1; i <= totalRunways; i++) {
            if (runways[i].freeTime) {
                if (!(--runways[i].freeTime))
                    std::cout << "runway " << std::setw(2) << std::setfill('0') << i << " is free" << std::endl;
                else
                    allRunwaysFree = 0;
            }
        }
        
        if (endFlag && isEmpty(landQueueHead) && isEmpty(offQueueHead) && allRunwaysFree)
            break;
        
        currentTime++;
    }
    
    std::cout << "simulation finished" << std::endl
              << "simulation time: " << std::setw(4) << std::setfill(' ') << currentTime << std::endl;
    
    double landAverageWait = static_cast<double>(landWaitTime) / totalLandings;
    double offAverageWait = static_cast<double>(offWaitTime) / totalTakeoffs;
    
    std::cout << "average waiting time of landing: " << std::fixed << std::setw(4) << std::setprecision(1) << landAverageWait << std::endl
              << "average waiting time of takeoff: " << std::fixed << std::setw(4) << std::setprecision(1) << offAverageWait << std::endl;
    
    for (i = 1; i <= totalRunways; i++) {
        std::cout << "runway " << std::setw(2) << std::setfill('0') << i << " busy time: " << std::setw(4) << std::setfill(' ') << runways[i].totalTime << std::endl;
        totalTime += runways[i].totalTime;
    }
    
    double busyTimePercentage = (static_cast<double>(totalTime) / totalRunways) * 100 / currentTime;
    
    std::cout << "runway average busy time percentage: " << std::fixed << std::setprecision(1) << busyTimePercentage << "%" << std::endl;
    
    return 0;
}

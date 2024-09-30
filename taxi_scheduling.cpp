#include <iostream>
#include <queue>
#include <vector>
#include <functional>

class Taxi {
public:
    int number;          // Taxi number
    int priority;    // Priority of taxi

    Taxi(int number, int priority) : number(number), priority(priority) {}

    // Overloading operator to sort based on priorities of taxis
    bool operator<(const Taxi& other) const {
        return priority < other.priority; // Higher priority taxis will book first
    }
};

class TaxiScheduler {
private:
    std::priority_queue<Taxi> taxiQueue; // Priority queue to store taxis

public:
    //Function to add a new taxi in the queue
    void addTaxi(int number, int priority) {
        Taxi newTaxi(number, priority);
        taxiQueue.push(newTaxi);
        std::cout << "Taxi Number: " << number << " Priority: " << priority << std::endl;
    }

    //Function to determine which taxi should be booked first
    void taxiOrder() {
        std::cout << "Priority of Taxis:\n";
        while (!taxiQueue.empty()) {
            Taxi currentTaxi = taxiQueue.top(); 
            taxiQueue.pop(); // Remove it from the queue
            std::cout << "Taxi number: " << currentTaxi.number << " with Priority: " << currentTaxi.priority << std::endl;
        }
    }
};

int main() {
    TaxiScheduler scheduler;

    // Adding taxis with varying priorities
    scheduler.addTaxi(1, 3); // Taxi number: 1, Priority: 3
    scheduler.addTaxi(2, 5); 
    scheduler.addTaxi(3, 1); 
    scheduler.addTaxi(4, 4); 
    scheduler.addTaxi(5, 2); 

    // Taxis order with their priorities
    scheduler.taxiOrder();

    return 0;
}

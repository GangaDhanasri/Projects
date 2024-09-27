#include <iostream>
#include <queue>
#include <vector>
#include <functional>

class Task {
public:
    int id;          // Task ID
    int priority;    // Priority of the task

    Task(int id, int priority) : id(id), priority(priority) {}

    // Overload the operator to sort tasks by priority
    bool operator<(const Task& other) const {
        return priority < other.priority; // Higher priority tasks are executed first
    }
};

class TaskScheduler {
private:
    std::priority_queue<Task> taskQueue; // Priority queue to store tasks

public:
    // Method to add a task
    void addTask(int taskId, int priority) {
        Task newTask(taskId, priority);
        taskQueue.push(newTask);
        std::cout << "Added Task ID: " << taskId << " with Priority: " << priority << std::endl;
    }

    // Method to execute tasks based on their priority
    void executeTasks() {
        std::cout << "Executing Tasks:\n";
        while (!taskQueue.empty()) {
            Task currentTask = taskQueue.top(); // Get the task with the highest priority
            taskQueue.pop(); // Remove it from the queue
            std::cout << "Executed Task ID: " << currentTask.id << " with Priority: " << currentTask.priority << std::endl;
        }
    }
};

int main() {
    TaskScheduler scheduler;

    // Adding tasks with varying priorities
    scheduler.addTask(1, 3); // Task ID: 1, Priority: 3
    scheduler.addTask(2, 5); // Task ID: 2, Priority: 5
    scheduler.addTask(3, 1); // Task ID: 3, Priority: 1
    scheduler.addTask(4, 4); // Task ID: 4, Priority: 4
    scheduler.addTask(5, 2); // Task ID: 5, Priority: 2

    // Execute tasks
    scheduler.executeTasks();

    return 0;
}

#include "taskManager.h"
#include <iostream>
#include <vector>
#include <string>

int main(){
    std::vector<std::string> tasks;

    int choice;
    loadTask(tasks);

    while (true) {
    showMenu();
    std::cout << "choose your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            showTask(tasks);
            break;
        case 2:
            addTask(tasks);
            break;
        case 3:
            removeTask(tasks);
            break;
        case 4:
            saveTask(tasks);
            break;
        case 5:
            return 0;
        default:
            std::cout << "invalid choice\n";            
    }
}
    return 0;
}
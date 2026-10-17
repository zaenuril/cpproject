#include <cstdio>
#include <ios>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include "taskManager.h"

void showMenu(){
        std::cout << "============================\n";
        std::cout << "= welcome to task manager  =\n";
        std::cout << "============================\n";
        std::cout << "=     1. Show Task         =\n";
        std::cout << "=     2. Add Task          =\n";
        std::cout << "=     3. Remove Task       =\n";
        std::cout << "=     4. Save Task         =\n";
        std::cout << "=     5. Exit              =\n";
        std::cout << "============================\n";
    }

void addTask(std::vector<std::string>& tasks){
        std::string taskName;

        std::cout << "enter a task here: ";
        std::getline(std::cin >> std::ws, taskName);

        tasks.push_back(taskName);

        std::cout << "Task added!\n";
    }

void showTask(const std::vector<std::string>& tasks){
        int i = 1;
        std::cout << "\n============================\n";
        std::cout << "Your current task is\n";

        for (const auto& task : tasks) {
            std::cout << i << ". " <<  task << '\n';
            i++;
        }
        std::cout << "============================\n";
}

void removeTask(std::vector<std::string>& tasks){
        if(tasks.empty()){
            std::cout << "\n\nno tasks available. \n";
            std::cout << "please add your task! \n\n\n";
            return;
}

        showTask(tasks);
        int choice;

        std::cout << "Enter task number to remove: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "invalid input!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
        }

        if (choice < 1) {
            std::cout << "\nINVALID NUMBER OF TASK!\n";
            return;
        }

        auto index = static_cast<std::vector<std::string>::size_type>(choice - 1);
        if (index >= tasks.size()) {
            std::cout << "\nINVALID NUMBER OF TASKS!\n";
            return;
        }
        tasks.erase(tasks.begin() + index);
        std::cout << "Task removed! \n\n";
}

void saveTask(std::vector<std::string>& tasks){
    std::ofstream file("header_file/tasks.txt");

    if (!file.is_open()) {
        std::cerr << "gagal menyimpan file!\n";
        return;
    }

    for (const auto& task : tasks) {
        file << task << '\n';
    }

    file.close();
    std::cout << "data berhasil ditulis ke file!\n";
}

void loadTask(std::vector<std::string>& tasks){
    std::ifstream file("header_file/tasks.txt");

    std::string task;

    if (!file.is_open()) {
        std::cerr << "gagal membuka file!\n";
        return;
    }

    while (std::getline(file, task)) {
         tasks.push_back(task);
    }
}

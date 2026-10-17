#pragma once

#include <vector>
#include <iostream>

void showMenu();
void addTask(std::vector<std::string>& tasks);
void showTask(const std::vector<std::string>& tasks);
void removeTask(std::vector<std::string>& tasks);
void saveTask(std::vector<std::string>& tasks);
void loadTask(std::vector<std::string>& tasks);
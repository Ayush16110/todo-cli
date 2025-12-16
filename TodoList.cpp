#include <string>
#include<sstream>
#include <vector>
#include<fstream>
#include "TodoList.hpp"

// Add Task
void TodoList::addTask(std::string title, std::string description) {
    Task newTask(nextId, title, description);
    tasks.push_back(newTask);
    nextId++;
}

// List Task
const std::vector<Task>& TodoList::getTasks() const{
    return tasks;
}

// Delete Task
bool TodoList::deleteTaskById(int id) {
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->ID == id) {
            tasks.erase(it);   
            return true;       
        }
    }
    return false;              
}

// Edit Task
void TodoList::editTaskById(int id, const std::string& title, const std::string& description) {
    for(auto& task : tasks) {
        if(task.ID == id) {
            task.title = title;
            task.description = description;
        }
    }
}

// Mark as done
bool TodoList::markTaskDoneById(int id) {
    for(auto& task : tasks) {
        if(task.ID == id) {
            task.completed = true;
            return true;
        }
    }
    return false;
}

// Save to File
void TodoList::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if(file) {
        for (const Task& task : tasks) {
            file << task.ID << "|" << task.title << "|" << task.description << "|" << task.completed << "\n";
        }
        file.close(); 
    }
}

// Load From File
void TodoList::loadFromFile(const std::string& filename) {

    std::ifstream file(filename);

    if (!file) {
        return;
    }
    tasks.clear();

    std::string line;
    int maxId = 0;

    while(std::getline(file, line)) {
        std::stringstream ss(line);

        std::string idStr, title, description, completedStr;
        std::getline(ss, idStr, '|');
        std::getline(ss, title, '|');
        std::getline(ss, description, '|');
        std::getline(ss, completedStr, '|');

        int id = std::stoi(idStr);
        bool completed = (completedStr == "1");

        Task task(id, title, description);
        task.completed = completed;

        tasks.push_back(task);
        if(id > maxId) {
            maxId = id;
        }

    }

    nextId = maxId + 1;

    file.close();
}

std::vector<Task> TodoList::searchByKeyword(std::string keyword) const {
    std::vector<Task> result;

    for(const auto& task : tasks) {
        if(task.title.find(keyword) != std::string::npos || task.description.find(keyword) != std::string::npos) {
            result.push_back(task);
        }
    }

    return result;
}

std::vector<Task> TodoList::getCompletedTasks() const {
    std::vector<Task> result;

    for(const auto& task : tasks) {
        if(task.completed) {
            result.push_back(task);
        }
    }

    return result;
}

std::vector<Task> TodoList::getPendingTasks() const {
    std::vector<Task> result;

    for(const auto& task : tasks) {
        if(!task.completed) {
            result.push_back(task);
        }
    }

    return result;
}

const Task* TodoList::getTask(int id) const {
    for(const auto& task : tasks) {
        if(task.ID == id) return &task;
    }

    return nullptr;
}
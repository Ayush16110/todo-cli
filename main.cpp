#include <iostream>
#include <string>
#include <vector>
#include "TodoList.hpp"

using namespace std;

void printTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
    } else {
        for (const Task& task : tasks) {
            cout << "ID: " << task.ID << endl;
            cout << "Title: " << task.title << endl;
            cout << "Description: " << task.description << endl;
            cout << "Completed: "
            << (task.completed ? "Yes" : "No") << endl;
            cout << "---------------------------\n";
        }
    }
}

int main() {
    TodoList todolist;
    todolist.loadFromFile("tasks.txt");

    while (true) {
        int input;

        cout << "\n1. Add New Task" << endl;
        cout << "2. List All Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Edit Task" << endl;
        cout << "5. Mark as Done" << endl;
        cout << "6. Search Task by Keyword" << endl;
        cout << "7. Show Completed Tasks" << endl;
        cout << "8. Show Pending Tasks" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";

        cin >> input;

        cin.ignore();

        // Add Tasks
        if (input == 1) {
            string title, description;
            
            do {
                cout << "Enter Title: ";
                getline(cin, title);

                if (title.find_first_not_of(' ') == string::npos) {
                    cout << "Title cannot be empty. Try again.\n";
                }
            } while (title.find_first_not_of(' ') == string::npos);

            
            cout << "Enter Description: ";
            getline(cin, description);
            
            todolist.addTask(title, description);
            
            todolist.saveToFile("tasks.txt");
            
            cout << "Task added successfully!\n";
        }
        
        // List all Tasks
        else if (input == 2) {
            const vector<Task>& tasks = todolist.getTasks();
            printTasks(tasks);
        }
        
        // Delete Task
        else if(input == 3) {
            int taskId;
            cout << "Enter the ID of the task you want to delete: ";
            cin >> taskId;
            cin.ignore();

            if (taskId <= 0) {
                cout << "Invalid ID. Please enter a positive number.\n";
                continue;
            }

            
            if (todolist.deleteTaskById(taskId)) {
                cout << "Task with ID " << taskId << " deleted successfully.\n";
                todolist.saveToFile("tasks.txt");
            } else {
                cout << "Task with ID " << taskId << " not found.\n";
            }
            
        }
        
        // Edit Task
        else if (input == 4) {
            int taskId;
            cout << "Enter the ID of the task you want to edit : ";
            cin >> taskId;
            cin.ignore();

            if (taskId <= 0) {
                cout << "Invalid ID. Please enter a positive number.\n";
                continue;
            }

            const Task* task = todolist.getTask(taskId);
            if(task == nullptr) {
                cout << "Task with ID " << taskId << " not found.\n";
                continue;
            }

            string newTitle, newDescription;
            cout << "Current Title: " << task->title << endl;
            cout << "Current Description: " << task->description << endl;


            cout << "Enter New Title (Press Enter to keep old one)" << endl;
            getline(cin, newTitle);
            if(newTitle.empty()) {
                newTitle = task->title;
            }
            cout << "Enter New Description (Press Enter to keep old one)" << endl;
            getline(cin, newDescription);
            if(newDescription.empty()) {
                newDescription = task->description;
            }
            todolist.editTaskById(taskId, newTitle, newDescription);
            todolist.saveToFile("tasks.txt");
            cout << "Task updated successfully.\n";

        }

        // Mark as done
        else if(input == 5) {
            int taskId;
            cout << "Enter the ID of the task you want to mark as done: ";
            cin >> taskId;
            cin.ignore();
            if (taskId <= 0) {
                cout << "Invalid ID. Please enter a positive number.\n";
                continue;
            }

            if (todolist.markTaskDoneById(taskId)) {
                cout << "Task with ID " << taskId << " marked as done.\n";
                todolist.saveToFile("tasks.txt");
            } else {
                cout << "Task with ID " << taskId << " not found.\n";
            }

        }

        // Search by keyword
        else if(input == 6) {
            string keyword;
            cout << "Enter the Keyword : " << endl;
            getline(cin, keyword);
            if (keyword.find_first_not_of(' ') == string::npos) {
                cout << "Search keyword cannot be empty.\n";
                continue;
            }
            vector<Task> tasks = todolist.searchByKeyword(keyword);
            printTasks(tasks);
        }

        // Filter Completed Tasks
        else if(input == 7) {
            vector<Task> tasks = todolist.getCompletedTasks();
            printTasks(tasks);
        }

        // Filter Completed Tasks
        else if(input == 8) {
            vector<Task> tasks = todolist.getPendingTasks();
            printTasks(tasks);
        }

        // Exits
        else if (input == 0) {
            cout << "Exiting program...\n";
            break;
        }

        // Handles edge cases / invalid inputs
        else {
            cout << "Invalid choice. Try again.\n";
            continue;
        }
    }

    return 0;
}

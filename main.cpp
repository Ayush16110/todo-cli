#include <iostream>
#include <string>
#include "TodoList.hpp"

using namespace std;

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
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";

        cin >> input;

        cin.ignore();

        // Add Tasks
        if (input == 1) {
            string title, description;
            
            cout << "Enter Title: ";
            getline(cin, title);
            
            cout << "Enter Description: ";
            getline(cin, description);
            
            todolist.addTask(title, description);
            
            todolist.saveToFile("tasks.txt");
            
            cout << "Task added successfully!\n";
        }
        
        // List all Tasks
        else if (input == 2) {
            const vector<Task>& tasks = todolist.getTasks();
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
        
        // Delete Task
        else if(input == 3) {
            int taskId;
            cout << "Enter the ID of the task you want to delete: ";
            cin >> taskId;
            cin.ignore();
            
            if (todolist.deleteTaskById(taskId)) {
                cout << "Task with ID " << taskId << " deleted successfully.\n";
            } else {
                cout << "Task with ID " << taskId << " not found.\n";
            }
            
            todolist.saveToFile("tasks.txt");
        }
        
        // Edit Task
        else if (input == 4) {
            int taskId;
            cout << "Enter the ID of the task you want to edit : ";
            cin >> taskId;
            cin.ignore();
            
            string title, description;
            cout << "Enter New Title" << endl;
            getline(cin, title);
            cout << "Enter New Description: ";
            getline(cin, description);

            if(todolist.editTaskById(taskId, title, description)) {
                cout << "Task with ID " << taskId << " updated successfully.\n";
            } else {
                cout << "Task with ID " << taskId << " not found.\n";
            }

            todolist.saveToFile("tasks.txt");
        }

        // Mark as done
        else if(input == 5) {
            int taskId;
            cout << "Enter the ID of the task you want to mark as done: ";
            cin >> taskId;
            cin.ignore();

            if (todolist.markTaskDoneById(taskId)) {
                cout << "Task with ID " << taskId << " marked as done.\n";
            } else {
                cout << "Task with ID " << taskId << " not found.\n";
            }

            todolist.saveToFile("tasks.txt");
        }

        // Exits
        else if (input == 0) {
            cout << "Exiting program...\n";
            break;
        }

        // Handles edge cases / invalid inputs
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

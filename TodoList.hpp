#include<string>
#include<vector>

struct Task {
    int ID;
    std::string title;
    std::string description;
    bool completed = false;

    Task(int ID, std::string title, std::string description) {
        this->ID = ID;
        this->title = title;
        this->description = description;
    }
};

class TodoList {
    private:
        std::vector<Task> tasks;
        int nextId = 1;
    
    public:
        void addTask(std::string title, std::string description); //add task
        const std::vector<Task>& getTasks() const; //list task
        bool deleteTaskById(int id); //delete task
        void editTaskById(int id, const std::string& title, const std::string& description); // edit task
        bool markTaskDoneById(int id); //mark as done
        void saveToFile(const std::string& filename) const; // save to file
        void loadFromFile(const std::string& filename); // load from file
        std::vector<Task> searchByKeyword(std::string keyword) const; // Search feature
        std::vector<Task> getCompletedTasks() const; // Filter completed tasks
        std::vector<Task> getPendingTasks() const; // Filter pending tasks
        const Task* getTask(int id) const; // Fetch single task with ID

};
#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class TodoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() const {
        std::cout << "\nTo-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            if (tasks[i].completed) {
                std::cout << "[C] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << tasks[i].description << std::endl;
        }
        std::cout << std::endl;
    }

    void deleteTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            std::cout << "Task deleted: " << tasks[index - 1].description << std::endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cout << "Invalid task index.\n";
        }
    }

    void markTaskAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed: " << tasks[index - 1].description << std::endl;
        } else {
            std::cout << "Invalid task index.\n";
        }
    }
};

int main() {
    TodoList todoList;

    char choice;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Mark Task as Completed\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                std::cin.ignore(); // Ignore newline from previous input
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            }
            case '2':
                todoList.viewTasks();
                break;
            case '3': {
                size_t deleteIndex;
                std::cout << "Enter the index of the task to delete: ";
                std::cin >> deleteIndex;
                todoList.deleteTask(deleteIndex);
                break;
            }
            case '4': {
                size_t completeIndex;
                std::cout << "Enter the index of the task to mark as completed: ";
                std::cin >> completeIndex;
                todoList.markTaskAsCompleted(completeIndex);
                break;
            }
            case '5':
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '5');

    return 0;
}

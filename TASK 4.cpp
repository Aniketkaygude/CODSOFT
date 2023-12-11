#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Task structure
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function prototypes
void addTask(vector<Task>& taskList, const string& description);
void viewTasks(const vector<Task>& taskList);
void markAsCompleted(vector<Task>& taskList, int taskIndex);
void removeTask(vector<Task>& taskList, int taskIndex);

int main() {
    vector<Task> taskList;
    int choice;

    do {
        cout << "\n===== TO-DO LIST MANAGER =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore(); // Clear the buffer
                getline(cin, description);
                addTask(taskList, description);
                break;
            }
            case 2:
                viewTasks(taskList);
                break;
            case 3: {
                int taskIndex;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> taskIndex;
                markAsCompleted(taskList, taskIndex);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter the index of the task to remove: ";
                cin >> taskIndex;
                removeTask(taskList, taskIndex);
                break;
            }
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }

    } while (choice != 5);

    return 0;
}

void addTask(vector<Task>& taskList, const string& description) {
    Task newTask(description);
    taskList.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "No tasks found." << endl;
    } else {
        cout << "\n===== TASK LIST =====" << endl;
        for (size_t i = 0; i < taskList.size(); ++i) {
            cout << i << ". ";
            if (taskList[i].completed) {
                cout << "[Completed] ";
            }
            cout << taskList[i].description << endl;
        }
    }
}

void markAsCompleted(vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        taskList[taskIndex].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        taskList.erase(taskList.begin() + taskIndex);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

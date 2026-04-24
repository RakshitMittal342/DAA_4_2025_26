#include <bits/stdc++.h>
using namespace std;

struct Task {
    int id;
    string name;
    int priority;

    Task(int i, string n, int p) : id(i), name(n), priority(p) {}
};


struct Compare {
    bool operator()(Task a, Task b) {
        return a.priority < b.priority;
    }
};

class Scheduler {
private:
    priority_queue<Task, vector<Task>, Compare> pq;
    int nextId = 1;

public:
    void addTask(string name, int priority) {
        pq.push(Task(nextId++, name, priority));
        cout << "Task added successfully!\n";
    }

    void executeTask() {
        if (pq.empty()) {
            cout << "No tasks to execute.\n";
            return;
        }

        Task t = pq.top();
        pq.pop();

        cout << "\nExecuting Task:\n";
        cout << "ID: " << t.id << " | Name: " << t.name << " | Priority: " << t.priority << "\n";
    }

    void viewTasks() {
        if (pq.empty()) {
            cout << "No tasks available.\n";
            return;
        }

        auto temp = pq;

        cout << "\nPending Tasks (Highest Priority First):\n";
        while (!temp.empty()) {
            Task t = temp.top();
            temp.pop();
            cout << "ID: " << t.id << " | Name: " << t.name << " | Priority: " << t.priority << "\n";
        }
    }
};

void showMenu() {
    cout << "\n===== PRIORITY TASK SCHEDULER =====\n";
    cout << "1. Add Task\n";
    cout << "2. Execute Highest Priority Task\n";
    cout << "3. View All Tasks\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Scheduler scheduler;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            string name;
            int priority;

            cout << "Enter task name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter priority (higher = more important): ";
            cin >> priority;

            scheduler.addTask(name, priority);
        }
        else if (choice == 2) {
            scheduler.executeTask();
        }
        else if (choice == 3) {
            scheduler.viewTasks();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

string tasks[100];
int count = 0;


void addTask() {
    if (count >=100) {
        cout << "Task list is full!\n";
        return;
    }
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, tasks[count]);
    count++;
    cout << "Task added!\n";
}

void display() {
    if (count == 0) {
        cout << "No tasks to display.\n";
        return;
    }
    cout << "\nYour Tasks:\n";
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask() {
    if (count == 0) {
        cout << "No tasks to delete.\n";
        return;
    }
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "Invalid task number!\n";
        return;
    }

    for (int i = index - 1; i < count - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    count--;
    cout << "Task deleted.\n";
}

void showMenu() {
    cout << "1. Add a Task\n";
    cout << "2. Display Tasks\n";
    cout << "3. Delete a Task\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    cout << "\n TO-DO LIST MENU \n";
    cout<<"=====================\n";
    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                display();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                cout << "Exiting To-Do List\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

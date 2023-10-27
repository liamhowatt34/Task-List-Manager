// To-Do List Orgainizer Main.

#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const int MENU_SIZE = 5;
const int ADD_TASK = 1;
const int DISPLAY_TODO = 2;
const int DISPLAY_COMPLETED = 3;
const int MARK_COMPLETED = 4;
const int EXIT = 5;

int get_int() {
    int user_int = 0;
    string input;

    while (true) {
        getline(cin, input);

        stringstream ss(input);
        if (ss >> user_int) {
            return user_int;
        } else {
            return -1;
        }
    }
}

void displayTaskList(const vector<string> &taskList) {
    for (int i = 0; i < taskList.size(); i++) {
        cout << i + 1 << ". " << taskList[i] << endl;
    }
}

int main() {
    vector<string> to_do_list;
    vector<string> completed_list;
    bool taking_input = true;
    int menu_choice = 0;
    int number_of_tasks = 0;
    int completed_task_i = 0;

    while (taking_input) {
        cout << "1. Enter a new task(s)." << endl;
        cout << "2. Display to do list." << endl;
        cout << "3. Display completed task(s) list." << endl;
        cout << "4. Mark a task as completed." << endl;
        cout << "5. Exit." << endl;
        cout << "Select an option: ";
        menu_choice = get_int();
        cout << endl;

        switch (menu_choice) {
            case ADD_TASK:
                cout << "Enter the number of tasks you want to add: ";
                number_of_tasks = get_int();

                for (int i = 0; i < number_of_tasks; i++) {
                    string task = "";
                    cout << "Enter task #" << i + 1 << ": ";
                    getline(cin, task);
                    to_do_list.push_back(task);
                }
                break;
            case DISPLAY_TODO:
                cout << "To-Do List: " << endl;
                displayTaskList(to_do_list);
                break;
            case DISPLAY_COMPLETED:
                cout << "Completed Tasks List: " << endl;
                displayTaskList(completed_list);
                break;
            case MARK_COMPLETED:
                cout << "To-Do List: " << endl;
                displayTaskList(to_do_list);

                cout << "Enter a task # to mark completed: ";
                completed_task_i = get_int();
                cout << endl;

                if (completed_task_i > 0 &&
                    completed_task_i - 1 < to_do_list.size()) {
                    completed_list.push_back(to_do_list[completed_task_i - 1]);
                    to_do_list.erase(to_do_list.begin() + completed_task_i - 1);
                    break;
                } else {
                    cout << "Error. Enter a valid number." << endl;
                    break;
                }
            case EXIT:
                cout << "Exiting.." << endl;
                taking_input = false;
                break;
            default:
                cout << "Error. Enter a valid number." << endl;
        }
        cout << endl;
    }
    return 0;
}

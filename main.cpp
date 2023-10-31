// Task List Manager Main.

#include <sqlite3.h>

#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// constants
const int MENU_SIZE = 5;
const int ADD_TASK = 1;
const int DISPLAY_TODO = 2;
const int DISPLAY_COMPLETED = 3;
const int MARK_COMPLETED = 4;
const int DELETE_TASK = 5;
const int CLEAR_COMPLETED_LIST = 6;
const int EXIT = 7;

// functions
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

// main func
int main() {
    vector<string> to_do_list;
    vector<string> completed_list;
    bool taking_input = true;
    int menu_choice = 0;
    int number_of_tasks = 0;
    int completed_task_i = 0;
    int deleted_task_i = 0;

    // begin main loop
    while (taking_input) {
        cout << ADD_TASK << ". Enter a new task(s)." << endl;
        cout << DISPLAY_TODO << ". Display task list." << endl;
        cout << DISPLAY_COMPLETED << ". Display completed task(s) list."
             << endl;
        cout << MARK_COMPLETED << ". Mark a task as completed." << endl;
        cout << DELETE_TASK << ". Delete a task." << endl;
        cout << CLEAR_COMPLETED_LIST << ". Clear completed task list." << endl;
        cout << EXIT << ". Exit." << endl;
        cout << "Select an option: ";
        menu_choice = get_int();
        cout << endl;

        switch (menu_choice) {
            case ADD_TASK:
                cout << "Enter the number of tasks you want to add: ";
                number_of_tasks = get_int();

                if (number_of_tasks <= 0) {
                    cout << "Error. Enter a valid number." << endl;
                    break;
                }

                for (int i = 0; i < number_of_tasks; i++) {
                    string task = "";
                    cout << "Enter task #" << i + 1 << ": ";
                    getline(cin, task);
                    to_do_list.push_back(task);
                }
                break;
            case DISPLAY_TODO:
                cout << "Task List: " << endl;
                displayTaskList(to_do_list);
                break;
            case DISPLAY_COMPLETED:
                cout << "Completed Tasks List: " << endl;
                displayTaskList(completed_list);
                break;
            case MARK_COMPLETED:
                cout << "Task List: " << endl;
                displayTaskList(to_do_list);

                if (to_do_list.size() < 1) {
                    cout << "Task List is Empty." << endl;
                    break;
                } else {
                    cout << "Enter a task # to mark completed: ";
                    completed_task_i = get_int();
                    cout << endl;

                    if (completed_task_i > 0 &&
                        completed_task_i - 1 < to_do_list.size()) {
                        completed_list.push_back(
                            to_do_list[completed_task_i - 1]);
                        to_do_list.erase(to_do_list.begin() + completed_task_i -
                                         1);
                        break;
                    } else {
                        cout << "Error. Enter a valid number." << endl;
                        break;
                    }
                }
            case DELETE_TASK:
                cout << "Task List: " << endl;
                displayTaskList(to_do_list);

                if (to_do_list.size() < 1) {
                    cout << "Task List is Empty." << endl;
                    break;
                } else {
                    cout << "Enter a task # to delete from task list: ";
                    deleted_task_i = get_int();
                    cout << endl;

                    if (deleted_task_i > 0 &&
                        deleted_task_i - 1 < to_do_list.size()) {
                        to_do_list.erase(to_do_list.begin() + deleted_task_i -
                                         1);
                        break;
                    } else {
                        cout << "Error. Enter a valid number." << endl;
                        break;
                    }
                }
            case CLEAR_COMPLETED_LIST:
                completed_list.erase(completed_list.begin(),
                                     completed_list.end());
                cout << "Clearing completed list" << endl;
                break;
            case EXIT:
                cout << "Exiting." << endl;
                taking_input = false;
                break;
            default:
                cout << "Error. Enter a valid number." << endl;
        }
        cout << endl;
    }
    return 0;
}

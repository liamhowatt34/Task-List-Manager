// Task List Manager Main.

#include <sqlite3.h>

#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

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
    std::string input;

    while (true) {
        std::getline(std::cin, input);
        std::stringstream ss(input);
        if (ss >> user_int) {
            return user_int;
        } else {
            return -1;
        }
    }
}

void displayTaskList(const std::vector<std::string>& taskList) {
    for (int i = 0; i < taskList.size(); i++) {
        std::cout << i + 1 << ". " << taskList[i] << '\n';
    }
}

// main func
int main() {
    std::vector<std::string> to_do_list;
    std::vector<std::string> completed_list;
    bool taking_input = true;
    int menu_choice = 0;
    int number_of_tasks = 0;
    int completed_task_i = 0;
    int deleted_task_i = 0;

    // opening a database connection to store to.
    // sqlite3* database;
    // int rc = sqlite3_open(
    //     "todo.db",
    //     &database);  // "todo.db" is the name of the SQLite database file.

    // if (rc) {
    //     cerr << "Can't open database: " << sqlite3_errmsg(database) << endl;
    //     return 1;
    // }

    // const char* createTableSQL =
    //     "CREATE TABLE IF NOT EXISTS tasks (id INTEGER PRIMARY KEY, task TEXT,
    //     " "completed INTEGER)";
    // rc = sqlite3_exec(database, createTableSQL, 0, 0, 0);

    // if (rc) {
    //     cerr << "SQL error: " << sqlite3_errmsg(database) << endl;
    // }

    // begin main loop
    while (taking_input) {
        std::cout << ADD_TASK << ". Enter a new task(s)." << '\n';
        std::cout << DISPLAY_TODO << ". Display task list." << '\n';
        std::cout << DISPLAY_COMPLETED << ". Display completed task(s) list."
                  << '\n';
        std::cout << MARK_COMPLETED << ". Mark a task as completed." << '\n';
        std::cout << DELETE_TASK << ". Delete a task from the task list."
                  << '\n';
        std::cout << CLEAR_COMPLETED_LIST << ". Clear completed task list."
                  << '\n';
        std::cout << EXIT << ". Exit." << '\n';
        std::cout << "Select an option: ";
        menu_choice = get_int();
        std::cout << '\n';

        switch (menu_choice) {
            case ADD_TASK:
                std::cout << "Enter the number of tasks you want to add: ";
                number_of_tasks = get_int();

                if (number_of_tasks <= 0) {
                    std::cout << "Error. Enter a valid number." << '\n';
                    break;
                }

                for (int i = 0; i < number_of_tasks; i++) {
                    std::string task = "";
                    std::cout << "Enter task #" << i + 1 << ": ";
                    std::getline(std::cin, task);
                    to_do_list.push_back(task);
                }
                break;
            case DISPLAY_TODO:
                std::cout << "Task List: " << '\n';
                displayTaskList(to_do_list);
                break;
            case DISPLAY_COMPLETED:
                std::cout << "Completed Tasks List: " << '\n';
                displayTaskList(completed_list);
                break;
            case MARK_COMPLETED:
                std::cout << "Task List: " << '\n';
                displayTaskList(to_do_list);

                if (to_do_list.size() < 1) {
                    std::cout << "Task List is Empty." << '\n';
                    break;
                } else {
                    std::cout << "Enter a task # to mark completed: ";
                    completed_task_i = get_int();
                    std::cout << '\n';

                    if (completed_task_i > 0 &&
                        completed_task_i - 1 < to_do_list.size()) {
                        completed_list.push_back(
                            to_do_list[completed_task_i - 1]);
                        to_do_list.erase(to_do_list.begin() + completed_task_i -
                                         1);
                        break;
                    } else {
                        std::cout << "Error. Enter a valid number." << '\n';
                        break;
                    }
                }
            case DELETE_TASK:
                std::cout << "Task List: " << '\n';
                displayTaskList(to_do_list);

                if (to_do_list.size() < 1) {
                    std::cout << "Task List is Empty." << '\n';
                    break;
                } else {
                    std::cout << "Enter a task # to delete from task list: ";
                    deleted_task_i = get_int();
                    std::cout << '\n';

                    if (deleted_task_i > 0 &&
                        deleted_task_i - 1 < to_do_list.size()) {
                        to_do_list.erase(to_do_list.begin() + deleted_task_i -
                                         1);
                        break;
                    } else {
                        std::cout << "Error. Enter a valid number." << '\n';
                        break;
                    }
                }
            case CLEAR_COMPLETED_LIST:
                completed_list.erase(completed_list.begin(),
                                     completed_list.end());
                std::cout << "Clearing completed list." << '\n';
                break;
            case EXIT:
                std::cout << "Exiting." << '\n';
                taking_input = false;
                break;
            default:
                std::cout << "Error. Enter a valid number." << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}
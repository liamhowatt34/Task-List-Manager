// Task List Manager.

#include <sqlite3.h>

#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

// constants
const int MENU_SIZE = 5;
enum MenuChoice {
    ADD_TASK = 1,
    DISPLAY_TODO,
    DISPLAY_COMPLETED,
    MARK_COMPLETED,
    DELETE_TASK,
    CLEAR_COMPLETED_LIST,
    EXIT
};

// functions
void display_menu() {
    std::cout << ADD_TASK << ". Enter a new task(s)." << '\n';
    std::cout << DISPLAY_TODO << ". Display task list." << '\n';
    std::cout << DISPLAY_COMPLETED << ". Display completed task(s) list."
              << '\n';
    std::cout << MARK_COMPLETED << ". Mark a task as completed." << '\n';
    std::cout << DELETE_TASK << ". Delete a task from the task list." << '\n';
    std::cout << CLEAR_COMPLETED_LIST << ". Clear completed task list." << '\n';
    std::cout << EXIT << ". Exit app." << '\n';
    std::cout << "Select an option: ";
}

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

void add_task(std::vector<std::string>& task_list) {
    std::cout << "Enter the number of tasks you want to add: ";
    int number_of_tasks = get_int();

    if (number_of_tasks <= 0) {
        std::cout << "Error. Enter a valid number." << '\n';
    }

    for (int i = 0; i < number_of_tasks; i++) {
        std::string task = "";
        std::cout << "Enter task #" << i + 1 << ": ";
        std::getline(std::cin, task);
        task_list.push_back(task);
    }
}

void display_task_list(const std::vector<std::string>& task_list) {
    for (int i = 0; i < task_list.size(); i++) {
        std::cout << i + 1 << ". " << task_list[i] << '\n';
    }
}

void mark_completed(std::vector<std::string>& to_do_list,
                    std::vector<std::string>& completed_list) {
    std::cout << "Task List: " << '\n';
    display_task_list(to_do_list);

    if (to_do_list.size() < 1) {
        std::cout << "Task List is Empty." << '\n';
    } else {
        std::cout << "Enter a task # to mark completed: ";
        int completed_task_i = get_int();
        std::cout << '\n';

        if (completed_task_i > 0 && completed_task_i - 1 < to_do_list.size()) {
            completed_list.push_back(to_do_list[completed_task_i - 1]);
            to_do_list.erase(to_do_list.begin() + completed_task_i - 1);
        } else {
            std::cout << "Error. Enter a valid number." << '\n';
        }
    }
}

void delete_task(std::vector<std::string>& to_do_list) {
    std::cout << "Task List: " << '\n';
    display_task_list(to_do_list);

    if (to_do_list.size() < 1) {
        std::cout << "Task List is Empty." << '\n';
    } else {
        std::cout << "Enter a task # to delete from task list: ";
        int deleted_task_i = get_int();
        std::cout << '\n';

        if (deleted_task_i > 0 && deleted_task_i - 1 < to_do_list.size()) {
            to_do_list.erase(to_do_list.begin() + deleted_task_i - 1);

        } else {
            std::cout << "Error. Enter a valid number." << '\n';
        }
    }
}

// main function
int main() {
    std::vector<std::string> to_do_list;
    std::vector<std::string> completed_list;
    bool taking_input = true;

    // begin main loop
    while (taking_input) {
        display_menu();
        int menu_choice = get_int();
        std::cout << '\n';

        switch (menu_choice) {
            case ADD_TASK:
                add_task(to_do_list);
                break;
            case DISPLAY_TODO:
                std::cout << "Task List: " << '\n';
                display_task_list(to_do_list);
                break;
            case DISPLAY_COMPLETED:
                std::cout << "Completed Tasks List: " << '\n';
                display_task_list(completed_list);
                break;
            case MARK_COMPLETED:
                mark_completed(to_do_list, completed_list);
                break;
            case DELETE_TASK:
                delete_task(to_do_list);
                break;
            case CLEAR_COMPLETED_LIST:
                completed_list.clear();
                std::cout << "Clearing completed list." << '\n';
                break;
            case EXIT:
                std::cout << "Exiting..." << '\n';
                taking_input = false;
                break;
            default:
                std::cout << "Error. Enter a valid number." << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}
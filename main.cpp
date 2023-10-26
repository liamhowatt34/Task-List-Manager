#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> to_do_list;
    vector<string> completed_list;
    bool taking_input = true;
    int menu_choice = 0;
    int number_of_tasks = 0;
    int completed_task_i = 0;
    int repeat = 0;

    while (taking_input) {
        cout << "1. Enter a new task." << endl;
        cout << "2. Display to do list." << endl;
        cout << "3. Display completed task list." << endl;
        cout << "4. Check-off a task." << endl;
        cout << "5. Exit." << endl;
        cout << "Select an option: ";
        cin >> menu_choice;

        switch (menu_choice) {
            case 1:
                cout << "How many tasks do you want to enter? ";
                cin >> number_of_tasks;

                for (int i = 0; i < number_of_tasks; i++) {
                    string task = "";
                    cout << "Enter task #" << i + 1 << ": ";
                    cin >> task;
                    to_do_list.push_back(task);
                }
                break;
            case 2:
                cout << "To Do List: " << endl;

                for (int i = 0; i < to_do_list.size(); i++) {
                    cout << i + 1 << ". " << to_do_list[i] << endl;
                }
                break;
            case 3:
                cout << "Completed Tasks' List: " << endl;

                for (int i = 0; i < completed_list.size(); i++) {
                    cout << i + 1 << ". " << completed_list[i] << endl;
                }

                break;
            case 4:
                cout << "Enter a task number to complete: ";
                cin >> completed_task_i;

                if (completed_task_i > 0 &&
                    completed_task_i - 1 < to_do_list.size()) {
                    completed_list.push_back(to_do_list[completed_task_i - 1]);
                    to_do_list.erase(to_do_list.begin() + completed_task_i + 1);
                }
                break;
            case 5:
                break;
            default:
                cout << "Invalid option.";
        }
        cout << "Enter 1 to do another operation/ Enter 2 to exit: ";
        cin >> repeat;
        switch (repeat) {
            case 1:
                taking_input = true;
                break;
            case 2:
                taking_input = false;
                break;
        }
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> to_do_list;
    vector<string> completed_list;
    int number_of_tasks = 0;

    cout << "How many tasks do you want to enter? ";
    cin >> number_of_tasks;

    for (int i = 0; i < number_of_tasks; i++) {
        string task = "";
        cout << "Enter task #" << i + 1 << ": ";
        cin >> task;
        to_do_list.push_back(task);
    }

    cout << endl << "To Do List: " << endl;

    for (int i = 0; i < to_do_list.size(); i++) {
        cout << i + 1 << ". " << to_do_list[i] << endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct todolist
{
    int id;
    string task;
};

int ID = 0; 

void banner();
void addTask();
void showTask();
int searchTask();
void deleteTask();
void updateTask();
void terminateTask();

todolist tasks[10];

int main() {
    system("cls");
    while (true) 
    {
        banner();
        cout <<"\n-------------- Todo List --------------"<<endl;
        cout << "\n\t 1. Add Task ";
        cout << "\n\t 2. Show Task ";
        cout << "\n\t 3. Search Task ";
        cout << "\n\t 4. Delete Task ";
        cout << "\n\t 5. Update Task ";
        cout << "\n\t 0. Terminate Task ";

        int choice;
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                addTask();
                break;
            case 2:
                showTask();
                break;
            case 3:
                searchTask();
                break;
            case 4:
                deleteTask();
                break;           
            case 5:
                updateTask();
                break;  
            case 0:
                terminateTask();
                break;       

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    }

    return 0;
}

void banner() {
    cout << "____________________________________________" << endl;
    cout << "\t         My Todo " << endl;
    cout << "____________________________________________" << endl;
}

void addTask() {
    system("cls");
    banner();
    todolist todo;
    cin.ignore(); 
    cout << "Enter new task: ";
    getline(cin, todo.task);

        // if (save == 'y') {
         ID++;
        // ofstream fout("todo.txt", ios::app); // Open file in append mode
        // fout << "\n" << ID;
        // fout << "\n" << todo.task;
        // fout.close();
        todo.id = ID;

        tasks[ID - 1] = todo; 

        char more;
        cout << "Add more tasks? (y/n): ";
        cin >> more;

        if (more == 'y') {
            addTask(); 
        } else {
            system("cls");
            cout << "Task added successfully!" << endl;
            return;
        }
    }
    //system("cls");

void showTask() {
    // Implement function to show tasks from file
    system("cls");
    banner();
    //todolist todo;
    //ifstream fin;
    //fin.open("todo.txt");
    cout << "Tasks: " << endl;

    // while (!fin.eof())
    // {
    //     fin >> todo.id;
    //     fin.ignore();
    //     getline(fin, todo.task);
    //     if(todo.task != "") {
    //         cout << "\t " << todo.id << ": " << todo.task << endl;
    for (int i = 0; i < ID; ++i) {
        cout << "\t " << tasks[i].id << ": " << tasks[i].task << endl;
    }
    //     }
    //     else{
    //         cout << "\tEmpty " << endl;  
    //     }
    // }
    //fin.close();
    char exit;
    cout << "\nExit? (y/n): ";
    cin >> exit;
    if(exit != 'y') {
        system("cls");
        showTask();
    } 
    else {
        system("cls");
    }
}

int searchTask() {
    // Implement function to search tasks from file
    system("cls");
    banner();
    int id;
    cout << " Enter task id: ";
    cin >> id;
    // todolist todo;
    // ifstream fin("todo.txt");
    // while (!fin.eof()) 
    // {
    for (int i = 0; i < ID; ++i) {
        if (tasks[i].id == id) {
            system("cls");
            cout << "Task Found : \n";
            cout << "\t" << tasks[i].id <<": " << tasks[i].task << endl;
            return id;
        }
    }
    //     fin >> todo.id;
    //     fin.ignore();
    //     getline(fin, todo.task);
    //     if(todo.id == id) {
    //         system("cls");
    //         cout << "\t" << todo.id << ": " << todo.task << endl;
    //         return id;
    //     }
    // }
    system("cls");
    cout << "Task not found " << endl;
    return 0;
}

void deleteTask() {
    // Implement function to delete tasks from file
    system("cls");
    int id = searchTask();
    if(id != 0) {
        char del;
        cout << "\n\tDelete this task? (y/n): ";
        cin >> del;
        if(del == 'y') {
            // todolist todo;
            // ofstream tempFile;
            // tempFile.open("temp.txt");
            // ifstream fin;
            // fin.open("todo.txt");

            // int index = 1;
            // while(!fin.eof()) {
            for(int i = 0; i < ID; ++i) {
                if (tasks[i].id == id) {
                    for (int j = i; j< ID - 1; ++j) {
                        tasks[j] = tasks[j + 1];
                    }
                    ID--;
                    break;
                }
            }
            //     fin >> todo.id;
            //     fin.ignore();
            //     getline(fin, todo.task);
            //     if(todo.id != id) {
            //         tempFile << "\n" << index;
            //         tempFile << "\n" << todo.task;
            //         index++;
            //         ID--;
            //     }
            // }
            // fin.close();
            // tempFile.close();
            // remove("todo.txt");
            // rename("temp.txt", "todo.txt");
            system("cls");
            cout << "\n\tTask deleted Successfully!" << endl;
        }
        else {
            system("cls");
            cout <<" Task not deleted" << endl;
        }
    }
}

void updateTask() {
    system("cls");
    int id = searchTask();
    if (id != 0) {
        // todolist todo;
        // ifstream fin("todo.txt");
        // ofstream fout("temp.txt");

        // while (fin >> todo.id && getline(fin >> ws, todo.task)) {
        
        for (int i = 0; i < ID; ++i) {
            if (tasks[i].id == id) {
                cout << "Enter updated task description: ";
                cin.ignore(); // Clear input buffer before getline()
                getline(cin, tasks[i].task);
                system("cls"); // Platform-dependent clear screen command
                cout << "Task updated successfully!" << endl;
                break;
            }
        }
    }
        //     if (todo.id == id) {
        //         cout << "Enter updated task description: ";
        //         cin.ignore(); // Clear input buffer
        //         getline(cin, todo.task);
        //     }
        //     fout << todo.id << "\n" << todo.task << "\n";
        // }
        // fin.close();
        // fout.close();
        // remove("todo.txt");
        // rename("temp.txt", "todo.txt");
        //system("cls");
        //cout << "Task updated successfully!" << endl;
      //  break;
    //}
}

void terminateTask() {
    system("cls");
    banner();
    cout << "Terminating the Todo List Application." << endl;
    exit(0); 
    }
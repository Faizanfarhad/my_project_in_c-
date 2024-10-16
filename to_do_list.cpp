#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>

using namespace std;
struct Node
{
    int num;
    char description[1000];
    Node *next;
};
void clear_terminal(){
#ifdef _WIN32
    system("cls");
#else
system("clear");
#endif
}
class TaskList
{
    vector<TaskList> tasks;
    void create_list();

public:
    struct Node *head;
    TaskList() : head(nullptr) {}
    void display();
    void call_create();
    void delete_task();
    void serach_task();
};
void TaskList ::create_list()
{
    Node *temp;
    int n;
    cout << "how many task do you want to enter : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        temp = new Node();
        cout << "Enetr the task Number :";
        cin >> temp->num;
        cin.ignore();
        cout << "Enter the decription :";
        cin.getline(temp->description, 1000);

        temp->next = head;
        head = temp;
    }
}
void TaskList ::display()
{

    if (head == nullptr)
    {
        cout << "Error! Because you are not putting any data in it!" << endl;
        return;
    }
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << "task Number : " << ptr->num << endl;
        cout << "task discription : " << ptr->description << endl;
        ptr = ptr->next;
    }
}
void TaskList ::call_create()
{
    create_list();
}

void TaskList ::delete_task()
{
    if (head == NULL)
    {
        cout << "Error\n";
        return;
    }

    int n;
    char description[1000];
    cout << "Enter the Number of task : ";
    cin >> n;
    cin.ignore();

    cout << "enter the description for matching : ";
    cin.getline(description, 1000);

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {

        if (n == temp->num && strcmp(description, temp->description) == 0)
        {

            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Delete Successfully!!!" << endl;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Task is Not Founded!!" << endl;
}
void TaskList :: serach_task()
{
    if (head == NULL)
    {
        cout<<"Error"<<endl;
        return;
    }
    
    int n;
    char description[1000];
    cout << "Enter the Number of task : ";
    cin >> n;
    cin.ignore();

    cout << "enter the description for matching : ";
    cin.getline(description, 1000);

    Node *temp;
    temp = head;

    while (temp != NULL)
    {
                if (n == temp->num && strcmp(description, temp->description) == 0)
        {
            cout<<"Task Number is : "<<temp->num<<endl<<"description is : "<<temp->description<<endl;
            temp = temp->next;
        }
    }
    cout<<"Details Are Not Founded !!"<<endl;
}
int main()
{
    TaskList tasklist;
    int n;
        clear_terminal();
    while (1)
    {
        cout << "choose a option" << endl
             << "1. Cerate a Task" << endl
             << "2. Display A Task" << endl
             << "3. Delete A Task" << endl
             << "4. Search Task" << endl
             << "5. Exit" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            tasklist.call_create();
            break;
        case 2:
            tasklist.display();
            break;
        case 3:
            tasklist.delete_task();
            break;
        case 4:
            tasklist.serach_task();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid Choice!!!";
            break;
        }
    }
    return 0;
}
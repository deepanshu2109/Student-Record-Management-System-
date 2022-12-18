

#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
class singlylinkedlist
{
private:
    struct node
    {
        string name, id, roll_no, Gpa, Section;
        node *next;
    };
    node *head = NULL;

public:
    int insertnode(string n, string sec, string roll, string i, string Gpa)
    {
        node *ptr = new node;
        ptr->name = n;
        ptr->Section = sec;
        ptr->roll_no = roll;
        ptr->id = i;
        ptr->Gpa = Gpa;
        ptr->next = NULL;
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
    int display()
    {
        int i = 0;
        if (head == NULL)
        {
            cout << "\n\t\t ****************empty linked list*****************\n\n\n ";
        }
        else
        {
            cout << "\t\t\t * ************************************ \t\t\t "<<endl;
            cout<< "\t\t\t*****All Data of Student****\t\t\t" << endl;
            cout << "\t\t\t*************************************\t\t\t "<<endl<<endl;
            node *temp = head;
            while (temp != NULL)
            {
                cout << "Record of Student : " << i + 1 << endl<< endl;
                cout << "Name ofStudent "<<" :\t "<<temp->name<<endl;
                cout<< "Class of student "<<" :\t "<<temp->Section<<endl;
                cout<< "Roll no of student"<< " : "<< temp->roll_no<< endl;
                cout << "Id of student\t "<<" :\t "<<temp->id<<endl;
                cout<< "Cgpa ofstudent "<<" :\t "<<temp->Gpa<<endl;
                temp = temp->next;
                i++;
            }
        }
    }
    int delete1()
    {
        string a;
        int count = 0;
        if (head == NULL)
        {
            cout << endl
                 << "\t\t****************empty linked list*****************\n\n "<<endl;
        }
        else
        {
            cout << "\t\t\t * ************************************ \t\t\t "<<endl;
            cout<< "\t\t\t*****Delete any record ofstudent ***\t\t\t "<<endl;
            cout<< "\t\t\t*************************************\t\t\t "<<endl<<endl;
            cout<< endl<< "Enter the Roll No of Student : ";
            cin >> a;
            if (a == head->roll_no)
            {
                node *ptr = head;
                head = ptr->next;
                cout << endl<< "\n\n\t\t\tData OF student " << ptr->name << " Is Deleted" << endl;
                delete ptr;
                count++;
            }
            else
            {
                node *prev = head;
                node *ptr = head->next;
                while (ptr != NULL)
                {
                    if (a == ptr->roll_no)
                    {
                        prev->next = ptr->next;
                        cout << endl<< "\n\n\t\t\tData OF student " << ptr->name << " Is Deleted" << endl;
                        count++;
                        delete ptr;
                        break;
                    }
                    prev = ptr;
                    ptr = ptr->next;
                }
            }
            if (count == 0)
            {
                cout << endl<< "\t\t\t______!!! Student recordnot found !!!________ "<<endl;
            }
        }
    }
    int search()
    {
        string a;
        int count = 0;
        int found = 1;
        if (head == NULL)
        {
            cout << endl<< "\t\t****************empty linked list*****************\n\n "<<endl;
        }
        else
        {
            cout << "\t\t\t * ************************************ \t\t\t "<<endl;
            cout<< "\t\t\t*****Search record of Student ***\t\t\t "<<endl;
			cout<<"\t\t\t * ************************************\t\t\t "<<endl<<endl;
            cout<< " Enter Roll No For searching Data Of Student : ";
            cin >>a;
            node *ptr = head;
            while (ptr != NULL)
            {
                if (a == ptr->roll_no)
                {
                    cout << "Name of Student "<<" :\t "<<ptr->name<<endl;
                    cout<< "Class of student "<<" :\t "<<ptr->Section<<endl;
                    cout<< "Roll no of student"<< " :\t "<< ptr->roll_no<< endl;
                    cout << "Id of student\t "<<" :\t "<<ptr->id<<endl;
                    cout<< "Cgpa of student "<<" :\t "<<ptr->Gpa<<endl;
                    count++;
                }
                ptr = ptr->next;
                found++; //found is used here to tell the position of the node
            }
            if (count == 0)
            {
                cout << endl<< "\t\t\t______!!! Student record not found !!!________ "<<endl;
            }
        }
    }
    int update()
    {
        string a;
        string name1, i, roll, Gpa, sec;
        int count = 0;
        int found = 1;
        if (head == NULL)
        {
            cout << endl<< "\t\t****************empty linked list*****************\n\n "<<endl;}
        else
            {
                cout << "\t\t\t * ************************************ \t\t\t "<<endl;
                cout<< "\t\t\t*****Update record of Student ****\t\t\t "<<endl;
                cout<< "\t\t\t*************************************\t\t\t "<<endl<<endl;
                cout<< "enter roll no  for update : ";
                cin >> a;
                node *ptr = head;
                while (ptr != NULL)
                {
                    if (a == ptr->roll_no)
                    {
                        cout << endl<< "value for update is found : " << a << " at node " << found << endl;
                        cout << "\nEnter the name of student : ";
                        cin >> name1;
                        cout << endl<< endl<< "Enter the class : ";
                        cin >> sec;
                        cout << endl << endl << "Enter the Roll no : ";
                        cin >> roll;
                        cout << endl << endl << "Enter the Gpa : ";
                        cin >> Gpa;
                        cout << endl << endl << "Enter the ID : ";
                        cin >> i;
                        ptr->name = name1;
                        ptr->roll_no = roll;
                        ptr->Section = sec;
                        ptr->Gpa = Gpa;
                        ptr->id = i;
                        cout << endl<< "_______||| Record is updated ||| _______ : "<<endl<<endl;
                        count++;
                    }
                    ptr = ptr->next;
                    found++; // for the position of node
                }
                if (count == 0)
                {
                    cout << endl<< "\t\t\t______!!! Student record not found !!!________ "<<endl;
                }
            }
        }
        int sum()
        {
            int a;
            int sum = 0;
            if (head == NULL)
            {
                cout << endl<< "\t\t****************empty linked list*****************"<<endl;
            }
            else
            {
                node *ptr = head;
                while (ptr != NULL)
                {
                    sum = sum + 1;
                    ptr = ptr->next;
                }
                cout << "\t\t\t * ************************************ \t\t\t "<<endl;
                cout<< "\t\t\t*****Total Data of Student ****\t\t\t "<<endl;
                cout<< "\t\t\t*************************************\t\t\t "<<endl<<endl;
                cout<< endl<< "\t\t _____||| Total no.of student records are : "<<sum<<" ||| _____ "<<endl;
            }
        }
    };
    int main()
    {
        singlylinkedlist l;
        string name, sec, roll, Gpa, i;
        int choice, key;
        char c;
        cout << "\t\t\t\t\t\t "<<endl;
        cout<< "\t\t\t****STUDENT MANAGEMENT SYSTEM****\t\t\t "<<endl;
		cout<<"\t\t\t \t\t\t "<<endl<<endl<<endl;
        cout<< "\n\tPress any key to continue..." << endl;
        getch();
        //system("cls");
    loop:
        cout << "\n\n\n\t\tPress '1' To add Record:" << endl;
        cout << "\t\tPress '2' To Display Record:" << endl;
        cout << "\t\tPress '3' To Search Record:" << endl;
        cout << "\t\tPress '4' To Modify Record:" << endl;
        cout << "\t\tPress '5' To Delete Record:" << endl;
        cout << "\t\tPress '6' To count all Record:" << endl;
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            
            cout<< "\t\t\t___________Insert the record of student___________\t\t\t "<<endl;
            cout<<endl<<endl;
            cout << "Enter the name of student : ";
            fflush(stdin);
            getline(cin,name);
            
            
            cout << endl
                 << "Enter the Section : ";
            cin >> sec;
            cout << endl
                 << "Enter the Roll no : ";
            cin >> roll;
            cout << endl
                 << "Enter the Gpa of Student : ";
            cin >> Gpa;
            cout << endl
                 << "Enter the ID : ";
            cin >> i;
            l.insertnode(name, sec, roll, Gpa, i);
            goto loop;
            break;
        case 2:
            l.display();
            goto loop;
            break;
        case 3:
            l.search();
            goto loop;
            break;
        case 4:
            l.update();
            goto loop;
            l.delete1();
            goto loop;
            break;
        case 5:
            l.delete1();
            goto loop;
            break;
        case 6:
            l.sum();
            goto loop;
            break;
        default:
            cout << "\n\nYou enter wrong key... !!!!"<<endl;goto loop;
        }
    }

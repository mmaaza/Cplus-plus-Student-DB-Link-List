//Program: Student Database using LinkedLists
//Programmer: Muhammad Maaz Ahmad
//Date: 25-09-2023
//Compiler: Microsoft Visual Studio Community 2022

#include <iostream>
#include <string>
#define MAX 5
using namespace std;

struct Student {
    int regNo;
    string name;
    int marks[MAX];
};

struct node {
    Student st;
    node* next;
};

void readData(node*& cur, node*& prev, node* &first) {
    char ch1;
    do {
        cur = new node;
        cur->next = NULL;
        cout << "Enter roll no: ";
        cin >> cur->st.regNo;
        cout << endl << "Enter Name: ";
        cin >> cur->st.name;

        for (int i = 0; i <= 4; i++) {
            cout << "Enter the marks of subject " << i + 1 << ": ";
            do {
                cin >> cur->st.marks[i];
                if (cur->st.marks[i] >= 0 && cur->st.marks[i] <= 100)
                    break;
                else {
                    cout << "Enter your marks again: ";
                }
            } while (true);
        }

        if (first == NULL) {
            first = prev = cur;
        }
        else {
            prev->next = cur;
            prev = cur;
        }
        cout << "Do you want to add another record? [y/n]: ";
        cin >> ch1;
        if (ch1 == 'N' || ch1 == 'n')
            break;
    } while (true);
}

void appendData(node* cur, node* prev, node*& first, node*& nnode) {
    cur = first;

    nnode->next = NULL;
    cout << "Enter roll no: ";
    cin >> nnode->st.regNo;
    cout << endl << "Enter Name: ";
    cin >> nnode->st.name;
    for (int i = 0; i <= 4; i++) {
        cout << "Enter the marks of subject " << i + 1 << ": ";
        cin >> nnode->st.marks[i];
    }
    while (cur != NULL) {
        prev = cur;
        cur = cur->next;
    }
    prev->next = nnode;
}

void disData(node* cur, node* prev, node*& first) {
    cur = first;

    cout << "Reg #\tName\t\t\t\tSubject 1\tSubject 2\tSubject 3\tSubject "
        "4\tSubject 5\tTotal Marks\tPercentage"
        << endl;
    while (cur != NULL) {
        int totalSum = 0;
        for (int i = 0; i < 5; i++)
            totalSum += cur->st.marks[i];
        double perc;
        perc = totalSum / 500 * 100;
        cout << cur->st.regNo << "\t\t" << cur->st.name << "\t\t\t\t"
            << cur->st.marks[0] << "\t\t\t" << cur->st.marks[1] << "\t\t\t"
            << cur->st.marks[2] << "\t\t\t" << cur->st.marks[3] << "\t\t\t"
            << cur->st.marks[4] << totalSum << perc << endl;
        cur = cur->next;
    }
}

void searchData(node*& first, node* cur, node* prev) {
    int seregNo;
    bool found = false;

    cout << "Enter the reg number which you want to search: ";
    cin >> seregNo;

    cur = first;

    while (cur != NULL) {
        if (seregNo == cur->st.regNo) {

            cout << "Record found:" << endl;
            cout << "Reg #\tName\t\t\tSubject 1\tSubject 2\tSubject 3\tSubject "
                "4\tSubject 5"
                << endl;
            cout << cur->st.regNo << "\t\t" << cur->st.name << "\t\t\t"
                << cur->st.marks[0] << "\t\t" << cur->st.marks[1] << "\t\t"
                << cur->st.marks[2] << "\t\t" << cur->st.marks[3] << "\t\t"
                << cur->st.marks[4] << endl;
            found = true;
            break;
        }
        cur = cur->next;
    }

    if (!found) {
        cout << "Record not found." << endl;
    }
}

void delRec(node*& first, node* cur, node* prev) {
    int delregNo;
    cout << "Enter the regno which you want to delete : ";
    cin >> delregNo;
    bool found = false;
    cur = prev = first;
    if (delregNo == first->st.regNo) {
        found = true;
        first = first->next;
        prev = first;
        delete cur;
    }
    else {
        cur = first->next;
        while (cur != NULL) {
            if (delregNo == cur->st.regNo) {
                if (cur->next != NULL) {
                    prev->next = cur->next;
                    delete cur;
                }
                else {
                    prev->next = NULL;
                    delete cur;
                }
                found = true;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
    }
    if (!found) {
        cout << "Record not found." << endl;
    }
    else {
        cout << "Record Deleted Successfully!";
    }
}

int main() {
    char ch;

    node* cur = NULL;
    node* prev = NULL;
    node* first = NULL;
    node* nnode = new node;

    do {
        cout << endl
            << "----------------** Menu **----------------" << endl
            << "1. Add Student Data" << endl
            << "2. Append Record" << endl
            << "3. Display Result Card" << endl
            << "4. Search a particular Record" << endl
            << "5. Delete a Record" << endl
            << "6. Exit" << endl
            << "----------------** ---- **----------------" << endl;

        cout << "Enter your choice: ";
        cin >> ch;
        cout << endl;
        switch (ch) {
        case '1':
            readData(cur, prev, first);
            break;
            // Append data
        case '2': {
            if (first != NULL)
                appendData(cur, prev, first, nnode);
            else
                cout << "No data present. First add Data";
        } break;
            // ================== Display Student Data ===================== //
        case '3':
            if (first != NULL)
                disData(cur, prev, first);
            else
                cout << "No data present. First add Data";
            break;
            // =================== Search Any Record ======================
        case '4': 
            if (first != NULL)
                searchData(first, cur, prev);
            else
                cout << "No data present. First add Data";
            break;
            // =============== Delete Record ===============
        case '5': {
            if (first != NULL)
                delRec(first, cur, prev);
            else
                cout << "No data present. First add Data";
        } break;
        case '6':
            exit(-1);
            break;
        default:
            cout << "Invalid Input" << endl;
        }
    } while (true);
    return 0;
}

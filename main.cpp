
//  COMSC-210 | Lab 17: Modularize the Linked List Code | Guo An Wang
//  IDE used: Xcode
//  Created by Guo An Wang on 10/1/25.

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

//function output displays data of linked list
//arguments : pointer to head of linked list
//return : none
void output(Node *);

//function addFront adds data to head of linked list
//arguments : reference to head of linked list
//return : none
void addFront(Node *&);

//function addBack data to tail of linked list
//arguments : reference to head of linked list
//return : none
void addBack(Node *&);

//function deleting deletes chosen node of linked list
//arguments : reference to head of linked list
//return : none
void deleting(Node *&);

//function insert inputs data at selected Node
//arguments : reference to head of linked list
//return : none
void insert(Node *&);

//function deleteAll deallocates data
//arguments : reference to head of linked list
//return : none
void deleteAll(Node *&);


int main() {
    srand(time(0));
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99 (inside addFront function)
    for (int i = 0; i < SIZE; i++) {
        addFront(head);
    }
    //calling output function
    cout << "Original Linked List: " << endl;
    output(head);
    //calling addBack function
    cout << "Add to Back" << endl;
    addBack(head);
    //calling deleting function
    cout << "Calling delete function: " << endl;
    deleting(head);
    //calling insert function
    cout << "Insert Function: " << endl;
    insert(head);
    // calling deleteAll function
    cout << "Calling delete all function" << endl;
    deleteAll(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addFront(Node *&xy){
    int tmp_val = rand() % 100; //create random integer for node
    Node *newVal = new Node; //creating new Struct to dynamically allocate new node
    newVal->value= tmp_val; //new Struct gives value to node
    // adds node at head
    if (!xy) { // if this is the first node, it's the new head
        newVal->next = nullptr;
        xy = newVal;
    }
    else { // its a second or subsequent node; place at the head
        newVal->next = xy;
        xy = newVal;
    }
}
void addBack(Node *&xy){
    int tmp_val = rand() % 100;
    Node *newVal = new Node;//creating new Struct to dynamically allocate new node
    newVal->value= tmp_val; //new Struct gives value to node
    newVal->next = nullptr; //new Node will be the last
    if (!xy) { // if this is the first node, it's the new head
        xy = newVal;
    } else { //otherwise goes to last node
        Node *current = xy;
        while (current->next) { //moving to end of linked list
            current = current->next;
        }
        current->next = newVal; //link new node to end of list
    }
    output(xy);
}

void deleting(Node *&xy){
    cout << "Which node to delete? " << endl;
    output(xy);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    jk = xy;
    Node *prev = xy;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            jk = jk->next;
        else {
            jk = jk->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (jk) {  // checks for current to be valid before deleting the node
        prev->next = jk->next;
        delete jk;
        jk = nullptr;
    }
    output(xy);
}
void insert(Node *&xy){
    jk = xy;
    cout << "After which node to insert 10000? " << endl;
    Node *current = xy;
    int count = 1;
    int entry;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = xy;
    for (int i = 0; i < entry&&current; i++){
        current = current->next;
    }
    if (!current) {
        cout << "Invalid Choice" << endl;
        return;
    }
    
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    current->next = newnode;
    output(xy);
}

void deleteAll(Node *&xy){
    Node *current = xy;
    while (current) {
        Node *next = current->next;
        delete current;
        current = next;
    }
    xy = nullptr;
    output(xy);
}

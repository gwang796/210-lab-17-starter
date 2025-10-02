
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

void output(Node *);
void addFront(Node *&);
void addBack(Node *, Node *);
void deleting(Node *, Node *);
void insert(Node *, Node *);
void deleteAll(Node *, Node *);

int main() {
    srand(time(0));
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        addFront(head);
    }
    output(head);
    Node * current = head;

    //calling deleting function
    deleting(head, current);
    
    //calling insert function
    insert(head,current);

    // calling deleteAll function
    deleteAll(head,current);

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
    int tmp_val = rand() % 100;
    Node *newVal = new Node;
    newVal->value= tmp_val;
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
void addBack(Node *xy, Node *jk){
    
}
void deleting(Node *xy, Node *jk){
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
void insert(Node *xy, Node *jk){
    jk = xy;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    int entry;
    while (jk) {
        cout << "[" << count++ << "] " << jk->value << endl;
        jk = jk->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    jk = xy;
    Node *prev = xy;
    prev = xy;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            jk = jk->next;
        else {
            jk = jk->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = jk;
    prev->next = newnode;
    output(xy);
}

void deleteAll(Node *xy, Node *jk){
    xy = jk;
    while (xy) {
        jk = xy->next;
        delete xy;
        xy = jk;
    }
    jk = nullptr;
    output(jk);
}

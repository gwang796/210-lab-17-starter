
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
void addFront(Node *, Node *);
void addBack(Node *, Node *);
void deleting(Node *, Node *, int);
void insert(Node *, Node *, int, int);
void deleteAll(Node *, Node *);

int main() {
    srand(time(0));
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node
    Node * current = head;
    int entry;

    // insert a node
    /*current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head); */

    //calling deleting function
    deleting(head, current);

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

void addFront(Node * xy){
    
}
void addBack(Node *xy, Node *jk){
    
}
void deleting(Node *xy, Node *jk, int entry){
    cout << "Which node to delete? " << endl;
    output(xy);
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
void insert(Node *xy, Node *jk, int count, int entry){
    jk = xy;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
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

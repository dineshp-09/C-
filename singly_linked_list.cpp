/*
Singly Linked List Implementation 
*/

#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class LinkedList {
    Node *head;
    public:
        LinkedList() {
            head = NULL;
        }
        void addFirst(int);
        void addLast(int);
        void insertPosition(int, int);
        void deletePosition(int);
        void display();
};

void LinkedList::addFirst(int val) {
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        newNode = NULL;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::addLast(int val) {
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    Node * temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::insertPosition(int pos, int val) {
    Node *newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    Node * temp = head;
    Node * prev = NULL;
    int p = 1;
    while(temp->next != NULL && p < pos) {
        prev = temp;
        temp = temp->next;
        p++;
    }
    prev->next = newNode;
    newNode->next = temp;
}

void LinkedList::deletePosition(int pos) {
    Node * temp = head;
    Node * prev = NULL;
    int p = 1;
    while(temp->next != NULL && p < pos) {
        prev = temp;
        temp = temp->next;
        p++;
    }
    prev->next = temp->next;
    delete temp;
    temp = NULL;
}

void LinkedList::display() {
    for(Node *temp = head; temp != NULL; temp = temp->next)
        cout<<temp->data<<"->";
}

int main() {
    LinkedList lst;
    lst.addFirst(30);
    lst.addFirst(20);
    lst.addFirst(10);
    cout<<"Add First:"<<endl;
    lst.display();
    lst.addLast(40);
    cout<<"\nAdd Last:"<<endl;
    lst.display();
    lst.insertPosition(4, 35);
    cout<<"\nInsert at Position 4:"<<endl;
    lst.display();
    lst.deletePosition(4);
    cout<<"\nDelete at Position 4:"<<endl;
    lst.display();
    return 0;
}

/* 
Output:
Add First:
10->20->30->
Add Last:
10->20->30->40->
Insert at Position 4:
10->20->30->35->40->
Delete at Position 4:
10->20->30->40->
*/

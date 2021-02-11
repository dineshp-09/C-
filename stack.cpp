/*
Stack Implementation Program
*/

#include <iostream>

using namespace std;

#define SIZE 10
class Stack {
  int *ptr;
  int top, length;
  public:
    Stack() {}
    Stack(int size) {
      top = -1;
      length = size;
      if (size == 0)
        ptr = NULL;
      else
        ptr = new int[length];
    }

    ~Stack() {
      if (ptr != NULL)
        delete[]ptr;
    }

    void push(int ele) {
      if (ptr == NULL) {
        cout << "\nstack size is zero";
        cout << "\nenter size of stack";
        cin >> length;
        ptr = new int[length];
      }
      if (top == (length - 1)) {
        cout << "\nstack full";
      }
      else {
        top++;
        ptr[top] = ele;
      }
    }

    int pop() {
      if (ptr == NULL || top == -1) {
        cout << "\nstack empty";
        return -1;
      }
      int ele = ptr[top];
      top--;
      return ele;
    }

    int peek() {
      if (ptr == NULL || top == -1) {
        cout << "\nstack empty";
        return -1;
      }
      return ptr[top];
    }

    void display() {
      for (int i = 0; i <= top; i++) {
        cout << ptr[i] << " ";
      }
    }
};

int main() {
  Stack s1(SIZE);
  s1.push(10);
  s1.display();
  cout << endl;
  s1.push(20);
  s1.push(30);
  s1.push(40);
  s1.push(50);
  s1.display();
  cout << endl;
  s1.pop();
  s1.display();
  cout << endl;
  return 0;
}

/* Output: 
10
10 20 30 40 50
10 20 30 40
*/

#include <iostream>
using namespace std;


class twoStacks {
    int *arr;
    int size;
    int top1, top2;
    
    public:
        twoStacks(int n) {
            size = n;
            arr = new int[size];
            top1 = -1;
            top2 = size;
        }
        
        void push1(int x) {
            if (top1 < top2-1) {
                arr[++top1] = x;
            } else {
                std::cout << "stack overflow" << std::endl;
                exit (1);
            }
        }
        
        void push2(int x) {
            if (top1 < top2-1) {
                arr[--top2] = x;
            } else {
                std::cout << "stack overflow" << std::endl;
                exit (1);
            }
        }
        
        int pop1() {
            if (top1 >= 0) {
                int x = arr[top1--];
                return x;
            } else {
                std::cout << "stack underflow" << std::endl;
                exit (1);
            }
        }
        
        int pop2() {
            if (top2 < size) {
                int x = arr[top2++];
                return x;
            } else {
                std::cout << "stack underflow" << std::endl;
            }
            return -1;
        }
        void display() {           
            for (int i=0; i<size; i++) {
                cout<<arr[i]<<" ";
            }
        }
};

int main() {
	twoStacks ts(5);
	ts.push1(5);
	ts.push2(10);
	ts.push2(15);
	ts.push1(11);
	ts.push2(7);
    cout<<"Before"<<endl;
    ts.display();
    cout<<endl;
	cout<<"pop from stack-1: "<<ts.pop1()<<endl;
	ts.push2(40);
    cout<<"After"<<endl;
	cout<<"pop from stack-2: "<<ts.pop2()<<endl;
    ts.display();
	return 0;
}

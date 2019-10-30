/*
Program to find fibonacci series till given number
*/

#include<iostream>

using namespace std;

void Fibonacci(int num)
{
    int a = 0, b = 1, c;
    if(num == 0)
        cout <<"empty";
    while (c < num) {
        c = a + b;
        a = b;
        b = c;
        cout <<c<<" ";
    }
}

int main()
{
    int num = 8;
    Fibonacci(num);
    return 0;
}

// Output: 1 2 3 5 8

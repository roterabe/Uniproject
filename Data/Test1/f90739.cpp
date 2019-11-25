/* C++ program to implement basic stack 
   operations */
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

//Implementation of Stack with template and class
template <typename T>
class Stack
{
    int top;

public:
    int a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }
    bool push(T x);
    void pop();
    T peek();
    bool isEmpty();
};
template <typename T>
bool Stack<T>::push(T x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        //cout << x << " pushed into stack\n";
        return true;
    }
}
template <typename T>
void Stack<T>::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        //return 0;
    }
    else
    {
        int x = a[top--];
        //return x;
    }
}
template <typename T>
T Stack<T>::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}
template <typename T>
bool Stack<T>::isEmpty()
{
    return (top < 0);
}

bool areParanthesisBalanced(string expr)
{
    Stack<char> s;
    char x;

    // insert all opening brackets in expression
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        //remove mathing bracket from top of stack

        switch (expr[i])
        {
        case ')':

            x = s.peek();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            x = s.peek();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':

            x = s.peek();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack
    return (s.isEmpty());
}

//take input and test it

int main()
{
    string expr;
    cin >> expr;

    if (areParanthesisBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
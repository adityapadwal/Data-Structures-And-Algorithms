#include<iostream>
using namespace std;
class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int [size];
        top = -1;
    }

    void push(int element)
    {
        if(top == size-1)
        {
            cout<<"\n Stack Overflow! ";
        }
        else
        {
            top++;
            arr[top] = element;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"\n Stack Underflow! ";
        }
        else
        {
            cout<<"\n Popped Element: "<<arr[top];
             top--;
        }
    }

    void peek()
    {
        if(top >= 0 && top < size)
        {
            cout<<"\n Top element: "<<arr[top];
        }
        else
        {
            cout<<"\n Stack is empty! ";
        }
    }

    void isEmpty()
    {
        if(top == -1)
        {
            cout<<"\n Stack is empty! ";
        }
        else
        {
            cout<<"\n Stack is not empty! ";
        }
    }

};

int main()
{
    int ch;
    int p;
    Stack st(10);

    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);

    st.peek();

    st.pop();

    st.peek();

    st.pop();

    st.peek();

    st.pop();

    st.peek();


return 0;
}

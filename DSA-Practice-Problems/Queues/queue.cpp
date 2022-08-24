#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>q;
    int ch;
    while(true)
    {
        cout<<"\n <====MENU====> ";
        cout<<"\n 1. Push ";
        cout<<"\n 2. Pop";
        cout<<"\n 3. Empty ";
        cout<<"\n 4. Front";
        cout<<"\n 5. Size ";
        cout<<"\n 0. Exit";
        cout<<"\n Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: 
            int n;
            cout<<"\n Enter number: ";
            cin>>n;
            q.push(n);
            break;

            case 2: 
            if(q.empty())
            {
                cout<<"\n Queue is empty! Nothing to pop!! ";
            }
            else
            {
                q.pop();
                cout<<"\n Element popped! ";
                break;
            }

            case 3:
            if(q.empty())
            {
                cout<<"\n The queue is empty";
            }
            else
            {
                cout<<"\n The queue is not empty";
            }
            break;

            case 4:
            cout<<"\n Front element: "<<q.front();
            break;

            case 5: 
            cout<<"\n Size of queue: "<<q.size();
            break;

            case 0: 
            cout<<"Thank you!";
            exit(0);
            break;
        }

    }
return 0;
}
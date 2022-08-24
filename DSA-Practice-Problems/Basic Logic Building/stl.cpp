#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main()
{

cout<<"\n Topic: Arrays";
// Lecture 1: Arrays
array<int, 4> a = {1,2,3,4};
for(int i=0; i<a.size(); i++)
{
    cout<<" "<<a[i];
}
cout<<"\n Using .at() operator";
cout<<"\n The value at index 2 is: "<<a.at(2)<<endl;
cout<<"\n Using .empty() operator" ;
cout<<a.empty();
cout<<"\n Using front operator";
cout<<"\n The first element of the array is: "<<a.front();
cout<<"\n Using back operator";
cout<<"\n The last operator of the array is: "<<a.back();

cout<<endl;
cout<<endl;

cout<<"\n Topic: Vector";
// Lecture 2: Vectors
vector<int>v;
cout<<"\n The capacity of the vector is: "<<v.capacity();
cout<<"\n The size of the vector is: "<<v.size();
v.push_back(6);
v.push_back(7);
v.push_back(8);
v.push_back(9);
v.push_back(10);
cout<<"\n Before pop: ";
for(int i=0; i<v.size(); i++)
{
    cout<<" "<<v[i];
}

v.pop_back();
v.pop_back();
cout<<endl;

cout<<"\n After pop: ";
for(int i=0; i<v.size(); i++)
{
    cout<<" "<<v[i];
}

cout<<endl;
cout<<endl;
// Topic: Dequeue

deque<int>d;
d.push_back(1);
d.push_back(3);
d.push_front(2);
d.push_front(4);
cout<<"\n Printing all the elements of the dequeue: ";
for(int i: d)
{
    cout<<i<<" ";
}

cout<<endl;
cout<<endl;
// Topic: List 
cout<<"\n List"<<endl;
list<int>l;
l.push_back(1);
l.push_front(2);
for( int i: l)
{
    cout<<" "<<i;
}

cout<<endl;
cout<<endl;
// Topic: Stack 
cout<<"\n Stack";
stack<string> s;
s.push("Aditya");
s.push("Padwal");
cout<<"\n Top element is: "<<s.top();
s.pop();
cout<<"\n Now the top-most element is: "<<s.top();
cout<<"\n Size of the stack is: "<<s.size();

cout<<endl;
cout<<endl;
// Topic: Queue
cout<<"\n Topic: Queue";
queue<int>q;
q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);
cout<<"\n Size before pop: "<<q.size();
q.pop();
q.pop();
cout<<"\n First element of the queue is: "<<q.front();
cout<<"\n Size of queue after pop: "<<q.size();


cout<<endl;
cout<<endl;
// Topic: Priority Queue
cout<<"\n Priority Queue";
// max heap
priority_queue<int> maxi;  // default prority queue is max heap
// min heap
priority_queue<int, vector<int>, greater<int> >mini;

maxi.push(1);
maxi.push(3);
maxi.push(2);
maxi.push(0);
cout<<"\n Printing all the elements of the prority queue (max-heap): "<<endl;
int n = maxi.size();
for(int i=0; i<n; i++)
{
    cout<<maxi.top()<<" ";
    maxi.pop();
}
mini.push(1);
mini.push(3);
mini.push(2);
mini.push(0);
cout<<"\n Printing all the elements of the priority queue (min-heap): "<<endl;
int m = mini.size();
for(int i=0; i<m; i++)
{
    cout<<mini.top()<<" ";
    mini.pop();
}

cout<<endl;
cout<<endl;
//Topic: Set
cout<<"\n Topic: Set"<<endl;
set<int> st;
st.insert(5);
st.insert(5);
st.insert(5);
st.insert(6);
st.insert(1);
st.insert(0);
st.insert(0);
st.insert(0);
st.insert(0);
st.insert(0);
st.insert(0);
st.insert(0);
st.insert(0);

cout<<"\n Printing all the elements of the set: "<<endl;
for(auto i : st)
{
    cout<<i<<endl;
}
cout<<endl;
cout<<"\n Using .count() to check if an element is present or not!!!";
cout<<"\n 5 is present or not? : "<<st.count(5);
cout<<"\n 3 is present or not? : "<<st.count(3);

cout<<endl;
cout<<endl;
// Topic: Map
cout<<"\n Topic: Map";
map<int, string> m;
m[1]="Babbar";
m[2]="Love";
m.insert({5, "Bheem"});
m[13]="Aditya";
for(auto q:m)
{
    cout<<q.first()<<endl;
}
return 0;
}
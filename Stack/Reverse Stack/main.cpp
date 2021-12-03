#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void insert_at_bottom (stack<int> &s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    int top = s.top();
    s.pop();
    insert_at_bottom(s,element);
    s.push(top);
}

void reverse_stack(stack<int> &s){
    if(s.empty()){
        return ;
    }
    int ele = s.top();
    s.pop();
    reverse_stack(s);
    insert_at_bottom(s,ele);

}

int main()
{
    stack<int> s1;
    s1.push(10);
    s1.push(11);s1.push(12);s1.push(13);s1.push(14);
    cout<<s1.top()<<endl;
    reverse_stack(s1);
    cout<<s1.top();
    return 0;
}

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    //max heap
    priority_queue <int> maxii;

    //min heap

    priority_queue <int , vector<int>, greater<int>> mini;


    //max heap implementation
    maxii.push(1);
    maxii.push(3);
    maxii.push(8);
    maxii.push(6);
    maxii.push(4);
    while(!maxii.empty()){
        cout<<maxii.top()<<endl;
        maxii.pop();
    }

    //min heap implementation
    mini.push(1);
    mini.push(3);
    mini.push(8);
    mini.push(6);
    mini.push(4);
    while(!mini.empty()){
        cout<<mini.top()<<endl;
        mini.pop();
    }


    return 0;
}

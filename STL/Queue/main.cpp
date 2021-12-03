#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    queue <string> q;
    q.push("Tushar");
    q.push("Arora");
    q.push("is");
    q.push("a");
    q.push("good");
    q.push("boy");

    q.pop();
    cout<<q.front()<<endl;

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}

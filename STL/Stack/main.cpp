#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack <string> s;
    s.push("Tushar");
    s.push("Arora");
    s.push("is");
    s.push("a");
    s.push("good");
    s.push("boy");
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.size()<<endl;
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }


    stack <int> x;
    x.push(1);
    x.push(3);
    x.push(5);
    x.push(7);
    x.push(9);
//    int result = 0;
//    while(!x.empty()){
//        result += x.top();
//        x.pop();
//    }
//    cout<<"Sum of all elements of stack"<<result<<endl;

    stack <int> y(x);
    while(!y.empty()){
        cout<<y.top()<<endl;
        y.pop();
    }

    return 0;
}

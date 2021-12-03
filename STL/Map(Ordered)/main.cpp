#include <iostream>
#include <bits/stdc++.h>
#include<map>

using namespace std;

int main()
{
    map <int,int> m;
    m[1] = 12;
    m[2] = 14;
    m[5] = 16;
    m.insert({3,15});

    for(auto i:m){
        cout<<i.second<<endl;
    }

    cout<<m.count(3);

    m.erase(5);

    cout<<"After Erase"<<endl;

    for(auto i:m){
        cout<<i.second<<endl;
    }


    return 0;
}

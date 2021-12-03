#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    list <int> l;
    l.push_front(23);
    l.push_back(25);
    for(int i:l){
        cout<<i<<endl;
    }
            l.erase(l.begin());

    for(int i:l){
        cout<<i<<endl;
    }
    return 0;
}

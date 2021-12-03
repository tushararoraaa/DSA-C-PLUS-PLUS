#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    set <int> s;


    s.insert(0);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(8);
    s.insert(6);
    s.insert(2);
    s.insert(6);
    s.insert(8);

    for(int i : s){
        cout<<i<<endl;
    }

   s.erase(s.begin());

     for(int i : s){
        cout<<i<<endl;
    }







    return 0;
}

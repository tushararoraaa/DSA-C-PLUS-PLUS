#include <iostream>
#include<deque>

using namespace std;

int main()
{
    deque <int> d;
    d.push_front(1);
    d.push_back(2);
    d.push_front(3);
    for(int i:d){
        cout<<i<<endl;
    }
    d.pop_front();
for(int i:d){
        cout<<i<<endl;
    }
    return 0;
}

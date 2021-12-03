#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    int size;
    cin>>size;
    for(int i = 0; i<size; i++)   //input elements
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i: a)               //output elements
    {
        cout<<i<<endl;
    }

    vector <int> b(5);
    vector <int> c(b);
    for(int i:c)
    {
        cout<<i<<endl;
    }
    vector <int> d(5,12);
    cout<<"Before Pop"<<endl;
    for(int i:d)
    {
        cout<<i<<endl;
    }
    cout<<"After Pop"<<endl;
    d.pop_back();
    for(int i:d)
    {
        cout<<i<<endl;
    }
    cout<<"Size = "<<a.size()<<endl;
    cout<<"Capacity = "<<a.capacity()<<endl;
    cout<<"At index 3 = "<<a.at(3)<<endl;
    cout<<"First Element = "<<a.front()<<endl;
    cout<<"Last element = "<<a.back()<<endl;
    return 0;
}

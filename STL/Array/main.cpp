#include <iostream>
#include<array>

using namespace std;

int main()
{
    array<int, 8> arr = {1,2,3,4,5,6,7,8};
    cout<<arr.at(3)<<endl;
    int size = arr.size();
    for(int i = 0 ; i<size; i++){
        cout<<arr[i]<<endl;
    }
    int front = arr.front();
    cout<<front<<endl;
    int last = arr.back();
    cout<<last<<endl;
    cout<<arr.empty();
    return 0;
}

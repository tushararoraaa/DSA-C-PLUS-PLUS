#include <iostream>

using namespace std;

void bubble(int arr[], int n){
    int counter = 1;
    while(counter<n){
        for(int i = 0; i<n-counter; i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        counter++;
    }
    cout<<"After Sorting"<<endl;
    for(int i =0; i<n; i++){
        cout<<arr[i]<<endl;
    }
}


int main()
{
    int arr[5] = {4,2,34,39,7};
    cout<<"Before sorting"<<endl;
    for(int i =0; i<5; i++){
        cout<<arr[i]<<endl;
    }
    bubble(arr,5);

    return 0;
}

#include <iostream>

using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int left, int right){
    int pivotElement = arr[right];
    int i = left-1;
    for(int j = left; j<right; j++){
        if(arr[j]<pivotElement){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,right);
    return i+1;

}

void QuickSort(int arr[], int left, int right){
    if(left<right){
        int pi = partition(arr,left,right);
        QuickSort(arr,left,pi-1);
        QuickSort(arr,pi+1,right);
    }
}

int main()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    cout<<"Enter elements of array"<<endl;
    int *arr = new int[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    QuickSort(arr,0,n-1);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> removeDuplicates(int *arr , int size){
    vector<int> output;
    unordered_map<int,bool> seen;

    for(int i = 0; i<size; i++){
        if(seen.count(arr[i])>0){
            continue;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int main()
{
    int arr[] = {1,3,2,4,3,3,4,5,6,3,4,5,7};
    vector<int> v = removeDuplicates(arr,13);
    for(int i:v){
        cout<<i<<endl;
    }
    return 0;
}

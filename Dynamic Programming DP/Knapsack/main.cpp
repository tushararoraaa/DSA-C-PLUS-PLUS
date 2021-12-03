#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int Knapsack(int *weight, int *value,int n, int W){
    if(n==0|| W==0){
        return 0;
    }

    if(weight[0]>W){
        return Knapsack(weight+1, value+1, n-1, W);
    }

    int x = Knapsack(weight+1,value+1,n-1,W-weight[0])+value[0];
    int y = Knapsack(weight+1, value+1, n-1, W);
    return max(x,y);
}

int main()
{
    int n,W;
    cin>>n>>W;
    int *weight = new int[n];
    int *value = new int[n];
    for(int i = 0; i<n; i++){
        cin>>weight[i];
    }
    for(int i = 0; i<n; i++){
        cin>>value[i];
    }
    cout<<Knapsack(weight,value,n,W);
    return 0;
}

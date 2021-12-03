#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minCostPath(int **arr, int m, int n , int a , int b){

    if(a==m-1 && b==n-1){
        return arr[a][b];
    }

    if(a>=m || b>=n){
        return INT_MAX;
    }

    int x = minCostPath(arr,m,n,a,b+1);
    int y = minCostPath(arr,m,n,a+1,b+1);
    int z = minCostPath(arr,m,n,a+1,b);

    int ans = min(x,min(y,z))+arr[a][b];
    return ans;


}

int minCostPath(int **arr, int m, int n ){
    return minCostPath(arr,m,n,0,0);
}

int minCostPath_Beetter(int **arr, int m, int n, int a , int b, int **ans){
    if(a==m-1 && b==n-1){
        return arr[a][b];
    }

    if(a>=m || b>=n){
        return INT_MAX;
    }

    if(ans[a][b]!= -1){
        return ans[a][b];
    }

    int x = minCostPath_Beetter(arr,m,n,a+1,b,ans);
    if(x<INT_MAX){
        ans[a+1][b] = x;
    }
    int y = minCostPath_Beetter(arr,m,n,a+1,b+1,ans);
    if(y<INT_MAX){
        ans[a+1][b+1] = y;
    }
    int z = minCostPath_Beetter(arr,m,n,a,b+1,ans);
    if(z<INT_MAX){
         ans[a][b+1] = z;
    }
    ans[a][b] = min(x,min(y,z))+arr[a][b];
    return ans[a][b];
}

int minCostPath_Beetter(int **arr, int m, int n){
    int **ans = new int*[m];
    for(int i = 0; i<m; i++){
        ans[i] = new int[n];
        for(int j = 0; j<n; j++){
            ans[i][j] = -1;
        }
    }
    return minCostPath_Beetter(arr,m,n,0,0,ans);

}

int minCostPath_DP(int **arr, int m, int n){
    int **ans = new int*[m];
    for(int i = 0; i<m; i++){
        ans[i] = new int[n];
    }

    ans[m-1][n-1] = arr[m-1][n-1];

    for(int i = n-2; i>= 0; i--){
        ans[m-1][i] = arr[m-1][i]+ans[m-1][i+1];
    }

    for(int i = m-2;  i>=0; i--){
        ans[i][n-1] = arr[i][n-1]+ans[i+1][n-1];
    }

    for(int i  = m-2; i>=0; i--){
        for(int j = n-2; j>=0; j--){
            ans[i][j] = arr[i][j]+min(ans[i][j+1],min(ans[i+1][j+1],ans[i+1][j]));
        }
    }

    return ans[0][0];

}

int main()
{
    int m , n;
    cin>>m>>n;
    int **arr = new int*[m];
    for(int i = 0; i<m; i++){
        arr[i] = new int[n];
        for(int j = 0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<minCostPath(arr,m,n)<<endl;
    cout<<minCostPath_Beetter(arr,m,n)<<endl;
    cout<<minCostPath_DP(arr,m,n)<<endl;
    return 0;
}

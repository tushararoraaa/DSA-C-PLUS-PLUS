#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int fibo(int n){
    if(n<=1){
        return n;
    }
    int a = fibo(n-1);
    int b = fibo(n-2);

    return a+b;
}

int fibo_better(int *ans, int n){
    if(n<=1){
        ans[n] = n;
        return n;
    }

    if(ans[n-1]==0){
        ans[n-1] = fibo_better(ans,n-1);
    }
    if(ans[n-2]==0){
        ans[n-2] = fibo_better(ans,n-2);
    }
    ans[n] = ans[n-1]+ans[n-2];
    return ans[n];

}

int fibo_better(int n){
    int *ans = new int[n+1];

    for(int i = 0; i<n; i++){
        ans[i] = 0;
    }
    return fibo_better(ans,n);
}

int fibo_DP(int n){
    int *ans = new int[n];
    ans[0] = 0;
    ans[1] = 1;

    for(int i = 2; i<=n; i++){
        ans[i] = ans[i-1]+ans[i-2];
    }
    return ans[n];
}


int main()
{
    cout<<fibo(10)<<endl;
    cout<<fibo_better(10)<<endl;
    cout<<fibo_DP(10);
    return 0;
}

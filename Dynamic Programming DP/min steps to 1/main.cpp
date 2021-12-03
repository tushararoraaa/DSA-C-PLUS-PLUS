#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int min_steps(int n){
    if(n==1){
        return 0;
    }

    int x = min_steps(n-1);
    int y = INT_MAX;
    int z = INT_MAX;
    if(n%2==0){
        y = min_steps(n/2);
    }
    if(n%3==0){
        z = min_steps(n/3);
    }
    return 1+(min(x,min(y,z)));
}

int min_steps_better(int *ans , int n){
    if(n==1){
        ans[n] = 0;
        return 0;
    }

    int y = INT_MAX;
    int z = INT_MAX;
    if(ans[n-1]==-1){
        ans[n-1] = min_steps_better(ans,n-1);
    }
    if(n%2 == 0){
        if(ans[n/2]==-1){
            ans[n/2] = min_steps_better(ans,n/2);
        }
        y = ans[n/2];
    }
    if(n%3 == 0){
        if(ans[n/3]==-1){
            ans[n/3] = min_steps_better(ans,n/3);
        }
        z = ans[n/3];
    }
    ans[n] = 1+min(ans[n-1],min(y,z));
    return ans[n];
}

int min_steps_better(int n){
    int *ans = new int[n+1];
    for(int i =0; i<=n; i++){
        ans[i] = -1;
    }
    return min_steps_better(ans,n);
}

int main()
{
    int n;
    cin>>n;
//    cout<<min_steps(n)<<endl;
    cout<<min_steps_better(n);
    return 0;
}

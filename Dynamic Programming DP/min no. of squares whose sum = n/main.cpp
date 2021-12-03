#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int getMinSquares(int n){
    if(sqrt(n)-floor(sqrt(n))==0){
        return 1;
    }
    if(n<=3){
        return n;
    }
    int result = n;
    for(int i = 1; i<=n; i++){
        int temp = i*i;
        if(temp>n){
            break;
        }else{
            result = min(result, 1+getMinSquares(n-temp));
        }
    }
    return result;
}

int getMinSquares_DP(int n){
    if(n<=3){
        return n;
    }
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;

    for(int i = 4; i<= n; i++ ){
        ans[i] = i;
        for(int j = 1; j<=ceil(sqrt(n)); j++){
            int temp = j*j;
            if(temp>i){
                break;
            }else{
                ans[i] = min(ans[i], 1+ans[i-temp]);
            }
        }
    }
    return ans[n];
}

bool perfectSquare(int n){
    if(sqrt(n)-floor(sqrt(n)) == 0){
        return true;
    }else{
        return false;
    }

}

int getMinSquares_LagrangesTheorem(int n){

    if(perfectSquare(n)){
        return 1;
    }

    for(int i = 0; i<=sqrt(n); i++){
        if(perfectSquare(n-(i*i))){
            return 2;
        }
    }

     while (n % 4 == 0) {
        n >>= 2;
    }
    if (n % 8 == 7) {
        return 4;
    }

    return 3;

}

int main()
{
    cout<<getMinSquares(100)<<endl;
    cout<<getMinSquares_DP(10)<<endl;
    cout<<getMinSquares_LagrangesTheorem(6);
    return 0;
}

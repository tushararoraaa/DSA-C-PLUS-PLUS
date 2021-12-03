#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unsigned int balancedBT(int h){
    if(h<=1){
        return 1;
    }

    unsigned int x = balancedBT(h-1);
    unsigned int y = balancedBT(h-2);

    return x*x + x*y +x*y;
}

unsigned int balancedBT_DP(int h){
    unsigned int *ans = new unsigned int[h+1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 3;

    for(int i = 3; i<=h; i++){
        ans[i] = ans[i-1]*ans[i-1] + 2*(ans[i-1]*ans[i-2]);
    }
    return ans[h];

}



int main()
{
    int h;
    cin>>h;
    cout<<balancedBT(h)<<endl;
    cout<<balancedBT_DP(h)<<endl;
    return 0;
}

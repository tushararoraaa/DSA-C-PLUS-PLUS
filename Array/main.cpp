#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int stock(int prices[], int size){
    int minn = prices[0];
    int index;
    for(int i = 1; i<size; i++){

        if(prices[i]<minn){
            minn=prices[i];
            index = i;
        }
    }
    cout<<index<<endl;
    int answer;
    if(index==size-1){
        answer = 0;
    }else{
        int maxx;
        for(int j = index; j<size; j++){
        if(prices[j]>prices[j+1]){
            maxx = prices[j];
        }
    }
    answer = maxx-minn;
    }
    return answer;

}

int main()
{
    int prices[6] = {7,1,5,3,6,4};
    cout<<stock(prices,6)<<endl;

    return 0;
}



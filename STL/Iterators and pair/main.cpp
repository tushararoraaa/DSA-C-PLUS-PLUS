
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector <pair <int,int>> vp = {{1,2}, {3,4}, {5,6}, {7,8}};
   vector <pair <int,int>> :: iterator it;
    for(it = vp.begin(); it!=vp.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
//    for(auto i: vp){
//        cout<<i.first<<" "<<i.second<<endl;
//    }

    map <int,string> m;
    m[1] = "Tushar";
    m[2] = "Arora";
    m[4] = "good";
    m.insert({3,"is"});
    cout<<"Key"<<" "<<"\t"<<"Element"<<endl;

    for(auto i:m){
        cout<<i.first<<" "<<"\t"<<i.second<<endl;
    }




    return 0;
}

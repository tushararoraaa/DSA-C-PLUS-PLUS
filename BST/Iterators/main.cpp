#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map <string,int> umap;
    umap["abc"] = 0;
    umap["abc1"] = 1;
    umap["abc2"] = 2;
    umap["abc3"] = 3;
    umap["abc4"] = 4;
    umap["abc5"] = 5;
    umap["abc6"] = 6;

    unordered_map<string,int> ::iterator it = umap.begin();
    cout<<"Key"<<'\t'<<"Value"<<endl;
    for(auto i = it; i!= umap.end(); i++){
        cout<<i->first<<'\t'<<i->second<<endl;
    }

    while(it != umap.end()){
        cout<<it->first<<'\t'<<it->second<<endl;
        it++;
    }

    //FIND ELEMENT IN MAP USING ITERATOR
    unordered_map<string,int> ::iterator it2 = umap.find("abc2");
    cout<<it2->second<<endl;


    vector <int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    vector<int>::iterator i;
    i = v.begin();
    while(i!=v.end()){
        cout<<*i<<endl;
        i++;
    }
    cout<<endl;

    //ITERATOR TO REVERSE VECTOR
    vector<int>::iterator itr;
    itr = v.end()-1;
    while(itr!=v.begin()-1){
        cout<<*itr<<endl;
        itr--;
    }

    return 0;
}

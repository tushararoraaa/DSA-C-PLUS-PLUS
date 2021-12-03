#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map <string,int> umap1;

    //INSERTION:-
    umap1.insert({"abc", 1});

    pair<string,int> p1("def",2);
    umap1.insert(p1);
    umap1["ghi"] = 3;

    //ACCESS:-
    cout<<umap1["abc"]<<endl;
    cout<<umap1.at("def")<<endl;
    cout<<umap1["ghi"]<<endl;
    cout<<"Size = "<<umap1.size()<<endl;
    cout<<umap1["jkl"]<<endl;   //THIS WILL ADD JKL = 0 AUTOMATICALLY SO ALWAYS USE AT() OPERATOR INSTEAD OF []
    cout<<"Size = "<<umap1.size()<<endl;

    //SEARCHING

    if(umap1.count("ghi")>0){
        cout<<"GHI is present"<<endl;
    }

    //DELETION USING ERASE() OPERATOR

    umap1.erase("ghi");
    cout<<"Size = "<<umap1.size()<<endl;
    return 0;
}

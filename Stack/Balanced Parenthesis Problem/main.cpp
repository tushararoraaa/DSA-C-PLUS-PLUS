#include <iostream>
#include<bits/stdc++.h>

using namespace std;

bool isBalanced(string s1){
    stack <char> s;
    char x;
    int l = s1.length();
    for(int i = 0; i<l; i++){
        if(s1[i]=='(' || s1[i]=='{' || s1[i]=='['){
            s.push(s1[i]);
            continue;
        }

         if (s.empty()){
            return false;
         }


        switch(s1[i]){
        case ')':
            x = s.top();
            s.pop();
            if(x == '{'|| x == '[')
                return false;
            break;
        case ']':
            x = s.top();
            s.pop();
            if(x == '('|| x == '{')
                return false;
            break;

        case '}':
            x = s.top();
            s.pop();
            if(x == '('|| x == '[')
                return false;
            break;


        }
    }

}

int main()
{

    string s1;
    cin>>s1;
    if(isBalanced(s1)){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"Not balanced"<<endl;
    }
    return 0;
}

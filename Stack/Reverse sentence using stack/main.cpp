#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void reverse_str(string s){
    stack <string> st;
    for(int i = 0; i<s.length(); i++){
        string word="";
        while(s[i]!= ' ' && i<s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main()
{
    string s = "Hey, how are you?";
    reverse_str(s);
    return 0;
}

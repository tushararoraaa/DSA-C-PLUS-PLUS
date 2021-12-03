#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int LCS(string s1, string s2)
{
    if(s1.size()<=0 || s2.size()<=0)
    {
        return 0;
    }

    if(s1[0]==s2[0])
    {
        return 1+LCS(s1.substr(1),s2.substr(1));
    }
    else
    {
        int a = LCS(s1.substr(1),s2);
        int b = LCS(s1,s2.substr(1));
        int c = LCS(s1.substr(1),s2.substr(1));

        return max(a,max(b,c));
    }


}

int LCS_Better(string s1, string s2, int **ans)
{

    if(s1.size() ==0 || s2.size()==0)
    {
        return 0;
    }

    int m = s1.size();
    int n = s2.size();

    if(ans[m][n]!=-1)
    {
        return ans[m][n];
    }

    if(s1[0]==s2[0])
    {
        ans[m-1][n-1] = LCS_Better(s1.substr(1),s2.substr(1),ans);
        ans[m][n] = 1+ans[m-1][n-1];
    }
    else
    {
        ans[m-1][n] = LCS_Better(s1.substr(1),s2,ans);
        ans[m][n-1] = LCS_Better(s1,s2.substr(1),ans);
        ans[m][n] = max(ans[m-1][n],ans[m][n-1]);

    }
return ans[m][n];
}

int LCS_Better(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    int **ans = new int*[m];
    for(int i = 0; i<=m; i++)
    {
        ans[i] = new int[n];
        for(int j = 0; j<=n; j++)
        {
            ans[i][j] = -1;
        }
    }
    return LCS_Better(s1,s2,ans);
}

int LCS_DP(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    int **ans = new int*[m];
    for(int i = 0; i<=m; i++)
    {
        ans[i] = new int[n];
        for(int j = 0; j<=n; j++)
        {
            ans[i][j] = -1;
        }
    }

    //FIRST ROW
    for(int j = 0; j<=n; j++){
        ans[0][j] = 0;
    }

    //FIRST COLUMN
    for(int i = 0; i<=m; i++){
        ans[i][0] = 0;
    }

    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(s1[m-i]==s2[n-j]){
                ans[i][j] = 1+ans[i-1][j-1];
            }else{
                ans[i][j] = max(ans[i][j-1],ans[i-1][j]);
            }
        }
    }
    return ans[m][n];
}


int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<LCS(s1,s2)<<endl;
    cout<<LCS_Better(s1,s2)<<endl;
    cout<<LCS_DP(s1,s2)<<endl;
    return 0;

}

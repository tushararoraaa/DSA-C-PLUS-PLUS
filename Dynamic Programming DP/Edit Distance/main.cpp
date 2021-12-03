#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int editDistance(string s1, string s2)
{
    if(s1.size()==0 || s2.size()==0)
    {
        return max(s1.size(),s2.size());
    }
    if(s1[0]==s2[0])
    {
        return 1+editDistance(s1.substr(1),s2.substr(1));
    }
    else
    {
        int p = editDistance(s1.substr(1),s2)+1;
        int q = editDistance(s1,s2.substr(1))+1;
        int r = editDistance(s1.substr(1),s2.substr(1));

        return min(p,min(q,r));
    }

}

int editDistance_Better(string s1, string s2, int **ans)
{
    if(s1.size()==0 || s2.size()==0)
    {
        return max(s1.size(),s2.size());
    }
    int m = s1.size();
    int n = s2.size();
    if(ans[m][n]!=-1)
    {
        return ans[m][n];
    }

    if(s1[0]==s2[0])
    {
        ans[m][n] = editDistance_Better(s1.substr(1),s2.substr(1),ans);

    }
    else
    {
        ans[m-1][n] = editDistance_Better(s1.substr(1),s2,ans);
        ans[m][n-1] = editDistance_Better(s1,s2.substr(1),ans);
        ans[m-1][n-1] = editDistance_Better(s1.substr(1),s2.substr(1),ans);
        ans[m][n] = 1+min(ans[m-1][n],min(ans[m][n-1],ans[m-1][n-1]));
    }

    return ans[m][n];


}

int editDistance_Better(string s1,string s2)
{
    int m = s1.size();
    int n = s2.size();
    int **ans = new int*[m+1];
    for(int i=0; i<=m; i++)
    {
        ans[i] = new int[n+1];
        for(int j = 0; j<=n; j++)
        {
            ans[i][j] = -1;
        }
    }
    return editDistance_Better(s1,s2,ans);
}

int editDistance_DP(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    int **ans = new int*[m+1];
    for(int i=0; i<=m; i++)
    {
        ans[i] = new int[n+1];
    }

    for(int j = 0; j<=n; j++)
    {
        ans[0][j]=j;
    }

    for(int i = 0; i<=m; i++)
    {
        ans[i][0] = i;
    }

    for(int i = 1; i<=m; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(s1[m-i]==s2[n-j])
            {
                ans[i][j] = ans[i-1][j-1];
            }
            else
            {
                ans[i][j] = 1+min(ans[i-1][j],min(ans[i][j-1],ans[i-1][j-1]));
            }
        }
    }
    return ans[m][n];
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<editDistance(s1,s2)<<endl;
    cout<<editDistance_Better(s1,s2)<<endl;
    cout<<editDistance_DP(s1,s2)<<endl;
    return 0;
}

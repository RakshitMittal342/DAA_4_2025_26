#include <bits/stdc++.h>
using namespace std;
int fn(string s1,string s2,vector<vector<int>> &dp,int i,int j, int m, int n){
    if(i==m || j==n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]) return 1 + fn(s1,s2,dp,i+1,j+1,m,n);
    else{
        return dp[i][j]=max(fn(s1,s2,dp,i+1,j,m,n),fn(s1,s2,dp,i,j+1,m,n));
    }
}
int main(){
    string s1="abcde";
    string s2="abefgcd";
    int m=s1.size();
    int n=s2.size();
    vector<vector<int>> dp(m,vector<int>(n,-1));
    cout << fn(s1,s2,dp,0,0,m,n);
}
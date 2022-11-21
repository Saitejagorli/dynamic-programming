/*finding the length of the lrs(variation of lcs)*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s1,s2;
    int n,i,j;
    cout<<"Enter the string length:";
    cin>>n;
    cout<<"Enter the string:";
    cin>>s1;
    s2=s1;
    int dp[n+1][n+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s1[i-1]==s2[j-1] && i!=j)
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<"Longest repeating sequence is of length "<<dp[n][n];
    ex : aass
         \ \
        a a s s
}
/*finding the longest repeating subsequence*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string s1,s2;
    int n,i,j;
    cout<<"Enter the string length:";
    cin>>n;
    cout<<"Enter the string:";
    cin>>s1;
    s2=s1;
    string dp[n+1][n+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[i][j] =" "; //we are filling the empty string
            else if(s1[i-1]==s2[j-1] && i!=j)
                dp[i][j]=dp[i-1][j-1]+s1[i-1]; //here we are concatenating the present char to previous lrs
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]); //here we are finding the max by including and excluding
        }
    }
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Longest repeating sequence is of  "<<dp[n][n];
}
/*time and space complexity is o(n^2)*/
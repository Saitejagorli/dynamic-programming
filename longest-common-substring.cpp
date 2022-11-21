#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<limits.h>
using namespace std;
int main(){
    string s1,s2;
    int n1,n2,i,j,maxi=INT_MIN;
    cout<<"Enter the string1 length:";
    cin>>n1;
    cout<<"Enter the string2 length:";
    cin>>n2;
    cout<<"Enter the string 1: ";
    cin>>s1;
    cout<<"Enter the string2:";
    cin>>s2;
   
    int dp[n1+1][n2+1];
    for(i=0;i<=n1;i++){
        for(j=0;j<=n2;j++){
            if(i==0 || j==0)
                dp[i][j]=0; 
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1]; 
            else
                dp[i][j]=0;
        }
    }
    for(i=0;i<=n1;i++){
        for(j=0;j<=n2;j++){
            if(dp[i][j]>maxi)
               maxi=dp[i][j];
        }
        
    }
   cout<<maxi<<endl;
}
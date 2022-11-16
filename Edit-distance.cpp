/* You are given two strings and you have to make the strings equal by doing some operations like 1)insertion 2)deletion 3)replace*/
//back tracking approach
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int count(string s1,string s2, int m, int n){
    if(m==0)
      return n; //base case that if length of one str1 is zero we need
    if(n==0)    //to make another length of str2 insertions to make the 
      return n; //strings equal
    if(s1[m-1]==s2[n-1])
      return count(s1,s2,m-1,n-1); //if the chars are equal we need not
                                   //to do any operations
    else
      return 1+min({count(s1,s2,m,n-1),count(s1,s2,m-1,n),count(s1,s2,m-1,n-1)}); //here we can make three operations like insertion,
                  //deletion,replace so we are finding the minimum of these operations
}
int main(){
    int m,n;
    string s1,s2;
    cout<<"Enter the length of the two str1 and str2 respectively:";
    cin>>m>>n;
    cout<<"Enter the string1:";
    cin>>s1;
    cout<<"Enter the string2:";
    cin>>s2;
    cout<<"Minimum no of operations are "<<count(s1,s2,m,n);
    return 0;
}
/*time complexity is O(3^m+O(3^n)) and space complexity is O(n)*/
/*dynamic programming tabulation approach*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int m,n,i,j;
    string s1,s2;
    cout<<"Enter the length of the two str1 and str2 respectively:";
    cin>>m>>n;
    cout<<"Enter the string1:";
    cin>>s1;
    cout<<"Enter the string2:";
    cin>>s2;
    int dp[m+1][n+1];
    for(i=0;i<=m;i++)
        dp[i][0]=i;
    for(j=0;j<=n;j++)
       dp[0][j]=j;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1])
              dp[i][j]=dp[i-1][j-1]; //no operation required 
            else
              dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]}); 
              //finding the minimum operation of insertion deletion and replace
        }
    }
    cout<<"Minimum no of operations are "<<dp[m][n];
    return 0;
}
/*time and space complexity is O(m*n)*/
/* tabulation space optimization to O(n)*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int m,n,i,j;
    string s1,s2;
    cout<<"Enter the length of the two str1 and str2 respectively:";
    cin>>m>>n;
    cout<<"Enter the string1:";
    cin>>s1;
    cout<<"Enter the string2:";
    cin>>s2;
    int dp[2][n+1];
    for(j=0;j<=n;j++)
       dp[0][j]=j;
    for(i=1;i<=m;i++){
        for(j=0;j<=n;j++){
            if(j==0)
             dp[i%2][j]=i;
            else if(s1[i-1]==s2[j-1])
              dp[i%2][j]=dp[(i-1)%2][j-1]; //no operation required 
            else
              dp[i%2][j]=1+min({dp[i%2][j-1],dp[(i-1)%2][j],dp[(i-1)%2][j-1]}); 
              //finding the minimum operation of insertion deletion and replace
        }
    }
    cout<<"Minimum no of operations are "<<dp[m%2][n];
    return 0;
}
/*time complexity is O(m*n) and  space complexity is O(n)*/
/*brutforce recursion*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int sub(string s1, string s2,int m,int n){
    if(m==0 || n==0) //base case if there are no strings return 0
      return 0;
    if(s1[m-1]==s2[n-1])
      return 1+sub(s1,s2,m-1,n-1); //if both the characters are equal we have 1 subsequence length 
    return max(sub(s1,s2,m-1,n),sub(s1,s2,m,n-1));//if they are not equal we are calling by including and excluding
}
int main(){
    string s1,s2;
    int m,n;
    cout<<"Enter the length of the strings:";
    cin>>m>>n;
    cout<<"Enter the string1 :";
    cin>>s1;
    cout<<"Enter the string2 :";
    cin>>s2;
    cout<<"longest common subsequence is "<<sub(s1,s2,m,n);

}
/* time complexity is O(2^(n+m)) and space complexity is O(n) recursive stack space */
/* dynamic programming tabulation approach*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string s1,s2;
    int m,n,i,j;
    cout<<"Enter the length of the strings:";
    cin>>m>>n;
    cout<<"Enter the string1 :";
    cin>>s1;
    cout<<"Enter the string2 :";
    cin>>s2;
    int dp[m+1][n+1];
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0)
              dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
              dp[i][j]=1+dp[i-1][j-1]; //if equal we increase lenth 1 to previous obtained small problem
            else
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//we considering max of it's previous probelms by including and excluding
        }
    }
    cout<<"Longest common subsequence length is "<<dp[m][n];
 return 0;
}
/*time complexity and space complexity is O(n*w)*/

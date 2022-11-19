/*recursive approach */
#include<iostream>
using namespace std;
int  unique_paths(int m,int n){
    if(m==1 || n==1)
        return 1;
    else
        return unique_paths(m-1,n)+unique_paths(m,n-1);
        //here we are going either top or left as it is top down approach
}
int main(){
    int m,n;
    cout<<"Enter the dimensions of the grid:";
    cin>>m>>n;
    cout<<"The unique paths from the (0,0) to (m-1,n-1) is "<<unique_paths( m, n);
    return 0;
}
/*time complexity is O(2^n) and space complexity is O(n)*/
/*--------------------------------------------------------------------*/
/*dynamic programming memoization*/
// #include<iostream>
// #include<vector>
// using namespace std;
// int  unique_paths(int m,int n,vector<vector<int>>&dp){
//     if(m==1 || n==1)
//         return 1;
//     if(dp[m][n]!=-1)
//         return dp[m][n];
//     else
//         return dp[m][n]=unique_paths(m-1,n,dp)+unique_paths(m,n-1,dp);
//         //here we are going either top or left as it is top down approach
// }
// int main(){
//     int m,n;
//     cout<<"Enter the dimensions of the grid:";
//     cin>>m>>n;
//     vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
//     cout<<"The unique paths from the (0,0) to (m-1,n-1) is "<<unique_paths( m, n,dp);
//     return 0;
// }
/*time and space complexity is O(m*n)*/
/*---------------------------------------------------------------*/
/*dynamic programming tabulation method*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n,i,j;
    cout<<"Enter the dimensions of the grid:";
    cin>>m>>n;
    int dp[m][n];
    for(i=0;i<m;i++)
        dp[i][0]=1;
    for(j=0;j<n;j++)
        dp[0][j]=1;
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<"The unique paths from the (0,0) to (m-1,n-1) is "<<dp[m-1][n-1];
    return 0;
}
/*time and space complexity is O(m*n)*/
/*-----------------------------------------------------------------------------*/
/*tabulation with optimized space*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n,i,j;
    cout<<"Enter the dimensions of the grid:";
    cin>>m>>n;
    int dp[n]={1};
    for(i=0;i<m;i++){
        for(j=1;j<n;j++){
             dp[j]+=dp[j-1];
        }
    }
    cout<<"The unique paths from the (0,0) to (m-1,n-1) is "<<dp[n-1];
    return 0;
}
/*time complexity is O(m*n) and space complexity is O(n)*/
/*------------------------------------------------------------------------------------*/

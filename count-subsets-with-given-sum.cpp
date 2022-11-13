/* backtracking */
#include<iostream>
#include<vector>
using namespace std;
int subset_sum(vector<int>&v,int n,int sum){
    if(sum==0)
      return 1;
    if(n==0)
      return 0;
    if(v[n-1]>sum)
       return subset_sum(v,n-1,sum);
    else
      return subset_sum(v,n-1,sum)+subset_sum(v,n-1,sum-v[n-1]);
}
int main(){
    int n,sum;
    cout<<"Enter the no of array elements:";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the elments:";
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<"Enter the sum:";
    cin>>sum;
    cout<<" The no of subsets with given sum is "<<subset_sum(v,n,sum);

}
/* time complexity is O(2^n) and space complexity is O(n) (recursive stack space) */
/*---------------------------------------------------------------------------------*/
/* dynamic programming tabulation method */
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,sum,i,j;
    cout<<"Enter the no of array elements:";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the elments:";
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<"Enter the sum:";
    cin>>sum;
    int dp[n+1][sum+1];
    for(i=0;i<=n;i++)
        dp[i][0]=1;
    for(j=1;j<=sum;j++)
        dp[0][j]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=sum;j++){
            if(v[i-1]>j)
               dp[i][j]=dp[i-1][j];
            else 
               dp[i][j]=dp[i-1][j]+dp[i-1][j-v[i-1]];

        }
    }
    cout<<"The no of subsets possible with given sum is "<<dp[n][sum];


  return 0;
}
/* space complexity is O(n*sum) and time complexity is O(n*sum) */
/*------------------------------------------------------------------------*/
/* dynamic programming memoization method */
#include<iostream>
#include<vector>
using namespace std;
int subset_sum(vector<int>&v,int n,int sum,vector<vector<int>>&dp){
    if(sum==0)
      return 1;
    if(n==0)
      return 0;
    if(dp[n][sum]!=-1)
       return dp[n][sum];
    if(v[n-1]>sum)
       return dp[n][sum]=subset_sum(v,n-1,sum,dp);
    else
      return dp[n][sum]=subset_sum(v,n-1,sum,dp)+subset_sum(v,n-1,sum-v[n-1],dp);
}
int main(){
    int n,sum;
    cout<<"Enter the no of array elements:";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the elments:";
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<"Enter the sum:";
    cin>>sum;
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    cout<<" The no of subsets with given sum is "<<subset_sum(v,n,sum,dp);

}
/* time complexity is O(2^n ) and space complexity is O(n*sum) */



// base recursion case of knapsack
#include<iostream>
#include<algorithm>
using namespace std;
int knapsack(int weight[],int profit[],int w,int n){
    if(n==0 || w==0)
       return 0;
    if(weight[n-1]>w)
       return knapsack(weight,profit,w,n-1);
    else  
      return max(knapsack(weight,profit,w,n-1),profit[n-1]+knapsack(weight,profit,w-weight[n-1],n-1));
}
int main(){
    int weight[5]={1,2,3,4,5};
    int profit[5]={10,30,22,11,4};
    int w=5;
    cout<<knapsack(weight,profit,w,5);
    return 0;
}
// time complexity=O(2^n)
//space complexity=O(n) auxillary stack space +O(1) for storing values
/*memoization method (top-down approach)*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int knapsack(int weight[],int profit[],int w,int n,int dp[][6]){
    if(n==0 || w==0)
       return 0;
    if(dp[n-1][w]!=-1)
       return dp[n-1][w];
    if(weight[n-1]>w)
       return dp[n-1][w]= knapsack(weight,profit,w,n-1,dp);
    else  
      return dp[n-1][w]=max(knapsack(weight,profit,w,n-1,dp),profit[n-1]+knapsack(weight,profit,w-weight[n-1],n-1,dp));
}
int main(){
    int weight[5]={1,2,3,4,5};
    int profit[5]={10,30,22,11,4};
    int w=5;
    int dp[6][6];
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(weight,profit,w,5,dp);
    return 0;
}
//time complexity is same as brut force recursion tc=O(2^n)
//space complexity is O(n) auxillary recursive stack space + O(n*w) for table
/* tabulation method (bottom up approach)*/
#include<iostream>
using namespace std;
int main(){
      int weight[5]={1,2,3,4,5};
      int profit[5]={10,30,22,11,4};
      int w=5,n=5,i,j;
      int dp[6][6];
      for( i=0;i<=n;i++){
        for(j=0;j<=w;j++){
            if(i==0 || j==0)
               dp[i][j]=0;     //base case
            else if(weight[i-1]>j)
                 dp[i][j]=dp[i-1][j]; //skip case so we are taking the previous profit by skipping it
            else
              dp[i][j]=max(dp[i-1][j],profit[i-1]+dp[i-1][j-weight[i-1]]);
              //here we are finding the maximum profit of by  excluding it and including the item 
    
        }
      }
        cout<<dp[5][5]<<endl;
        return 0;
}
//here the time complexity is tc=O(n*w)
// space complexity is 0(n*w) by declaring  variables only




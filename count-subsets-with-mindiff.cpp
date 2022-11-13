/* dynamic programming tabulation approach */
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,i,j,diff,sum=0;
    cout<<"Enter the no of elements:";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the elements:";
    for(i=0;i<n;i++) cin>>v[i];
    cout<<"Enter the minimum difference:";
    cin>>diff;
    /*  as we know that s1+s2=s and we know that s1-s2=diff
        => s1=(diff+s)/2 
        which we have to find the no of subsets of given sum which is know to us
        Here Iam just using tabulation method to solve this
    */
    for(i=0;i<n;i++) sum+=v[i];
    int sum1=(diff+sum)/2;
    int dp[n+1][sum1+1];
    for(i=0;i<=n;i++)
      dp[i][0]=1;
    for(j=1;j<=sum1;j++)
      dp[0][j]=0;
    for(i=1;i<=n;i++){
        for(j=1;j<=sum1;j++){
            if(v[i-1]>j)
              dp[i][j]=dp[i-1][j];
            else 
              dp[i][j]=dp[i-1][j]+dp[i-1][j-v[i-1]]; //here we are including it and excluding it
        }
    }
    cout<<"The count of subsets with minimum difference is "<<dp[n][sum1];
    return 0;
    /* ex:4
          3 1 2 3
          possibel sets
          s1               s2        diff
          3 3              1  2       3
          3 1 2            3          3
          1 2 3            3          3
          so if we can find the no of subsets s1=(diff+s)/2 we can find that no of ways
    */
}
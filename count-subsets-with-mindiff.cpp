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
}
    /* ex:4
          3 1 2 3
          possibel sets
          s1               s2        diff
          3 3              1  2       3
          3 1 2            3          3
          1 2 3            3          3
          so if we can find the no of subsets s1=(diff+s)/2 we can find that no of ways
    */
    /* it is also same as the target sum where you are given the array and you have find the no of ways that you  can make an array by adding + and -
    ex:  [1,1,1,1,1]
        target sum=3;
        so you can make it like [-1,1,1,1,1]
                                [1,-1,1,1,1]
                                [-1,1,-1,1,1]
                                [-1,1,1,-1,1]
                                [-1,1,1,1,-1]
         so the approach is if we can make two subsets s1 (positive values) and s2 (negative values)
            => s1-s2=diff and s1+s2=s
            => s1=(diff+s)/2 so if you can count the no of subsets of sum s1 then you get the count 
            which is a type of counting the subset of given sum
    */

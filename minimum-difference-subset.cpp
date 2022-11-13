/* brutforce approach */
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int mindiff(vector<int>v,int n,int sum1,int sum2){
    if(n==0)
      return abs(sum1-sum2);
    else
      return min(mindiff(v,n-1,sum1+v[n-1],sum2),mindiff(v,n-1,sum1,sum2+v[n-1]));
}
int main(){
    int n,i;
    cout<<"Enter the no of elements:";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the elements:";
    for(i=0;i<n;i++) cin>>v[i];
    cout<<"The minimum differnce possible is "<<mindiff(v,n,0,0);
    return 0;
}
/* time complexity O(2^n) and space complexity is O(n) (recursive stack space) */
/*-------------------------------------------------------------------------------*/
/* dynamic programming tabulation method */
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int main(){
    int n,i,j,sum=0,mini;
    cout<<"Enter the no of elements:";
    cin>>n;
    vector<int>v(n);
    cout<<"Enter the elements:";
    for(i=0;i<n;i++) cin>>v[i];
    for(i=0;i<n;i++) sum+=v[i];
    bool dp[n+1][sum/2+1];
    for(i=0;i<=n;i++)
      dp[i][0]=true;
    for(j=1;j<=sum/2;j++)
      dp[0][j]=false;
    for(i=1;i<=n;i++){
        for(j=1;j<=sum/2;j++){
            if(v[i-1]>j)
               dp[i][j]=dp[i-1][j];
            else 
              dp[i][j]=dp[i-1][j] || dp[i-1][j-v[i-1]];

        }
    }
    for(j=sum/2;j>=0;j--){
        if(dp[n][j]==true){
            mini=sum-2*j;
            break;
        }
    }
    cout<<"The minimum possible difference is "<<mini;

 return 0;
}
/* time complexity and space complexity is O(n*sum) */
/*-----------------------------------------------------*/
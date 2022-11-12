// // using backtracking
#include<iostream>
using namespace std;
bool subset_sum(int a[],int n,int sum){
    if(sum==0)
      return true;
    if(n==0 && sum!=0) //base case
      return false;
    if(a[n-1]>sum)
      return subset_sum(a,n-1,sum); //if the elment is greater than ignore it
    else
      return subset_sum(a,n-1,sum) || subset_sum(a,n-1,sum-a[n-1]); //we are excluding the current and including the current 
}
int main(){
    int a[5]={1,2,3,4,5};
    cout<<subset_sum(a,5,99);

  return 0;
}
// //time complexity=O(2^n) space complexity is O(n) auxillary recursion stack space as it is the depth of the tree
/* using dynamic programming tabulation */
#include<iostream>
using namespace std;
int main(){
   int a[5]={1,2,3,4,5};
   int sum=6,i,j;
   bool dp[6][7];
   for(i=0;i<6;i++){
   	dp[i][0]=true;  //it is true  because we need not to include all the elements to provide sum 0 
	}
	for(j=1;j<7;j++){
		dp[0][j]=false; //it is false because without having elements we cannot provide sum of columns
	}

   for( i=1;i<6;i++){
       for( j=1;j<7;j++){
            if(a[i-1]>j)
              dp[i][j]=dp[i-1][j];  //if current element is greater than sum(column) we have to skip
           else
             dp[i][j]= dp[i-1][j] || dp[i-1][j-a[i-1]]; //here we can include it or exclude it
       }
       
   }
  
   for(i=0;i<6;i++){
       for(j=0;j<7;j++){
           cout<<dp[i][j]<<" ";
       }
       cout<<endl;
   }
   return 0;

}
//time complexity is O(n*sum) and space complexity is O(n*sum) for the table and declared variables

/* dynamic programming memoization method */
#include<iostream>
#include<cstring>
using namespace std;
bool subset_sum(int a[],int n,int sum,int dp[][7]){
    if(sum==0)
      return true;
    if(n==0 && sum!=0) //base case
      return false;
    if(a[n-1]>sum)
      return dp[n][sum]=subset_sum(a,n-1,sum,dp); //if the elment is greater than ignore it
    else
      return dp[n][sum]=subset_sum(a,n-1,sum,dp) || subset_sum(a,n-1,sum-a[n-1],dp); //we are excluding the current and including the current 
}
int main(){
    int n=5,sum=6;
    int a[n]={1,2,3,4,5};
    int dp[6][7],i,j;
    memset(dp,-1,sizeof(dp));
    cout<<subset_sum(a,5,6,dp)<<endl;
    for(i=0;i<n+1;i++){
       for(j=0;j<sum+1;j++){
           cout<<dp[i][j]<<" ";
       }
       cout<<endl;
   }
  return 0;
}

/* time complexity is O(n*sum) and space complexity is O(n*sum) */

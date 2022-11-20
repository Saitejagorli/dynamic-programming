#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    int matrix[3][3]={{1,1,1},
                      {1,0,1},
                      {1,1,1}};
    int dp[4][4];
    memset(dp,0,sizeof(dp));
    int largest=0,i,j;
    for(i=1;i<4;i++){
        for(j=1;j<4;j++){
            if(matrix[i-1][j-1]==1){
                dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
            if(largest<dp[i][j])
                largest=dp[i][j];
            }
        }
    }
   cout<<"Found the maximum square matrix of area "<<largest*largest;
   return 0;
}
/*time and space complexity is O(m*n)*/
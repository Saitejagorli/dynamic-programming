/*brut force approac*/
#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,int r,int c,vector<vector<int>>grid){
    if(i==r || j==c)
        return 0; //if the range out of bounds
    if(grid[i][j]==1)
        return 0;  //if there is an obstacle
    if(i==r-1 && j==c-1)
        return 1; //if it reach the destination
    else
        return solve(i+1,j,r,c,grid)+solve(i,j+1,r,c,grid); //here we are moving down or right
}
int main(){
    vector<vector<int>>obstacle_grid={{0,0,0},{0,1,0}, {0,0,0} };
    cout<<"The unique paths through the grid is "<<solve(0,0,3,3,obstacle_grid);
}
/*time complexity is O(2^m*n) and space complexity is O(m*n)*/
#include<iostream>
#include<vector>
using namespace std;
int solve(int i,int j,int r,int c,vector<vector<int>>grid,vector<vector<int>>&dp){
    if(i==r || j==c)
        return 0;
    if(grid[i][j]==1)
        return 0;
    if(i==r-1 && j==c-1)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    else
        return dp[i][j]=solve(i+1,j,r,c,grid,dp)+solve(i,j+1,r,c,grid,dp);
}
int main(){
    vector<vector<int>>obstacle_grid={{0,0,0},{0,1,0}, {0,0,0} };
    vector<vector<int>>dp(4,vector<int>(4,-1));
    cout<<"The unique paths through the grid is "<<solve(0,0,3,3,obstacle_grid,dp);
}
/*time and space complexity is O(m*n)*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int obstacle_grid[3][3]={{0,0,0},{0,1,0}, {0,0,0} };
    int dp[3][3];
    int i,j;
    bool flag=false;
    for(i=0;i<3;i++){
        if(flag || obstacle_grid[i][0]==1){
            dp[i][0]=0;
            flag=true;  //if there is an obstacle in the first row then there will not be any path to the next cell as it is a unique path
        }
        else
            dp[i][0]=1;
    }
    flag=false;
    for(j=0;j<3;j++){
        if(flag || obstacle_grid[0][j]==1)
        {
            flag=true; //if there is an obstacle in the first column then there will not be any path to the next cell as it is a unique path
            dp[0][j]=0;
        }
        else
            dp[0][j]=1;
    }
     cout<<"hi1"<<endl;
    for(i=1;i<3;i++){
        for(j=1;j<3;i++){
            if(obstacle_grid[i][j]==1)
                dp[i][j]=0;  //if there is an obstacle then there will be no paths through this cell
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
     for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<"hi"<<endl;
    cout<<"The unique paths through the grid is "<<dp[2][2];
    return 0;

}
/*time and space complexity is O(m*n)*/

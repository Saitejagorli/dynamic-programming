/*brut force approach*/
// #include<iostream>
// #include<vector>
// using namespace std;
// int min_cost_path(int i,int j,int r, int c,vector<vector<int>>grid){
//     if(i==r || j==c)
//         return 1e5;
//     if(i==r-1 && j==c-1)
//         return grid[i][j];
//     else{
//         return grid[i][j]+min(min_cost_path(i+1,j,r,c,grid),min_cost_path(i,j+1,r,c,grid));
// }
// }
// int main(){
//     vector<vector<int>>grid={{1,2,3},{4,5,6},{7,8,9}};
//     cout<<"The minimum cost path from (0,0) t0 (2,2) is "<<min_cost_path(0,0,3,3,grid);

// }
/*time complexity is O(2^m+n) and space complexity is O(m+n)  recursive stack space*/
/*----------------------------------------------------------------------------------*/
/*dynamic programming memoization*/
// #include <iostream>
// #include <vector>
// #include <limits.h>
// #include <algorithm>
// using namespace std;
// int min_cost_path(int i, int j, int r, int c, vector<vector<int>> grid, vector<vector<int>> &dp)
// {

//     if (i == r || j == c)
//         return INT_MAX;
//     if (i == r - 1 && j == c - 1)
//         return grid[i][j];
//     if (dp[i][j] != -1)
//         return dp[i][j];
//     else
//     {
//         return dp[i][j] = grid[i][j] + min(min_cost_path(i + 1, j, r, c, grid, dp), min_cost_path(i, j + 1, r, c, grid, dp));
//     }
// }
// int main()
// {
//     vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
//     vector<vector<int>> dp(3, vector<int>(3, -1));
//     cout << "The minimum cost path from (0,0) t0 (2,2) is " << min_cost_path(0, 0, 3, 3, grid, dp);
// }
/*time complexity is o(m*n) space complexity is O(m+n) recursive stack space*/
/*-------------------------------------------------------------*/
 /*dynamic programming tabulation approach*/
 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int dp[3][3],i,j;
    dp[0][0]=grid[0][0];
    for(i=1;i<3;i++)
        dp[i][0]+=dp[i-1][0]; //filling the present cost + previous cost in a row
    for(j=1;j<3;j++)
        dp[0][j]+=dp[0][j-1]; //filling the present cost + previous cost in a column
    for(i=1;i<3;i++){
        for(j=1;j<3;j++){
            dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]); //finding the minimum and and filling it with present cost
        }
    }
    cout << "The minimum cost path from (0,0) t0 (2,2) is " <<dp[2][2];
    return 0;
}
/*time and space complexity is O(m*n)*/
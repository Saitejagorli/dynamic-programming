/* we need to find the minimum no of operations to make string1 to string 2
 here we can delete in string1 and insert the characters into string1
 * the worst case is we can delete all the chars and insert the chars to make the strings equal*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string s1,s2;
    int m,n,i,j;
    cout<<"Enter the length of the strings:";
    cin>>m>>n;
    cout<<"Enter the string1 :";
    cin>>s1;
    cout<<"Enter the string2 :";
    cin>>s2;
    int dp[m+1][n+1];
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0)
              dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
              dp[i][j]=1+dp[i-1][j-1]; //if equal we increase lenth 1 to previous obtained small problem
            else
              dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//we considering max of it's previous probelms by including and excluding
        }
    }
    cout<<"Minimum no of operations are  "<<m+n-2*dp[m][n];
    /* ex: abcd anc
           first we find the longest common subsequence then the 
           deletions will be len(str1)-len(lcs)
           insertions len(str2)-len(lcs)
           total operations will be len(str1)+len(str2)-2*len(lcs)
        */
 return 0;
}
/*time complexity and space complexity is O(n*w)*/

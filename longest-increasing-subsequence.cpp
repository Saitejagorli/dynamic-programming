#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,i,j;
    cout<<"Enter the no of array elements:";
    cin>>n;
    cout<<"Enter the array elements:";
    vector<int>v(n);
    for(i=0;i<n;i++) cin>>v[i];
    vector<int>lis(n,1);//every element has lis of length 1
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(v[i]>v[j] && lis[i]<=lis[j])
                lis[i]=1+lis[j];
        }
    }
    cout<<"Longest increasing subsequence is of length "<<*max_element(lis.begin(),lis.end());
}
/* another variant for this approach is to find the longest bitconic sequence where you have to find the lcs ans longest decreasing subsequence and add and 
find the max by lcs +lds-1 */

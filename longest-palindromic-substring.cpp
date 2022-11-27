/*the bruforce approach is finding all the substrings and finding whether it is a palindrome or not*/
<----------------------------------------------------------------------------------------------------------------------------------------------------------->
/*dynamic programming tabulation approach*/
string longestPalindrome(string s) {
        int n=s.size(),i,j,start=0,k,maxlen;
        bool dp[n][n];                     //taking the table of length of the string
        memset(dp,0,sizeof(dp));
        maxlen=1;
        for(i=0;i<n;i++)
            dp[i][i]=true;  //filling the diagonal elements with true 
        for(i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;   // finding the palindromic substrings of length 2
                start=i;
                maxlen=2;
            }
        }
        for(k=3;k<=n;++k){     //here k loop indicates the length of the substring
            for(i=0;i<n-k+1;++i){
                j=i+k-1;
                if(s[i]==s[j] && dp[i+1][j-1]){      //checking if the current characters are equal  and the internal substring is palindrome
                    dp[i][j]=true;                  // like a bb a 
                if(k>maxlen){                      //     0 12 3 as s[0] and s[3] are equal and checking if the internal string  s[1:2] is palindrome or not
                  start=i;
                    maxlen=k;
                  }        
                }
            }
        }
        return s.substr(start,maxlen);
    }
 /*time complexity is O(n^2) and space complexity is O(n^2) auxillary space*/
<----------------------------------------------------------------------------------------------------------------------------------------------------------->

/*memoization time and space complexity is O(n) */
 int help(string s,int i,int* dp){
       
        if(i>=s.size())
            return 1;
        if(dp[i]!=-1) return dp[i];
        int op1=s[i]-'0',ans=0,op2=0;
        if(i< s.size()-1){
                op2=op1*10+s[i+1]-'0';    // finding the two digit number
        }
        if(op1>0){
            ans+=help(s,i+1,dp);     //if number is >0
            
        }
         if(op1>0 && op2>0 && op2<=26){
                    ans+=help(s,i+2,dp);}
       return dp[i]=ans;
    }
    int numDecodings(string s) {
        int dp[s.size()];
        memset(dp,-1,sizeof(dp));
        return help(s,0,dp);
        
    }
/* dynamic programming tabulation time and space complexity is O(n) */
 int numDecodings(string s) {
        int n=s.size();
        int dp[n+2];
        memset(dp,0,sizeof(dp));
        dp[n]=1;
        dp[n+1]=1; //base condition
        for(int i=n-1;i>=0;i--){
             int op1=s[i]-'0',op2=0;
             if(i< s.size()-1)
                op2=op1*10+s[i+1]-'0';    
             if(op1>0)
                dp[i]+=dp[i+1];
             if(op1>0 && op2>0 && op2<=26)
                    dp[i]+=dp[i+2];
        }
        return dp[0];
        
    }

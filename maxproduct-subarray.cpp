int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int i,ma,mi,ans;
        ans=nums[0];
        mi=ans;
        ma=ans;
        for(i=1;i<n;i++){
            if(nums[i]<0)
                swap(ma,mi);   //swapping because when the negative element hit we get max as min and min as max
            ma=max(nums[i],ma*nums[i]);     //finding the max by including the  element and multiplying it with previous subarray
            mi=min(nums[i],mi*nums[i]);     //finding the min by including the  element and multiplying it with previous subarray
            ans=max(ma,ans);
        }
        return ans;            
    }

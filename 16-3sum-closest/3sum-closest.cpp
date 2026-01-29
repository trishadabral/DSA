class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,k,j,curr,sum=nums[0]+nums[1]+nums[2];
        while(i<n){
            j=i+1;
            k=n-1;
            while(j<k){
                curr=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)>abs(curr-target))sum=curr;
                else if(curr<target)j++;
                else k--;
            } 
            i++;  
        }
        return sum;
    }
    
};
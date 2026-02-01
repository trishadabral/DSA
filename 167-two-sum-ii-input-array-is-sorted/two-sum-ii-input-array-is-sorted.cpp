class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      vector<int>res;
        int sum,i=0,j=numbers.size()-1;
        while(i<j){
            sum=numbers[i]+numbers[j];
            if(sum==target){
                i++;j++;
                res.push_back(i);
                res.push_back(j);
                return res;
            }
            else if(sum>target)j--;
            else i++;
        }
        return res;  
    }
};
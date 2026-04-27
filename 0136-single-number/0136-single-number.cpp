class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size(), i=0;
        sort(nums.begin(), nums.end());
        if(n==1){
            return nums[0];
        }
        else{
            for(i=1; i<n-1; i++){
                if((nums[i] != nums[i+1]) && (nums[i] != nums[i-1])) {
                    break;
                }
                else if(nums[0] != nums[1]){
                    i=0;
                    break;
                }
            }
        }
        return nums[i];
    }
};
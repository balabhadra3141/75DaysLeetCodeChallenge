class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int current = 1;
        int maxCount = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1] + 1){
                    current++;
                }
                else{
                    maxCount = max(maxCount, current);
                    current = 1;
                }
            }
        }
        return max(maxCount, current);
    }
};
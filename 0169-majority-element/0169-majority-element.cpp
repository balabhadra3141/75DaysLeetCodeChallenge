class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();
        for(int num : nums){
            map[num]++;
            if (map[num] > n/2)
                return num;
        }
        return -1;
    }
};
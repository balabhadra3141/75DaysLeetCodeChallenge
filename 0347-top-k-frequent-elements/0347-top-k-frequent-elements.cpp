class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {         map <int, int> freq;
        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }
        vector<pair<int,int>> vec(freq.begin(), freq.end());
        sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        vector<int> result;
        for (int i = 0; i < k; i++){
        result.push_back(vec[i].first);
        }
        return result;
    }
};
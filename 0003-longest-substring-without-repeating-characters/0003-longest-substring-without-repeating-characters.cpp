class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int left = 0, maxLen = 0;
        for (int right = 0; right < s.size(); right++) {
            char current = s[right];
            if (lastSeen.count(current) && lastSeen[current] >= left) {
                left = lastSeen[current] + 1;
            }
            lastSeen[current] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
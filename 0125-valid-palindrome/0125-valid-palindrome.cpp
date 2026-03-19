class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                s[i] = tolower(s[i]);
            } else {
                s.erase(i, 1);
                i--;
            }
        }
        for(int i=0; i<s.size()/2; i++){
            if(s[i] != s[s.size()-1-i])
                return false;
        }
        return true;
    }
};
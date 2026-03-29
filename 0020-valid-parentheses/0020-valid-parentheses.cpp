class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> mapping = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for (char c : s){
            if(mapping.find(c) != mapping.end()){
                if(st.empty() || st.top() != mapping[c]){
                    return false;
                }
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        return st.empty();
    }
};
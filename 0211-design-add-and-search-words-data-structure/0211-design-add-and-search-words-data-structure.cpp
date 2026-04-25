class WordDictionary {
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        TrieNode(){
            isEnd = false;
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
    bool dfs(string& word, int index, TrieNode* node){
        if(!node) 
            return false;
        if(index == word.size()){
            return node->isEnd;
        }
        char ch = word[index];

        if(ch == '.'){
            for(int i = 0; i < 26; i++){
                if(node->children[i] && dfs(word, index + 1, node->children[i])){
                    return true;
                }
            }
            return false;
        }else{
            return dfs(word, index + 1, node->children[ch - 'a']);
        }
    }

public:
    WordDictionary(){
        root = new TrieNode();
    }

    void addWord(string word){
        TrieNode* node = root;
        for(char ch : word){
            if(!node->children[ch - 'a']){
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }
    bool search(string word){
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
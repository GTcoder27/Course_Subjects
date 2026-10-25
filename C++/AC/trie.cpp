class Trie {
public:
    Trie* child[26]; // or we can make vector<Trie*> child;  
    bool eow;

    Trie() {
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
        eow = false; // end of word
    }
    
    void insert(string word) {
        Trie* curr = this;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(curr->child[index] == NULL){
                curr->child[index] = new Trie();
            }
            curr = curr->child[index];
        }
        curr->eow = true;
    }
    
    bool search(string word) {
        Trie* curr = this;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(curr->child[index] == NULL){
                return false;
            }
            curr = curr->child[index];
            
        }
        return curr->eow;
    }
    
    bool startsWith(string prefix) {
        Trie* curr = this;
        for(int i=0;i<prefix.size();i++){
            int index = prefix[i]-'a';
            if(curr->child[index] == NULL){
                return false;
            }
            curr = curr->child[index];
            
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
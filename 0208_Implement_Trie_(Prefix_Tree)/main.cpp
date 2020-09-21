class Trie {
    class TrieNode {
      public:
        bool end;
        vector<TrieNode *> cur;
        TrieNode() {
            end = false;
            cur = vector<TrieNode *>(26, nullptr);
        }
    };
    TrieNode *root;

    TrieNode *searchEnd(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size() && p; i++) {
            int idx = word[i] - 'a';
            p = p->cur[idx];
        }
        return p;
    }

  public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if (p->cur[idx] == nullptr) {
                p->cur[idx] = new TrieNode();
            }
            p = p->cur[idx];
        }
        p->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = searchEnd(word);
        return p != nullptr && p->end == true;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = searchEnd(prefix);
        return p != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

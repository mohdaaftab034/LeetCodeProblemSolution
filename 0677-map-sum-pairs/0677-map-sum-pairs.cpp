class MapSum {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int sum = 0;
    };
    
    TrieNode* root;
    unordered_map<string, int> map; // Stores the original key-value pairs

public:
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        // Find the difference if the key already exists
        int diff = val;
        if (map.count(key)) {
            diff -= map[key];
        }
        map[key] = val;
        
        // Update the Trie with the difference
        TrieNode* curr = root;
        curr->sum += diff;
        for (char c : key) {
            if (!curr->children.count(c)) {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
            curr->sum += diff;
        }
    }
    
    int sum(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            if (!curr->children.count(c)) {
                return 0; // Prefix does not exist
            }
            curr = curr->children[c];
        }
        return curr->sum;
    }
};
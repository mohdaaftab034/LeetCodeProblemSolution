class MyHashSet {
private:
    int numBuckets = 769; // A prime number to reduce hash collisions
    vector<list<int>> buckets;
    
    int hash(int key) {
        return key % numBuckets;
    }

public:
    MyHashSet() {
        buckets.resize(numBuckets);
    }
    
    void add(int key) {
        int h = hash(key);
        for (int val : buckets[h]) {
            if (val == key) return; // Key already exists
        }
        buckets[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        buckets[h].remove(key);
    }
    
    bool contains(int key) {
        int h = hash(key);
        for (int val : buckets[h]) {
            if (val == key) return true;
        }
        return false;
    }
};
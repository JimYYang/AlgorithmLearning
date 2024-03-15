class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> hash;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (hash.count(val))
            return false;
        hash[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!hash.count(val))
            return false;
        int id = hash[val];
        swap(nums[id], nums.back());
        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

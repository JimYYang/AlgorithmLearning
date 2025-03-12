class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> pos;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (pos.count(val))
        {
            return false;
        }
        int n = nums.size();
        pos[val] = n;
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!pos.count(val))
            return false;
        int idx = pos[val];
        int back = nums.back();
        pos[back] = idx;
        std::swap(nums[idx], back);
        nums.pop_back();
        pos.erase(val);
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
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int>freq, need;
        for(auto & cur :nums){
            freq[cur]++;
        }
        for(int & v : nums){
            if(freq[v] == 0){
                continue;
            }
            if(need.count(v) && need[v] > 0){
                freq[v]--;
                need[v]--;
                need[v+1]++;
            }else if(freq[v] > 0 && freq[v+1] > 0 && freq[v+2] > 0){
                freq[v]--;
                freq[v+1]--;
                freq[v+2]--;
                need[v+3]++;
            }else{
                return false;
            }
        }
        return true;
    }
};

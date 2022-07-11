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


//找到这样的子序列
bool isPossible(vector<int>& nums){
    unordered_map<int,int>freq;
    unordered_map<int, vector<vector<int>>need;
    //need记录了哪些子序列需要这个结尾
    for(int v : nums)freq[v]++;
    for(int & v : nums){
        if(freq[v] == 0){
            continue;
        }
        if(need.count(v) && need[v].size() > 0){
            freq[v]--;
            vector<int>seq = need[v].back():
            need[v].pop_back();
            seq.push_back(c);
            need[v+1].push_back(seq);
        }else if(freq[v] > 0 && freq[v+1] > 0 && freq[v+2] > 0){
            freq[v]--;
                freq[v+1]--;
                freq[v+2]--;
                vector<int>seq = {v, v + 1, v + 2};
            need[v+3].push_back(seq);
        }else{
            return false;
        }
    }
    for(auto it : need){
        for(auto cur : it.second){
            for(auto v : cur){
                cout << v << " ";
            }
            cout << endl;
        }
    }
    
}

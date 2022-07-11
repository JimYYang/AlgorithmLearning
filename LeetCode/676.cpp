//本题还可以使用字典树（前缀树的方法来做）
class MagicDictionary {
private:
    vector<string>words;

public:
    MagicDictionary() {

    }
    
    void buildDict(vector<string> dictionary) {
        words = dictionary;
    }
    
    bool search(string searchWord) {
        for(auto & cur : words){
            if(cur.length() != searchWord.size()){
                continue;
            }
            int diff = 0;
            for(int i = 0; i < cur.size(); ++i){
                if(cur[i] != searchWord[i]){
                    ++diff;
                }
                if(diff > 1)break;
            }
            if(diff == 1)return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

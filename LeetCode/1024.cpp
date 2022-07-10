class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
        
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
       sort(clips.begin(), clips.end(), cmp);
       int res = 0, curEnd = 0, nextEnd = 0;
       int i = 0, n = clips.size();
       while(i < n && clips[i][0] <= curEnd){
            while(i < n && clips[i][0] <= curEnd){
                nextEnd = max(nextEnd, clips[i][1]);
                i++;
            } 
            res++;
            curEnd = nextEnd;
            //每次都要检查一下
            if(curEnd >= time){
                return res;
            } 
        } 
        return -1;
    }
};

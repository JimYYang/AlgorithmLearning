class Solution {
public:
// https://www.acwing.com/solution/content/132100/
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();

        auto tmp = arr;
        sort(arr.begin(), arr.end());
        long long a = 0, b = 0;

        int res = 0;
        for(int i = 0; i < n; i ++){
            a += tmp[i];
            b += arr[i];

            if(a == b) res ++;
        }
        return res;

    }
};


class Solution {
public:
// https://www.acwing.com/solution/content/132100/
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int max_left[n], min_right[n];

        max_left[0] = arr[0];

        for(int i = 1; i < n; i ++){
            max_left[i] = max(arr[i], max_left[i - 1]);
        }

        min_right[n - 1] = arr[n - 1];

        for(int i = n - 2; i >= 0; i --){
            min_right[i] = min(min_right[i + 1], arr[i]);
        }

        int res = 1; // 注意至少是一
        for(int i = 0; i < n - 1; i ++){
            if(max_left[i] <= min_right[i + 1])
                res++;
        }

        return res;
        
    }
};

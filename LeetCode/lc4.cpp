class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();

        if (tot & 1)
            return find(nums1, 0, nums2, 0, tot / 2 + 1);
        return (find(nums1, 0, nums2, 0, tot / 2 + 1) + find(nums1, 0, nums2, 0, tot / 2)) / 2.0;
    }

    int find(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
    {
        // int n = nums1.size(), m = nums2.size();

        // if (n - i > m - j) return find(nums2, j, nums1, i, k);

        // if (n == i) return nums2[j + k - 1];
        // if (k == 1)
        // {
        //     return min(nums1[i], nums2[j]);
        // }

        // int si = min(k / 2, n - i);
        // int sj = k / 2;
        // if (nums1[i + si - 1] < nums2[j + sj - 1])
        // {
        //     return find(nums1, si + i, nums2, j, k - si);
        // }
        // return find(nums1, i, nums2, sj + j, k - sj);

        int n = nums1.size(), m = nums2.size();

        
        while (true)
        {
            if (n - i > m - j) return find(nums2, j, nums1, i, k);

            if (i == n) return nums2[j + k - 1];
            if (k == 1) return min(nums1[i], nums2[j]);

            int si = min(k / 2, n - i);
            int sj = k / 2;
            if (nums1[i + si - 1] < nums2[j + sj - 1])
            {
                i += si;
                k -= si;
            }
            else
            {
                j += sj;
                k -= sj;
            }
        }
    }
};
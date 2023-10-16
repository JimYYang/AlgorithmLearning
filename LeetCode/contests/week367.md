### week 367



<hr class="no-shadow" style="border: none; border-top: 6px solid gray;">



[<font size=5>**T2:2904**</font>](https://leetcode.cn/problems/shortest-and-lexicographically-smallest-beautiful-string/)

#### 算法1：滑动窗口

滑动窗口模板：枚举右端点  移动左端点

```python
class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        if s.count('1') < k:
            return ''
        left = cnt = 0
        ans = s
        for right, c in enumerate(s):
            cnt += int(c)
            while cnt > k or s[left] == '0':
                cnt -= int(s[left])
                left += 1
            if cnt == k:
                t = s[left: right + 1]
                if len(t) < len(ans) or len(t) == len(ans) and t < ans:
                    ans = t
        return ans
```



<hr class="no-shadow" style="border: none; border-top: 6px solid gray;">



[<font size=5>**T1/3:2905**</font>](https://leetcode.cn/problems/find-indices-with-index-and-value-difference-ii/description/)

#### 算法1：

对于`abs(i - j) >= indexDifference`:

- 对于这类条件，通常可以枚举一个下标，而维护另一个下标（将其加入可选的集合中）

对于`ans(nums[i] - nums[j]) >= valueDifference`:

- 对于这类条件，我在比赛中的处理方法是转化为：

  1. $nums[i]\  -\  nums[j]\  >=\  valueDifference$  转化为：

     $nums[i]\  -\ valueDifference \  >=\  nums[j]$

     因为`c++`中提供`lower_bound`函数，所以转换一下：

     $\ valueDifference \ - nums[i]  <= -\  nums[j]$

     即在已经添加的集合（$-nums[j]$）中（类比两数之和）找到一个大于等于$\ valueDifference \ - nums[i]$的数

  2. $nums[i]\  -\  nums[j]\  <=\  -valueDifference$ 转化为：

     $nums[i]\  +\ valueDifference \  <=\  nums[j]$

     即在已经添加的集合（$nums[j]$）中（类比两数之和）找到一个大于等于$\ valueDifference \ + nums[i]$的数

```c++
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int a, int b) {
        unordered_map<int, int> mp1, mp2;
        set<int> st1, st2;
        int n = nums.size();
        for (int i = n - 1 - a, j = n - 1; i >= 0; i--, j--) {
            if (!mp1.count(nums[j])) {
                mp1[nums[j]] = j;
                mp2[-nums[j]] = j;
            }
            st1.insert(nums[j]);
            st2.insert(-nums[j]);
            auto it1 = st1.lower_bound(nums[i] + b);
            auto it2 = st2.lower_bound(b - nums[i]);
            if (it1 != st1.end())
                return {i, mp1[(*it1)]};
            if (it2 != st2.end())
                return {i, mp2[(*it2)]};
        }
        return {-1, -1};
    }
};
```



#### 算法2：

条件1处理不变

条件2的处理：

- 找一个数字$a$与一个集合$B$中所有数字$b$差的绝对值的最大值，即$|a - b|$

  只需要找到$B$中**最大值**和**最小值**和$a$做减法，取绝对值，找二者的最大值即可

```python
class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        min_idx = max_idx = 0
        for j in range(indexDifference, len(nums)):
            i = j - indexDifference
            if nums[i] > nums[max_idx]:
                max_idx = i
            if nums[i] < nums[min_idx]:
                min_idx = i
            
            if abs(nums[j] - nums[max_idx]) >= valueDifference:
                return [max_idx, j]
            if abs(nums[j] - nums[min_idx]) >= valueDifference:
                return [min_idx, j]
        return [-1, -1]
```



<hr class="no-shadow" style="border: none; border-top: 6px solid gray;">



[<font size=5>**T4:2906**</font>](https://leetcode.cn/problems/construct-product-matrix/description/)

#### 算法1：

- 除法没有**同余定理**  只有**加法和乘法**才可以任意取模
- 除法时注意是否会**除0**
- 逆元首先要是质数，而且**质数要大于数据范围**，否则取模可能得到0，0没有逆元
- 大数相乘很耗时 中间要取模

前后缀分解即可

```python
class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        MOD = 12345
        n, m = len(grid), len(grid[0])
        res = [[1] * m for _ in range(n)]

        suf = 1
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                res[i][j] = suf
                suf = suf * grid[i][j] % MOD
        
        pre = 1
        for i in range(0, n):
            for j in range(0, m):
                res[i][j] = pre * res[i][j] % MOD
                pre = pre * grid[i][j] % MOD
        return res
```




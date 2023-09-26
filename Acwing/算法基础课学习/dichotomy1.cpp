//注意第一个>=指的是左边界  就算没有返回数组长度  也可能不存在目标值（第一个比目标值大的值）

    /**
     * 范围查询规律
     * 初始化:
     *   int left = 0;
     *   int right = nums.length - 1;
     * 循环条件
     *   left <= right
     * 右边取值
     *   right = mid - 1
     * 左边取值
     *   left = mid + 1
     * 查询条件
     *   >= target值, 则 nums[mid] >= target时, 都减right = mid - 1
     *   >  target值, 则 nums[mid] >  target时, 都减right = mid - 1
     *   <= target值, 则 nums[mid] <= target时, 都加left = mid + 1
     *   <  target值, 则 nums[mid] <  target时, 都加left = mid + 1
     * 结果
     *   求大于(含等于), 返回left
     *   求小于(含等于), 返回right
     * 示例(求> 或 >=)
     *     private int search(int[] nums, int target) {
     *         int left = 0;
     *         int right = nums.length - 1;
     *         while (left <= right){
     *             int mid = (right - left) / 2 + left;
     *             if (nums[mid] 查询条件 target){
     *                 right = mid - 1;
     *             } else {
     *                 left = mid + 1;
     *             }
     *         }
     *         return left(根据查询条件确认);
     *     }
     * 核心思想: 要找某个值, 则查找时遇到该值时, 当前指针(例如right指针)要错过它, 让另外一个指针(left指针)跨过他(体现在left <= right中的=号), 则找到了
     */

class Solution {
    /**
     * 二分查找
     */
    public int[] searchRange(int[] nums, int target) {
        //寻找左边界(这里寻找第一个 >= target的索引)
        int leftIndex = search(nums, target);
        if (leftIndex >= nums.length || nums[leftIndex] != target){
            return new int[]{-1, -1};
        }
        //寻找右边界(这里寻找第一个 >= target+1的索引)
        int rightIndex = search(nums, target + 1);
        return new int[]{leftIndex, rightIndex - 1};
    }

    /**
     * 寻找第一个>=目标值的索引, 找不到则返回数组长度
     */
    private int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right){
            int mid = (right - left) / 2 + left;
            if (nums[mid] >= target){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}

class Solution {
    /**
     * 二分查找
     */
    public int[] searchRange(int[] nums, int target) {
        //寻找左边界(这里寻找第一个 >= target的索引)
        int leftIndex = search(nums, target);
        if (leftIndex >= nums.length || nums[leftIndex] != target){
            return new int[]{-1, -1};
        }
        //寻找右边界(这里寻找第一个 >= target+1的索引)
        int rightIndex = search(nums, target + 1);
        return new int[]{leftIndex, rightIndex - 1};
    }

    /**
     * 寻找第一个>=目标值的索引, 找不到则返回数组长度
     */
    private int search(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right){
            int mid = (right - left) / 2 + left;
            if (nums[mid] >= target){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}


//递减的情况

//注意第一个>=指的是左边界 就算没有返回数组长度 也可能不存在目标值（第一个比目标值大的值）
收藏中给出的是非递减排列的情况

如果数组非递增排列

求第一个>= 没有输出-1


int left=0,right=b.size()-1;
    while(left<=right){
        int mid=(right-left)/2+left;
        if(b[mid]>=target)left=mid+1;
        else right=mid-1;
    }
    return right;
求第一个> 没有输出-1


int left=0,right=b.size()-1;
    while(left<=right){
        int mid=(right-left)/2+left;
        if(b[mid]>target)left=mid+1;
        else right=mid-1;
    }
    return right;
求第一个<= 没有输出数组长度


int left=0,right=b.size()-1;
    while(left<=right){
        int mid=(right-left)/2+left;
        if(b[mid]<=target)right=mid-1;
        else left=mid+1;
    }
    return left;
求第一个< 没有输出数组长度


int left=0,right=b.size()-1;
    while(left<=right){
        int mid=(right-left)/2+left;
        if(b[mid]<target)right=mid-1;
        else left=mid+1;
    }
    return left;

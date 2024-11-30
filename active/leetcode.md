

# zuochengyun

binary search 
https://www.bilibili.com/video/BV1Mh4y1P7qE/?spm_id_from=333.999.0.0&vd_source=7cd8ff38af0673e57d422f9be15e8d0e


https://www.bilibili.com/video/BV1WQ4y1W7d1/?spm_id_from=333.999.0.0&vd_source=7cd8ff38af0673e57d422f9be15e8d0e

recursion
https://www.bilibili.com/video/BV1JP411p7KG/?spm_id_from=333.999.0.0&vd_source=7cd8ff38af0673e57d422f9be15e8d0e

子串
子序列
字符串

正则表达式

回文数（字符串和数字属性结合）

链表

二叉树 二叉搜索树

Arrays

Linked Lists

Tries

Heaps

Backtracking

Graphs

Dynamic Programming


# code

```java
class Solution {
    public int removeElement(int[] nums, int val) {
        int j = nums.length - 1;
        for (int i = 0; i <= j; i++) {
            // Your student needs to implement this part
            // Hint: Check if nums[i] equals val, then what needs to be done?
            if(nums[i] == val) {
                // swap i j
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j--;
                i--;
            }
        }
        // Your student needs to return the length of the array after removing the elements
        return j + 1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {3, 2, 2, 3};
        int val = 1;
        int result = solution.removeElement(nums, val);
        System.out.println(result);
    }
}

```
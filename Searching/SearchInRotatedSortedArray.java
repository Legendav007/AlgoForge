package Searching;

public class SearchInRotatedSortedArray {

//   There is an integer array nums sorted in ascending order (with distinct values).
//   Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array
//   is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated 
//   by 3 indices and become [4,5,6,7,0,1,2].
//   Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
//   You must write an algorithm with O(log n) runtime complexity.

 
//   Example 1:
//   Input: nums = [4,5,6,7,0,1,2], target = 0//   Output: 4


//  Time Complexity of the solution: O(log N)
//  Space Complexity : O(1)
    public static int search(int[] nums, int target) {
        int n = nums.length;
        if (n == 0) return -1;

        int pivot = findRotationIndex(nums);         // index of smallest element

        int ans1 = BS(nums, target, 0, pivot-1);  //Applying binary search in first half
        if (ans1 != -1) return ans1;
        return BS(nums, target, pivot, n - 1);  //Applying binary search in second half
    }

    // returns index of smallest element (rotation pivot)
    public static int findRotationIndex(int[] nums) {
        int s = 0, e = nums.length - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return s;
    }

    public static int BS(int[] nums, int target, int start, int end) { //Binary Search
        int s = start, e = end;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (target < nums[mid]) {
                e = mid - 1;
            } else if (target > nums[mid]) {
                s = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    //Optional : Main method to test it
    public static void main(String[] args) {
        int[] nums = {3,4,5,6,1,2};
        int target = 2;
        int index = search(nums, target);
        if(index!=-1)
        {
            System.out.println("Target element exists at index: " + index);
        }
        else{
            System.out.println("Target element does not exist!");
        }
    }
}

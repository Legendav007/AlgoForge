package Searching;

public class BinarySearch {
    
//   Explanation:
//   Binary Search is a divide-and-conquer algorithm used to find a target value within a sorted array.

//   Steps:
//   1-Start: Compare the target value to the middle element of the array.
//   2-Match: If they are equal, the position is returned.
//   3-Divide:
//      (i)  If the target is less than the middle element, the search continues in the lower (left) half.
//      (ii) If the target is greater than the middle element, the search continues in the upper (right) half.
//   4-Repeat: This process repeats until the target is found or the search interval becomes empty (meaning the element is not in the array).

//   Time Complexity: O(log N)
//   In each step of the algorithm, the search space is cut in half.
//   Hence, 
//   after 1st step ----> N/2
//   after 2nd step ----> N/4
//   after 3rd step ----> N/8 and so on.
//   after kth step ----> [N/(2)^k] 
//   If target element exists, then we have 1 element left after the last step
//   Therefore, [N/(2)^k] = 1 => k=log N (base 2)

//   Worst Case: O(log n)
//   Best Case: O(1)


//   Space Complexity: O(1) [Since we are not taking any extra space and not using recursion]

    

    //This algorithm returns the index of the target element if the target element exists in the array
    //If target element does not exist, then it returns -1
    public static int search(int[] nums, int target) //Condition: Array must be sorted.
    {
        int start = 0; 
        int end = nums.length-1;  //defining start and end indeces
        while(start<=end)
        {
            int mid = start + (end-start)/2;  //middle element index
            if(nums[mid] < target)   
            {
                start=mid+1;
            }
            else if(nums[mid] > target)
            {
                end=mid-1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }

    //Optional: Main method to Test it
    public static void main(String[] args)
    {
        int[] nums = {-12, -11, -9, -4, -1, 0, 1, 5, 8, 10};
        int target = 5;
        int index=search(nums, target);
        if (index!=-1) {
            System.out.println("Element Found at index: " + index);
        }
        else{
            System.out.println("Element does not exist in the array.");
        }
    }
}

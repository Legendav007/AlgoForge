# Median of Three Quick Sort

## Problem Statement

The goal is to sort an array or list of $N$ comparable elements in ascending order efficiently.

Standard Quick Sort often suffers from performance degradation (reaching $O(N^2)$ time complexity) when the input array is already sorted or nearly sorted, due to poor pivot selection (e.g., always picking the first or last element). This variation uses the **Median of Three** strategy to select a pivot, ensuring better partition balance and robust performance on sorted inputs.

**Constraints:**

- The algorithm must perform sorting in-place (minimal auxiliary memory).
- Expected time complexity is $O(N \log N)$.

---

## Approach / Intuition

Quick Sort is a divide-and-conquer algorithm. Its efficiency relies on the **pivot** splitting the array into two roughly equal halves.

- If the split is balanced, recursion depth is logarithmic ($O(\log N)$).
- If the split is unbalanced (e.g., 1 element vs $N-1$), recursion depth is linear ($O(N)$), leading to quadratic time complexity.

The **Median of Three** approach mitigates this risk by looking at three candidate elements:

1. The first element (`arr[low]`)
2. The middle element (`arr[mid]`)
3. The last element (`arr[high]`)

The algorithm finds the median of these three values and swaps it into the pivot position. This simple heuristic almost guarantees that the pivot is not an extreme value (min or max) in sorted or reverse-sorted arrays, preserving the $O(N \log N)$ performance.

---

## Step-by-Step Explanation

1. **Select Candidates:** Identify indices `low`, `mid` (center), and `high`.
2. **Sort Candidates:** Compare the values at these three indices and swap them so that `arr[low] <= arr[mid] <= arr[high]`.
    - `arr[low]` becomes the smallest of the three.
    - `arr[high]` becomes the largest of the three.
    - `arr[mid]` becomes the **median**.
3. **Position Pivot:** Swap `arr[mid]` (the median) with `arr[high]` (or `arr[high-1]`). This places the pivot at the end of the range, ready for the partitioning step.
4. **Partition:** - Iterate through the range using two pointers.
    - Move elements smaller than the pivot to the left side.
    - Move elements larger than the pivot to the right side.
    - Place the pivot in its final correct sorted position.
5. **Recursion:** Recursively apply the same steps to the left and right sub-arrays.
6. **Base Case:** If the sub-array has fewer than 2 elements, stop.

---

## Code Implementation

### C++

```cpp
#include <bits/stdc++.h>
using namespace std;

// function to swap elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Selects median of three and moves it to the high index to act as pivot
int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    // Sort low, mid, high such that arr[low] <= arr[mid] <= arr[high]
    if (arr[mid] < arr[low])
        swap(&arr[low], &arr[mid]);
    if (arr[high] < arr[low])
        swap(&arr[low], &arr[high]);
    if (arr[high] < arr[mid])
        swap(&arr[mid], &arr[high]);

    // arr[mid] is now the median. Swap it with arr[high] to use as the pivot
    swap(&arr[mid], &arr[high]);
    
    return arr[high];
}

int partition(int arr[], int low, int high) {
    int pivot = medianOfThree(arr, low, high);
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
```

### Java

```java
import java.util.Arrays;

class Main {
    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    static int medianOfThree(int[] arr, int low, int high) {
        int mid = low + (high - low) / 2;

        // Sort low, mid, high
        if (arr[mid] < arr[low]) swap(arr, low, mid);
        if (arr[high] < arr[low]) swap(arr, low, high);
        if (arr[high] < arr[mid]) swap(arr, mid, high);

        // Swap median to high to act as pivot
        swap(arr, mid, high);
        return arr[high];
    }

    static int partition(int[] arr, int low, int high) {
        int pivot = medianOfThree(arr, low, high);
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr, i, j);
            }
        }
        swap(arr, i + 1, high);
        return i + 1;
    }

    static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    public static void main(String args[]) {
        int[] arr = {10, 7, 8, 9, 1, 5};
        System.out.println("Original array: " + Arrays.toString(arr));
        
        quickSort(arr, 0, arr.length - 1);
        
        System.out.println("Sorted array: " + Arrays.toString(arr));
    }
}
```

### Python

```Python
def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def median_of_three(arr, low, high):
    mid = low + (high - low) // 2
    
    # Sort low, mid, high
    if arr[mid] < arr[low]:
        swap(arr, low, mid)
    if arr[high] < arr[low]:
        swap(arr, low, high)
    if arr[high] < arr[mid]:
        swap(arr, mid, high)
        
    # Swap median to high to act as pivot
    swap(arr, mid, high)
    return arr[high]

def partition(arr, low, high):
    pivot = median_of_three(arr, low, high)
    i = low - 1
    
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            swap(arr, i, j)
            
    swap(arr, i + 1, high)
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

def main():
    arr = [10, 7, 8, 9, 1, 5]
    print(f"Original array: {arr}")
    quick_sort(arr, 0, len(arr) - 1)
    print(f"Sorted array: {arr}")

if __name__ == "__main__":
    main()
```

## Time Complexity

- **Best Case**: *O(n log n)*
  - Occurs when the partitions are balanced

- **Average Case**: *O(n log n)*
  - The Median of Three heuristic makes this the standard expectation for random and partially sorted data.

- **Worst Case**: *O(N^2)*
  - Occurs if the median of the three candidates consistently ends up being an extreme value in the subarray (rare, but theoretically possible with specific adversarial inputs)

## Space Complexity

- Auxiliary Space:  *O(1)*

## Edge Cases

- **All elements are negative**: the algorithm correctly returns the maximum (least negative) element.

- **Single element array:** the element itself is the maximum subarray sum.

- **Array containing zeros:** zeros are handled naturally without affecting correctness.

## References

- [Quicksort Pivot Selection: Median Of 3 And Median Of Medians](https://maxgcoding.com/quicksort-pivot-selection)

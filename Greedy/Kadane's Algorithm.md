# Kadane's Algorithm

## Problem Statement

Find the maximum possible sum of a contiguous non-empty subarray within an array of integers.

Constraints:
- At least one element must be chosen
- Time complexity should be O(n)

## Approach / Intuition
Kadane's algorithm is based on a greedy decision approach at each index.

The core logic behind the algorithm is that a negative running sum can never positively impact our global maximum, hence we discard it.

## Step-by-Step Explanation

### Initial Setup:
- Initialize `currentSum` as the first element of the array.

- Initialize `maxSum` as the first element aswell, to handle arrays with all negative values.

### Main logic

At every position `i`, it keeps track of the maximum sum of a subarray that ends at index `i`.
Let this sum be `currentSum`

**For each element we have two possibilities:**
- Either extend the subarray by adding the current element

**OR**

- Start a new subarray from the current element discarding all previous elements.

While doing this we also keep track of the best possible `currentSum` found.
Let this value be `maxSum`.

`maxSum` is the best subarray sum seen so far.

### Algorithm Progression

- Let's say the `currentSum` upto index `i-1` is negative, if we add it, it will only reduce the total (negative effect). So, rather tham adding it we discard it and start freshly.

    _In terms of a sliding-window interpretation we can say that we move the left pointer to the current position as to discard previous elements._

- Now if the `currentSum` is non-negative upto `i-1`, continuing to extend the subarray increases the chance of getting a better `currentSum`

    _In terms of a sliding-window interpretation we move the right pointer by one step as to include the next element._

Any time our `currentSum` exceeds `maxSum` we update the maxSum to be equal to the currentSum.

### Example:
![alt text](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/f16c1a92-9cbd-43d4-ae6b-0d143e833d00/sharpen=1)

## Code Implementation

### C++
```cpp
#include <bits/stdc++.h>
using namespace std;

void kadanesAlgorithm() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long currentSum = arr[0];
    long long maxSum = arr[0];

    for (int i = 1; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum << endl;
}

int main() {
    kadanesAlgorithm();
    return 0;
}
```

### Python
```python
def kadanes_algorithm():
    n = int(input())
    arr = list(map(int, input().split()))

    current_sum = arr[0]
    max_sum = arr[0]

    for i in range(1, n):
        current_sum = max(arr[i], current_sum + arr[i])
        max_sum = max(max_sum, current_sum)

    print(max_sum)


if __name__ == "__main__":
    kadanes_algorithm()
```

## Time Complexity
_O(n)_ in all cases since each element is processed exactly once.

## Space Complexity
- Auxiliary Space:  _O(1)_

## Edge Cases

- **All elements are negative**: the algorithm correctly returns the maximum (least negative) element.

- **Single element array:** the element itself is the maximum subarray sum.

- **Array containing zeros:** zeros are handled naturally without affecting correctness.

## References
- [Neetcode Advanced-Algorithms](https://neetcode.io/courses/advanced-algorithms/0)
- [Kadane's Algorithm Visualizer](https://ammar-montaser.github.io/Kadane-s-Algorithm-Visualizer/)
# Generate All Subsets (Power Set) using Backtracking

## Problem Statement
Given a **collection of distinct elements**, generate all possible subsets (the power set).
The solution set must not contain duplicate subsets. The result can be returned in any order.

**Example:**
* **Input:** `elements = [1, 2, 3]` (or `['a', 'b', 'c']`)
* **Output:** `[[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]`

**Constraints:**
* The input collection contains unique elements.
* The size of the collection is small (typically N <= 20) due to exponential time complexity.

---

## Approach / Intuition
To generate all subsets, we use the **Backtracking** paradigm. The core intuition is based on the "Choice Diagram" for every element in the collection.

For each element in the collection, we have exactly two choices:
1.  **Include** the element in the current subset.
2.  **Exclude** the element from the current subset.

By traversing this decision tree (State-Space Tree) recursively, we explore all $2^N$ possibilities. When we reach the end of the collection (base case), the current group of chosen elements forms a valid subset.

---

## Step-by-Step Explanation
1.  **Initial Setup**: Create a `result` list to store the final subsets and a `current` list to track the subset currently being built during recursion.
2.  **Recursive Function**: Define a helper function that takes the current `index` of the collection we are processing.
3.  **Base Case**: Check if `index` equals the size of the input collection. If yes, it means we have made a decision (include/exclude) for every element. Add a copy of `current` to `result` and return.
4.  **Recursive Step (Include)**:
    * Add the element at the current `index` to the `current` list.
    * Recursively call the function for `index + 1`.
    * **Backtrack**: Remove the last element added to `current`. This step is crucial to "undo" the change (backtrack) and return to the state before the element was included.
5.  **Recursive Step (Exclude)**:
    * Recursively call the function for `index + 1` (without adding the current element).

---

## Code Implementation

### C++

```cpp
#include <iostream>
#include <vector>

using namespace std;

class GenerateSubsets {
public:
    // Main function to generate all subsets
    vector<vector<int>> subsets(vector<int>& elements) {
        vector<vector<int>> result;
        vector<int> current;
        // Start backtracking from index 0
        backtrack(0, elements, current, result);
        return result;
    }

private:
    // Helper function for recursion
    void backtrack(int index, vector<int>& elements, vector<int>& current, vector<vector<int>>& result) {
        // Base Case: Processed all elements
        if (index == elements.size()) {
            result.push_back(current);
            return;
        }

        // Choice 1: Include the element
        current.push_back(elements[index]);
        backtrack(index + 1, elements, current, result);

        // Backtrack: Remove the element to explore the "Exclude" path
        current.pop_back();

        // Choice 2: Exclude the element
        backtrack(index + 1, elements, current, result);
    }
};

int main() {
    GenerateSubsets solution;
    
    // 1. Read number of elements
    int n;
    cout << "Enter the number of unique elements: ";
    if (!(cin >> n)) return 0;

    // 2. Read elements
    vector<int> elements(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; ++i) {
        cin >> elements[i];
    }

    // 3. Generate Subsets
    vector<vector<int>> result = solution.subsets(elements);

    // 4. Print Output
    cout << "All Subsets: " << endl;
    for (const auto& subset : result) {
        cout << "[ ";
        for (int el : subset) {
            cout << el << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

```

### Java

```java

import java.util.*;

public class GenerateSubsets {
    
    // Main logic to generate subsets
    public List<List<Integer>> subsets(List<Integer> elements) {
        List<List<Integer>> result = new ArrayList<>();
        // Start backtracking from index 0
        backtrack(0, elements, new ArrayList<>(), result);
        return result;
    }

    // Helper method for recursion
    public void backtrack(int index, List<Integer> elements, List<Integer> current, List<List<Integer>> result) {
        // Base Case: If we have processed all elements
        if (index == elements.size()) {
            result.add(new ArrayList<>(current)); // Add deep copy of current subset
            return;
        }

        // Choice 1: Include the element at 'index'
        current.add(elements.get(index));
        backtrack(index + 1, elements, current, result);

        // Backtrack: Remove the last element to explore the "Exclude" path
        current.remove(current.size() - 1);

        // Choice 2: Exclude the element at 'index'
        backtrack(index + 1, elements, current, result);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // 1. Read the number of elements
        System.out.print("Enter the number of unique elements: ");
        int n = sc.nextInt();
        
        // 2. Read the elements into a List
        List<Integer> elements = new ArrayList<>();
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            elements.add(sc.nextInt());
        }
        
        // 3. Generate and print subsets
        GenerateSubsets solution = new GenerateSubsets();
        List<List<Integer>> output = solution.subsets(elements);
        
        System.out.println("All Subsets: " + output);
        
        sc.close();
    }
}

```

### Python
```python
from typing import List

def generate_subsets(elements: List[int]) -> List[List[int]]:
    """
    Generates all subsets (the Power Set) of the given collection using backtracking.
    """
    result = []
    current = []
    
    def backtrack(index: int):
        # Base Case: processed all elements
        if index == len(elements):
            result.append(current.copy())
            return
        
        # Choice 1: Include the element at 'index'
        current.append(elements[index])
        backtrack(index + 1)
        
        # Backtrack: Remove the element to explore the "Exclude" path
        current.pop()
        
        # Choice 2: Exclude the element at 'index'
        backtrack(index + 1)
        
    # Start recursion from index 0
    backtrack(0)
    return result

if __name__ == "__main__":
    # 1. Take input from user
    try:
        # standard input format: space-separated integers
        input_str = input("Enter distinct elements separated by space (e.g., 1 2 3): ")
        if not input_str.strip():
            elements = []
        else:
            elements = list(map(int, input_str.split()))
            
        print(f"Input: {elements}")
        
        # 2. Generate Subsets
        subsets = generate_subsets(elements)
        
        # 3. Print Result
        print(f"All Subsets: {subsets}")
        
    except ValueError:
        print("Invalid input. Please enter integers only.")

```


## Time Complexity
- **O(N * 2^N)**
  - **Reasoning**:
    - The recursion tree has a depth of **N**, and at each level, we branch into two paths (include or exclude). This generates a total of **2^N** nodes (subsets).
    - In the base case (when a subset is formed), we create a deep copy of the `current` list to add it to the `result`. Copying a list of length **N** takes **O(N)** time.
    - Therefore, the total time complexity is **O(N * 2^N)**.

---

## Space Complexity
- **Auxiliary Space: O(N)**
  - **Reasoning**:
    - **Recursion Stack**: The maximum depth of the recursion stack is **N** (the number of elements in the input), as we go one level deeper for each element.
    - **Temporary Storage**: The `current` list used to track the current subset can hold at most **N** elements.
    - *Note*: If we count the space required to store the final output (the power set), it would be **O(N * 2^N)**, but the auxiliary space required for the algorithm's logic is just **O(N)**.

    ## Edge Cases
- **Empty Collection:**
  - If the input is an empty list `[]`, the algorithm should return a list containing just the empty subset `[[]]`.
- **Single Element:**
  - If the input is `[1]`, the output should be `[[], [1]]`.
- **Maximum Recursion Depth:**
  - Since the time complexity is exponential ($2^N$), this algorithm is only feasible for small input sizes (typically $N \le 20$). Larger inputs will cause Time Limit Exceeded (TLE) or Stack Overflow errors.
- **Duplicate Handling:**
  - This specific algorithm assumes **distinct** elements. If the input contains duplicates (e.g., `[1, 2, 2]`), this standard backtracking approach will generate duplicate subsets (e.g., `[2]` and `[2]`). To handle duplicates, a sorting step and a condition to skip adjacent duplicates would be required (as seen in the "Subsets II" variation).

---

## References (Optional)
- **LeetCode Problem:** [78. Subsets](https://leetcode.com/problems/subsets/)
- **GeeksForGeeks:** [Power Set using Backtracking](https://www.geeksforgeeks.org/power-set/)
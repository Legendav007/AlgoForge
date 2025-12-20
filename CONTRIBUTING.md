# Contribution Guidelines

Welcome to **AlgoForge**!  
AlgoForge is a mentored open-source repository created as part of the **Winter of Open Source** initiative. The goal of this project is to build a high-quality collection of **algorithms and data structures**, with a strong emphasis on explanation, analysis, and understanding—not just raw code.

We encourage contributions from all skill levels.

---

## How to Contribute to AlgoForge

### Step 1: Fork the Repository

1. Fork this repository to your GitHub account.
2. Clone your forked repository to your local machine:

```bash
git clone https://github.com/Legendav007/AlgoForge.git
```

---

### Step 2: Choose an Algorithm

1. Browse the existing folders and check whether the algorithm you want to add already exists.
2. If it exists, **do not duplicate it**. You may improve documentation or add missing explanations.
3. If it does not exist, create a new folder under the appropriate category.
4. Create an **Issue** describing the algorithm you want to work on and wait until it is assigned.

---

## Contribution Format (Mandatory)

⚠️ **Each algorithm must be contributed as a single Markdown (`.md`) file.**

- No standalone `.cpp`, `.java`, or `.py` files  
- Explanation, analysis, and code must all be inside **one `.md` file**  
- Pull Requests not following this format will **not be merged**

---

## Required Folder Structure

```
Category_Name/
└── algorithm_name.md
```

Example:
```
Searching/
└── binary_search.md
```

---

## Mandatory `algorithm_name.md` Structure

Each algorithm Markdown file **must include all of the following sections**:

- **Algorithm Name**
- **Problem Statement**
- **Approach / Intuition**
- **Step-by-Step Explanation**
- **Code Implementation**
- **Time Complexity**
- **Space Complexity**

---

## Example Algorithm File (Binary Search)

Below is an example of how a complete algorithm file should look.

```md
# Binary Search

## Problem Statement
Given a sorted array and a target element, determine whether the target exists in the array.

## Approach / Intuition
Binary Search works by repeatedly dividing the search space in half.  
At each step, the middle element is compared with the target to decide which half to search next.

## Step-by-Step Explanation
1. Initialize two pointers: `low` and `high`
2. Compute the middle index
3. Compare the middle element with the target
4. Reduce the search space accordingly
5. Repeat until the element is found or the range becomes invalid

## Code Implementation

### C++
```cpp
int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

### Python
```python
def binary_search(arr, target):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1
```
## Time Complexity
O(log n)

## Space Complexity
O(1)
```

---

## Step 3: Update Roadmap.md

After your Pull Request is merged:

- Check the corresponding algorithm in **Roadmap.md**
- If the algorithm is not listed, add a new checkbox under the appropriate section
- Add a **hyperlink** pointing to your algorithm folder or `.md` file

> Do not update the roadmap before your PR is merged.

---

## Step 4: Submit a Pull Request

1. Push your changes to your forked repository
2. Open a Pull Request to the `main` branch

Ensure that:
- The algorithm is documented in a **single `.md` file**
- All mandatory sections are present
- Folder naming follows repository conventions
- Roadmap is updated correctly

Mentors will review your PR and may request changes before merging.

---

## Important Notes

- ❌ PRs without explanation or analysis will be rejected  
- ❌ PRs containing only raw code will be rejected  
- ❌ PRs not following the `.md` format will be rejected  
- Write clean, readable code

---

Thank you for contributing to **AlgoForge**.  
Learn the algorithm. Explain it. Analyze it. Then code it.

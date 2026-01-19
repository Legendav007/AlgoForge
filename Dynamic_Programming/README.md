# Longest Common Subsequence (LCS)

## Introduction

The **Longest Common Subsequence (LCS)** problem is a classic Dynamic Programming problem
used to find the longest sequence that appears in two sequences **in the same order**
but **not necessarily contiguously**.

This explanation is **language-agnostic** and applies to any programming language.

---

## Table of Contents

- What is LCS?
- Key Idea
- Dynamic Programming Approach
- DP Table Explanation
- Reconstructing the LCS
- Example
- Algorithm Complexity
- Applications
- Common Mistakes
- License

---

## What is LCS?

The **Longest Common Subsequence** of two sequences is the longest sequence of elements
that:
- Appears in both sequences
- Maintains relative order
- Does not need to be contiguous

### Example

Sequence A: ABCDE
Sequence B: ACE
LCS: ACE
Length: 3



---

## Key Idea

Instead of generating all subsequences (which is inefficient),
Dynamic Programming is used to:
- Break the problem into smaller subproblems
- Store intermediate results
- Build the final answer efficiently

---

## Dynamic Programming Approach

### Step 1: Define the DP Table

Create a 2D table where:

dp[i][j] = length of LCS using
first i elements of sequence A
first j elements of sequence B


An extra row and column represent empty sequences.

---

### Step 2: Fill the DP Table

For each position `(i, j)`:

#### Case 1: Elements Match

dp[i][j] = 1 + dp[i-1][j-1]

---

## DP Table Explanation

For:

A = "ABC"
B = "AC"

DP table:

  ""  A  C
"" 0 0 0
A 0 1 1
B 0 1 1
C 0 1 2

The value in the **bottom-right cell** is the LCS length.

---

## Reconstructing the LCS (Backtracking)

To retrieve the actual subsequence:

1. Start from the bottom-right of the DP table
2. If elements match:
   - Add element to result
   - Move diagonally up-left
3. If they do not match:
   - Move in the direction of the larger value (up or left)
4. Reverse the collected result

---

## Example

Sequence 1: AGGTAB
Sequence 2: GXTXAYB
LCS Length: 4
LCS String: GTAB


---

## Algorithm Complexity

| Metric | Complexity |
|------|------------|
| Time | O(n × m) |
| Space | O(n × m) |

Where:
- `n` = length of first sequence
- `m` = length of second sequence

---

## Applications

- Text comparison tools
- Version control systems
- DNA sequence analysis
- Plagiarism detection
- File diff utilities

---

## Common Mistakes

- Confusing subsequence with substring
- Forgetting base cases for empty sequences
- Incorrect backtracking logic
- Assuming characters must be adjacent



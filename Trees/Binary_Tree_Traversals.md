# Algorithm Name

Binary Tree Traversals (Inorder, Preorder, Postorder)

---

## Problem Statement

Given a binary tree, traverse all its nodes using three standard traversal techniques: Inorder, Preorder and Postorder Traversal
The goal is to visit every node exactly once following the specific order defined by each traversal method.

**Constraints (if applicable):**

* The tree can be empty/ unbalanced
* The number of nodes can range from 0 to N

---

## Approach / Intuition

The recursive approach is used because a binary tree is a recursive data structure.
Each node has a left and right subtree, which are themselves binary trees.

The algorithm works by:

* Breaking the problem into smaller subproblems (left and right subtrees)
* Applying the same traversal logic recursively
* Combining results in a specific order depending on the traversal type

This approach is simple, intuitive, and closely matches the tree structure.

---

## Step-by-Step Explanation

### Initial Setup

* Start from the root node of the binary tree
* Define recursive functions for each traversal type

### Main Logic

* **Inorder Traversal**

  * Traverse left subtree
  * Visit the current node
  * Traverse right subtree

* **Preorder Traversal**

  * Visit the current node
  * Traverse left subtree
  * Traverse right subtree

* **Postorder Traversal**

  * Traverse left subtree
  * Traverse right subtree
  * Visit the current node

### Algorithm Progression

* The recursion continues down to leaf nodes
* Eg for Inorder, The recursion continues to go to left subtree until the last node(leaf node), then visits that leaf node.
* Once a null node is encountered, recursion stops for that branch
* The call stack unwinds, completing traversal

Sure 👍
Here is the same traversal shown **using arrows**.

---

### Binary Tree (Visulization)

```
        1
       / \
      2   3
     / \
    4   5
```

---

### Preorder Traversal (Root → Left → Right)

```
1 → 2 → 4 → 5 → 3
```

---

### Inorder Traversal (Left → Root → Right)

```
4 → 2 → 5 → 1 → 3
```

---

### Postorder Traversal (Left → Right → Root)

```
4 → 5 → 2 → 3 → 1
```


### Termination Condition and Edge Cases

* If the current node is null, return immediately, Handles empty trees naturally

---

## Code Implementation

### C++

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // traversal functions can be called here
    return 0;
}
```

---

### Java

```java
class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

class Main {

    static void inorder(Node root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
    }

    static void preorder(Node root) {
        if (root == null) return;
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
    }

    static void postorder(Node root) {
        if (root == null) return;
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");
    }

    public static void main(String[] args) {
        // traversal functions can be called here
    }
}
```

---

### Python

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def inorder(root):
    if root is None:
        return
    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)

def preorder(root):
    if root is None:
        return
    print(root.data, end=" ")
    preorder(root.left)
    preorder(root.right)

def postorder(root):
    if root is None:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.data, end=" ")

if __name__ == "__main__":
    pass
```

---

## Time Complexity

* **Best Case:** O(N)
* **Average Case:** O(N)
* **Worst Case:** O(N)

As Each node is visited exactly once.

---

## Space Complexity

* **Auxiliary Space:** O(H) (Function Stack)

  * H is the height of the tree
  * Worst case: O(N) for skewed tree (forms a chain)
  * Best case: O(log N) for balanced tree (distibuted evenly)

---

## Edge Cases

* Empty tree, Tree with a single node, Left/Right-skewed tree, Right-skewed tree

---

## References 

* [geeksforgeeks.org](https://www.geeksforgeeks.org/dsa/tree-traversals-inorder-preorder-and-postorder/)

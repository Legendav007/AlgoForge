/*
author: @datavorous
date: 12/18/25
algorithm: bfs
*/

#include <iostream>
#include <vector>
using namespace std;


class TreeNode {
    public:
        int value;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val) {
            value = val;
            left = nullptr;
            right = nullptr;
        }
};

vector<int> bfs(TreeNode* root) {
    if (root == nullptr) return {};

    vector<int> result;
    vector<TreeNode*> queue;
    queue.push_back(root);

    int front = 0;

    while (front < queue.size()) {
        TreeNode* current = queue[front];
        front++;

        result.push_back(current->value);
        if (current->left != nullptr)
            queue.push_back(current->left);
        if (current->right != nullptr)
            queue.push_back(current->right);

    }
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<int> traversal = bfs(root);

    for(int val : traversal)
        cout << val << " ";

    cout << "\n";
}
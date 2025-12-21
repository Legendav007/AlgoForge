/*
author: @datavorous
date: 12/18/25
algorithm: bfs
*/

package main

import "fmt"

type TreeNode struct {
	value int
	left *TreeNode
	right *TreeNode
}

func bfs(root *TreeNode) []int {
	if root == nil {
		return []int{}
	}

	result := []int{}
	queue := []*TreeNode{root}
	front := 0

	for front < len(queue) {
		current := queue[front]
		front++

		result = append(result, current.value)
		
		if current.left != nil {
			queue = append(queue, current.left)
		}

		if current.right != nil {
			queue = append(queue, current.right)
		}
	}
	return result
}

func main() {
	root := &TreeNode{value: 1}

	root.left = &TreeNode{value: 2}
	root.right = &TreeNode{value: 3}

	root.left.left = &TreeNode{value: 4}
	root.left.right = &TreeNode{value: 5}
	root.right.right = &TreeNode{value: 6}

	fmt.Println(bfs(root))
}
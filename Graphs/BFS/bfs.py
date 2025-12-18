"""
author: @datavorous
date: 12/18/25
algorithm: bfs
"""

class TreeNode:
    """
    Docstring for TreeNode

    The binary tree, we have the value for each node.
    And two pointers.
    """
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def bfs(root):

    # this is the base condition
    if not root:
        return []
    
    result = []

    # main differentiating factor with DFS is this queue
    # queue can be thought of as a 'timeline of work'
    queue = [root]
    # and front points to WHAT we are doing now
    # appending adds FUTURE WORK
    # DO NOT THINK of it as a layer counter 
    # it is an INDEX POINTER
    # it goes like this: 
    # node 1 -> node 2 -> node 3 -> ... and so on
    # it is the index of the next node to process in the queue
    front = 0

    # initially only the root is known, nothing else exists yet 
    # essentially, queue = [TreeNode(1)], front = 0 and result = []

    while front < len(queue):
        # are there UNPROCESSED nodes left in the queue?
        # if true, we move forward with layer number
        current = queue[front]
        front += 1

        # we append the current node value, this is the result list
        result.append(current.value)

        # and make sure to append the left and right child node objects too
        # given they are not None
        # we WILL check these nodes LATER ON (future iterations)
        if current.left: queue.append(current.left)
        if current.right: queue.append(current.right)

    return result


def main():
    """
    The tree we are making here:
        1
       / \
      2   3
     / \   \
    4   5   6
    """
    root = TreeNode(1)

    root.left = TreeNode(2)
    root.right = TreeNode(3)

    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.right = TreeNode(6)

    print(bfs(root))

if __name__ == '__main__':
    """
    The gist of the BFS algorithm:

    1. queue holds discovered but NOT YET processed noddes
    2. front points to the next node to process
    3. each iteration processes exactly one node 
    4. children are appended to the end as future work 
    5. BFS ends when ALL DISCOVERED nodes are PROCESSED.
    """
    main()

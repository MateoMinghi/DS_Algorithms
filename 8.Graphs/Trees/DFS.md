Depth-first Search (DFS) is an algorithm for traversing a tree or graph. The algorithms starts at the root node (if there is one), or an arbitrary node, and explores as far as possible along each branch before backtracking.

There's two versions of the algorithm:

* Recursive DFS: This version uses recursive calls to manage backtracking. 
* Iterative DFS: This version uses a stack to emulate the recursion. #think about the possibility of using a dictionary


### Recursive DFS
In the recursive version, the algorithm explores each branch of the graph as deep as possible, calling itself for each unvisited neighboring node. When it reaches a node with no invisited neigbohts, it backtracks to explore other branches.

For instance:

    A
   / \
  B   C
 /   / \
D   E   F

- We start at the root node 'A', mark it as visited, and explore its children. 
- We move to node 'B', mark it as visited, and explore its children. 
- We move to 'D', mark it as visited, and since it doesn't have any children, we backtrack to 'B'.
- Since we have already visited 'B' and all of its children, we backtrack to 'A', and explore its other neighbor 'C'.
- We move to 'C', mark it as visited, and explore its children. 
- We move to 'E', mark it as visited. Since 'E' doesn't have any children, backtrack to 'C', and explore 'F'.
- Move to 'F', mark it as visited, and the traversal is complete.

```python
def dfs_recursive(node, visited=None):
    if visited is None:
        visited = set()
    
    if node not in visited:
        print(node)  # Process the node
        visited.add(node)
        for neighbor in node.neighbors:
            dfs_recursive(neighbor, visited)
```



### Iterative DFS

The algorithm works exactly the same, except that we use a stack to manage the nodes we visit: 

- Start at A, push A onto the stack.
- Pop A, mark it as visited, and push its neighbors (C and B).
- Pop B, mark it as visited, and push its neighbor (D).
- Pop D, mark it as visited. Since D has no neighbors, continue.
- Pop C, mark it as visited, and push its neighbors (F and E).
- Pop E, mark it as visited. Since E has no neighbors, continue.
- Pop F, mark it as visited. The traversal is complete.

```py
def dfs_iterative(start):
    visited = set()
    stack = [start]
    
    while stack:
        node = stack.pop()
        if node not in visited:
            print(node)  # Process the node
            visited.add(node)
            # Push all unvisited neighbors to the stack
            for neighbor in node.neighbors:
                if neighbor not in visited:
                    stack.append(neighbor)

```





# DFS for Binary Trees

Although the idea behind the algorithm is the same (go as deep as possible before backtracking), in Binary  Trees we can approach it in three ways:

* Preorder Traversal (Root -> Left -> Right)
* Inorder Traversal (Left -> Root -> Right)
* Postorder Traversal (Left -> Right -> Root)

### Recursive DFS in Binary Trees

### Preorder Traversal (Recursive)
The root is processed first, followed by its left and right children.

- Visit the current node (root).
- Recursively traverse the left subtree.
- Recursively traverse the right subtree.

     10
    /  \
   5   15
  / \    \
 2   7   20

The order would be 10, 5, 2, 7, 15, 20.

```py
def preorder_recursive(root):
    if root:
        print(root.value)  # Process the node
        preorder_recursive(root.left)
        preorder_recursive(root.right)
```

### Inorder Traversal (Recursive)

The left subtree is processed first, then the root, and finally the right subtree. Inorder traversal of a BST gives nodes in sorted order.

- Recursively traverse the left subtree.
- Visit the current node (root).
- Recursively traverse the right subtree.

```py
def inorder_recursive(root):
    if root:
        inorder_recursive(root.left)
        print(root.value)  # Process the node
        inorder_recursive(root.right)
```
For the same tree as in the preorder example, Inorder would print: 2, 5, 7, 10, 15, 20.

###  Postorder Traversal (Recursive)
Both subtrees are processed before the root

- Recursively traverse the left subtree.
- Recursively traverse the right subtree.
- Visit the current node (root).


```py
def postorder_recursive(root):
    if root:
        postorder_recursive(root.left)
        postorder_recursive(root.right)
        print(root.value)  # Process the node

```
For the same tree, Postorder would print: 2, 7, 5, 20, 15, 10.


By the way,  when I say "processing the node," I mean performing some specific operation or task on that node during traversal. What you do when "processing" a node depends on the problem you're trying to solve. 

When to choose one over the other?

*Preorder*: Use when you need to process the root node before its children. Good for copying trees, prefix expressions, and tree serialization.

*Inorder*: Use when you need to process nodes in sorted order (applicable to BSTs). Ideal for in-order data retrieval or checking BST properties.

*Postorder*: Use when you need to process children before the root. Useful for deleting trees, postfix expressions, and dependency resolution.
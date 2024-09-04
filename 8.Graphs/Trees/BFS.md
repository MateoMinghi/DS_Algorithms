# BFS

The name is self-explanatory. Unlike DFS, in which we want to maximize how deep we 
go before we backtrack, in BFS the idea is to start traversing from the root node
and exploring all the neighbours at the current depth level, before we move on to 
the next depth level.

Basic idea:

1.- Start at the root node and add it to a queue.

2.- While the queue is not empty, dequeue a node and visit it.

3.- Enqueue all of its children (if any) into the queue.

4.- Repeat steps 2 and 3 until the queue is empty.

BFS is naturally aligned with a queue because you want to explore nodes level by level, from left to right.
* Process: You enqueue the root, then repeatedly dequeue a node, process it, and enqueue its children. This ensures that all nodes at a given level are processed before any nodes at the next level.
* Why it works: The FIFO order ensures that nodes are processed in the order they’re discovered, which is crucial for level-by-level traversal. 
* The key characteristic of BFS is that you visit all nodes at the current level before moving to the next level. A queue supports this because it processes nodes in the exact order they’re added.
* When using a queue, nodes are processed from left to right at each level. This is critical for BFS, especially in tasks like level order traversal or shortest path algorithms.


The code is actually pretty straight-forward:
```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void bfs(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;  // Create a queue for BFS
    q.push(root);        // Start with the root node

    while (!q.empty()) {
        TreeNode* node = q.front(); // Get the current node at the front of the queue
        //The front() method returns a reference to the first element that was added to the queue. This element will be the next one to be processed.
        q.pop();

        // Process the current node (e.g., print its value)
        cout << node->val << " ";

        // Enqueue the left child
        if (node->left) {
            q.push(node->left);
        }

        // Enqueue the right child
        if (node->right) {
            q.push(node->right);
        }
    }
}

int main() {
    // Create a simple binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Perform BFS traversal
    cout << "BFS Traversal: ";
    bfs(root);

    return 0;
}
```

Fairly similar to the stack implementation of DFS.
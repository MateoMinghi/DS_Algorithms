<div align="center">
  <h1>Linked Lists</h1>
</div>

### Linked Lists
Linked Lists are linear data structures. Unlike arrays, linked lists use nodes to store elements which are not stored in contiguous memory locations.

#### Nodes

Nodes are the building blocks of Linked Lists. They hold two things: the value or whatever the fuck we want to store, and a reference to the next node.

Such references are exactly what allow Linked Lists to be linear, every node has the address of its succeeding node. That is how each node can access its succeeding node. 
> This means, of course, that the final node in a Linked List (also known as the tail), will ve pointing to Null, since there is no other element to point to. If the list is empty, that node will also point to Null.


In order to build a linked list we need to
* Create nodes
* Connect nodes
* Append nodes
* Insert nodes
* Delete nodes


A simple implementation of a node in c++:

```cpp
struct Node{
public:    
    int data;
    Node* next;
};
```

In C++, it is perfectly valid for a struct (or class) to contain a pointer to the same type. This allows the creation of linked data structures like linked lists, trees, etc. The reason this works is that a pointer is simply a reference to a memory location, so the compiler doesn't need to know the complete definition of the struct at the point where the pointer is declared.

>Node* next: next is a pointer to an instance of Node.
 

In a linked list, the next pointer in a Node object is meant to point to another instance of Node, which may or may not exist at the time of the Node's creation. Initially, this pointer is typically set to nullptr to indicate that it doesn't point to any Node yet. When you link nodes together, you set the next pointer to point to the appropriate Node. Hence why the constructure sets the pointer initially to nullptr.

Notice how in the above code we didn´t explicitly declare a constructor. When that happens, the C++ compiler will just use a default constructor, setting the pointer to the its default initialization, which is nullptr.

Here's what it would look like if explicitly declared constructors:

```cpp
struct Node{
public:    
    int data;
    Node* next;

    Node(): data(0), next(nullptr){}
    Node(int data) : data(data), next(nullptr) {}
};
```

At the end of the day, we can choose to use whatever the fuck we want. The most common implementations i've been able to find use dynamic memory to create the instances:

```cpp
struct Node {
    int data;
    Node* next;
};

int main() {
    // Creating Node objects on the heap and initializing manually
    Node* nodePtr = new Node();
    nodePtr->data = 42;
    nodePtr->next = nullptr;

    Node* secondNode = new Node();
    secondNode->data = 15;
    secondNode->next = nullptr;

    // Assigning next pointer of nodePtr to secondNode
    nodePtr->next = secondNode;

    // Accessing and printing values
    std::cout << "Node 1 data: " << nodePtr->data << std::endl;
    std::cout << "Node 2 data: " << nodePtr->next->data << std::endl;

    // Clean up memory (deallocate heap-allocated nodes)
    delete nodePtr;
    delete secondNode;

    return 0;
}

```
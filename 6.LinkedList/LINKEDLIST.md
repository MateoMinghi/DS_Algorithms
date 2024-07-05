<div align="center">
  <h1>Linked Lists</h1>
</div>

### Linked Lists
Linked Lists are linear data structures. Unlike arrays, linked lists use nodes to store elements which are not stored in contiguous memory locations.

#### Nodes

Nodes are the building blocks of Linked Lists. They hold two things: the value or whatever the fuck we want to store, and a reference to the next node.

Such references are exactly what allow Linked Lists to be linear, every node has the address of its succeeding node. That is how each node can access its succeeding node. 
> This means, of course, that the final node in a Linked List (also known as the tail), will ve pointing to Null, since there is no other element to point to. 


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
 

In a linked list, the next pointer in a Node object is meant to point to another instance of Node, which may or may not exist at the time of the Node's creation. Initially, this pointer is typically set to nullptr to indicate that it doesn't point to any Node yet. When you link nodes together, you set the next pointer to point to the appropriate Node. Hence why the constructor sets the pointer initially to nullptr.

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

    // Clean up memory (deallocate heap-allocated nodes)
    delete nodePtr;
    delete secondNode;

    return 0;
}

```

This is necessary to understand Linked List, although I cannot imagine many many scenarios in which we would want to create isntances
of just the node.

Let's hop on to the complete implementation of a Linked List in c++

```cpp
#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
```

Notice how in the example above we don't bother declaring what a single node is going to point to.
We assume that every new instance of Node will have a null pointer, which makes the creation and appending
of Linked Lists very straight-forward. In case we were to insert a node in the middle of the list,
we would update the value of the pointer, so it points to whatever is ahead.

Once we have a class/struct for our nodes, we can create the Linked List (LL). In object-oriented design,
this would be a composition, as multiple nodes make up a single linked list. It's a "has-a" relationship. 

```cpp
class LinkedList {
private:
    Node* head;
    //here we are saying that the variable head will have an adress of a Node.
    //what node? That's irrelevant, we just care that it points to a Node.

public:
    LinkedList() {
        head = nullptr;
        //here we are saying that the head, assuming the list is empty, will point
        //to nullptr. 
    }


    //function to push a node (insert it as the first element)
    void push(int data) {
        Node* newNode = new Node(data); //creating a new node in the heap.
        //such new node will carry a value that we indicate, and will point to nullptr
        //because our Node constructor says so
        newNode->next = head; //here we are accessing the member variable next, and saying that it
        //points to whatever the head is. In the case of inserting the very first node, it will point to 
        //nullptr. In the case of inserting a new head, it will point to the adress of the old head
        //because head is updated in the next line 
        head = newNode; //head is updated and assigned to point to the address of newNode
    }

    //function to append a node (insert it at the end of the list)
    void append(int data) {
        Node* newNode = new Node(data); //creating a new node in the heap
        if (head == nullptr) { //if the pointer head is poiting to nullptr
            //it means that the list is empty
            head = newNode; //head now points to the address of the new node
            //the exact same logic as in the push() function
            return;
        }
        Node* temp = head; //create a new "temporary" pointer called temp
        //temp will point to a Node. In this case, it points to the same adress as the head
        while (temp->next != nullptr) {
            temp = temp->next;
        //in this cycle we say that while it doesn't point to nullptr, it means that
        //we are not at the end of the list, so we are iterating unitl we reach the end
        //Inside the loop, temp is updated to point to the next node in the list (temp = temp->next), 
        //effectively advancing through each node until temp points to the last node.
        }
        temp->next = newNode;
        //Once the loop exits (because temp->next is nullptr), temp now points to the last node in the list.
        //temp->next = newNode; sets the next pointer of this last node to point to newNode, thereby appending newNode at the end of the linked list.
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);
    //list.append(4);
    //list.append(5);
    list.printList();  // Output: 3 2 1 4 5
    return 0;
}

```

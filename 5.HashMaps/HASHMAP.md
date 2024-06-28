<div align="center">
  <h1>Hash Maps</h1>
</div>

Although the terms **Hash Map** and **Hash Table**  are usually used interchangeably, there is a slight difference worth describing.

A Hash Map is an abstract data type that maps keys to values, while a Hash Table is the implementation of such abstract data type.

Leaving formality aside, we can use either term to refer to a data structure that relates a key to a value. In order for that relationship to take place, we utilize hash functions.

<p align="center"><img src="https://github.com/MateoMinghi/DS_Algorithms/blob/main/imgs/hash-table.png"></p>

LeetCode describes hash functions as *"the most important component of a hash table which is used to map the key to a specific bucket."* 
> By a bucket, they essentially mean a slot in the array where the items are stored.

Anyway, when designing a hash function, we should try to follow these principles:
  
* Make use of all info provided by the key
* Uniformly distribute output across the table
* Map similar keys to very different hash values
  
All of these principles have the intention of avoiding collisions, which essentially means assigning two or more values to the same bucket. It's quite hard to come up with algorithms that are completly collision-free, but some examples could be:

- **For numeric keys:** divide the key by the number of available adresses, n, and take the remainder   
- **For alphanumeric keys:** divide the sum of ASCII codes in a key by the number of available adresses, n, and take the remainder

Regardless of the hash function utilized, it must avoid collisions.

We use hash tables over other data structures for several reasons. The nature of a given problem migh incline us to use a hash table if the relationship between keys and values are extremely important, for instance, a student's name and their ID number. 

Aside from that, hash tables are super efficient:

- Modifying an element: O(1)

- Searching for an element: O(n)

- Inserting an element: O(1)
# 42-ft-containers
The standard C++ containers have all a specific usage. To make sure you understand them, let’s re-implement them!

### STL Pocket Reference

The fundamental purpose of a container is to store multiple objects of the same type. Different kinds of containers have different characteristics: speed, size, and ease of use. The choice of container depends on the characteristics and behavior you require.

In C++, the containers are implemented as class templates. The firt template parameter is the type of the object that are to be stored in the container. You can use any type that has value semantics, which means obects must beahve as ordinary values in the same manner as integers or other fundamental types.

Containers types:
- Sequence containers: vector, list, deque, array, forward_list
- Container adaptors: stack, queue, priority_queue
- Associative containers: set, multiset, map, multimap
- Unordered associative containers: unordered_set, unordered_multiset, unordered_map, unordered_multimap

### Sequence containers

**vector**: A vector is like an array, except that the vector can grow as needed. Items can be rapidly added or removed only at the end. At other positions, insertingg and deletin items is slower. Random access to any item is fast. Items are stored contiguously in memory. The header is <vector>

Sequence containers compare objects for equality using the equality operator (==).

### Associative containers

**map**: A map (or dictionary) is an associative container that stores pairs of keys and associated objects. Pairs are stored in ascending order of keys. A map requires unique keys. The header is <map>.

Associative containers compare objects for equivalence, which is slightly different from equality. For example, two strings may be equal, but not equivalent. The equivalence operator is used to compare objects for equivalence.

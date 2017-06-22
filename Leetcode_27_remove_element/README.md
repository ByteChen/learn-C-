## Leetcode
### 27. Remove Element
* 总结：对于vector，需要执行erase操作时，尽量不使用迭代器，而使用下标操作。
* 原因：After erasing or pushing in a vector all the iterators to it may become invalid(if the vector gets reallocated). 
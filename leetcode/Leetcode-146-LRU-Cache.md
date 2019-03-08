---
title: Leetcode 146. LRU Cache
date: 2018-11-21 06:09:31
updated: 2018-11-21 06:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Design and implement a data structure for  [Least Recently Used (LRU) cache](https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU). It should support the following operations:  `get`  and  `put`. `get(key)`  - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1. `put(key, value)`  - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

**Follow up:**  
Could you do both operations in  **O(1)**  time complexity?

**Example:**

> LRUCache cache = new LRUCache( 2 /* capacity */ );
> 
> cache.put(1, 1);
> cache.put(2, 2);
> cache.get(1);       // returns 1
> cache.put(3, 3);    // evicts key 2
> cache.get(2);       // returns -1 (not found)
> cache.put(4, 4);    // evicts key 1
> cache.get(1);       // returns -1 (not found)
> cache.get(3);       // returns 3
> cache.get(4);       // returns 4

**Difficulty**:Medium

**Category**:Design

<!-- more -->

------------

# Analyze

刚开始没看明白要实现什么东西，看了一些LRU缓存器的介绍之后，明白了这就是实现一个LRU(Least Recently Used)最近最少使用的缓存器，这个缓存器有两个函数。

- Get函数
- Put函数

**Get函数**：根据输入`key`获取`value`,如果没有，那么就返回`-1`
这个函数可以分为以下几个小的部分去实现：

- 查找hashmap，如果没有找到就返回-1
- 如果找到这个数值，那就把对应的在`cacheList`里面的元素位置换到List的最前面来，实现最近使用的放在最前面，修改了`cacheList`里面该元素的位置之后，更新`Hashmap`里面的值

**put函数**: 插入一对新的(key, value)，如果原缓存器中有该key，则需要先删除掉原有的，将新的插入到缓存器的顶部。如果不存在，则直接插入到顶部。

- 查找是否当前`cacheMap`里面存在当前元素
- 如果没有当前元素： 就检查是否超过的容量，若加入新的值后缓存器超过了容量，则需要删掉一个最不常用的值, 也就是删除`cacheList`里面的最后一个元素
- 没有当前元素，超出容量的话：删除最少使用的元素; 然后将当前元素插入到`cacheList`的第一个位置，并设置`cacheMap`里面的数值。
- 如果有当前元素：直接通过`Hashmap`修改元素在List里面的数值，并将这个元素转移到List的最前面。

# Solution

```cpp
// Do both operations in O(1) time complexity
class LRUCache {
 public:
  LRUCache(int capacity) { this->capacity = capacity; }

  int get(int key) {
    if (cacheMap.find(key) == cacheMap.end()) return -1;

    // Update the location of the CacheNode(key, value)
    // Trasfer the CacheMap[Key] from the cacheList to the cacheList.begin()
    cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
    cacheMap[key] = cacheList.begin();
    return cacheMap[key]->value;
  }

  void put(int key, int value) {
    // 1. If there is a key in the List, then delete it and insert the new one
    if (cacheMap.find(key) == cacheMap.end()) {
      if (cacheList.size() == capacity) {
        // Delete the last element
        cacheMap.erase(cacheList.back().key);
        // cacheList.erase(cacheList.back());
        cacheList.pop_back();
      }
      cacheList.push_front(CacheNode(key, value));
      cacheMap[key] = cacheList.begin();
    } else {
      cacheMap[key]->value = value;
      cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
    }
    // 2. If there is no key in the list, then insert it and put it to the begin.
    // After insert the element, if the new capacity is over than default capacity,
    // then delete the last one element in the List.
  }

 private:
  struct CacheNode {
    int key;
    int value;
    CacheNode(int k, int v) : key(k), value(v) {}
  };
  list<CacheNode> cacheList;
  unordered_map<int, list<CacheNode>::iterator> cacheMap;
  int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```
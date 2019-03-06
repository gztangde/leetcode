---
title: Leetcode 133. Clone Graph
date: 2019-01-07 09:09:31
updated: 2019-01-07 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

题目大意：无向图的深度复制

Given a reference of a node in a **[connected](https://en.wikipedia.org/wiki/Connectivity_(graph_theory)#Connected_graph)** undirected graph, return a  [**deep copy**](https://en.wikipedia.org/wiki/Object_copying#Deep_copy)  (clone) of the graph. Each node in the graph contains a val (`int`) and a list (`List[Node]`) of its neighbors.

**Example:**

![](https://assets.leetcode.com/uploads/2019/02/19/113_sample.png)

**Input:** `{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4","neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],"val":3}],"val":2},{"$ref":"4"}],"val":1}`

**Explanation:**
Node 1's value is 1, and it has two neighbors: Node 2 and 4.
Node 2's value is 2, and it has two neighbors: Node 1 and 3.
Node 3's value is 3, and it has two neighbors: Node 2 and 4.
Node 4's value is 4, and it has two neighbors: Node 1 and 3.

**Note:**

1. The number of nodes will be between 1 and 100.
2. The undirected graph is a  [simple graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)#Simple_graph), which means no repeated edges and no self-loops in the graph.
3. Since the graph is undirected, if node  _p_ has node  _q_ as neighbor, then node  _q_ must have node  _p_ as neighbor too.
4. You must return the  **copy of the given node**  as a reference to the cloned graph.

**Difficulty**:Medium

**Category**:Depth-First-Search, Breadth-First-Search, Graph

# Analyze

cite:[Clone Graph 克隆无向图](http://www.cnblogs.com/grandyang/p/4267628.html)

**如何处理每一个节点的neighbors**

由于所有的结点都具有不同的数值，所以我们可以使用`HashMap`来对应原图中的结点和新生成的克隆图中的结点。图的遍历的基本方法是 `DFS` 和 `BFS`. 在递归函数中，首先判断是否为空`m.count(node)`，然后再看当前的结点是否已经被克隆过了，若在 `HashMap` 中存在，则直接返回其映射结点。否则就克隆当前结点，并在 `HashMap` 中建立映射，然后遍历当前结点的所有neihbor结点，调用递归函数并且加到克隆结点的 `neighbors` 数组中即可.

# Solution

## Solution 1: DFS

```cpp
class Solution {
 public:
  Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> m;
    return helper(node, m);
  }

 private
  Node* helper(Node* node, unordered_map<Node*, Node*>& m) {
    if (!node) return nullptr;
    if (m.count(node)) return m[node];
    Node* clone = new Node(node->val);
    m[node] = clone;
    for (Node* neighbor : node->neighbors) {
      clone->neighbors.push_back(helper(neighbor, m));
    }
    return clone;
  }
};
```

## Solution 2: BFS--Queue + HashTable

使用BFS来遍历图，使用队列queue进行辅助，还是需要一个HashMap来建立原图结点和克隆结点之间的映射。先克隆当前结点，然后建立映射，并加入queue中，进行while循环。在循环中，取出队首结点，遍历其所有neighbor结点，若不在HashMap中，我们根据 neigbor 结点值克隆一个新 neighbor 结点，建立映射，并且排入queue中。然后将 neighbor 结点在 HashMap 中的映射结点加入到克隆结点的 neighbors 数组中即可

```cpp
class Solution {
 public:
  Node *cloneGraph(Node *node) {
    if (!node) return NULL;
    unordered_map<Node *, Node *> m;
    queue<Node *> q{{node}};

    Node *clone = new Node(node->val);
    m[node] = clone;
    while (!q.empty()) {
      Node *t = q.front();
      q.pop();
      for (Node *neighbor : t->neighbors) {
        if (!m.count(neighbor)) {
          m[neighbor] = new Node(neighbor->val);
          q.push(neighbor);
        }
        m[t]->neighbors.push_back(m[neighbor]);
      }
    }
    return clone;
  }
};
```
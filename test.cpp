class MyCircularDeque {
 public:
  /** Initialize your data structure here. Set the size of the deque to be k. */
  MyCircularDeque(int n) {
    buffer = vector<int>(k, 0);
    cnt = 0;
    k = k;
    front = k - 1;
    rear = 0;
  }

  /** Adds an item at the front of Deque. Return true if the operation is successful. */
  bool insertFront(int value) {
    if (cnt == k) return false;
    buffer[front--] = value;
    front = (front + k) % k;
    ++cnt;
    return true;
  }

  /** Adds an item at the rear of Deque. Return true if the operation is successful. */
  bool insertLast(int value) {
    if (cnt == k) return false;
    buffer[rear] = value;
    rear = (rear + 1) % k;
    ++cnt;
    return true;
  }

  /** Deletes an item from the front of Deque. Return true if the operation is successful. */
  bool deleteFront() {
    if (cnt == 0) return false;
    front = (front - 1) % k;
    return true;
  }

  /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
  bool deleteLast() {
    if (cnt == 0) return false;
    rear = (rear - 1 + k) % k;
    --cnt;
    return true;
  }

  int getFront() {
    return cnt == 0 ? false : buffer[(front + 1) % k];
  }

  int getRear() {
    if (cnt == 0) return false;
    return buffer[(rear - 1 + k) % k];
  }

  /** Checks whether the circular deque is empty or not. */
  bool isEmpty() { return cnt == 0; }

  /** Checks whether the circular deque is full or not. */
  bool isFull() { return cnt == k; }

 private:
  vector<int> buffer;
  int cnt;
  int k;
  int front;
  int rear;
};

class MyCircularQueue {
 public:
  /** Initialize your data structure here. Set the size of the queue to be k. */
  MyCircularQueue(int k) : buffer(k, -1), cnt(0), n(k), front(k - 1), rear(k - 1) {}

  /** Insert an element into the circular queue. Return true if the operation is successful. */
  bool enQueue(int value) {
    if (cnt == n) return false;
    buffer[rear--] = value;
    rear = (rear + n) % n;
    ++cnt;
    return true;
  }

  /** Delete an element from the circular queue. Return true if the operation is successful. */
  bool deQueue() {
    if (cnt == 0) return false;
    front = (front - 1) % n;
    --cnt;
    return true;
  }

  /** Get the front item from the queue. */
  int Front() { return cnt == 0 ? -1 : buffer[front]; }

  /** Get the last item from the queue. */
  int Rear() { return cnt == 0 ? -1 : buffer[(rear + 1) % n]; }

  /** Checks whether the circular queue is empty or not. */
  bool isEmpty() { return cnt == 0; }

  /** Checks whether the circular queue is full or not. */
  bool isFull() { return cnt == n; }

 private:
  vector<int> buffer;
  int cnt;
  int n;
  int front;
  int rear;
};
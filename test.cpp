class Solution {
 public:
  bool isPowerOfFour(int num) {
    int temp = 0b01010101010101010101010101010101;
    return num > 0 && (num & (num - 1)) == 0 && (num & temp) != 0;
  }
};
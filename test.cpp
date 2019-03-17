class Solution {
 public:
  int bitwiseComplement(int N) {
    if (N == 0) return 1;
    s_ = "";
    string num = toBinary(N);
    int right = num.size() - 1;
    int cnt = 1, ans = 0;
  
    for (; right >= 0; --right) {
      if (num[right] == '0') {
        ans += cnt;
      }
      cnt *= 2;
    }
    return ans;
  }

 private:
  string s_;
  string toBinary(int n) {
    s_ = (n % 2 == 0 ? '0' : '1') + s_;
    if (n / 2 != 0) {
      toBinary(n / 2);
    }
    return s_;
  }
};
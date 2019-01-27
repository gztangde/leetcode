
# Question

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

**Example:**
> **Input:** "25525511135"
> **Output:** `["255.255.11.135", "255.255.111.35"]`



# Solution

```cpp
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
      vector<string> res;
      digit_to_ip(s, 4, "", res);
      return res;
    }

    void digit_to_ip(string s, int n, string out, vector<string>& res) {
      // If the n = 0, then this is the last one. Don't do anything.
      if(n==0) {
        if( s.empty() ) res.push_back(out);
        // std::cout << "[INFO] Out=" << out << std::endl;
        // else return false;
      }
      else {  // If n > 0, to get each substring by recursion
        for(int i = 1; i <= 3; ++i) {
          if( s.size() >= i && isVaild( s.substr(0, i))) {
            // std::cout << "[INFO] n =" << n << std::endl;
            if(n == 1) {
              // std::cout<< "[INFO] n == 1"<< std::endl;
              digit_to_ip(s.substr(i), n - 1, out+s.substr(0, i), res);
            } //Deal with the last one
            else digit_to_ip(s.substr(i), n - 1, out+s.substr(0, i)+'.', res);
          }
        }
      }
    }
    // Check the subddr is not more than 255
    bool isVaild(string s) {
      if(s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0') ) return false; 
      int ipsubaddr = atoi(s.c_str());
      return ipsubaddr <= 255 && ipsubaddr >= 0;
    }
};
```
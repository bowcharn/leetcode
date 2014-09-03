/*

A message containing letters from A-Z is being encoded to numbers using the 
following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of
 ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.


A~Z分别对应1~26，现在给定一个数字串，求可能的解码方式数

最多只有两位，因此判断两位是否可以合在一起，和在一起的条件是前一位等于1或2，
当前位小于等于6。
可合并f(n) = f(n-1) + f(n-2) 不能合f(n) = f(n-1)

注意0比较特殊，如果0的前面不是1或2那么无法解码f(n)=0，
如果是那么必须跟前一个合并，即f(n) = f(n-2)

本质是带条件限定的斐波那契数列
*/
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0)
            return 0;
        if(s[0] == '0') //do not forget
            return 0;

        int a = 1;
        int b = 1;

        //f(n) = f(n-1) + judge?f(n-2):0
        for(int i = 1; i < n; i++)
        {
            int prev = s[i-1]-'0';
            int curr = s[i] - '0';
            if(  curr == 0 )
            {
                if(prev != 1 && prev != 2)
                    return 0;
                else
                    b = a;
            }
            else if( prev != 0 && prev*10 + curr <= 26)
            {
                int c = a+b;
                a = b;
                b = c;
            }
            else
            {
                a = b;
            }

        }

        return b;
    }
};


int main()
{
  std::cout<<Solution().numDecodings("29")<<std::endl
	   <<Solution().numDecodings("123")<<std::endl
	   <<Solution().numDecodings("123000004")<<std::endl
	   <<Solution().numDecodings("1111")<<std::endl;

  return 0;
}

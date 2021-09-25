/*
Every non-negative integer N has a binary representation, for example, 8 can be represented as “1000” in binary and 7 as “0111” in binary.

The complement of a binary representation is the number in binary that we get when we change every 1 to a 0 and every 0 to a 1. For example, the binary complement of “1010” is “0101”.

For a given positive number N in base-10, return the complement of its binary representation as a base-10 integer.

*/

#include <iostream>

using namespace std;

class CalculateComplement {
    public:
     static int bitwiseComplement(int n) {
        // TODO: Write your code here
        int complement = n ^ 0xffffffff;
        // Xor'ing with 1's till the leftmost set bit should give us the 
        // complement.
        int leftmostSetbit = 0;
        
        /*for(int i= 1; i < 32 ;i++ )
        {
          mask = 1;
          mask = mask << i;
          if(mask & n)
            leftmostSetbit = i;
        }
        leftmostSetbit += 1; */
        int num = n;
        while(num != 0)
        {
          num = num >> 1;
          leftmostSetbit++;
        }
        //Create a mask to find complement
        int mask = 1;
        mask = 0xffffffff;
        mask = mask << leftmostSetbit ;
        complement = complement ^ mask;
        return complement;
    }
};

int main(int argc, char* argv[]) {
  // your code goes here
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(8) << endl;
  cout << "Bitwise complement is: " << CalculateComplement::bitwiseComplement(10) << endl;
}
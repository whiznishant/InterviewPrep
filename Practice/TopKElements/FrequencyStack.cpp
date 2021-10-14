/*
Frequency Stack (hard)#
Design a class that simulates a Stack data structure, implementing the following two operations:

push(int num): Pushes the number ‘num’ on the stack.
pop(): Returns the most frequent number in the stack. If there is a tie, return the number which was pushed later.
Example:

After following push operations: push(1), push(2), push(3), push(2), push(1), push(2), push(5)

1. pop() should return 2, as it is the most frequent number
2. Next pop() should return 1
3. Next pop() should return 2

*/

/***************  REVISE THIS AGAIN AND AGAIN ********** !!!!!!!!!!!!!!!!!!!!!!!!!!!
 * Awesome Concept, keep pushing the numbers with frequency to the 
 * max heap. so first time lets say we push 1 it is pushed as (1,1), next time if you 
 * push 1 it is pushed as (1,2).  So in the heap there are multiple entries to the same 
 * number with their frequencies
 *
 * 
 */


using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencyStack {
 public: 
  struct compare
  {
    bool operator()( pair<int,pair<int,int>> &lhs, pair<int,pair<int,int>> &rhs )
    {
        if(lhs.second.first == rhs.second.first)   // same frequencies then compare the sequence numbers.
         return lhs.second.second < rhs.second.second;
        
        return lhs.second.first < rhs.second.first;
    }
  };
  int sequenceNumber = 0;
  unordered_map<int,int> freqMap;  //Second part contains frequency and sequence number.
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare> maxHeap;

  virtual void push(int num) {
    // TODO: Write your code here
    freqMap[num] += 1;
    maxHeap.push(make_pair(num, make_pair(freqMap[num],sequenceNumber++)));
  }

  virtual int pop() {
    // TODO: Write your code here
    auto top = maxHeap.top();
    maxHeap.pop();
    if( freqMap[top.first] != 0)
        freqMap[top.first] -= 1;
    return top.first;
  }
};

int main(int argc, char *argv[]) {
  FrequencyStack frequencyStack;
  frequencyStack.push(1);
  frequencyStack.push(2);
  frequencyStack.push(3);
  frequencyStack.push(2);
  frequencyStack.push(1);
  frequencyStack.push(2);
  frequencyStack.push(5);
  cout << frequencyStack.pop() << endl;
  cout << frequencyStack.pop() << endl;
  cout << frequencyStack.pop() << endl;
}

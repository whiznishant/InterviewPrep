using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class MedianOfAStream {
 public:
  priority_queue<int> leftMaxHeap;
  priority_queue<int, vector<int>, greater<int>> rightMinHeap;

  virtual void insertNum(int num) {
    // TODO: Write your code here
    if(leftMaxHeap.size() == 0)
    {
      leftMaxHeap.push(num);
      return;
    }
    int maxNumLeft = leftMaxHeap.top();
    if(num > maxNumLeft)
    {
      rightMinHeap.push(num);
      if(rightMinHeap.size() > leftMaxHeap.size())
      {
         int shiftNum = rightMinHeap.top();
         rightMinHeap.pop();
         leftMaxHeap.push(shiftNum);
      }
    }
    else
    {
      leftMaxHeap.push(num);
      if(leftMaxHeap.size() > rightMinHeap.size() + 1 )
      {
        int shiftNum = leftMaxHeap.top();
        leftMaxHeap.pop();
        rightMinHeap.push(shiftNum);
      }
    }   
  }

  virtual double findMedian() {
    // TODO: Write your code here
    int numElemLeft = leftMaxHeap.size();
    int numElemRight = rightMinHeap.size();
    if(numElemLeft == numElemRight)
    {
       return (leftMaxHeap.top() + rightMinHeap.top())/2.0;
    }
    return leftMaxHeap.top();
  }
};

int main(int argc, char *argv[]) {
  MedianOfAStream medianOfAStream;
  medianOfAStream.insertNum(3);
  medianOfAStream.insertNum(1);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(5);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(4);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
}
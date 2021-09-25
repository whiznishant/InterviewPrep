using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayReader {
 public:
  vector<int> arr;

  ArrayReader(const vector<int> &arr) { this->arr = arr; }

  virtual int get(int index) {
    if (index >= arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};
/**** first attempt :-) *///////////
/*
class SearchInfiniteSortedArray {
 public:
  static int search(ArrayReader *reader, int key) {
    // TODO: Write your code here
    int prevEndIdx = 0;
    int endIdx = 1;
    while(reader->get(endIdx) != numeric_limits<int>::max() )
    {
      prevEndIdx = endIdx;
      endIdx = endIdx*2;
    }
    int s = prevEndIdx,e = endIdx;
    while(s<=e)
    {
      int mid = s + (e-s)/2;
      if(reader->get(mid) != numeric_limits<int>::max() )
        s = mid+1;
      else
        e = mid-1;
    }
    s = 0;
    while(s<=e)
    {
      int mid = s + (e-s)/2;
      if(reader->get(mid)==key)
        return mid;
      if(key > reader->get(mid))
        s = mid + 1;
      else
        e = mid - 1;
    }
    return -1;
  }
};*/

class SearchInfiniteSortedArray {
 public:
  static int bsearch(ArrayReader *reader,int key,int s,int e)
  {
    while(s<=e)
    {
      int mid = s + (e-s)/2;
      if(reader->get(mid) == key)
        return mid;
      if( key > reader->get(mid))
      {
        s = mid+1;
      }
      else
      {
        e = mid -1;
      }
    }
    return -1;
  }
  static int search(ArrayReader *reader, int key) {
    // TODO: Write your code here

    int s = 0,e =1;
    while(key > reader->get(e))  // find the end where the key lies
    {
      s = e;
      e = 2 * e;
    }
    return bsearch(reader,key,s,e); //Do a normal binary search after that .
  }
};


int main(int argc, char *argv[]) {
  ArrayReader *reader =
      new ArrayReader(vector<int>{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
  cout << SearchInfiniteSortedArray::search(reader, 30) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 11) << endl;
  reader = new ArrayReader(vector<int>{1, 3, 8, 10, 15});
  cout << SearchInfiniteSortedArray::search(reader, 15) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 200) << endl;
  delete reader;
}

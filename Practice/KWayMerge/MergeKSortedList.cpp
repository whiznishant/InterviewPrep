using namespace std;

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

/* 

struct minHeapComparator
{
    bool operator()(pair<ListNode*,int> lhs, pair<ListNode*,int> rhs )
    {
      return lhs.first->value > rhs.first->value;
    }
};

class MergeKSortedLists {
 public:
  static ListNode *merge(const vector<ListNode *> &lists) {
    ListNode *resultHead = new ListNode(INT_MIN);
    // TODO: Write your code here
    priority_queue<pair<ListNode *,int>,vector<pair<ListNode *,int>> 
                        ,minHeapComparator>  pq;

    vector<ListNode *> root;
    std::copy(lists.begin(),lists.end(), std::back_inserter(root));
    // populate the priority queue by add all the minimum elements from all 
    // the lists
    for(int listIdx = 0;listIdx < root.size();listIdx++  )
    {
        //Add all list elements to pq;
        if(root[listIdx] != nullptr)
        {
          pq.push(make_pair(root[listIdx],listIdx));
          root[listIdx] = root[listIdx]->next;
        }
    }

    bool merging = true;
    ListNode *curr = resultHead;
    while(!pq.empty())
    {
      pair<ListNode *,int> temp = pq.top();
      pq.pop();
      curr->next = temp.first;
      curr = temp.first;
      curr->next = nullptr;
      if(root[temp.second] != nullptr )
      {
        pq.push(make_pair(root[temp.second],temp.second));
        root[temp.second] = root[temp.second]->next;
      }
    }    
    return resultHead->next;
  }
};*/

struct minHeapComparator
{
    bool operator()(ListNode* lhs, ListNode* rhs )
    {
      return lhs->value > rhs->value;
    }
};

class MergeKSortedLists {
 public:
  static ListNode *merge(const vector<ListNode *> &lists) {
    ListNode *resultHead = new ListNode(INT_MIN);
    // TODO: Write your code here
    priority_queue<ListNode *,vector<ListNode *>,minHeapComparator>  pq;
    vector<ListNode *> root;
    std::copy(lists.begin(),lists.end(), std::back_inserter(root));
    // populate the priority queue by add all the minimum elements from all 
    // the lists
    for(int listIdx = 0;listIdx < root.size();listIdx++  )
    {
        //Add all list elements to pq;
        if(root[listIdx] != nullptr)
        {
          pq.push(root[listIdx]);
          root[listIdx] = root[listIdx]->next;
        }
    }

    ListNode *curr = resultHead;
    while(!pq.empty())
    {
      ListNode *temp = pq.top();
      pq.pop();
      curr->next = temp;
      curr = temp; 
      if(temp->next != nullptr )
      {
        pq.push(temp->next);
      }
    }
    curr->next = nullptr;    
    return resultHead->next;
  }
};

int main(int argc, char *argv[]) {
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(6);
  l1->next->next = new ListNode(8);

  ListNode *l2 = new ListNode(3);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(7);

  ListNode *l3 = new ListNode(1);
  l3->next = new ListNode(3);
  l3->next->next = new ListNode(4);

  ListNode *result = MergeKSortedLists::merge(vector<ListNode *>{l1, l2, l3});
  cout << "Here are the elements form the merged list: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}

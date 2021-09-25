using namespace std;

#include <iostream>

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class ReverseAlternatingKElements {
 public:
  static void reverseXNodesAndSkipX( ListNode *currHead, ListNode **newHead, ListNode **newTail, int x )
  {
      int currIdx = 1;
      ListNode *curr = currHead;
      ListNode *nxt = nullptr;
      ListNode *prev = nullptr;
      while( curr != nullptr )
      {
          nxt = curr->next;
          curr->next = prev;
          if( currIdx % x == 0 )
          {
             break;
          }
          prev = curr;
          curr = nxt;
          currIdx++;
      }
      if( curr == nullptr )
      {
        *newHead = prev;
        *newTail = currHead;
        currHead->next = nullptr;
        return;
      }
      *newHead = curr;
      currHead->next = nxt;
      
      prev = curr;
      curr = nxt;
      currIdx++;
      while(curr != nullptr && currIdx % x != 0 )
      {
          prev = curr;
          curr = curr->next;
          currIdx++;
      }
      if( curr == nullptr )
      {
          *newTail = prev;
      }
      else
      {
          *newTail = curr;
      }
    
  }


  static ListNode *reverse(ListNode *head, int k) {
    // TODO: Write your code here
    ListNode *curr = head;
    ListNode *prevListEnd = nullptr;
    ListNode *currProcListHead = head;
    ListNode *currProcListTail = nullptr;
    ListNode *nextListStart = nullptr;
    while(curr != nullptr)
    {
        reverseXNodesAndSkipX(curr,&currProcListHead,&currProcListTail,k);
        if(prevListEnd == nullptr)
        {
            head = currProcListHead;
        }
        else
        {
            prevListEnd->next = currProcListHead;
        }

        prevListEnd = currProcListTail;
        curr = currProcListTail->next;
    }
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);

  ListNode *result = ReverseAlternatingKElements::reverse(head, 2);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
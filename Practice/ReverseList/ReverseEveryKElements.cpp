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

class ReverseEveryKElements {
 public:
  static ListNode *reverse(ListNode *head, int k) {
    // TODO: Write your code here
    ListNode *curr = head;
    int currIdx = 1;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;
    ListNode *prevListLast = nullptr;
    ListNode *currHead = head;
    while( curr != nullptr )
    {

      next = curr->next;
      curr->next = prev;
      prev = curr;
      if(currIdx % k == 0 || next == nullptr )
      {
        if(prevListLast == nullptr)
          head = curr;
        else
          prevListLast->next = curr;

        prevListLast = currHead;
        currHead = next;
        prev = nullptr;
      }
      curr = next;
      currIdx += 1;
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

  ListNode *result = ReverseEveryKElements::reverse(head, 3);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
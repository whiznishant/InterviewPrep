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

class ReverseSubList {
 public:
  static ListNode *reverse(ListNode *head, int p, int q) {
    // TODO: Write your code here
    int currIdx = 1;
    ListNode *curr = head;
     ListNode *prev = nullptr;
    while( currIdx != p && curr != nullptr )
    {
        prev = curr;
        curr = curr->next;
        currIdx++;
    }
    if(curr == nullptr)
      return head;

    ListNode *left = prev;   

    ListNode *connectToRight = curr;
    prev = nullptr;
    ListNode *next = curr->next;
    while( curr != nullptr && currIdx != q+1)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      currIdx++;
    }
    if(left)
    {
        left->next = prev;
    }
    else
    {
        head = prev;
    }
    connectToRight->next = curr;
    return head;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  ListNode *result = ReverseSubList::reverse(head, 3, 5);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}
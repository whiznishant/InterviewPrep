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

class RearrangeList {
 public:
  static ListNode *reverseList( ListNode *head )
  {
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = nullptr;
    while(curr != nullptr)
    {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
  static void reorder(ListNode *head) {
    // TODO: Write your code here    
    ListNode *fast=head, *slow=head;
    while( fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *second = slow->next;
    slow->next = nullptr;

    second = reverseList(second);
    ListNode *first = head;
    ListNode *firstNext, *secondNext;
    while( first != nullptr || second != nullptr )
    {
      firstNext = first->next;
      secondNext = second->next;
      first->next = second;
      second->next = firstNext;

      first = firstNext;
      second = secondNext;
    }
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);
  head->next->next->next->next->next = new ListNode(12);
  RearrangeList::reorder(head);
  while (head != nullptr) {
    cout << head->value << " ";
    head = head->next;
  }
}

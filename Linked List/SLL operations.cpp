#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;

    Node(int value) {
        data = value;
        next = nullptr;
    }

    Node(int value, Node* nextNode) : data(value), next(nextNode) {}
};


Node* arrayToLL(int arr[], int size) {
  Node* head = new Node(arr[0]);
  Node* p = head;
  for (int i = 1; i < size; i++) {
    Node* temp = new Node(arr[i]);
    p->next = temp;
    p = p->next;
  }
  return head;
}

void printLL(Node *head) {
  Node* p = head;
  while (p != nullptr) {
    cout<<p->data<<" ";
    p = p->next;
  }
}

int lengthOfLL(Node *head) {
  Node* p = head;
  int length = 0;
  while (p != nullptr) {
    length++;
    p = p->next;
  }
  return length;
}

int searchInLL(Node *head, int val) {
  Node* p = head;
  while (p != nullptr) {
    if (p->data == val) return 1;
    p = p->next;
  }
  return 0;
}




Node* removeHead(Node* head) {
  if (head == nullptr)
    return head;
  Node* temp = head;
  head = head->next;
  delete temp;
  return head;
}


Node* removeTail(Node* head) {
  if (head == nullptr) {
    return nullptr;
  }
  if (head->next == nullptr) {
    delete head;
    return nullptr;
  }
  Node*p = head;
  while (p->next->next != nullptr) {
    p = p->next;
  }
  delete p->next;
  p->next = nullptr;
  return head;
}

Node* removeKth(Node* head, int k) {
  if (head == nullptr) {
    return head;
  }
  if (k == 1) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  
  int cnt = 0;
  Node* curr = head;
  Node* prev = nullptr; 
  while (curr != nullptr) {
    cnt++;
    if (cnt == k) {
      prev->next = curr->next;
      delete curr;
      return head;
    }
    prev = curr;
    curr = curr->next;
  }
  return head;
}


Node* removeEle(Node* head, int ele) {
  if (head == nullptr) {
    return head;
  }
  if (head->data == ele) {
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  
  Node* curr = head;
  Node* prev = nullptr; 
  while (curr != nullptr) {
    if (curr->data == ele) {
      prev->next = curr->next;
      delete curr;
      return head;
    }
    prev = curr;
    curr = curr->next;
  }
  return head;
}



Node* insertHead(Node* head, int ele) {
  return new Node(ele, head);
}

Node* insertTail(Node* head, int ele) {
  if (head == nullptr)
    return new Node(ele);
  
  Node* curr = head;
  while (curr->next != nullptr) {
    curr = curr->next;
  }
  Node* temp = new Node(ele);
  curr->next = temp;
  return head;
}


Node* insertPos(Node* head, int val, int k) {
  if (head == nullptr) {
    if (k == 1)
      return new Node(val);
    return head;
  }
  if (k == 1) {
    return new Node(val, head);
  }
  
  
  int cnt = 0;
  Node* p = head;
  while (p != nullptr) {
    cnt++;
    if (cnt = k - 1) {
      Node *temp = new Node(val, p->next);
      p->next = temp;
      return head;
    }
    p = p->next;
  }
  return head;
}


Node* insertBeforeVal(Node* head, int ele, int val, int k) {
  if (head == nullptr) {
    return head;
  }
  if (head->data == val) {
    return new Node(ele, head);
  }
  
  Node* p = head;
  while (p != nullptr) {
    if (p->next->data == val) {
      Node *temp = new Node(ele, p->next);
      p->next = temp;
      return head;
    }
    p = p->next;
  }
  return head;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    //Node* head = nullptr;
    Node* head = arrayToLL(arr, 4);
    //cout<<head->next->next->data;
    
    printLL(head); //1 2 3 4
    cout<<lengthOfLL(head)<<endl; //4
    cout<<searchInLL(head, 3)<<endl; //1
    cout<<searchInLL(head, 7)<<endl; //0
    
    head = removeHead(head);
    printLL(head); //2 3 4 
    
    
    cout<<lengthOfLL(head)<<endl; //3
    head = removeTail(head);
    printLL(head); //2 3 
    cout<<lengthOfLL(head)<<endl; //2
    head = removeTail(head);
    printLL(head); //2
    cout<<lengthOfLL(head)<<endl; //1
    head = removeTail(head);
    printLL(head); //2 3 
    cout<<lengthOfLL(head)<<endl; //0
     
     
   
    head = arrayToLL(arr, 4); //1 2 3 4
    head = removeKth(head, 2);
    printLL(head); //1 3 4
    head = removeEle(head, 3);
    printLL(head); //1 4
    
    head = insertHead(head, 100);
    printLL(head); //100 1 4
    
    head = insertTail(head, 989);
    printLL(head); //100 1 4 989
    
    head = insertPos(head, 555, 2);
    printLL(head); //100 555 1 4 989
    
    head = insertBeforeVal(head, 900, 989, 2);
    printLL(head); //100 555 1 4 900 989
    return 0;
}
#include <iostream>

template<typename T>
struct Node {
  T* data;  // Pointer to any type of data
  Node* prev;
  Node* next;

  Node(T* data) : data(data), prev(nullptr), next(nullptr) {}
  ~Node() { delete data; }  // Cleanup to prevent memory leaks
};

template<typename T>
class DoublyLinkedList {
  public:
    Node<T>* head;
    Node<T>* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void addNode(T* data) {
      Node<T>* newNode = new Node<T>(data);
      if (!head) {
        head = tail = newNode;
      } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
      }
    }

    void removeNode(T* data) {
      Node<T>* temp = head;
      while (temp) {
        if (*(temp->data) == *data) {  // Compare the values pointed to
          if (temp == head && temp == tail) {
            head = tail = nullptr;
          } else if (temp == head) {
            head = head->next;
            head->prev = nullptr;
          } else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
          } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
          }
          delete temp;
          return;
        }
        temp = temp->next;
      }
    }

    ~DoublyLinkedList() {
      while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
      }
    }
};

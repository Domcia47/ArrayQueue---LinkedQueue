#ifndef LINKEDQUEUE_HPP // include guard
#define LINKEDQUEUE_HPP

#include <stdexcept>

template <typename T>
class LinkedQueue {
public:
    LinkedQueue();
    ~LinkedQueue();
 

    void push(T value) {// add a new element to the queue
        Node* newNode = new Node(value);// create a new node
        if (tail == nullptr) { // if tail is a null pointer, head and tail point to the new node
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;// the next pointer of the current tail points to the new node
            tail = newNode;// the new node becomes the tail
        }
        num_elements++; // increment the number of elements
    }

    T pop() {
        if (num_elements > 0) {
           
            T x = head->val;
            Node* ptr = head;
            head = head->next;
            delete ptr; // free memory for the removed node
            if(num_elements==1){// if removing the last element, reset tail and head
                tail=nullptr;
                head=nullptr;
            }
            num_elements--;// decrease the number of elements
            return x;
        } else {
            throw std::out_of_range("LinkedQueue underflow");
        }
    }

    int size() {// returns the number of elements
        return num_elements;
    }

    bool empty() {// checks if the queue is empty
        return size() == 0;
    }
    void clear() {// iterates through all nodes and frees memory
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp; // free memory for the removed node
        }
        tail = nullptr;
        num_elements = 0;
    }

    
private:
    struct Node {
        T val;
        Node* next;
        Node(T val) : val(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int num_elements;
};

template <typename T>
LinkedQueue<T>::LinkedQueue() : head(nullptr), tail(nullptr), num_elements(0) {}
template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear(); // call the clear function to free memory for all nodes
}

#endif


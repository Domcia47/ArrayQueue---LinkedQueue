#define ARRAYQUEUE_HPP

#include <stdexcept>

template <typename T>
class ArrayQueue {
public:  
    ArrayQueue(); // default constructor
    ArrayQueue(int capacity); // constructor with size
    ~ArrayQueue();  
    void push(T value) { // inserts element x into the queue (also enqueue)
        if (num_elements < capacity) { // check if the queue is not full
            data[tail] = value; // assign the value to the array at index tail
            tail = (tail + 1) % capacity; // increment the tail value without going beyond the queue indices
            num_elements++; // increment the number of elements in the queue
        } else
            throw std::out_of_range("ArrayQueue overflow");
    } 
    T pop() {
        if (num_elements > 0) { // check if the queue is not empty
            T x = data[head]; // assign the value from the beginning of the array to a variable
            head = (head + 1) % capacity; // increment the head value without going beyond the queue indices
            num_elements--; // decrement the number of elements in the queue
            return x;
        } else {
            throw std::out_of_range("ArrayQueue underflow");
        }
    } 
    int size() { // returns the number of elements in the queue
        return num_elements;
    } 
    bool empty() { // checks if the queue is empty
        return size() == 0;
    } 
private:
    T* data;
    int head; // index of the first element in the queue 
    int tail; // index under which the next element will be added
    int num_elements; // number of elements in the queue
    int capacity; // capacity of the queue
};

template <typename T>
ArrayQueue<T>::ArrayQueue(int capacity): data(new T[capacity]), head(0), tail(0), num_elements(0), capacity(capacity) {}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] data;
}

template <typename T>
ArrayQueue<T>::ArrayQueue() : data(new T[1000000]), head(0), tail(0), num_elements(0), capacity(1000000) {}

#endif


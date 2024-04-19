#include <iostream>
#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"
//#include "LinkedStack.hpp"


int main(){
    std::ios_base::sync_with_stdio(false);
    
    int n;// variable storing the number of operations
    int x;// variable for reading the number to be placed on the queue
    std::string s;// variable for storing the operation symbol
    std::cin >> n;// read the number of operations
    
    // check if the read value meets the task conditions
    if(n > 1000000){
        std::cout << "Argument out of range." << std::endl;
        return 1;
    }

    
    //ArrayQueue<int> queue(1000000); // create a queue
    LinkedQueue<int> queue;// create a queue
    

    for(int i = 0; i < n; i++){
        std::cin >> s;// read the character corresponding to the operation

        // if 'D' is read, print 'EMPTY' if the queue is empty or print the top element of the queue by calling pop()
        if(s == "D"){
            
            if(queue.empty()) std::cout << "EMPTY" << std::endl;
            else  std::cout << queue.pop() << std::endl;
            
        }
        // if 'S' is read, print the number of elements in the queue by calling the size() method
        else if(s == "S") {
            
            std::cout << queue.size() << std::endl;
        }
        // if 'A' is read, read the next character into variable x and place it in the queue by calling push(x)
        else if(s == "A"){

            std::cin >> x;
            
            queue.push(x);
        }
        // otherwise, the read command is incorrect
        else{
            std::cout << "Błędne polecenie.";
            return 1;
        }
    }
}

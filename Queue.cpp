/* 
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author:
 * Date:
 */
 
#include "Queue.h"


// Description:  Constructor
Queue::Queue() : elementCount(0), capacity(INITIAL_CAPACITY), frontindex(0), backindex(0) {
    this->elements = new int[INITIAL_CAPACITY];
} 
// Description:Queue class destructor
Queue::~Queue() {
    delete[] this->elements; // Remove dynamic memory taken
    this->elements = nullptr;
}
// Description:  Inserts element x at the back (O(1))
void Queue::enqueue(int x) 
{
    if (this->elementCount == this->capacity)
        //If the queue capacity is full, we double the amount of dynamic memory capacity
    {
        int cap = this->capacity * 2;
        int* newelements = new int[cap]; //We make a new array with double capacity
        for (int i = 0; i < this->elementCount; i++)
        {
            newelements[i] = this->elements[this->frontindex];
            this->frontindex = (this->frontindex + 1) % this->capacity; //We pour the data of the previous array into the new array
        }
        this->frontindex = 0;
        this->backindex = this->elementCount;
        delete[] this->elements; // We delete the previous array
        this->elements = newelements; // We put the previous array equal to the new array
        this->capacity = this->capacity * 2; // We double the capacity
    }
    elementCount++;
    elements[backindex] = x;
    backindex = (backindex + 1) % capacity;
} 


// Description:  Removes the frontmost element (O(1))
// Precondition:  Queue not empty
void Queue::dequeue() 
{
    if ((this->elementCount <= (this->capacity / 4)) && ((this->capacity / 2) >= this->INITIAL_CAPACITY))
        //If the amount of data is less than a quarter of the capacity and not less than INITIAL_CAPACITY
    {
        int cap = this->capacity / 2;
        int* newelements = new int[cap]; // We make the new array with half capacity
        for (int i = 0; i < this->elementCount; i++)
        {
            newelements[i] = this->elements[this->frontindex]; 
            //We pour the data of the previous array into the new array
            this->frontindex = (this->frontindex + 1) % this->capacity;
        }
        this->frontindex = 0;
        this->backindex = this->elementCount;
        delete[] this->elements; // We delete the previous array
        this->elements = newelements; // We put the previous array equal to the new array
        this->capacity = this->capacity / 2; // It halves the capacity
    }
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
} 


// Description:  Returns a copy of the frontmost element (O(1))
// Precondition:  Queue not empty
int Queue::peek() const {
    return elements[frontindex];
} 


// Description:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return elementCount == 0;
}





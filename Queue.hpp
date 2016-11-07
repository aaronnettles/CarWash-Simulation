/**
 *  Matthew Hunt
 *  Aaron Nettles
 *  Justin Smith
 *  Christopher Jones
 *
 *  Data Structures with Dr. Zhao
 *  Project 2: Car Wash Simulation
 *  19MAR2016
 */

#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED

template<typename T>
class Queue {

	int counter; // number of elements currently in queue
	int size; // maximum number it can contain

	int back_index; // index of back element
	int front_index; // index of front element

	T *elements; // pointer to array on heap which stores elements

public:

	// constructors
    Queue();

    Queue(int);

    // copy constructor
    Queue(const Queue&);

    // copy assigner
    Queue& operator = (const Queue&);

    // destructor
    ~Queue();

    // determine if queue is empty
    bool empty();

    // determine if queue is full
    bool full();

    // get number of elements of queue
    int number_of_elements();

    // push an item onto queue
    bool push(T);

    // pop an item off queue
    bool pop();

    // get item in back of queue
    T back();

    // get item in front of queue
    T front();

};

// constructors
template<typename T>
Queue<T>::Queue()
    : size(30) // default size of 30
    , counter(0) {

    back_index = size - 1;
    front_index = 0;

    elements = new T[size];
}

template<typename T>
Queue<T>::Queue(int s)
    : size(s)
    , counter(0) {

    back_index = size - 1;
    front_index = 0;
    
    elements = new T[size];
}

// copy constructor
template<typename T>
Queue<T>::Queue(const Queue<T>& q)
    : size(q.size)
    , counter(q.counter) {

    back_index = q.back_index;
    front_index = q.front_index;

    elements = new T[size];
    for(int i = 0; i < size; ++i) {
        elements[i] = q.elements[i];
    }
}

// copy assigner
template<typename T>
Queue<T>& Queue<T>::operator = (const Queue<T>& q) {
    size = q.size;
    counter = q.counter;

    back_index = q.back_index;
    front_index = q.front_index;

    elements = new T[size];
    for(int i = 0; i < size; ++i) {
        elements[i] = q.elements[i];
    }

    return *this;
}

// destructor
template<typename T>
Queue<T>::~Queue() {
    delete [] elements;
    elements = NULL;
}

// determine if queue is empty
template<typename T>
bool Queue<T>::empty() { return counter == 0; }

// determine if queue is full
template<typename T>
bool Queue<T>::full() { return counter == size; }

// get number of elements of queue
template<typename T>
int Queue<T>::number_of_elements() { return counter; }

// push an item onto queue
template<typename T>
bool Queue<T>::push(T item) {
    if(counter < size) { // if there is space for an element
        back_index = (back_index + 1) % size; // use modulation to increment back element index
        elements[back_index] = item; // put item there
        ++counter;

        return true;
    } else {
        return false;
    }
}

// pop an item off queue
template<typename T>
bool Queue<T>::pop() {
    if(counter > 0) {
        front_index = (front_index + 1) % size; // use modulation to increment front element index
        --counter;

        return true;
    } else {
        return false;
    }
}

// get item in back of queue
template<typename T>
T Queue<T>::back() { return elements[back_index]; } // back element is at back index

// get item in front of queue
template<typename T>
T Queue<T>::front() { return elements[front_index]; } // front element is at front index

#endif // QUEUE_HPP_INCLUDED
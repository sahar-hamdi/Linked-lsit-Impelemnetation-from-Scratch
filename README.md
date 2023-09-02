# Linked-list-Impelemnetation-from-Scratch


In this problem, you should develop a linked list class similar to that provided in the C++ STL.
The public interface of your class should provide basic insertion and deletion functions. In
addition, it should provide an iterator class as an inner class in order to access the data stored in
the list. For example, if we have a list of three elements, and want to access the second element,
we should declare an iterator and initialize it to the position of the first element, and move to the
second position as shown in the code below:

list<int> myList;
myList.push_back(1);
myList.push_back(2);
myList.push_back(3);
list<int>::iterator it = myList.begin();
it++;
cout<< *it;

notice the usage of the scope operator in the declaration of the iterator, this is because the
iterator class is defined as an inner class inside the list class:

template<class type>
class myList {
public:
class iterator {
// your code for the iterator class here
};
// your code for the list class here
};

Your list class should be a template class. 

The list class should have the following public interface:


• list() – default constructor. 

• list(type value, int initial_size) – constructs a list having ‘initial_size’
elements whose values are ‘value’. 

• ~list() – a destructor to clear the list and leave no memory leaks.

• int size() – returns the current number of elements in the list. 

• void insert(type value, iterator position) – adds an element at
position specified by the iterator. For example, if the passed iterator currently points to the
second element, this element will be shifted on position, and the new value should be
added at the second position. 

• iterator erase(iterator position) – erases the element specified by the
iterator and return an iterator to the next element, throws exception if position points after
the last element. 

• list<type>& operator = (list<type> another_list) – overloads the
assignment operator to deep copy a list into another list and return the current list by
reference. 

• iterator begin() – returns an iterator pointing to the first element. 

• iterator end() – returns an iterator pointing after the last element. 


You should develop an iterator class the following public interface:

• void operator ++ () – overloads the operator ++, it should advance the iterator one
position towards the end of the list, throws exception if it is currently pointing after the last
element. 

• void operator -- () – overloads the operator --, it should move the iterator one
position toward the beginning of the list, throws exception if it is currently pointing to the
first element of the list.

• type& operator * () – overloads the dereference operator to return the value
contained in the current node by refence to allow its modification. 

• bool operator == (const iterator &) – overloads the equality comparison
operator, should return true if the passed operator points to the same node. 


All node pointers in the list class of the iterator class should be private and inaccessible from
outside of the class. 

No memory leaks or dangling pointers. 

It is highly recommended to implement it as a double linked list, however, it is up to you.
As mentioned above, our .end() function should return an iterator pointing to a position after the
last element as the STL .end() function does. This can be done easily by having a dummy node
after the actual tail, this dummy node contains no data, but mark the end of the list. So,
physically, our list is never empty, which will ease the implementation of insertion and remove
operations, as now we don’t have to handle an “empty list” case. However, this dummy node
should be disregarded when we return the size.

Write a main function to test all the above.

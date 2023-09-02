#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename T>
class MyList {
private:
//class Node.
    class Node{
    public:
        T data;
        Node *next = nullptr;
        Node *prev = nullptr;

    };
    Node *first;
    Node *last;
    int Initial_Size ;
    //dummy node contains no data, but mark the end of the list
    Node *dummy;
public:
    //Class Iterator.
    class Iterator{
    private: friend class MyList<T>;
        Node *itr;
    public:
        // Default Constructor.
        Iterator() {}
        //Parameterized Constructor.
        Iterator(Node *ptr) {
            itr = ptr;
        }
        // ++ prefix operator OverLoading to move from current Node to the next Node.
        void operator++() {
            if(itr->next == NULL)
            {
                //this exception if it is currently pointing after the last element.
                throw "Error! last element exceede";
            }
            itr= itr->next;
        }
        // -- Prefix operator OverLoading.
        void operator--()
        {
            if(itr->prev == NULL || itr == NULL )
            {
                //this exception if it is currently pointing to the first element in the list.
                throw "Error! This is First element";
            }
            itr= itr->prev;

        }
        // * Operator to return value if user Entered *.
        const T& operator* () const {
            return itr->data;
        }
        /*overloads the equality comparison
        operator, should return true if the passed operator points to the same node*/
        bool operator==(const Iterator& another){
            return this->itr == another.itr;
        }
        bool operator!=(const Iterator& another){
            return this->itr->next != another.itr;
        }
    };

    //Default Constructor
    MyList() {
        Initial_Size = 0;
        last = first = dummy = new Node ;


    }

    // Parameterized Constructor.
    MyList(T value, int size){
        first = last = dummy = new Node;
        Initial_Size = 0;
        for(int i = 0 ; i < size ; i++){
            Push_Back(value);
        }
    }
    //a Function to Insert a Node at the begin of the List.
    void Push_Front(T value)
    {
        //Creat New Node(Memory Allocating).
        Node *new_node = new Node ;
        // Assign Data value.
        new_node -> data = value ;
        // Check if the list is empty or not.
        if(Initial_Size == 0){
            first = new_node;
        }
            //if List is Not Empty.
        else{
            first->prev = new_node;
            new_node->next = first;
            first = new_node;
        }
        Initial_Size++;
    }
//a Function to Insert a Node at The End of the List.
    void Push_Back(T value){
        //Alocate memory for the node.
        Node *New_Node = new Node ;
        //Set data to the new_node.
        New_Node->data = value;

        //Check if the list is empty or not.
        if(Initial_Size == 0){
            first = last = New_Node;
            last->next = dummy;
            dummy->prev = last;
        }
            //List is Not Empty.
        else{
            last->next = New_Node;
            New_Node->prev = last;
            last = New_Node;
            New_Node->next=dummy;
            dummy->prev=New_Node;
        }
    Initial_Size++;
    }
    //Insert at position.
    void insertAtPosition(T value, Iterator position)
    {
        if(position.itr == first){
            Push_Front(value);
        }
        else if(position.itr == last){
            Push_Back(value);
        }
        else{
            Node *newNode = new Node;
            newNode->data = value;
            Node *ptr = position.itr;
            newNode->next = ptr;
            ptr->prev->next = newNode;
            newNode->prev = ptr->prev;
            ptr->prev = newNode;
            Initial_Size++;
        }
    }


    // a Function To Display The Elements of the list.
    void Display() {
        if(Initial_Size == 0)
            throw"The list is empty";

        for(Node* cur= first ; cur ; cur=cur->next)
            cout<<cur->data<<" ";
        cout<<'\n';
    }

    //a Function Size that return current number of elements in list.
    int getSize() {
        return Initial_Size;
    }
    //Iterator Erase Function that erases the element specified by the
    //iteratorand return an iterator to the next element
    Iterator Erase(Iterator Position) {
        if(Position.itr == last->next)
        {
            //if position points after the last element.
            throw "Error!Out of list";
        }
        Iterator to_delete ;
        if(Position.itr == first)
        {
            first=Position.itr->next;
            first->prev = nullptr;
        }
        else{
            Position.itr->prev->next = Position.itr->next;
            Position.itr->next->prev = Position.itr->prev;
        }
        to_delete=Position ;
        ++Position;
        delete to_delete.itr ;
        --Initial_Size ;
        return Position;


    }
    /*Assignment Operator(= ) overloads the
    assignment operator to deep copy a list into another listand return the current list by
        reference*/
    MyList& operator=(const MyList& OtherList)
    {
        if(this == &OtherList)
            return *this;
        first = last = NULL;
        for(auto x : OtherList){
            Push_Back(x);
        }

    }



    //Iterator Begin returns an iterator pointing to the first element.
    Iterator begin() const {
        return first;
    }
    //Iterator End returns an iterator pointing after the last element.
    Iterator end() const {
        return last->next;
    }

    //Destructor.
    ~MyList() {
        Node* pointer;
        while (first != NULL) {
            pointer = first;
            first = first->next;
            delete pointer;
        }
    }

};
int main(){
    MyList<int>list;
    list.Push_Back(3);
    list.Push_Back(4);
    list.Push_Back(5);
    list.Push_Front(8);
    auto its = list.begin();
    ++its;
    list.Erase(its);
    for(auto it = list.begin(); it != list.end();++it){
        cout << *it << endl ;
    }
MyList<int>obj = list;
    auto iterat = obj.begin();
    cout << *iterat << endl;
    MyList<int>mylist(1 , 7);
    auto itr = mylist.begin();
    ++itr;
    mylist.insertAtPosition(9 ,itr);
    mylist.Erase(itr);
    for(auto it = mylist.begin(); it != mylist.end();++it){
        cout << *it << endl;
    }
    MyList<int>mine;
    mine = list ;
    for(auto it = mine.begin(); it != mine.end();++it){
        cout << *it << endl;
    }


}
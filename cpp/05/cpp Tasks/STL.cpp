/*STL containers, iterators, algorithms, and functors*/


#include <iostream>
#include<vector>
#include <algorithm>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>
void testVector()
{

//Vectors are dynamic arrays that can grow in size. They support random access and efficient insertion/removal at the end
    std::vector<int> vec={1,4,3,2,5};
    
    //iterating over the vector using an iterator
    std::cout<<"Vector elements : ";
    for(auto it=vec.begin();it !=vec.end(); ++it)
    {
        std::cout << *it <<" ";
    }
    std::cout<<std::endl;


    //Accessing elments
    std::cout <<"First elment in Queue: "<<vec.front()<<std::endl;
    std::cout <<"Last element in Queue: "<<vec.back()<< std::endl;

    //sorting the vector
    std::sort(vec.begin(),vec.end());
    std::cout <<"Sorted vector; ";
    for(const auto &val:vec)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    //Reversing 
    std::reverse(vec.begin(),vec.end());
    std::cout << "Reversed vector: ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    //Removing
    vec.erase(vec.begin() + 1); // Removes the second element
    std::cout << "Vector after erasing the second element: ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

void testDeque(){

//double ended queue
// double-ended queues that allow efficient insertion and deletion at both ends.
    std::deque<int> deq={10,20,30,40,60};

     // Iterating over the Queue
    std::cout << "queue elements: ";
    for (auto it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // Accessing elements
    std::cout << "Deque front: " << deq.front() << std::endl;
    std::cout << "Deque back: " << deq.back() << std::endl;
    //pushing elements to the front and back
    deq.push_front(75);
    deq.push_back(75);
    std::cout << "Deque after pushing: ";
    for (const auto& val : deq) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Popping elements from the front and back
    deq.pop_front();
    deq.pop_back();
    std::cout << "Deque after popping: ";
    for (const auto& val : deq) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

}


void testList()
{
//Lists are doubly-linked lists that allow efficient insertion and deletion of elements from any position.
     std::list<int> lst={111,22,44,333,22,75,21};
     
     //iterating over the list
     std::cout << "List elements: ";
     for(auto it=lst.begin();it !=lst.end();it++)
     {
        std::cout << *it <<" ";
     }
     std::cout << std::endl;
     
    // Inserting elements
    lst.insert(lst.begin(), 50);  // Insert at the beginning
    lst.insert(lst.end(), 550);   // Insert at the end
    std::cout << "List after insertion: ";
    for (const auto& val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;


     // Removing elements
    lst.remove(22);  // Remove all elements with value 300
    std::cout << "List after removing 300: ";
    for (const auto& val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

}


void testSet()
{
//Sets are containers that store unique elements following a specific order.
    std::set<int> set={4,5,4,44,3,2,1,7,9};
    //iterating over the set
    std::cout << "set elements: ";
    for (auto it = set.begin(); it != set.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    //inserting
    set.insert( 6);  
    set.insert( 550); 
    
    std::cout << "Set after insertion: ";

    for (const auto& val : set) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Finding an element
    auto it = set.find(44);
    if (it != set.end()) {
        std::cout << "Element 44 found in the set" << std::endl;
    } else {
        std::cout << "Element 44 not found in the set" << std::endl;
    }
}

void testMap(){
//Maps are associative containers that store elements formed by a combination of a key and a mapped value.
    std::map<char, int> m = {{'o', 1}, {'s', 2}, {'a', 3}};
    // Iterating 
    std::cout << "Map elements: ";
    for (const auto& pair : m) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;
    
    //inserting
    m['d']=4;
    m.insert(std::make_pair('e', 5));
    std::cout << "Map after insertion: ";
    for (const auto& pair : m) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;

    // Accessing elements
    std::cout << "Value for key 'o': " << m['o'] << std::endl;
  
    // Removing an element
    m.erase('a');
    std::cout << "Map after erasing key 'a': ";
    for (const auto& pair : m) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;

}
void testUnorderedSet() {
    std::unordered_set<int> us = {10, 20, 30, 40, 50};

    // Iterating over the unordered set
    std::cout << "Unordered Set elements: ";
    for (const auto& val : us) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Inserting elements
    us.insert(60);
    us.insert(80);
    std::cout << "Unordered Set after insertion: ";
    for (const auto& val : us) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Finding an element
    auto it = us.find(30);
    if (it != us.end()) {
        std::cout << "Element 30 found in the unordered set" << std::endl;
    } else {
        std::cout << "Element 30 not found in the unordered set" << std::endl;
    }
}
void testQueue() {
    //Queues are FIFO (First-In, First-Out) structures
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Queue front: " << q.front() << std::endl;
    std::cout << "Queue back: " << q.back() << std::endl;

    q.pop();
    std::cout << "Queue after popping: Front = " << q.front() << ", Back = " << q.back() << std::endl;
}

void testStack() {
    //stacks are LIFO (Last-In, First-Out) structures
    std::stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);

    std::cout << "Stack top: " << stk.top() << std::endl;

    stk.pop();
    std::cout << "Stack after popping: Top = " << stk.top() << std::endl;
}
void testPriorityQueue() {
    //A priority queue is a type of container adaptor that provides constant time lookup of the largest (by default) element
    std::priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    
    std::cout << "Priority Queue elements (in descending order): ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << std::endl;
}

void testUnorderedMap()
{
 //Unordered maps are hash tables and provide average constant-time complexity for lookup, insertion, and deletion operations.
    std::unordered_map<std::string,int> umap;
    umap["sherief"]=1;
    umap["ahmed"]=2;
    umap["mahmoud"]=3;
    
    //iterating over the unordered map
    std::cout<<"unordered map elements : ";
    for(const auto& pair:umap)
    {
        std::cout <<"{" <<pair.first <<":"<<pair.second <<"}";
    }
    std::cout << std::endl;
     // Accessing an element
    std::cout << "Value for 'mahmoud': " << umap["mahmoud"] << std::endl;

    // Erasing an element
    umap.erase("ahmed");
    std::cout << "Unordered Map after erasing 'ahmed': ";
    for (const auto& pair : umap) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;
}

int main()
{
   // testVector();
   // testDeque();
   // testList();
   //testSet();
   //testMap();
   //testUnorderedSet();
   //testQueue();
   //testStack();
   //testPriorityQueue();
   testUnorderedMap();
    return 0;
}
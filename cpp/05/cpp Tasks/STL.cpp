/*STL containers, iterators, algorithms, and functors*/

#include <cstddef>
#include <iostream>
#include <iterator>
#include <ostream>
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
//#include<tuple>
#include<bitset>
#include <numeric> // For accumulate
#include <utility> // For std::swap




void testVector()
{

//Vectors are dynamic arrays that can grow in size. They support random access and efficient insertion/removal at the end
    std::vector<int> vec={1,3,2,4,3,2,5};
    
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

    //partial sorting
    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());
    std::cout << "Partially sorted vector (first 3 elements): ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

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

    // Removing duplicates (consecutive)
    vec.push_back(1);
    vec.push_back(1);
    auto last = std::unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());
    std::cout << "Vector after removing consecutive duplicates: ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;


    //  Generating a sequence of values
    std::iota(vec.begin(), vec.end(), 3);  // Fills vec with 1, 2, 3, ...
    std::cout << "Vector after iota: ";
    for (int v : vec) {
        std::cout << v << " ";
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


void testMultimapAndMultiset()
{
//Multimaps and multisets are similar to maps and sets but allow duplicate keys
   
    // Multimap
    std::multimap<int, std::string> mmap = {{1, "one"}, {2, "two"}, {1, "uno"}};
    std::cout << "Multimap elements: ";
    for (const auto& pair : mmap) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;

    // Multiset
    std::multiset<int> mset = {1, 2, 4,2, 3, 3, 3};
    std::cout << "Multiset elements: ";
    for (const auto& val : mset) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}




void testPairandTuple()
{
  //Pairs and tuples are useful for storing a collection of values together, especially when they are of different types.
   //pairs
   std::pair<int,std::string> mypair(1,"omnia");
   std::cout <<"pair: {"<< mypair.first <<","<<mypair.second <<"}"<< std::endl;
   //Tuple
   std::tuple<int,std::string,double> myTuple(2,"sherief",3.5);
   std::cout <<"Tuple: {"<< std::get<0>(myTuple)<<","
                         << std::get<1>(myTuple)<< ","
                         << std::get<2>(myTuple)<< "}" <<std::endl;

    
    //modifying a tuple elements
   std::get<1>(myTuple) = "mahmoud";
   std::get<0>(myTuple)=3;
    std::cout << "Modified Tuple: {"
              << std::get<0>(myTuple) << ", "
              << std::get<1>(myTuple) << ", "
              << std::get<2>(myTuple) << "}" << std::endl;
}



void testBitset()
{//std::bitset provides a way to handle a fixed number of bits (binary digits).
    std::bitset<8> bits(42); // 00101010
    std::cout << "Bitset: " << bits << std::endl;
    std::cout << "Bitset with all bits set: " << bits.set() << std::endl;
    std::cout << "Bitset with all bits reset: " << bits.reset() << std::endl;
    std::cout << "Bitset with bit 3 flipped: " << bits.flip(3) << std::endl;

    // Checking individual bits
    std::cout << "Bit 3 is " << (bits[3] ? "set" : "unset") << std::endl;
}


void testStringOperations()
{
    std::string str="omnia ,sherief ";

    //find substring
    size_t found =str.find("omnia");
    if(found != std::string::npos)
    {
        std::cout <<"omnia is found at position : "<<found<<std::endl;
    }

    // Reversing
    std::reverse(str.begin(),str.end());
    std::cout <<"Reversed string" <<str <<std::endl;
    
    //Transform to uppercase
    std::transform(str.begin(),str.end(), str.begin(), ::toupper);
    std::cout << "Uppercase string: " << str << std::endl;
}

void testSetoperations()
{ //STL provides algorithms to perform set operations like union, intersection, and difference.
   std::set<int> set1 ={1,2,3,4,5};
   std::set<int> set2={2,3,4,6,7,8};
   std::vector<int> result;

   //set union
   //it does not repeat numbers
   std::set_union(set1.begin(),set1.end(),set2.begin(),set2.end(),std::back_inserter(result));
   std::cout <<"union of sets: ";
   for(const auto&val: result)
   {
    std::cout <<val<< " ";
   }
   std::cout<< std::endl;
   

   //set insertion
    result.clear();
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(result));
    std::cout << "Intersection of sets: ";
    for (const auto& val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Set Difference
    result.clear();
    std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(result));
    std::cout << "Difference of sets (set1 - set2): ";
    for (const auto& val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

}

void testHeapOperations() {
    //The STL provides functions to work with heaps, which are specialized tree-based data structures that satisfy the heap property

    std::vector<int> heap = {10, 300,20, 30, 5, 15};
    //convert to heap

    std::make_heap(heap.begin(),heap.end());
     std::cout << "Heap after make_heap: ";
    for (const auto& val : heap) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

      // Push a new element onto the heap
    heap.push_back(99);
    std::push_heap(heap.begin(), heap.end());
    std::cout << "Heap after push_heap (99): ";
    for (const auto& val : heap) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Pop the largest element off the heap
    std::pop_heap(heap.begin(), heap.end());
    heap.pop_back();
    std::cout << "Heap after pop_heap: ";
    for (const auto& val : heap) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Sort the heap
    std::sort_heap(heap.begin(), heap.end());
    std::cout << "Heap after sort_heap: ";
    for (const auto& val : heap) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    /*Maintaining the max-heap property means ensuring that, in a max-heap, every parent node is greater than or equal to its child nodes. This property must hold true for the entire heap
    After make_heap: The heap should be something like {300, 30, 20, 10, 5, 15}.
After push_heap(99): The heap should be something like {300, 99, 20, 10, 5, 15, 30}.
After pop_heap: The heap should be something like {99, 30, 20, 10, 5, 15}.
After sort_heap: The final sorted vector should be {5, 10, 15, 20, 30, 99}.*/
}


void testTransformandAccumulate()
{//std::transform and std::accumulate are powerful algorithms for applying operations across ranges.
    std::vector<int> vec={1,2,3,4,5};

    //applying  a transformation
      std::transform(vec.begin(), vec.end(), vec.begin(), [](int x) { return x * 2; });
    std::cout << "Transformed vector (doubled elements): ";
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Accumulating the sum of elements
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum of elements: " << sum << std::endl;

}

void testPermutations()
{//algorithms for generating permutations and combinations of sequences.
      std::vector<int> vec = {1, 2, 3};
//3!=3×2×1=6
    std::cout << "Permutations of {1, 2, 3}:" << std::endl;
    do {
        for (const auto& val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(vec.begin(), vec.end()));
}



void testBoundandBinarySearch()
{//algorithms are useful for searching and working with sorted ranges
    std::vector<int> vec = {1, 2, 4, 3, 5, 6, 8};
    
    //Binary search
    bool found =std::binary_search(vec.begin(),vec.end(),4);
     std::cout << "Element 4 " << (found ? "found" : "not found") << " in the vector." << std::endl;

     // Lower bound (first position where element is not less than 4)
    auto lower = std::lower_bound(vec.begin(), vec.end(), 4);
    std::cout << "Lower bound of 4: " << (lower - vec.begin()) << std::endl;

    // Upper bound (first position where element is greater than 4)
    auto upper = std::upper_bound(vec.begin(), vec.end(), 4);
    std::cout << "Upper bound of 4: " << (upper - vec.begin()) << std::endl;
}


void testUtilities() {
    int a = 5, b = 10;

    // Swap
    std::swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    // Min and Max
    int minVal = std::min(a, b);
    int maxVal = std::max(a, b);
    std::cout << "Min value: " << minVal << ", Max value: " << maxVal << std::endl;

    // Pair
    std::pair<int, int> p = std::make_pair(a, b);
    std::cout << "Pair: {" << p.first << ", " << p.second << "}" << std::endl;
}

int main()
{
   testVector();
   // testDeque();
   // testList();
   //testSet();
   //testMap();
   //testUnorderedSet();
   //testQueue();
   //testStack();
   //testPriorityQueue();
   //testUnorderedMap();
   //testPairandTuple();
   //testBitset();
   //testMultimapAndMultiset();
   //testStringOperations();
   //testSetoperations();
   //testHeapOperations();
   //testTransformandAccumulate();
   //testPermutations();
   //testBoundandBinarySearch();
   //testUtilities();
    return 0;
}

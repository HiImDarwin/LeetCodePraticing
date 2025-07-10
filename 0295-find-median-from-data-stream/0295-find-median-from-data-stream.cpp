class MedianFinder {
  multiset<int> left,right;
  int count;
public:
    MedianFinder() {
      count = 2;
      left.insert(INT_MIN);
      right.insert(INT_MAX);
    }
    
    void addNum(int num) {
      if(count%2 == 0 && num < *right.begin()){
        left.insert(num);
      } else if(count%2 == 0 && num > *left.rbegin()) {
        left.insert(*right.begin());
        right.erase(right.begin());
        right.insert(num);
      }  else if(count%2 == 1 && num < *left.rbegin()) {
        right.insert(*left.rbegin());
        left.erase(--left.end());
        left.insert(num);
      } else {
        right.insert(num);
      }
      count++;
    }
    
    double findMedian() {
      if(count <=2) return 0;
      if(count%2 == 1){
        return *left.rbegin();
      } else {
        return (*left.rbegin()+*right.begin()) / 2.0;
      }
    }
};


/*

even element: left.size() == right.size() 
odd element: left.size() == right.size() +1

[    a] [b    ]
add x

if count == even and x < a
insert in left
if count == even and x > b
x insert right
b insert left
right earse b

if count == odd and x < a
insert in left
right insert a
left earse a

if count == odd and x > b
x insert right


Time complexity is O(n*log n/2) = ( n log n)


Question
1. range of value
2. number of element

*/

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
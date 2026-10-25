#include<bits/stdc++.h>
using namespace std;
#define ll long long int;


main()
{
// Notes
1]  any prime number n can be written as: n = 2a + 3b
    at this time to simplify we can use 3 at one time and other all 2
2] 




    // Basics
    0] int low = 1, high = 100;  // Generates a random number between 1 to 100
        int randomInRange = low + rand() % (high - low + 1); 
    1] sqrt(34); 
    2] pow(3,2);  avoid using power function because it is with O(log n) 
                  in some conditions it is in-accurate.
    3] abs(-10) = 10;
    4] advance(it,3) // move iterator forward by 3
    5] stoi(str)   // string to integer
    6] atoi(str)  // arithmetic to integer 
    7] to_string(num)  // integer or float etc. to string
    8] memset(dp,-1,sizeof(dp));
    9] __gcd(m,n)  // to find GCD
    10] bitset<32>(40); // to find binary of 40
    11] cout<<ceil(5.7) // it will make its round off    because of inaccuracy
    12] ceil(x/4)  instead of this use cout<<((x+3)/4); 
                                       cout<<((x+5)/6); 
    13] !(1) = 0   //logical NOT
    14] auto up = upper_bound(nums.begin(), nums.end(),nums[i]);  //  greater than ( > )
        auto low = lower_bound(nums.begin(), nums.end(), nums[i]); //  greater than or equal to ( >= )
        int index = up-nums.begin();

    15] count_of_digits = (int)(log10(n)+1);  // to find count of digits in a number
    16] // custom comparator
        bool customComparator(const pair<int, int>& a,const pair<int, int>& b){
            return a.second > b.second; // Sort by second element in descending order
        }
        sort(vec.begin(), vec.end(), customComparator);
    17] sort(jobs.begin(), jobs.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
        });
    18] sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (count[a + 100] == count[b + 100])
                return a > b;
            return count[a + 100] < count[b + 100];
        }); 
    19] mid = left + (right - left) / 2;  // prefer this for binary search
    20] ios_base::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);    // to make faster operations
    21] bool is_prime(int x)    // to check whether the number is prime or not
        {
            if (x == 1)
                return 0;
            for (int i = 2; i * i <= x; ++i)
                if (x % i == 0)
                    return 0;
            return 1;
        }
    22] round(5.34);  => 5 // round off
        ceil(5.34); => 6
    23] next permutation
        next_permutation(arr.begin(),arr.end()); // it will change the array to next permutation
    24] int g = rand(); // Generates a random number between 0 and RAND_MAX
    25] cout<<fixed<<setprecision(6)<<ans<<endl;  // 3.1415926535 will print as 3.141593
        return round(number * 1e5) / 1e5;
    26] int mx = max({3,6,2,8});
    





    


    // tuples 
    1] tuple<int,string,double,char> t(20,"girish",2.0,'G');
    cout<<get<0>(t)<<endl;
    v.push_back(make_tuple(a, b, c, d));









    // arrays 
    1] int arr[] = {5, 2, 9, 1, 5, 6};
    2] int n = sizeof(arr) / sizeof(arr[0]);
    3] sort(arr, arr + n);
    4] 







    // Vector
    vector<int> v;
    1] v.insert(v.begin()+2, 45);  // element to insert at specific position (related to first or end position i.e v.begin() or v.end())
    2] v.erase(v.end()-2);  // delete element at specific position (related to first or end position i.e v.begin() or v.end())
        v.erase(v.begin() + index_to_remove);
        v.erase(remove(v.begin(), v.end(), value_to_remove), v.end());
    3] v.size(); // for length of vector 
    4] v.capacity();  // it increase in power of 2 or 4 (which is depend on compiler) i.e 0,1,2,4,8 and it is ( capacity >= size )
    5] v.push_back(34);
    6] v.pop_back(34);
    7] sort(v.begin(),v.end());
    8] auto it = find(v.begin(),v.end(),to_find); then 
        int ans = v.begin() - it;
    9] int sum = accumulate(v.begin(),v.end(),0);
    10] v.resize(4);  // new size of vector
    11] v.clear();  // clear vector
    12] v.sort(v.begin(),v.end());  // sort vector
    13] v.reverse(v.begin(),v.end());  // reverse vector
    14] vector<vector<int>> v(n, vector<int> (m));  // to declare n by m vector i.e vector<vector<int>> v 
    14] vector<vector<int>> v(n, vector<int> ());  // to declare n by 0 vector which is dynamic 
    14] vector<vector<int>> v(n, vector<int> (m,-1));  // fill all values with -1;
    15] count(or_.begin(),or_.end(), to_find_count)  // to find count of any element in vector
    16] is_sorted(vec.begin(), vec.end())  // vector is sorted or not
    17] vector<vector<int>> vis(r, vector<int>(c, 0)); 
    18] arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    19] arr1.emplace_back(10);  // constructs the integer 10 directly in place
        arr1.push_back(n);  // makes a copy of integer 10 and adds it to the vector
    20] arr1.insert(arr1.begin() + 2, 3, 10);  // inserts 3 integers 10 at the 2nd position
    21] arr1.insert(arr1.begin() + 2, arr2.begin(), arr2.end());  // inserts all elements of arr2 at the 2nd position
    22] addition = accumulate(nums.begin(), nums.end() , 0LL);
    23] int mx=*max_element(v.begin(), v.end());  // to find maximmum element
    24] int mn=*min_element(v.begin(), v.end());  // to find maximmum element
    25] next_permutation(s.begin(), s.end());
    26] sort(arr+1, arr+1+n);  // vector<int> arr(n+1);
    sort(arr, arr+n);  // vector<int> arr(n);
    27] iota(v.begin(), v.end(), 1); // fill with 1,2,3,4,5
    28] priority_queue<array<int,3>> pq;
    29] vector<vector<array<int,3>>> v2(2, vector<array<int,3>>(3));
    30] auto up = upper_bound(nums.begin(), nums.end(),nums[i]);  //  greater than ( > )
        auto low = lower_bound(nums.begin(), nums.end(), nums[i]); //  greater than or equal to ( >= )
        int index = up-nums.begin();
    31] int count = distance(it, data.end());
    32] sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (count[a + 100] == count[b + 100])
                return a > b;
            return count[a + 100] < count[b + 100];
        }); 
    33] sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());


    
    // String 
    string str = "Hello World";
    1] str.erase(index,1);  // one character will be removed
    2] str.erase(remove(str.begin(), str.end(), to_remove), str.end());  // to remove all occurances
    // 3] strcmp(str1,str2) // gives value > 0 when str1 is greater (not conform)
    4] getline(cin,str); // to input one line 
    5] str.substr(1,4);   // to get substring str.substr(start_position,length_of_substring)
    6] reverse(str.begin(),str.end());  // to reverse a string
    7] char c1[20] = "girish";
        char c2[20] = "nandanwar";
        strcat(c1,c2);
        cout<<c1<<endl;
    8] int num = 45;
        string str = to_string(num);   // use to change numeric to string
    9] sort(str.begin(),str.end());   // to make characters in lexographical order
    10] int num = stoi(str);   // string to integer
    11] transform(s.begin(),s.end(),s.begin(),::tolower);
    12] if (parentString.find(substring) != -1) cout << "Substring found!" << endl;
            // returns -1 if substring not found 
    13] ans += string(addCount, 'c');   // to add any character no. of times
    14] cout<<parentString.find(substring)  // return at which index substring is present
    15] s.resize(5);  // resize the string
    16] str.erase(1,4);   // to get substring str.erase(start_position,length_to_remove)
    17] bool isPalindrome(const string& s) {
            return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
        }
    18] return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());  // return true if equal otherwise return false
    19] s.find('g') == string::npos   // s.find('g') returns string::npos when it is not present

    
    




    // Queue
    queue<int> q;
    1] q.push(3);
    2] int front = q.front();
    3] q.pop_front();
       or 
       q.pop();
    4] q.push_front(child_v);



    // Deque
    deque<int> dq;
    1] dq.push_back(3);
    2] dq.pop_back();
    3] dq.push_front(3);
    4] dq.pop_front();
    6] dq.front();
       dq.back();
    5] for(int i=0;i<dq.size();i++){
           cout<<dq[i]<<" ";
       }





    // Heap
    priority_queue<int> pq;  // by default it is maxheap i.e top element is greater of all
    // in place of priority queue we can also use multiset
    1] pq.push(3);
    2] pq.pop();
    3] pq.top();
    4] priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap using a comparison function (greater<int>)
    5] struct Compare {
            bool operator()(const pair<int, int>& a,const pair<int, int>& b) const {
                return a.second > b.second; 
            }
        };
    6] priority_queue<pair<char,int>, vector<pair<char, int>>, Compare> pq;
    7] priority_queue<array<int,3>> pq;



    // Stack
    stack<int> s;
    s.push(3);
    s.top();
    s.pop();



        




    // Sets             1] set 2] multiset 3] unordered_set 3] unordered_multiset
    set<int> set1;

    1] set1.insert(30); 
    2] set1.erase(30); // delete by passing value 
    3] set1.erase(set1.begin()); // delete by passing position 
    4] set1.erase(++(set1.begin()),--(set1.end())); // delete from start_position to end position 
    5] advance(it,3) // move iterator forward by 3
    6] set1.max_size() //max no. of elements set can hold
    7] set1.empty()  // retrurs true if empty else false
    8] set1.clear() // removes all elements from set
    9] set1.find() // returns position of element if present, else return end iterator
    10] set1.lower_bound(20) // returns element if present else returns just greater value
    11] set1.upper_bound(20) // returns next greater value
        auto it = st.upper_bound(arr[i].second);
        int index = distance(st.begin(), it);
    12] set<int,greater<int>> set2; // stores values in descending order
    13] set1.count(3) // count no. of occurences of 3 (ususlly used in multisets)
    14] unordered_set<int> s(nums.begin(), nums.end()); // to enter all the values of arrays in unordered_set
        // it is very optimised way to find any element from unordered_set rather than an vector
    15] struct cmp{
            bool operator()(const pair<int,string> &a,const pair<int,string> &b) const{
                if(a.first == b.first) return a.second < b.second; 
                else return a.first > b.first;
            }
        };
        set<pair<int,string>,cmp> s1; 
    16] 




    // Maps         1] map 2] multimap 3] unordered_map 3] unordered_multimap
    map<int,string> map1;

    1] map1.erase(map1.begin());
    2] map1.erase(123);
    3] map1.erase(map1.begin(),map1.end()); // end operator done not get delete
    4] swap(map1,map2)
    5] map1.empty() // returns true if it is empty
    6] map1.size() 
    7] auto it = map1.find(30);   // to find values in map  
        cout<<(*it).second;
        // or 
        cout<<it->second;
    8] map1.upper_bound(20);
    9] map1.lower_bound(20);
    10] map1.clear();  // To remove all elements from a map
    11] 




    // Bit Manipulation 
    1] 4 ^ 5 ^ 4 ^ 2 ^ 5 = 2   //(it cancel out the similar numbers)
    2] // Calculate the number of bits in the number
       int numBits = log2(num) + 1;
    3] bitset<32> bits(40);  // to find binary of 40 in 32 bits
    4] bitset<numBits> bits("101");
       bits.to_ulong()  // binary to decimal
    5] bits.count()  // to count 1's in binary  
    6] ~0 = -1   // bitwise NOT
    7] __builtin_popcount(n) // for integer numbers
    8] __builtin_popcountll(n) // for long long numbers
    9] 


    pair<int,string> p
    1] make_pair(4,"ds"); 





    List

    for Leetcode 
    1] ListNode* newNode=new ListNode(__gcd(x,y), ptr); 

    // STL implimentation of Linked List
    // li.begin() -> iterator for first element 
    // li.end() -> iterator for position after last element
    // li.rbegin() -> iterator for first element in reverse iteration
    // li.rend() -> iterator for position after last element in reverse iteration
    // advance(it,n) -> advances the iterator by two places
    // li.insert(it,value) -> insert value before the position of iterator
    // li.insert(it,count,value) -> insert value count number of times before iterator
    // li.erase(it) -> delete element of iterator
    // li.erase(it_start,it_end) -> delete element from start to end-1 iterator
    // push_front(val) -> insert value in the front of the list 
    // pop_front() -> removes value from front of the list
    // push_back(val) -> insert value in the back of the list
    // pop_back() -> removes value from the back of the list


    list<int> l1 = {1,2,3,4,5};
    // auto itr = l1.begin();
    // cout<<*itr<<endl;
    // advance(itr,2);
    // cout<<*itr<<endl;
    for(auto it = l1.begin();it != l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it = l1.rbegin();it != l1.rend();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    auto it = l1.begin();
    l1.insert(it,50);
    l1.insert(it,60);
    it++;
    l1.insert(it,3,12);
    l1.erase(it);
    for(auto it = l1.begin();it != l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    auto it1 = l1.begin();
    advance(it1,3);
    auto it2 = l1.begin();
    advance(it2,6);
    l1.erase(it1,it2);
    
    for(auto it = l1.begin();it != l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl; 
    auto it3 = l1.begin();
    advance(it3,2);
    l1.erase(it3);
    for(auto it = l1.begin();it != l1.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;


















}

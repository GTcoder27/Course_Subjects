import java.io.*;                // For Input/Output
import java.util.*;              // For Data Structures and Algorithms
import java.math.*;              // For BigInteger and BigDecimal operations
import java.text.*;              // For formatting if needed

// Java Collections Frameworks



Scanner sc = new Scanner(System.in);
int n = sc.nextInt();  // for integer
long x = sc.nextLong();  // for Long
double x = sc.nextDouble();  // for Long
String s=sc.next();  // for single word string
String str=sc.nextLine();  // for complete line string
sc.close();





BasicFunctions 

nums.length   // to find length of array
Math.max(a,b)  // to find max from two elements
Math.min(a,b) // to find min from two elements
Integer.MIN_VALUE , Integer.MAX_VALUE
Math.abs(-2);  // absolute value









Arrays   
  
int numbers[] = new int[5];
int[][] arr = new int[4][3]; //4 rows and 3 cols 
nums.length   // to find length of array
reverseArray(nums);  // to reverse array 
Arrays.sort(nums)  // to sort array
Arrays.sort(arr, Comparator.comparingDouble(o -> o[2]));
Arrays.sort(arr, Comparator.reverseOrder());









ArrayList    

Integer, Boolean, Double, Float, etc..
List<Integer> arr = new ArrayList<>();
List<Integer> arr = new ArrayList<>(n);
ArrayList<ArrayList<Integer>> mainarr = new ArrayList<>(); // for 2D arrays
ArrayList<ArrayList<Integer>> arr = new ArrayList<>(rows); // Set capacity
for (int i = 0; i < rows; i++) {
   arr.add(new ArrayList<Integer>()); // Now the size increases with each add()
}
Collections.sort(res, (a, b) -> b.get(1) - a.get(1));  // for sorting 2D array
arr.add(10);
arr.remove(arr.size()-1); // remove element at 1st index
arr.get(2);  // give value at 2nd index
arr.set(2,6);  // change value of 2nd index to 6
arr.add(2,3); // add value at 2nd index
arr.size(); // gives size of arraylist
Collections.sort(arr); // to sort arraylist in ascending order
Collections.sort(arr, Collections.reverseOrder()); // sort in descending order
Collections.reverse(arr); // reverse arraylist
Collections.sort(jobs, (obj1,obj2) -> obj2.profit-obj2.profit); // sort in descending order









String s = "abc"
String s1 = new String();

str = reverseString(str)  // to reverse string
str = str.trim(); // Trim leading and trailing spaces
String[] words = s.split("\\s+");  // Split the string into words using one or more spaces as a delimiter
str.length() // to find length of String
str.toLowerCase();   
s1.equals(s2)   // return true if string are equal
s1.substring(0,3); // gives substring of the string
s1.compareTo(s2); // returns -ve if s1 < s2, 0 if s1 == s2, +ve if s1 > s2
s1.equalsIgnoreCase(s2);








StringBuilder

1] StringBuilder str = new StringBuilder()
2] str.toString()    // to convert StringBuilder to string
3] str.append("g");    // to append words to StringBuilder like push_back of c++
4] str.length()    // to find length of Stringbuilder
5] char temp = str.charAt(i);    // No inbuild swap function 
   str.setCharAt(i, str.charAt(j));
   str.setCharAt(j, temp);
6] Character.toLowerCase(str.charAt(index));   // to convert to lower case a character only   
7] str.charAt(index) // str[index] is not valid here
8] str.toLowerCase();  // to convert whole string to lower case
9] Character.toUpperCase(str.charAt(index)); // convert to upper case a character only








Bit Manipulation 

1] & // and operator
2] | // and operator
3] ^ // xor operator
4] << // left shift 
5] >> // right shift 
6] ~ // negation








Stack  

1] Stack<Integer> st = new Stack<>(); 
   Deque<Integer> st = new ArrayDeque<>(); // for better performance
2] st.push(20);
3] st.pop(); 
4] st.peek(); // gives top element
5] st.isEmpty(); // returns true if stack is empty
6] st.search(20); // Returns position from top (-1 if not found)
7] st.size(); // Returns number of elements






Queue 

1] Queue<Integer> q = new ArrayDeque<>(); // for better performance 
   Queue<Integer> q = new LinkedList<>(); 
2] q.add(20);  
3] q.peek(); // front element of queue 
4] q.remove(); // to remove front element of queue
5] q.size(); 
6] q.isEmpty();   






Priority Queue

1] PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder()); // max heap
2] pq.add(1);
3] pq.remove(); // removes and returns the head of the queue
4] pq.peek();  






Deque

Deque<Integer> dq = new ArrayDeque<>(); // for better performance
Deque<Integer> dq = new LinkedList<>(); 
dq.addFirst(1);  
dq.addLast(1);  
dq.removeFirst();
dq.removeLast(); 
dq.getFirst(1);  
dq.getLast(1);  
dq.peekFirst();
dq.peekLast();
dq.isEmpty();
dq.size();
 








Set 

Set<Integer> s = new HashSet<>();
s.add(10);
s.remove(10);
s.contains(10);
s.size();
s.isEmpty();
s.clear();




Map

Map<String, Integer> m = new HashMap<>();
m.put("A", 10);
m.putIfAbsent("B", 20);
m.get("A");
m.getOrDefault("C", 0);
m.remove("A");
m.containsKey("A");
m.containsValue(10);
m.size();
m.isEmpty();
m.clear();









LinkedList

1] List<Integer> ll = new LinkedList<>();
2] ll.add(30); // add to end of list
3] ll.addLast(20);  // add to last of linked list
4] ll.addFirst(10); // add at start of linked list
5] ll.removeFirst(); // remove first element from list
6] ll.removeLast(); // remove last element from list
7] Collections.reverse(ll); // to reverse list
8] Collections.reverse(ll.subList(mid, ll.size())); // Reverse second half
9] ll.get(ll.size() / 2);  // gives middle element
10] ll.size()  // give size of linked list
11] ll.subList(mid, ll.size);  // gives subList like subarray or substring
12] 













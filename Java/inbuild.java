import java.util.*;
import java.io.*;
import java.math.*;

/*
========================
📌 INPUT METHODS
========================
*/

// Scanner (easy but slower)
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
long l = sc.nextLong();
double d = sc.nextDouble();
sc.nextLine();
String s = sc.next();        // single word
String str = sc.nextLine();  // full line
sc.close();

// BufferedReader (fast input)
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
int x = Integer.parseInt(br.readLine());
String[] parts = br.readLine().split(" ");


/*
========================
📌 BASIC FUNCTIONS
========================
*/

Math.max(a,b);
Math.min(a,b);
Math.abs(-5);
Math.sqrt(16);
Math.pow(2,3);
Math.ceil(2.3);
Math.floor(2.9);
Math.round(2.5);

Integer.MAX_VALUE;
Integer.MIN_VALUE;
Long.MAX_VALUE;
Long.MIN_VALUE;


/*
========================
📌 ARRAYS
========================
*/

int[] arr = new int[5];
int[][] matrix = new int[3][4];

arr.length;

Arrays.sort(arr);
Arrays.binarySearch(arr, 5);
Arrays.fill(arr, 0);
Arrays.copyOf(arr, arr.length);

System.out.println(Arrays.toString(arr));

// 2D array sorting
Arrays.sort(matrix, (a,b) -> a[1] - b[1]);


/*
========================
📌 ARRAYLIST
========================
*/

List<Integer> list = new ArrayList<>();
List<Integer> list = new ArrayList<>(Collections.nCopies(10, 0)); 
List<List<Integer>> g = Stream.generate(ArrayList<Integer>::new)
                              .limit(n)
                              .collect(Collectors.toCollection(ArrayList::new));
or 
List<List<Integer>> g = new ArrayList<>();
for(int i=0;i<n;i++){
    g.add(new ArrayList<>());
}

list.add(10);
list.add(1, 20);
list.get(0);
list.set(0, 100);
list.remove(0);
list.size();
Collections.sort(list);
Collections.reverse(list);
Collections.max(list);
Collections.min(list);


/*
========================
📌 STRING
========================
*/

String s1 = "hello world";

s1.length();
s1.charAt(0);
s1.substring(0,5);

s1.contains("world");
s1.startsWith("he");
s1.endsWith("ld");

s1.replace("l","x");
s1.toUpperCase();
s1.toLowerCase();

String[] words = s1.split(" ");
String joined = String.join("-", words);

s1.equals("hello");
s1.equalsIgnoreCase("HELLO");


/*
========================
📌 STRINGBUILDER
========================
*/

StringBuilder sb = new StringBuilder("hello");

sb.append(" world");
sb.insert(5, "!");
sb.delete(0,2);
sb.reverse();

sb.toString();


/*
========================
📌 BIT MANIPULATION
========================
*/

a & b;
a | b;
a ^ b;
a << 1;
a >> 1;
~a;

// check power of 2
(n & (n - 1)) == 0;


/*
========================
📌 STACK (USE DEQUE)
========================
*/

Deque<Integer> st = new ArrayDeque<>();

st.push(10);
st.pop();
st.peek();
st.isEmpty();


/*
========================
📌 QUEUE
========================
*/

Queue<Integer> q = new ArrayDeque<>();

q.add(10);
q.poll();
q.peek();
q.isEmpty();


/*
========================
📌 PRIORITY QUEUE
========================
*/

PriorityQueue<Integer> minHeap = new PriorityQueue<>();
PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

minHeap.add(5);
minHeap.poll();
minHeap.peek();


/*
========================
📌 DEQUE
========================
*/

Deque<Integer> dq = new ArrayDeque<>();

dq.addFirst(10);
dq.addLast(20);

dq.removeFirst();
dq.removeLast();

dq.peekFirst();
dq.peekLast();


/*
========================
📌 SET
========================
*/

Set<Integer> set = new HashSet<>();

set.add(10);
set.remove(10);
set.contains(10);

// sorted set
Set<Integer> tree = new TreeSet<>();


/*
========================
📌 MAP
========================
*/

Map<String, Integer> map = new HashMap<>();

map.put("A",1);
map.putIfAbsent("B",2);

map.get("A");
map.getOrDefault("C",0);

map.containsKey("A");

for(String key : map.keySet()){
    System.out.println(key + " " + map.get(key));
}


/*
========================
📌 LINKED LIST
========================
*/

LinkedList<Integer> ll = new LinkedList<>();

ll.addFirst(10);
ll.addLast(20);

ll.removeFirst();
ll.removeLast();

ll.getFirst();
ll.getLast();


/*
========================
📌 COLLECTION UTILITIES
========================
*/

Collections.sort(list);
Collections.reverse(list);
Collections.shuffle(list);

Collections.frequency(list, 10);
Collections.binarySearch(list, 10);


/*
========================
📌 STREAMS (ADVANCED)
========================
*/

List<Integer> nums = Arrays.asList(1,2,3,4,5);

nums.stream()
    .filter(x -> x % 2 == 0)
    .forEach(System.out::println);

int sum = nums.stream().mapToInt(Integer::intValue).sum();


/*
========================
📌 HELPER FUNCTIONS
========================
*/

// GCD
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

// LCM
int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

// Reverse Array
void reverse(int[] arr){
    int l = 0, r = arr.length - 1;
    while(l < r){
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++; r--;
    }
}

// Fast Power
long power(long a, long b){
    long res = 1;
    while(b > 0){
        if((b & 1) == 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
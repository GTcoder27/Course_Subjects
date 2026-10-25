# ===============================
#   PYTHON COMPETITIVE NOTES
# ===============================
arr = list(map(int, input("Enter numbers: ").split()))
print("Array:", arr)


# -------------------------------
# Basics
# -------------------------------
1] import math, random, collections, itertools, heapq, bisect, functools
2] abs(-10) → 10
3] pow(2, 5, 13) → (2^5 mod 13) = 6
4] round(5.7) → 6
5] math.ceil(5.2) → 6
6] math.floor(5.9) → 5
7] math.sqrt(49) → 7.0
8] random.randint(1, 100)  # random number [1,100]

9] divmod(17, 3) → (5, 2)  # quotient, remainder
10] bin(40) → '0b101000'
11] oct(40) → '0o50'
12] hex(40) → '0x28'
13] isinstance(x, int)  # type check
14] a, b = divmod(sum(arr), len(arr))  # mean split

# -------------------------------
# Strings
# -------------------------------
s = "Hello World"
1] s[::-1]  # reverse string
2] s.upper() / s.lower()
3] s.find("World") → 6
4] s.replace("Hello", "Hi")
5] s.split() → ['Hello','World']
6] " ".join(["Hi","there"]) → "Hi there"
7] s.isdigit(), s.isalpha(), s.isalnum()
8] s.count("l") → 3
9] "".join(sorted("dcab")) → 'abcd'
10] s.startswith("He"), s.endswith("ld")
11] s.strip() → removes spaces
12] s.index("o") → 4

# -------------------------------
# Lists
# -------------------------------
arr = [5, 2, 9, 1, 5, 6]
1] arr.sort()
2] arr.reverse()
3] arr.append(10)
4] arr.pop() / arr.pop(2)
5] arr.remove(9)  # first occurrence
6] arr.index(5)  # position of first 5
7] arr.count(5) → 2
8] sum(arr), max(arr), min(arr)
9] arr[1:4]  # slicing
10] arr1 + arr2 → concatenation
11] [x*x for x in arr] → list comprehension
12] sorted(arr, reverse=True)
13] any(arr), all(arr)  # truth check
14] arr.copy(), arr.clear()
15] arr.sort(key=lambda x: -x)  # custom sort
16] arr.insert(2, 100)  # insert at index

# -------------------------------
# Tuples
# -------------------------------
t = (1, "hi", 3.4)
1] t[0] → 1
2] len(t)
3] t.count(1), t.index("hi")
4] a, b, c = t  # unpacking
5] tuple([1,2,3])  # list → tuple

# -------------------------------
# Dictionaries
# -------------------------------
d = {"a": 1, "b": 2}
1] d.keys(), d.values(), d.items()
2] d["a"] → 1
3] d.get("c", 0) → 0
4] d.pop("a"), del d["b"]
5] d.update({"c": 3})
6] {x: x*x for x in range(5)}  # dict comprehension
7] from collections import defaultdict
   dd = defaultdict(int)
   dd["x"] += 1
8] from collections import Counter
   Counter("aabbbc") → {'a':2,'b':3,'c':1}


# -------------------------------
# Sets
# -------------------------------
s1 = {1,2,3}
s2 = {3,4,5}
1] s1 | s2 → union
2] s1 & s2 → intersection
3] s1 - s2 → difference
4] s1.add(10), s1.remove(2)
5] 3 in s1 → True
6] s1.clear(), s1.pop()
7] {x for x in range(10) if x%2==0}  # comprehension

# -------------------------------
# Queue / Stack / Deque
# -------------------------------
Stack
append(x) → Push element to stack
pop() → Pop (remove) element from stack
stack[-1] → Peek (top element without removing)


from queue import Queue
q = Queue()
q.put(1), q.get()



# -------------------------------
# Heap (Priority Queue)
# -------------------------------
import heapq
arr = [5,1,8,3]
heapq.heapify(arr)   # min-heap
heapq.heappush(arr,0)
heapq.heappop(arr)
# max heap
maxheap = []
heapq.heappush(maxheap, -10)
val = -heapq.heappop(maxheap)

# -------------------------------
# Itertools
# -------------------------------
import itertools as it
1] list(it.permutations([1,2,3]))
2] list(it.combinations([1,2,3],2))
3] list(it.product([1,2],[3,4]))
4] it.accumulate([1,2,3]) → [1,3,6]
5] it.groupby("aaabbc")

# -------------------------------
# Bisect (Binary Search Utils)
# -------------------------------
import bisect
arr = [1,2,4,4,5]
1] bisect.bisect_left(arr, 4) → 2
2] bisect.bisect_right(arr, 4) → 4
3] bisect.insort(arr, 3)  # insert keeping sorted

# -------------------------------
# Math
# -------------------------------
import math
1] math.gcd(24,36) → 12
2] math.lcm(4,6) → 12
3] math.factorial(5) → 120
4] math.log(100,10) → 2
5] math.pi, math.e, math.inf

# -------------------------------
# Random
# -------------------------------
import random
1] random.randint(1,10)
2] random.choice([1,2,3])
3] random.shuffle(arr)
4] random.sample(arr, 2)

# -------------------------------
# Functions / OOP
# -------------------------------
1] def func(a,b=0,*args,**kwargs): pass
2] lambda x: x*x
3] class A:
       def __init__(self,val): self.val=val
       def show(self): print(self.val)
4] class B(A):  # inheritance
       def show(self): super().show()

# -------------------------------
# Useful Tricks
# -------------------------------
1] nums = list(map(int,input().split()))
2] from functools import lru_cache
   @lru_cache(None) def f(x): ...
3] enumerate(arr) → (index, value)
4] zip([1,2],[3,4]) → [(1,3),(2,4)]
5] sorted(d.items(), key=lambda x: x[1])  # sort by value
6] any(cond for x in arr), all(cond for x in arr)
7] try: ... except: ...
8] with open("file.txt") as f: data=f.read()




string
1] fruit = "Mango tasty"
2] mangoLen = len(fruit)
3] a = "!!!Hello Harry Harry!!!"
   print(a.strip("!"))
   output = "Hello Harry Harry"
4] print(a.replace("Harry", "John"))
5] print(a.split(" "))
6] print(a.count("Harry"))
7] print(a.find("ha"))  # return -1 if not found , return index if found
8] print(str1.startswith("Python")) 
9] print(str1.endswith("Python"))
10] print(str1.swapcase())  # change uppercase to lower and lowercase to uppercase







list 
1] Ordered collection of items.
2] Mutable → you can change, add, or remove elements.
3] Can store duplicate values.
4] Access by index (position).
5] list1 = [8, 2.3, [-4, 5], ["apple", "banana"]]
6] list1.append("orange")
7] n = int(input())
   arr = list(map(int, input().split()))   # take input list
8] my_list.reverse()





tuple
1] Ordered collection of items.
2] Immutable → once created, you can’t change, add, or remove elements.
3] Can store duplicate values.
4] Access by index.
tuple1 = (("parrot", "sparrow"), ("Lion", "Tiger"))




dictionary   # 
1] Unordered (in Python 3.7+, it remembers insertion order but doesn’t rely on index).
2] Mutable → can add, change, or remove items.
3] Stores key–value pairs (like a real dictionary: word = meaning).
4] Keys must be unique and immutable (string, number, tuple, etc.), values can be anything.
5] Access by key.
6] dict1 = {"name":"Sakshi", "age":20, "canVote":True}
7] ep1.clear()
8] ep1.pop(122)
9] ep1.popitem()
10] del ep1[122]





set
1] info = {"Carla", 19, False, 5.9, 19}
2] if "Carla" in info:
      print("Carla is present.")






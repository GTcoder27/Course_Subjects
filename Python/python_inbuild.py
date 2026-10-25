import math
import random
import bisect
import heapq
from collections import deque, Counter, defaultdict
from itertools import permutations



# ============================================================
# basic
# ============================================================
random_number = random.randint(1, 10) # gives value in int 
random_number = random.uniform(1, 10) # gives value in float
abs(-10)            # absolute value
s = str(123)        # to string 
math.sqrt(34)       # sqrt
math.ceil(5.34)                 # 6
round(5.34)                     # 5
round(5.000988979, 5)           # round to 5 decimal places
print(f"{ans:.5f}")             # round to 5 decimal places              
num = int("123")    # string to integer
math.gcd(12, 18)
pow(3, 2) or 3 ** 2 # power
dp = [-1] * 10          #  not recommended make array dp[10] with all -1
dp = [[0 for _ in range(5)] for _ in range(5)]   # for 2d array
bin(40)                          # '0b101000'  # Binary representation
format(40, '032b')               # 32-bit binary 
(9 / 4)             # gives 2.25
(9 // 4)            # gives 2
not True            # False
print("yes") if (a > b) else print("NO")
double = lambda x : x*2    # lambda function
print(double(5))
pip freeze > requirements.txt  # to include all installed packeages in requirements.txt
(a == b) # compare values
(a is b) # compare location of objects in memory
def func(*args,**kwargs)   
# *args take all arguments as tuple 
# ** kwargs take all arguments as dictionary as key value pair 
# for competitive programming
import sys
input = sys.stdin.readline      # fast input
sys.stdout.write("Hello\n")     # fast output
count_ones = bin(40).count('1')     # count 1s in binary




# ============================================================
# list
# ============================================================
arr = [2,45,6,7,12]
arr = [i*i for i in range(5)]                   # list comprehension
arr = [i*i for i in range(5) if (i%2 == 0)]     # list comprehension
low_index = bisect.bisect_left(arr, 2)          # lower bound
up_index = bisect.bisect_right(arr, 2)          # upper bound
arr.sort(key=lambda x: x[1], reverse=True)      # sort by second element 
arr.reverse()
arr.remove(45)  # remove by value
del arr[1]      # remove by index
del arr[0:3]    # remove by range
arr.clear()     # remove all elements
arr.append(3)
arr.count(7)
arr.insert(1,4)
arr2 = arr.copy()
arr.extend(arr2)         # add arr2 to arr and join both list (give 1d list)
arr.append(arr2)         # give 2d list
arr.index(2)             # gives error if not present
arr2 = list(map(cube,arr))   # map(function,array) function will apply for every element in list
def filter_function(a):
    return a > 5
arr2 = list(filter(filter_function,arr)) # gives all values > 5 from arr
for p in permutations(arr):      # finding permutations 
    print(p)








# ============================================================
# string
# ============================================================
str = "Hello World !"
len(str)
str.upper()
str.lower()
str.replace("Hello", "Hi")
str.rstrip("!")
arr = str.split(",")
str.capitalize()
str.count("o")
str.find("orl")                 # -1 if not found
str.index("orl")                # gives error if not found
str.isalnum()                   # alfanumeric or not
str.isspace()                   # space is present or not
str.startswith("Hell")          # gives true or false
str.endswith("!")               # gives true or false
print(f"my name is {name}")     # we can include variable values
print(square.__doc__)           # it will print the doc string of square function
                                # doc string is like -> '''square function'''



# ============================================================
# tuple
# ============================================================
# many same as list
t = (2,4,6,7,4,3,2,2,3)
t.index(2,3,7)          # find element in range t.index(element,start,end)





# ============================================================
# set
# ============================================================
# It is unordered 
st = {2,3,4}
st1 = {2,34,54,4}
st2 = {3,False,"girish",9,0}
st1.update(st2)             # st2 values will add to st1
st1.union(st2)              # All values from st1 and st2
st1.intersection(st2)       # common values from st1 and st2
st1.symmetric_difference(st2) # non common values i.e ~(st1 intersection st2) 
st1.difference(st2)         # st1 - st2 
st.add(3)                   # add element
st.remove(3)                # gives error if not present
st.discard(3)               # no error if not present
st.pop()                    # pop any random element
del st                      # delete set
sorted_st = sorted(st)      # sorted set


# ============================================================
# MULTISET
# ============================================================
ms = []
ms.extend([1, 1, 2, 3, 3])
ms.sort()
count = ms.count(3)
freq = Counter(ms)      # Better for frequency:
print(freq[3])


# ============================================================
# dictonary
# ============================================================
# after python 3.7 dictonary were in ordered format
dict = { 32:"d" , 45:"r" , 67:"t"}
dict2 = { 2:"y" , 9:"h"}
dict.keys()         # all keys 
dict.values()       # all values 
dict.clear()
dict.update(dict2)  # dict2 will added to dict
dict.pop(32)        # delete entery 32
dict.popitem()      # delete last entry
del dict 
for key,value in dict.items():  
    pass





# ============================================================
# file handling 
# ============================================================
f = open("myfile.txt","w")  # write mode
f.write("hello \n")     
f = open("myfile.txt","a")  # append mode
f.write("hello \n")         # it will append
f = open("myfile.txt","r")  # read mode 
f = open("myfile.txt","rt")  # read as text file
f = open("myfile.txt","rb")  # read as binary file 
text = f.read()
text = f.read(5)        # read only 5 charactes
f.close()

with open("myfile.txt","a"):  # don't have to close file 
    f.write("added")

while True:                 # read lines one by one
    line = f.readline() 
    if not line:
        break
    print(line)

lines = ["line1 \n","line2 \n","line3 \n"]
f.writelines(lines)           # write lines one by one

with open("myfile.txt","r"): 
    f.seek(10)            # skip 10 characters
    print(f.tell())      # gives 10 (tells on which position we are now)
    data = f.read()    # read whole file after 10 characters
f.truncate(5)    # resize the file to only 5 charactes (other content will get deleted)







# ============================================================
# QUEUE and DEQUE
# ============================================================
dq = deque()
dq.append(3)        # add to back
dq.appendleft(3)    # add left
dq.pop()            # pop right
dq.popleft()        # pop left
front = dq[0]   
back = dq[-1]
for x in dq:
    print(x)



# ============================================================
# HEAP / PRIORITY QUEUE
# ============================================================
# Python heapq is MIN HEAP by default.
# it is sorted based on tuples elements order (priority1, priority2)
pq = []
heapq.heappush(pq, 3)   # push
heapq.heappop(pq)       # pop smallest
top = pq[0]             # top

# Python has no direct max heap.
# we have to store negative values.

max_heap = []
heapq.heappush(max_heap, -3)
heapq.heappush(max_heap, -10)
maximum = -heapq.heappop(max_heap)
heapq.heappush(pq, (5, 10))




# ============================================================
# STACK
# ============================================================
# Python list works as a stack.
s = []
s.append(3)     # push
top = s[-1]     # top
s.pop()         # pop
if not s:       # empty or not



# ============================================================
# Linked List
# ============================================================
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
node = ListNode(10)
head = ListNode(10, next_node)    # create node with next
next_node = head.next

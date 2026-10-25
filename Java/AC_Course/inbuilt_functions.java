import java.io.*;                // For Input/Output
import java.util.*;              // For Data Structures and Algorithms
import java.math.*;              // For BigInteger and BigDecimal operations
import java.text.*;              // For formatting if needed


Basic Functions 

1] nums.length   // to find length of array
2] Math.max(a,b)  // to find max from two elements
3] Math.min(a,b) // to find min from two elements
4] Integer.MIN_VALUE , Integer.MAX_VALUE
5] 









Arrays   int[] numbers = new int[5]; 
  

1] nums.length   // to find length of array
2] reverseArray(nums);  // to reverse array 
3] Arrays.sort(nums)  // to sort array
4] 
5] 
6] 






ArrayList    

1] ArrayList<Integer> list = new ArrayList<>();
2] ArrayList<Integer> list = new ArrayList<>(n);
   ArrayList<ArrayList<Integer>> mainlist = new ArrayList<>(); // for 2D arrays
3] Integer, Boolean, Double, Float, etc..
4] list.add(10);
5] list.remove(1); // remove element at 1st index
6] list.get(2);  // give value at 2nd index
7] list.set(2,6)  // change value of 2nd index to 6
8] list.add(2,3); // add value at 2nd index
9] list.size() // gives size of arraylist
10] Collections.sort(list); // to sort arraylist in ascending order
11] Collections.sort(list, Collections.reverseOrder()); // sort in descending order
12] 










String s = "abc"
String s1 = new String();

1] str = reverseString(str)  // to reverse string
2] str = str.trim(); // Trim leading and trailing spaces
3] String[] words = s.split("\\s+");  // Split the string into words using one or more spaces as a delimiter
4] str.length() // to find length of String
5] str.toLowerCase();   
6] s1.equals(s2)   // return true if string are equal
7] s1.substring(0,3); // gives substring of the string
9] s1.compareTo(s2); // returns -ve if s1 < s2, 0 if s1 == s2, +ve if s1 > s2
10] 




StringBuilder

1] StringBuilder str = new StringBuilder()
2] str.toString()    // to convert StringBuilder to string
3] str.append("g");    // to append words to StringBuilder like push_back of c++
4] str.length() // to find length of Stringbuilder
5]  char temp = str.charAt(i);    // No inbuild swap function 
    str.setCharAt(i, str.charAt(j));
    str.setCharAt(j, temp);
6] Character.toLowerCase(str.charAt(index));   // to convert to lower case a character only   
7] str.charAt(index) // str[index] is not valid here
8] str.toLowerCase();  // to convert whole string to lower case
9] Character.toUpperCase(str.charAt(index)); // convert to upper case a character only



Bit Manipulation 

1] & // and operator
2] | // and operator
3] ^ // and operator
4] << // left shift 
5] >> // right shift 
6] ~ // negation

























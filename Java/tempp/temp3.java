package tempp;

import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

import java.util.*;

public class temp3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); 

        while (t-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            long x = sc.nextLong(); 
            int[] a = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            long count = 0;
            long sum = 0;
            int l = 0;

            // Extend the array logically instead of iterating over n*k
            for (int r = 0; r < Math.min(n * k, 2 * n); r++) {
                sum += a[r % n]; 

                while (sum >= x) {
                    count += (long) (k * n - r);  // Calculate remaining valid subarrays
                    sum -= a[l % n];
                    l++;
                }
            }

            System.out.println(count);
        }
        sc.close();
    }
}

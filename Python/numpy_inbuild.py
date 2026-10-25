import numpy as np

arr1 = arr = np.array([1,2,3,4,5])
arr2 = np.array([[1,2],[3,4],[5,6]])
np.arrange(1,11)        # [1,2,3,4,5,6,7,8,9,10]
np.arrange(1,11,2)      # [1,3,5,7,9] 
np.zeros(3)             # [0,0,0]
np.ones(3)              # [1,1,1]
np.zeros((2,3))         # 2 by 3 matrix of 0
np.ones((2,3))          # 2 by 3 matrix of 1
np.linspace(0,1,5)      # [0, 0,25, 0,50, 0,75, 1] // np.linespace(start,end,numbers_count_in_array)
np.random.rand(4)       # array with 4 random numbers
np.random.randn(10)      # numbers will be standardisation(between -3 to 3)
np.random.randint(1,20,10) # 10 random numbers between 1 to 20
arr.shape
arr.size
arr.dtype
arr.min()
arr.max()
arr.sum()               # total sum
np.sum(arr2,axis=1)      # sum row-wise (of every row)
np.sum(arr2,axis=0)      # sum col-wise (of every col)
arr.mean()
arr.std()               # standard deviation
arr.argmax()            # index of maximum element
arr.argmin()            # index of minimum element
arr.reshape(6,5)        # 6 rows and 5 columns
arr[0::2]               #[start : end : steps] (arr[-1::-1] reverses the array)
arr2[0:2,1:3]           # output = [[(0,1) (0,2)],       (i,j) are index positions
                        #           [(1,1) (1,2)]]
arr2[:,3]               # full 4th column  // arr2[rows_slice : columns_slice]  
a1 = np.array([1,2,4])
a2 = np.array([4,5,7])
a1 + a2, a1 - a2, a1 * a2, a1 / a2, a1 // a2,a1 ** a2
a1 = a2                 # deep copy  (same memory location)
a1 = a2.copy()          # shallow copy 
a1 @ a2                 # matrix multiplication 
a1.dot(a2)              # same as above (matrix multiplication)
arr2.T                    # transpose of matrix
np.vstack(a1,a2)    # verical stack (arr1 is 1st row ,arr2 is 2nd row)
np.hstack(a1,a2)    # horizontal stack (only one row bot concatinated)
np.column_stack(a1,a2)  # (arr1 is 1st column, arr2 is 2nd column)
np.hsplit(arr2,2)       # horizontal split equally 
np.vsplit(arr2,3)       # vertical split equally
arr2[arr2[:,1] > 5]     # gives all numbers > 5 which are in 2nd column
arr2[(arr2[:,0] >= 2) & (arr2[:,1] >= 3)]  # to apply and we have to use & 








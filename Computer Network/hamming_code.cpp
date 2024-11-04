#include<bits/stdc++.h>
// #include<iostream>
using namespace std;
// const int N = 32;
// int arr[N];
int hash_binary[100][32];

int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    int ans = 1;
    while(b--)
    {
        ans *= a;
    }
    return ans; 
}

int count_no_of_1(int total_bits,int index,string* arr1)
{
    int count = 0;
    for(int i=1;i<=total_bits;i++)
    {
        if(hash_binary[i][index] == 1)
        {
            if(arr1[i] == "1")
            {
                count++;
            }
        }
    }
    // only for checking 
    for(int i=total_bits;i>=1;i--)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    // only for checking
    return count;
}

int main()
{
    for(int i=1;i<=100;i++)
    {
        int temp_index1 = 1;
        int n = i; 
        while (n > 0) 
        {
            hash_binary[i][temp_index1++] = n % 2;
            n /= 2;
        }
    }
    string myinput;
    cin>>myinput;
    int countmyinput = 0;
    for(int i=0;i<myinput.length();i++)
    {
        countmyinput++;
    }
    int m = countmyinput;
    cout<<"m(data bits) = "<<m<<endl;
    int r;
    for(int i=0;i<100;i++)
    {
        if(power(2,i) >= (m+i+1))
        {
            r = i;
            break;
        }
    }
    cout<<"r(redundant bits) = "<<r<<endl;
    int total_bits = m+r;
    cout<<"Total number of bits = "<<total_bits<<endl;

    string arr1[total_bits+1];
    int temp1 = 0,temp2 = m-1;

    for(int i=1;i<=(total_bits);i++)
    {
        if(power(2,temp1) == i)
        {
            arr1[i] = "r"+ to_string(i);
            temp1++;
        }
        else
        {
            arr1[i] = myinput[temp2--];
        }
    }
    for(int i=1;i<=total_bits;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for(int i=total_bits;i>=1;i--)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    int count_of_1, count_of_r = 1;
    int error[r],error_temp = 0;
    for(int i=1;i<=total_bits;i++)
    {
        if(arr1[i] != "1" && arr1[i] != "0")
        {
            count_of_1 = count_no_of_1(total_bits,count_of_r,arr1);
            cout<<arr1[i]<<" = "<<count_of_1%2<<endl;
            string temp = to_string(count_of_1 % 2); 
            arr1[i] = temp;
            error[error_temp++] = count_of_1 % 2;
            count_of_r++;
        }
    }
    for(int i=total_bits;i>=1;i--)
    {
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<r;i++)
    {
        if(error[i] == 1)
        {
            cout<<"\nerror occured \n";
            break;
        }
    }
    int sum = 0;
    for(int i=0;i<r;i++)
    {
        sum += error[i]*power(2,i);
    }
    cout<<sum<<" th position \n";
    for(int i=total_bits;i>=1;i--)
    {
        if(i == sum)
        {
            if(arr1[i] == "1")
            {
                arr1[i] = "0";
            }
            else
            {
                arr1[i] = "1";
            }
        }
        cout<<arr1[i]<<" ";
    }
    cout<<"\n Error Resolved";

    return 0;
}

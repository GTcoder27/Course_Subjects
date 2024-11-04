#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "1] First Fit\n2] Best Fit\n3] Worst Fit\n";
    cin >> n;
    int arr[] = {100, 500, 200, 300, 600};
    int BF[] = {212, 417, 112, 426};
    int WF[] = {212, 417, 112, 426};
    int FF[] = {212, 417, 112, 426};
    switch (n)
    {
        case 1:
        {
            for (auto &i : FF)
            {
                for (auto &j : arr)
                {
                    if (i <= j)
                    {
                        j -= i;
                        break;
                    }
                }
            }
            cout << "final memory ";
            for (auto &i : arr)
            {
                cout << i << " ";
            }
            break;
        }
        case 2:
        {
            for (auto &i : BF)
            {
                int small_i = 0;
                int small = INT_MAX;
                for (int j = 0; j < (sizeof arr / sizeof arr[0]); j++)
                {
                    if ((arr[j] - i) <= small && (arr[j] - i) > 0)
                    {
                        small_i = j;
                        small = arr[j] - i;
                    }
                }
                cout << i << " -> " << arr[small_i] << endl;
                arr[small_i] -= i;
            }
            cout << "final remaining memory \n";
            for (auto i : arr)
            {
                cout << i << " ";
            }
            break;
        }
        case 3:
        {
            for (auto &i : WF)
            {
                int big = 0;
                for (int j = 0; j < 5; j++)
                {
                    if (arr[j] >= arr[big])
                    {
                        big = j;
                    }
                }
                if (arr[big] > i)
                {
                    cout << i << " -> " << arr[big] << endl;
                    arr[big] -= i;
                }
                else
                {
                    cout << "Memory is insufficient for " << i << endl;
                }
            }
            cout << "final remaining memory \n";
            for (auto i : arr)
            {
                cout << i << " ";
            }
            break;
        }
    }

    return 0;
}
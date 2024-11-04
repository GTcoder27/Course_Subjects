#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string P[] = {"p1", "p2", "p3", "p4", "p5"};
    int AT[] = {3, 1, 4, 0, 2};
    int BT[] = {1, 4, 2, 6, 3};
    int old_BT[] = {1, 4, 2, 6, 3};
    int n = sizeof AT / sizeof AT[0];
    int CT[n], WT[n], TAT[n];
    int total_CT = 0;
    int H_AT = 0, T_BT = 0;
    for (int i = 0; i < n; i++)
    {
        CT[i] = 0;
        WT[i] = 0;
        TAT[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (AT[i] > H_AT)
        {
            H_AT = AT[i];
        }
        T_BT += BT[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (AT[i] == 0)
        {
            BT[i] -= 1;
            total_CT += 1;
        }
    }

    for (int i = 0; i < H_AT - 1; i++)
    {
        int small[100];
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            if (AT[j] <= total_CT)
            {
                small[temp++] = j;
            }
        }
        // for(int k=0;k<temp;k++)
        // {
        //     cout<<small[k]<<" "<<endl;
        // }
        int smaller = T_BT;
        int smaller_index;
        for (int j = 0; j < temp; j++)
        {
            if (BT[small[j]] < smaller && BT[small[j]] != 0)
            {
                smaller = BT[small[j]];
                smaller_index = small[j];
            }
        }
        BT[smaller_index] -= 1;
        total_CT += 1;
        if (BT[smaller_index] == 0)
        {
            CT[smaller_index] = total_CT;
        }
        // cout<<"PID\tAT\tBT\tCT\tTAT\tWT\n";
        // for(int k=0;k<n;k++)
        // {
        //     cout<<P[k]<<"\t"<<AT[k]<<"\t"<<BT[k]<<"\t"<<CT[k]<<"\t"<<TAT[k]<<"\t"<<WT[k]<<"\n";
        // }
        // cout<<"Total CT = "<<total_CT<<endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int temp2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (BT[j] > temp2)
            {
                temp2 = BT[j];
            }
        }
        if (temp2 != 0)
        {
            int S_BT = T_BT;
            int index = 0;
            for (int j = 0; j < n; j++)
            {
                if (BT[j] < S_BT && BT[j] != 0)
                {
                    S_BT = BT[j];
                    index = j;
                }
            }
            if (S_BT != 0)
            {
                BT[index] -= S_BT;
                total_CT += S_BT;
                if (BT[index] == 0)
                {
                    CT[index] = total_CT;
                }
            }
            // cout<<"PID\tAT\tBT\tCT\tTAT\tWT\n";
            // for(int k=0;k<n;k++)
            // {
            //     cout<<P[k]<<"\t"<<AT[k]<<"\t"<<BT[k]<<"\t"<<CT[k]<<"\t"<<TAT[k]<<"\t"<<WT[k]<<"\n";
            // }
            // cout<<"Total CT = "<<total_CT<<endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - old_BT[i];
    }
    cout << "PID\tAT\told_BT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << P[i] << "\t" << AT[i] << "\t" << old_BT[i] << "\t" << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << "\n";
    }
    float sum_TAT = 0, sum_WT = 0;
    for (int i = 0; i < n; i++)
    {
        sum_TAT += TAT[i];
        sum_WT += WT[i];
    }
    cout << "Avg. TAT = " << sum_TAT / n << endl;
    cout << "Avg. WT = " << sum_WT / n << endl;
    return 0;
}

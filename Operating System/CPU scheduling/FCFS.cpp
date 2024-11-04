#include <bits/stdc++.h>
using namespace std;
int main()
{
    string P[] = {"p1", "p2", "p3", "p4", "p5"};
    int AT[] = {0, 1, 2, 3, 4};
    int BT[] = {2, 3, 5, 4, 6};
    int n = sizeof AT / sizeof AT[0];
    int CT[n], WT[n], TAT[n];
    int total_CT = 0;
    for (int i = 0; i < n; i++)
    {
        CT[i] = total_CT + BT[i];
        total_CT = CT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
    }
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << P[i] << "\t" << AT[i] << "\t" << BT[i] << "\t" << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << "\n";
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
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> P = {"p1", "p2", "p3", "p4", "p5"};
    vector<int> AT = {0,1,2,4};
    vector<int> oBT = {5,4,2,1};
    vector<int> priority = {10,20,30,40};
    vector<int> index;
    vector<int> BT = {5,4,2,1};
    int n = AT.size();
    int CT[n], WT[n], TAT[n];
    int total_BT = 0;
    for(auto i:BT){
        total_BT += i;
    }
    int total_CT = 0;
    while(total_BT > total_CT)
    {
        for(int i=0;i<AT.size();i++){
            if(AT[i]<=total_CT && BT[i]>0){
                index.push_back(i);
            }
        }
        int temp_max = 0,temp_index;
        for(int j=0;j<index.size();j++){
            if(priority[index[j]]>temp_max){
                temp_max = priority[index[j]];
                temp_index = index[j];
            }
        }
        BT[temp_index] -= 1;
        total_CT += 1;
        if(BT[temp_index] == 0){
            CT[temp_index] = total_CT;
        }
        index.clear();
    }
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - oBT[i];
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
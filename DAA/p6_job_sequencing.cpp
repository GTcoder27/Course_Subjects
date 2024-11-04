
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<pair<int, int>, int>> jobs = {
        {{3, 6}, 70},
        {{7, 2}, 10},
        {{2, 5}, 60},
        {{8, 2}, 22},
        {{5, 4}, 25},
        {{4, 6}, 65},
        {{6, 2}, 80},
        {{1, 4}, 20},
        };

    sort(jobs.begin(), jobs.end(), [](const auto &a, const auto &b){ 
        return a.second > b.second; 
    });
    // for(auto a : jobs){
    //     cout << a.first.first << " " << a.first.second << " " << a.second <<endl;
    // }


    int n = jobs.size();
    int max_deadline = 7;
    int max_profit = 0;
    vector<int> result(max_deadline, -1);

    for(auto job:jobs){
        while(job.first.second >= 0){
            if(result[job.first.second] == -1){
                result[job.first.second] = job.first.first;
                max_profit += job.second;
                break;
            }
            job.first.second--;
        }
    }
    cout<<max_profit<<endl;
    for(auto i:result){
        cout<<i<<" ";
    }


    return 0;
}
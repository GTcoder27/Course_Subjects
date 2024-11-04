#include <bits/stdc++.h>
using namespace std;

int main() {
    int max_w = 90;
    int price = 0;
    vector<pair<int,int>> p;
    p.push_back({100,20});  // 5 per 1
    p.push_back({60,10});  // 6 per 1
    p.push_back({100,50}); // 2 per 1
    p.push_back({200,50}); // 4 per 1

    vector<pair<int,int>> p1;
    int index = 0;
    for(auto i:p){
        p1.push_back({i.first/i.second,index++});
    }
    sort(p1.begin(), p1.end());
    reverse(p1.begin(), p1.end());

    cout<<"sequencing = ";
    for(int i=0;i<p1.size();i++){
        cout<<p1[i].second<<" ";
        if(p[p1[i].second].second <= max_w){
            max_w -= p[p1[i].second].second;
            price += p[p1[i].second].first;
        }
        else if(p1[i].first <= max_w){
            price += p[p1[i].second].first * max_w / p[p1[i].second].second; 
            max_w = 0;
        }
    }
    cout<<"\n"<<price;

    return 0;
}
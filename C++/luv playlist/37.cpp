// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     map< int,multiset<string> > marks_map;
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         int marks;
//         string name;
//         cin>> name>>marks;
//         marks_map[marks].insert(name);
//     }
//     auto current_it = --marks_map.end();
//     while(true)
//     {
//         auto &students = (*current_it).second;
//         int marks = (*current_it).first;
//         for(auto stu : students)
//         {
//             cout<<stu<<" "<<marks<<endl;
//         }
//         if(current_it == marks_map.begin()) break;
//         current_it--;
//     }
// return 0;
// }


/////OR/////

#include<bits/stdc++.h>
using namespace std;

int main()
{
    map< int,multiset<string> > marks_map;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int marks;
        string name;
        cin>> name>>marks;
        marks = -marks;
        marks_map[marks].insert(name);
    }
    for(auto &i:marks_map)
    {
        for(auto &k:(i.second)) {
            cout<<k<<" "<<(i.first)*(-1)<<endl;
        }
        
    }
    return 0;
}





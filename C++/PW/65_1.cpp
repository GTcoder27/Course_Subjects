#include <bits/stdc++.h>
using namespace std;
//Hashing  Seperate Chaining

class Hashing{

    vector<list<int>> hashtable;
    int buckets;
public:
    Hashing(int size){
        buckets = size;
        hashtable.resize(size);
    }

    int hashvalue(int key){
        return key % buckets;
    }

    void addKey(int key){
        int index = hashvalue(key);
        hashtable[index].push_back(key);
    }

    list<int>::iterator searchKey(int key){
        int index = hashvalue(key);
        return find(hashtable[index].begin(),hashtable[index].end(),key);
    }

    void deleteKey(int key){

        int index = hashvalue(key);
        if(searchKey(key)!=hashtable[index].end()){
            hashtable[index].erase(searchKey(key));
            cout<<key<<" is deleted "<<endl;
        }
        else{
            cout<<"Key is not present inside the hashtable "<<endl;
        }
    }

};



int main(){

    Hashing h(10);

    h.addKey(5);
    h.addKey(9);
    h.addKey(3);

    h.deleteKey(3);
    h.deleteKey(3);
    
    return 0;
}

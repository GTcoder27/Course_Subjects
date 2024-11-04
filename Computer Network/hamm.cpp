#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

// Function to generate Hamming code
vector<int> generateHammingCode(vector<int> data) {
    int dataSize = data.size();
    int codeSize = dataSize + (int)ceil(log2(dataSize + 1)) + 1; // Hamming code size
    vector<int> code(codeSize, 0);

    // Calculate parity bits
    int p1 = 0, p2 = 0, p3 = 0;
    for (int i = 0; i < dataSize; i++) {
        if ((i & 1) == 0) p1 ^= data[i];
        if ((i & 2) == 0) p2 ^= data[i];
        p3 ^= data[i];
    }

    // Create Hamming code
    int j = 0;
    for (int i = 0; i < codeSize; i++) {
        if ((i & (i - 1)) == 0) { // Power of 2 (parity bit position)
            if (i == 1) code[i] = p1;
            else if (i == 2) code[i] = p2;
            else if (i == 4) code[i] = p3;
        } else {
            code[i] = data[j++];
        }
    }

    return code;
}

// Function to print Hamming code
void printHammingCode(vector<int> code) {
    cout << "Hamming code: ";
    for (int i = 0; i < code.size(); i++) {
        cout << code[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {1, 0, 1, 1}; // Example data
    vector<int> hammingCode = generateHammingCode(data);
    printHammingCode(hammingCode);
    return 0;
}
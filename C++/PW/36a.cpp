#include <iostream>

using namespace std;

bool isArmstrong(int n, int sum) {
    if (n == 0) {
        return sum == n;
    }
    int digit = n % 10;
    return isArmstrong(n / 10, sum + digit * digit * digit);
}

int main() {
    int num = 153;
    if (isArmstrong(num, 0)) {
        cout << num << " is an Armstrong number" << endl;
    } else {
        cout << num << " is not an Armstrong number" << endl;
    }
    return 0;
}

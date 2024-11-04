#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the window size: ";
    int window_size;
    cin >> window_size;
    for (int i = 0; i < window_size; i++)
    {
        cout << "Frame " << i << "has been transmitted successfully ." << endl;
    }

    int sent;
    cout << "Enter the number of acknowledgement recieved" << endl;
    cin >> sent;
    for (int i = sent; i < window_size; i++)
    {
        cout << "Frame " << i << "has been re transmitted successfully" << endl;
    }
    return 0;
}
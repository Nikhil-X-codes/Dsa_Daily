#include<iostream>
using namespace std;

int climb(int n) {

    if(n == 0 || n == 1) {
        return 1;
    }

    if (n < 0)
    {
        return 0;
    }
    

    return climb(n - 1) + climb(n - 2);
}

int main() {
    int n = 3;
    cout << climb(n) << endl;
    return 0;
}
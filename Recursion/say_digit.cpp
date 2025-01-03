#include <iostream>
using namespace std;

void say(int n) {

string s[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if (n == 0) {
        return;
    }

    say(n / 10);

    cout << s[n % 10] << " ";
}

int main() {
    int n=123;
    say(n);
    return 0;
}
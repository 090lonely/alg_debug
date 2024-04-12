#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore(); // $$$$Clear the input buffer$$$$

    for (int i = 0; i < n; i++) {
        char s1[109]; // Allocate memory for the string
        int count = 0;
        cout << "Enter a string: ";
        cin.getline(s1, 109);
        for (int j = 0; s1[j] != '\0'; j++) {
            if ('0' <= s1[j] && s1[j] <= '9') {
                count++;
            }
        }
        cout << "Number of digits in the string: " << count << endl;
    }

    return 0;
}


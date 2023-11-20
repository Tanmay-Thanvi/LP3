// Implement the Naive string matching algorithm and Rabin-Karp algorithm for string matching. 

#include <bits/stdc++.h>
using namespace std; 

// Naive String Matching Algorithm
void naiveStringMatch(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int cnt = 0;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
            cnt++;
        }
    }
    cout<<"Total no. of substrings matched the pattern : "<<cnt<<endl;
}

// Rabin-Karp Algorithm
void rabinKarpStringMatch(const string& text, const string& pattern, int prime) {
    int n = text.length();
    int m = pattern.length();
    int pHash = 0;  // Hash value for the pattern
    int tHash = 0;  // Hash value for the text
    int cnt = 0;

    int h = 1;
    for (int i = 0; i < m - 1; i++) {
        h = (h * 256) % prime;
    }

    for (int i = 0; i < m; i++) {
        pHash = (256 * pHash + pattern[i]) % prime;
        tHash = (256 * tHash + text[i]) % prime;
    }

    for (int i = 0; i <= n - m; i++) {
        if (pHash == tHash) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) {
                cout << "Pattern found at index " << i << endl;
                cnt++;
            }
        }

        if (i < n - m) {
            tHash = (256 * (tHash - text[i] * h) + text[i + m]) % prime;
            if (tHash < 0) {
                tHash += prime;
            }
        }
    }
    cout<<"Total no. of substrings matched the pattern : "<<cnt<<endl;
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "Enter the pattern to search for: ";
    cin >> pattern;

    int prime = 101;  // A prime number for hash calculation

    cout << "------- Naive String Matching -------" << endl;
    naiveStringMatch(text, pattern);
    cout<<endl;

    cout << "------- Rabin-Karp String Matching -------" << endl;
    rabinKarpStringMatch(text, pattern, prime);
    cout<<endl;

    return 0;
}

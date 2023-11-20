// Fibonacci Numbers

#include <bits/stdc++.h>
using namespace std;

// Iteratively using memoization

vector<int> fib_nos;

int Iterative_Fibbonacci(int n)
{
    fib_nos.push_back(0);
    fib_nos.push_back(1);

    int cnt = 2;
    for (int i = 2; i < n; i++)
    {
        cnt++;
        fib_nos.push_back(fib_nos[i - 1] + fib_nos[i - 2]);
    }

    return cnt;
}

int rSteps = 0;

// Recursively

int Recursive_Fibbonacci(int n)
{
    rSteps++;
    if (n < 0)
        return 0;
    if (n == 1 || n == 0)
        return 1;
    return Recursive_Fibbonacci(n - 1) + Recursive_Fibbonacci(n - 2);
}

// Printing Fibonacci No.s

void Print_Fib_Nos()
{
    cout << " Fib No.s : ";
    for (int i = 0; i < fib_nos.size(); i++)
    {
        cout << fib_nos[i] << " ";
    }

    cout << endl;
}

// Main Function

int main()
{
    int n;
    char choice;

    cout << "\n **** Input Section **** \n";
    cout << "\n System >> Enter How Many no.s You want to Print. ";
    cout << "\n  User  << ";
    cin >> n;

    cout << "\n **** Output Section **** \n";\
    cout<<"\n System >> Fibbonacci Value : " << Recursive_Fibbonacci(n) << '\n';

    cout << "\n **** Analysis **** \n";
    cout<<"\n System >> Steps required using Iteration : " << Iterative_Fibbonacci(n) << '\n';
    cout << " System >> Steps required using recursion : " << rSteps << "\n\n";

    cout << " **** Print Array **** \n\n System >> Do You want to print array (Y/N) ? \n  User  << ";
    cin >> choice;
    cout << endl;
    if (toupper(choice) == 'Y')
    {
        Print_Fib_Nos();
    }
    else if (toupper(choice) != 'N')
    {
        cout << " System >> Invalid Input " << endl;
    }

    cout << "\n Program End!" << endl;
    return 0;
}

/*
    Recursive fibbonacci:
    Time Complexity: O(n*2n)
    Auxiliary Space: O(n), For recursion call stack.

    Iterative fibbonacci:
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/
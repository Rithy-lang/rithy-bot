#include <iostream>

using namespace std;

int main()
{
    int sum, s1, s2, s3, s4, s5, s6, s7, total = 800;
    float per;

    cout << "Calculate Percentage \n"
         << endl;

    cout << "Insert the marks of 7 subjects: \n"
         << endl;
    cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7;

    sum = s1 + s2 + s3 + s4 + s5 + s6 + s7;

    cout << "The sum of 7 subjects = " << sum << endl;

    per = (sum * 100) / total;

    cout << "\n Percentage = " << per << endl;

    return 0;
}
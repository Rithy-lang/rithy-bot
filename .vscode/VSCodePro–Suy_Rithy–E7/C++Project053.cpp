#include <iostream>

using namespace std;

double getAvg(int arr[], int size);

int main()
{
    int amt[8] = {87, 50, 30, 90, 87, 45, 100, 212};
    double avg;

    cout << "Passing Array to Function \n"
         << endl;

    avg = getAvg(amt, 8);

    cout << "The average of the amount = " << avg << endl;

    return 0;
}

double getAvg(int arr[], int size)
{
    int x, y = 0;
    double avg;

    for (x = 0; x < size; ++x)
    {
        y += arr[x];
    }

    avg = double(y) / size;

    return avg;
}
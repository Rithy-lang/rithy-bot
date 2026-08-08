#include <iostream>
using namespace std;

class student
{
private:
    string name;
    int age;

public:
    student()
    {
        name = "Unknown";
        age = 0;
    }
    student(string n)
    {
        name = n;
        age = 0;
    }
    student(string n, int a)
    {
        name = n;
        age = a;
    }
    void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    int main()
    {
        student s1;
        student s2("Alice");
        student s3("Bob", 20);
        s1.display();
        s2.display();
        s3.display();
        return 0;
    }
};
#include <iostream>
#include <string>

using namespace std;

class Student {
    public:
        string name;
        int age;
        double gpa;

    Student(string name, int age, double gpa){
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }
};

int main() {

    Student stud1("Spongebob", 20, 5.7);

    cout << stud1.name << "\n";
    cout << stud1.age << "\n";
    cout << stud1.gpa << "\n";

    return 0;
}





//Write a program to calculate the

#include <iostream>
#include <cstring>
using namespace std;

class Student {
protected:
    int  rollNo;
    char name[64];

public:
    void getStudent() {
        cout << "Enter Roll No : ";
        cin  >> rollNo;
        cout << "Enter Name    : ";
        cin.ignore(1000, '\n');
        cin.getline(name, 64);
    }

    void showStudent() {
        cout << "Roll No : " << rollNo << "\n";
        cout << "Name    : " << name   << "\n";
    }
};

class Test : virtual public Student {
protected:
    float theory[3];          

public:
    void getTestMarks() {
        cout << "Enter marks in 3 theory subjects (out of 100):\n";
        for (int i = 0; i < 3; i++) {
            cout << "  Subject " << (i + 1) << " : ";
            cin  >> theory[i];
        }
    }
};

class Sports : virtual public Student {
protected:
    float sportsMarks;        

public:
    void getSportsMarks() {
        cout << "Enter sports marks (out of 100) : ";
        cin  >> sportsMarks;
    }
};

class Result : public Test, public Sports {
    float total;

public:
    void calculate() {
        total = theory[0] + theory[1] + theory[2] + sportsMarks;
    }

    void display() {
        showStudent();       
        cout << "Theory Marks : " << theory[0] << ", "
             << theory[1] << ", " << theory[2] << "\n";
        cout << "Sports Marks : " << sportsMarks << "\n";
        cout << "TOTAL MARKS  : " << total << " / 400\n";
    }
};

int main() {
    Result r;

    r.getStudent();       
    r.getTestMarks();     
    r.getSportsMarks();   
    r.calculate();

    cout << "\n=========== RESULT ===========\n";
    r.display();
    cout << "==============================\n";

    return 0;
}

/*Consider an example of book shop which sells books and video tapes. These two classes are inherited from base class called media. 
The media class has command data members such as title and publication. The book class has data members for storing number of pages in a book and tape class has playing time in a tape.
Each class will have member functions such as read() and show() in the base class, these members have to be defined as virtual functions. 
Write a program to model the class hierarchy for book shop and processes objects of these classes using pointers to base class. 
Write the rules of virtual functions.*/

#include <iostream>
#include <cstring>
using namespace std;

class Media {
protected:
    char title[64];
    char publication[64];

public:
    virtual void read() {
        cin.ignore(1000, '\n');
        cout << "Enter title       : ";
        cin.getline(title, 64);
        cout << "Enter publication : ";
        cin.getline(publication, 64);
    }

    virtual void show() {
        cout << "Title       : " << title << "\n";
        cout << "Publication : " << publication << "\n";
    }

    virtual ~Media() {}
};

class Book : public Media {
    int pages;

public:
    void read() {               
        cout << "\n--- Enter Book details ---\n";
        Media::read();           
        cout << "Enter number of pages : ";
        cin  >> pages;
    }

    void show() {                
        cout << "\n[BOOK]\n";
        Media::show();
        cout << "Pages       : " << pages << "\n";
    }
};

class Tape : public Media {
    float playTime;              

public:
    void read() {                 
        cout << "\n--- Enter Video Tape details ---\n";
        Media::read();
        cout << "Enter playing time (minutes) : ";
        cin  >> playTime;
    }

    void show() {                
        cout << "\n[VIDEO TAPE]\n";
        Media::show();
        cout << "Play time   : " << playTime << " minutes\n";
    }
};

int main() {
    const int MAX = 10;
    Media *items[MAX];      
    int count = 0;
    int choice;

    do {
        cout << "\n1. Add Book\n2. Add Video Tape\n3. Display all\n0. Exit\nChoice: ";
        cin  >> choice;

        if (choice == 1 && count < MAX) {
            items[count] = new Book();     
            items[count]->read();          
            count++;
        }
        else if (choice == 2 && count < MAX) {
            items[count] = new Tape();    
            items[count]->read();         
            count++;
        }
        else if (choice == 3) {
            cout << "\n========== BOOK SHOP STOCK ==========";
            for (int i = 0; i < count; i++)
                items[i]->show();         
            cout << "\n=====================================\n";
        }
        else if ((choice == 1 || choice == 2) && count >= MAX) {
            cout << "Shop is full!\n";
        }
    } while (choice != 0);

    for (int i = 0; i < count; i++)
        delete items[i];                   
    return 0;
}

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdexcept>
using namespace std;

// Abstract class Advisory
class Advisory
{
public:
    virtual void giveAdvice() = 0;

    virtual ~Advisory()
    {
    }
};

// Base class Crop
class Crop
{
protected:
    string name;
    double area;
    string season;
    double yieldPerAcre;

    static int cropCount;

public:

    // Default constructor
    Crop()
    {
        name = "Unknown";
        area = 0;
        season = "Unknown";
        yieldPerAcre = 0;

        cropCount++;
    }

    // Parameterized constructor
    Crop(string n, double a, string s, double y)
    {
        if (a <= 0 || y <= 0)
        {
            throw invalid_argument(
                "Area and yield must be positive."
            );
        }

        name = n;
        area = a;
        season = s;
        yieldPerAcre = y;

        cropCount++;
    }

    // Virtual function for runtime polymorphism
    virtual double calculateYield()
    {
        return area * yieldPerAcre;
    }

    // Display crop details
    virtual void display()
    {
        cout << "\nCrop Name       : " << name;
        cout << "\nArea            : " << area << " acres";
        cout << "\nSeason          : " << season;
        cout << "\nYield Per Acre  : "
             << yieldPerAcre << " tons";
        cout << "\nTotal Yield     : "
             << calculateYield() << " tons";
    }

    // Operator overloading
    bool operator>(Crop &c)
    {
        return calculateYield() > c.calculateYield();
    }

    // Save crop data to file
    virtual void saveToFile()
    {
        ofstream fout("cropdata.txt", ios::app);

        if (!fout)
        {
            throw runtime_error("File could not be opened.");
        }

        fout << name << " "
             << area << " "
             << season << " "
             << yieldPerAcre << " "
             << calculateYield() << endl;

        fout.close();
    }

    // Static member function
    static int getCropCount()
    {
        return cropCount;
    }

    // Virtual destructor
    virtual ~Crop()
    {
    }
};

// Initialize static member
int Crop::cropCount = 0;


// Derived class CerealCrop
class CerealCrop : public Crop, public Advisory
{
private:
    string fertilizerType;

public:

    // Default constructor
    CerealCrop() : Crop()
    {
        fertilizerType = "Not specified";
    }

    // Parameterized constructor
    CerealCrop(string n, double a, string s,
              double y, string f)
        : Crop(n, a, s, y)
    {
        fertilizerType = f;
    }

    // Runtime polymorphism
    double calculateYield() override
    {
        return area * yieldPerAcre;
    }

    // Display details
    void display() override
    {
        Crop::display();

        cout << "\nFertilizer Type : "
             << fertilizerType << endl;
    }

    // Farming advice
    void giveAdvice() override
    {
        cout << "\nAdvice for Cereal Crops:";
        cout << "\nUse suitable fertilizers.";
        cout << "\nMaintain proper irrigation.";
        cout << "\nMonitor pests and diseases.\n";
    }

    // Virtual destructor
    ~CerealCrop()
    {
    }
};


// Derived class VegetableCrop
class VegetableCrop : public Crop, public Advisory
{
private:
    int irrigationFrequency;

public:

    // Default constructor
    VegetableCrop() : Crop()
    {
        irrigationFrequency = 0;
    }

    // Parameterized constructor
    VegetableCrop(string n, double a, string s,
                 double y, int i)
        : Crop(n, a, s, y)
    {
        irrigationFrequency = i;
    }

    // Runtime polymorphism
    double calculateYield() override
    {
        return area * yieldPerAcre;
    }

    // Display details
    void display() override
    {
        Crop::display();

        cout << "\nIrrigation Frequency : "
             << irrigationFrequency
             << " times per week" << endl;
    }

    // Farming advice
    void giveAdvice() override
    {
        cout << "\nAdvice for Vegetable Crops:";
        cout << "\nProvide regular irrigation.";
        cout << "\nUse organic manure.";
        cout << "\nHarvest vegetables at the proper stage.\n";
    }

    // Virtual destructor
    ~VegetableCrop()
    {
    }
};


// Main function
int main()
{
    try
    {
        cout << fixed << setprecision(2);

        // Creating crop objects
        CerealCrop c1(
            "Wheat", 5.0, "Winter", 2.5, "Urea"
        );

        VegetableCrop v1(
            "Tomato", 3.0, "Summer", 4.0, 3
        );

        // Runtime polymorphism
        Crop *ptr;

        cout << "\n========== CEREAL CROP ==========";

        ptr = &c1;
        ptr->display();

        cout << "\n\n========== VEGETABLE CROP ==========";

        ptr = &v1;
        ptr->display();


        // Calculate and display total yield
        cout << "\n\n========== TOTAL YIELD ==========";

        cout << "\nWheat Total Yield : "
             << c1.calculateYield() << " tons";

        cout << "\nTomato Total Yield : "
             << v1.calculateYield() << " tons";


        // Operator overloading
        cout << "\n\n========== CROP COMPARISON ==========";

        if (c1 > v1)
        {
            cout << "\nWheat has higher yield.";
        }
        else
        {
            cout << "\nTomato has higher or equal yield.";
        }


        // Abstract class implementation
        cout << "\n\n========== FARMING ADVICE ==========";

        Advisory *a;

        a = &c1;
        a->giveAdvice();

        a = &v1;
        a->giveAdvice();


        // File handling
        c1.saveToFile();
        v1.saveToFile();

        cout << "\nCrop data saved successfully.";


        // Retrieve data from file
        cout << "\n\n========== DATA FROM FILE ==========";

        ifstream fin("cropdata.txt");

        if (!fin)
        {
            throw runtime_error("File could not be opened.");
        }

        string cropName;
        double cropArea, cropYield, totalYield;
        string cropSeason;

        while (fin >> cropName
                   >> cropArea
                   >> cropSeason
                   >> cropYield
                   >> totalYield)
        {
            cout << "\n\nCrop Name : " << cropName;
            cout << "\nArea : " << cropArea;
            cout << "\nSeason : " << cropSeason;
            cout << "\nYield Per Acre : " << cropYield;
            cout << "\nTotal Yield : " << totalYield;
        }

        fin.close();


        // Static member
        cout << "\n\nTotal Crop Objects Created : "
             << Crop::getCropCount();

    }

    catch (invalid_argument &e)
    {
        cout << "\nInvalid Input: " << e.what();
    }

    catch (runtime_error &e)
    {
        cout << "\nRuntime Error: " << e.what();
    }

    catch (...)
    {
        cout << "\nAn unexpected error occurred.";
    }

    return 0;
}
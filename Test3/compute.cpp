#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;


// --- Declare your classes here ---
class Computation
{
public:
private:
};

// ---------------------------------

// --- DO NOT TOUCH ---
vector<int> readDataFromFile(string filepath);
vector<Computation *> readComputationsFromFile(string filepath);
// --------------------

int main(int argc, char const *argv[])
{
	// --- DO NOT TOUCH ---
	cout << fixed << setprecision(2);
	// --------------------

	// --- Read command line arguments ---
	string dataFile = "implement me";
	string computeFile = "implement me";
	// -----------------------------------

	// --- DO NOT TOUCH ---
	cerr << "Data from:" << dataFile << endl;
	cerr << "Computations from:" << computeFile << endl;

	vector<int> data = readDataFromFile(dataFile);
	vector<Computation *> computations = readComputationsFromFile(computeFile);

	for (auto computation : computations)
	{
		double result = computation->compute(data);
		cout << result << endl;
	}

	return 0;
	// --------------------
}

// Define functions and member functions here

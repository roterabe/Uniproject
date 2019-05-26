#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

// --- Declare your classes here ---
class Computation
{
public:
	virtual int compute() = 0;

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
	string dataFile = argv[1];	//"implement me";
	string computeFile = argv[2]; //"implement me";
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
vector<int> readDataFromFile(string filepath)
{
	int num = 0;
	vector<int> nums = vector<int>();
	ifstream input(filepath);
	while (input >> num)
	{
		nums.push_back(num);
	}
	return nums;
}
vector<Computation *> readComputationsFromFile(string filepath)
{
}
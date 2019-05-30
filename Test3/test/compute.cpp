#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

//  class to compute and declare virtual function for computing.
class Computation
{
public:
	//Computation(char comp);
	virtual double compute(vector<int> data) = 0;

private:
};

// This class sums all numbers in vector data.
class Sum : public Computation
{
public:
	Sum();
	virtual double compute(vector<int> data);

private:
};

// This class sums all odd numbers in vector data.
class Sumodd : public Computation
{
public:
	Sumodd();
	virtual double compute(vector<int> data);

private:
};

// This class outputs the maximal number from the vector data.
class Max : public Computation
{
public:
	Max();
	virtual double compute(vector<int> data);

private:
	//vector<int> data = vector<int>();
};

Computation *
newcompute(string compu);


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

// Saves data in vector.
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

// Saves computation type in vector and calls a new object as needed.
vector<Computation *> readComputationsFromFile(string filepath)
{
	string comp;
	vector<Computation *> operations = vector<Computation *>();
	ifstream oper(filepath, ios_base::in);
	while (oper >> comp)
	{
		// Error when read vitual function called.
		auto computation = newcompute(comp);
		operations.push_back(computation);
	}
	return operations;
}

// Computes what object to call and use.
Computation *newcompute(string compu)
{
	string sum1 = "sum";
	string sum_even = "sum-odd";
	string e_min = "max";
	if (sum1 == compu)
		return new Sum();
	else if (sum_even == compu)
		return new Sumodd();
	else if (e_min == compu)
		return new Max();
}

// Default constructors
Sum::Sum()
{
}

Sumodd::Sumodd()
{
}

Max::Max()
{
}

// Compute sum.
double Sum::compute(vector<int> data)
{
	double sum = 0;
	for (auto e : data)
	{
		sum += e;
	}
	return sum;
}

// Compute sum of odd numbers.
double Sumodd::compute(vector<int> data)
{
	double sumodd = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] % 2 != 0)
			sumodd += data[i];
	}
	return sumodd;
}

// Compute what is maximal number.
double Max::compute(vector<int> data)
{
	double maximal = data[0];
	for (int i = 0; i < data.size(); i++)
	{
		if (maximal < data[i])
			maximal = data[i];
	}
	return maximal;
}


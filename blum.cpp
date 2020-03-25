#include <iostream>

using namespace std;

//GLOBAL VARIABLES
//choose n = pq where p,q are relatively large primes and choose seed x such that gcd(n,x) = 1.
const int p = 1000003;
const int q = 2001911;
const unsigned long long int n = 2001917005733;
const int arrSize = 100000;
int fourBitFrequencies[16] = {0};

unsigned long long int fast_mod(unsigned long long int input)
{
	//only use the mod function when it is larger than (mod n)
	if (input > n) 
	{
		return input % n;
	}
	else if (input == n)
	{
		return 0;
	}
	else return n;
	//if input is larger than (modn) then do  input%n else return the input.
}

void countFourBitSequences(string compBits)
{
	//increments the frequency if there is a match.
	if(compBits == "0000") fourBitFrequencies[0]++; 
	if(compBits == "0001") fourBitFrequencies[1]++; 
	if(compBits == "0010") fourBitFrequencies[2]++; 
	if(compBits == "0011") fourBitFrequencies[3]++; 
	if(compBits == "0100") fourBitFrequencies[4]++; 
	if(compBits == "0101") fourBitFrequencies[5]++; 
	if(compBits == "0110") fourBitFrequencies[6]++; 
	if(compBits == "0111") fourBitFrequencies[7]++; 
	if(compBits == "1000") fourBitFrequencies[8]++; 
	if(compBits == "1001") fourBitFrequencies[9]++; 
	if(compBits == "1010") fourBitFrequencies[10]++; 
	if(compBits == "1011") fourBitFrequencies[11]++; 
	if(compBits == "1100") fourBitFrequencies[12]++; 
	if(compBits == "1101") fourBitFrequencies[13]++; 
	if(compBits == "1110") fourBitFrequencies[14]++; 
	if(compBits == "1111") fourBitFrequencies[15]++; 
}


int main() {
	char bitArray[arrSize] = {0};	
	int i = 0;
	unsigned long long int x = 3; //seed value = 3!		SEED VALUE HERE IS 3!
	const unsigned long long int ONE = 1;
	while(i < arrSize)
	{
		x = fast_mod(x*x);
		bitArray[i] = x & ONE;			
		
		/*if(bitArray[i] == ONE) // CODE FOR VISUAL TESTING
			cout << "1";
		else 
			cout << "0";
		*/
		i++;
	}

	int numZeros;
	int totalZeros = 0;
	for(int i = 0; i < arrSize - 1000; i++)
	{
		numZeros = 0;
		for(int j = i; j < i + 1000; j++)
		{
			if(bitArray[j] == 0)
			{
				numZeros++;
			}		
		}
		totalZeros += numZeros;
	}

	double avgZeros = static_cast<double>(totalZeros) / static_cast<double>(arrSize - 1000);

	cout << endl << "Average number of zeros per Subsequence of 1000: " << avgZeros;

	string subString = "";
	for(int i = 0; i < arrSize - 4; i++)
	{
		for(int j = i; j < i+4; j++)
		{
			if (bitArray[j] == '\000')
				subString += "0";
	 		else subString += "1";
		}
		countFourBitSequences(subString);
		subString = "";		
	}
	
	string randomBits = bitArray;
	cout << randomBits.substr(0,100);
	for(int i = 0; i < 16; i++)
	{
		cout << endl << "Frequency of " << (i ^ 0) << " (in binary)" << " is: " << static_cast<double>(fourBitFrequencies[i]) / static_cast<double>(arrSize - 4); 
	}	
	cout << endl;
return 0;
}

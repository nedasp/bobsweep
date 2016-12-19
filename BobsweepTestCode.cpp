#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str_number;

	cout << "Please enter an integer." << endl;
	getline(cin, str_number); // gets user enter input as string

	while (!str_number.empty()) // check if the entered key is not enter key
	{
		int number = stoi(str_number); // convert the entered string 2 integer

		string output = to_string(number) + " ="; // create the output sentence
		
		int power = 0;
		while (number % 2 == 0) // check if the number is even
		{
			power++;
			number /=2;
		}

        // create output format
		if (power == 1)
			output = output + " 2 *";
		else if (power>1)
			output = output + " 2^" + to_string(power) + " *";

		for (int i = 3; i <= number; i+=2) // just need to check odd numbers
		{
			int power = 0;
			while (number%i == 0)
			{
				power++;
				number = number / i;
			}
				
			// create output format	
			if (power == 1)
				output = output + " "+ to_string(i) + " *";
			else if (power>1)
				output = output + " "+ to_string(i) + "^" + to_string(power)+" *";
					
				
		}
		output.pop_back(); // pop out the last element (*)
		cout << output << endl;
		
		cout << "Please enter an integer." << endl;
		getline(cin, str_number);
	}

    return 0;
}
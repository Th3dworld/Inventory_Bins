#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//Define structure
struct InventBins 
{
	string PartInBin = "NULL";
	int NumPartsInBin = NULL;

};

//Prototye functions
void AddParts(InventBins[], int);
void RemoveParts(InventBins[], int);

int main() {
	//Declare Variables
	const int size = 10;
	int choice_index;
	InventBins userbins[size] =
	{	
		{"Valve", 10},
		{"Bearing", 5},
		{"Bushing", 15},
		{"Coupling", 21},
		{"Flange", 27},
		{"Gear", 5},
		{"Gear Housing", 5},
		{"Vacuum Gripper", 25},
		{"Cable", 18},
		{"Rod", 12}	
	};

	char choice = NULL, choice_act = NULL;
	string period = ".";

	//Run loop to display list and options
	while(choice != 'B')
	{
		cout << "\n------------------------------------------------------------------\n";
		cout << setw(10) << "Part Description" << " " << setw(50) << " Number Parts in the Bin\n";
		cout << "------------------------------------------------------------------\n";


		for (int i = 0; i < size; i++)
		{
			cout << setw(2) << right << (i+1)<< setw(0) << left << period << setw(14) << left << userbins[i].PartInBin << " " << right << setw(28) << userbins[i].NumPartsInBin << "\n";
		}
		cout << "------------------------------------------------------------------\n";

		//Display Menu
		cout << "\nPlease select an action\n";
		cout <<"A. Edit Bin\n";
		cout << "B. Exit\n";
		cout << "Selection:";
		
		//Get user inpute
		cin >> choice;
		choice = toupper(choice);
		
		//Validate user input
		while (choice > 'B' || choice < 'A')
		{
			cout << "\n\n!ERROR! You can only choose from the list below:\n";
			cout << "A. Edit Bin\n";
			cout << "B. Exit\n";
			cout << "Make correct Selection:";
			cin >> choice;
			choice = toupper(choice);
		}

		switch(choice)
		{
			case 'A': 
			{
			//Get user input
			cout << "\n\nWhich Bin would you like to edit?(Select Number)\n";
			cout << "Selection:";
			cin >> choice_index;
			 
			//validate input

			while (choice_index > 10 || choice_index < 1)
			{
				cout << "\n!ERROR! You can only choose a number between 1 and 10:\n";
				cout << "Make correct Selection:";
				cin >> choice_index;
			}

			//Display options
			cout << "\nWhat action would you like to take on " << userbins[choice_index - 1].PartInBin << "'s bin?\n";
			cout << "A. Add Parts\n";
			cout << "B. Remove Parts\n";
			cout << "Selection:";

			//Get user input
			cin >> choice_act;
			choice_act = toupper(choice_act);

			//Validate input
			while (choice_act > 'B' || choice_act < 'A')
			{
				cout << "\n!ERROR! You can only choose from the list below:\n";
				cout << "A. Add Parts\n";
				cout << "B. Remove Parts\n";
				cout << "Make correct Selection:";
				cin >> choice_act;
				choice_act = toupper(choice_act);
			}

			switch(choice_act)
			{
				case 'A': 
				{	
					//Call Addparts function
					AddParts(userbins, choice_index);
					break;
				}
				case 'B':
				{
					//Call RemoveParts function
					RemoveParts(userbins, choice_index);
					break;
				}
				default:
				{
					cout << "Never";
				}
			}
			case 'B':
				break;
			default:
				cout << "Never";

			

			break;
			}
		}

	}

	cout << "\n\n\nThank you for working with my program :-)\n\n\n";

	return 0;
}
//This function is used to add a specified amount of inventory from a specific bin
void AddParts(InventBins data[], int index)
{
	//Declare Variables
	int add;

	if (data[index - 1].NumPartsInBin < 30)
	{
		//Display action to be taken
		cout << "\nHow many more " << data[index - 1].PartInBin << "'s would you like to add this bin?";

		//Get user input
		cin >> add;

		//Input Validation
		//For negativity
		while (add < 0)
		{
			cout << "!ERROR! You cannot add a negative number of parts.\n";
			cout << "Please input a valid number of parts to add:";
			cin >> add;
		}

		//For Bin size
		while ((data[index - 1].NumPartsInBin + add) > 30)
		{
			cout << "\n!ERROR! You cannot have more than 30 parts per bin.\n";
			cout << "This bin currently has " << data[index - 1].NumPartsInBin << " so ";
			cout << "you can only add " << (30 - data[index - 1].NumPartsInBin) << " more parts to it.\n";
			cout << "How many would you like to add?";
			cin >> add;
		}

		//Add parts to bin
		data[index - 1].NumPartsInBin += add;

		cout << "\n\n";
		cout << setw(35) <<  "UPDATED LIST";
	}
	else
	{
		cout << "\nThis Bin is already full, please select another action.\n";
	}
}

//This function is used to remove a specified amount of inventory from a specific bin
void RemoveParts(InventBins data[], int index)
{
	//Declare Variables
	int subtract;

	if (data[index - 1].NumPartsInBin > 0)
	{
		//Display action to be taken
		cout << "\nHow many " << data[index - 1].PartInBin << "'s would you like to remove from this bin?";

		//Get user input
		cin >> subtract;

		//Input Validation
		//For negativity
		while (subtract < 0)
		{
			cout << "!ERROR! You cannot remove a negative number of parts.\n";
			cout << "Please input a valid number of parts to remove:";
			cin >> subtract;
		}

		//For Bin size
		while ((data[index - 1].NumPartsInBin - subtract) < 0)
		{
			cout << "\n!ERROR! You cannot have less than 0 parts per bin.\n";
			cout << "This bin currently has " << data[index - 1].NumPartsInBin << " so ";
			cout << "you can only remove up to " << data[index - 1].NumPartsInBin << " parts from it.\n";
			cout << "How many would you like to remove?";
			cin >> subtract;
		}

		//Add parts to bin
		data[index - 1].NumPartsInBin -= subtract;

		cout << "\n\n";
		cout << setw(35) << "UPDATED LIST";
	}
	else 
	{
		cout << "\nThis bin is already empty please select another action.\n";
	}
}
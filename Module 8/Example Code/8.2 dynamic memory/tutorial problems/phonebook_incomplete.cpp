// Phonebook Manager (dynamic array version)
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct PhoneRec {
    string name;
    string phone_no;
};

char selection_menu();
// Print selecltion menu to screen and read user selection

int load_phonebook(string filename, PhoneRec * &pb, int &pb_size);
// Load phonebook data from a file into the array parameter with a maximium size 
// specified by 'pb_size', and return the number of records loaded

void print_phonebook(PhoneRec pb[], int nRec);
// Print phonebook records stored in the array parameter. 'nRec' specifies the
// number of records stored in the array parameter

void sort_phonebook(PhoneRec pb[], int nRec);
// Sort the phonebook records stored in the array parameter by ascending order of
// the name. 'nRec' specifies the number of records stored in the array parameter

int search_phonebook(string str, PhoneRec pb[], int nRec);
// Search the recrods of the phonebook by partial match of the name and return
// the number of records found

int save_phonebook(string filename, PhoneRec pb[], int nRec);
// Save phonebook data stored in the array parameter into a file. 'nRec' specifies
// the number of records stored in the array parameter. Return 0 if error in
// opening file

int add_record(PhoneRec pb[], int nRec);
// Add a new record to the phonebook and return the new size

string upper_case(string str);
// Return a string with all letters in upper case

void grow_phonebook(PhoneRec * &pb, int &pb_size, int n);
// Grow the phonebook by increasing the size of the array by n

int main()
{
	int phonebook_size = 3;
    PhoneRec * phonebook = new PhoneRec[phonebook_size];
    
    int num_records = 0, count;
	string str;
		
	char choice = selection_menu();
	while (choice != '0')
	{
		switch (choice)
		{
			case '1':
				cout << "Please enter the filename: ";
				cin >> str;
				num_records = load_phonebook(str, phonebook, phonebook_size);
				cout << endl << num_records << " record(s) loaded." << endl << endl;				
				break;
				
			case '2':
				print_phonebook(phonebook, num_records);
				break;
				
			case '3':
				sort_phonebook(phonebook, num_records);
				print_phonebook(phonebook, num_records);
				break;
				
			case '4':
				cout << "Please enter a name: ";
				cin >> str;
				cout << endl;
				count = search_phonebook(str, phonebook, num_records);
				cout << count << " record(s) found." << endl << endl;
				break;
					
			case '5':
				cout << "Please enter the filename: ";
				cin >> str;
				count = save_phonebook(str, phonebook, num_records);
				cout << endl << count << " record(s) saved." << endl << endl;
				break;
				
			case '6':
				if (num_records >= phonebook_size)
					grow_phonebook(phonebook, phonebook_size, 3);

				if (num_records < phonebook_size)
					num_records = add_record(phonebook, num_records);
				cout << "There are now " << num_records <<
						" record(s) in the phonebook." << endl << endl;
				break;
				
			default:
				cout << "Invalid input!" << endl;
		}
		choice = selection_menu();
	}

	cout << "Goodbye!" << endl << endl;

	delete [] phonebook;	

	return 0;
}

char selection_menu()
{
	char choice;
	
	// print selection menu
	cout << "********************************" << endl;
	cout << "* Welcome to Phonebook Manager *" << endl;
	cout << "********************************" << endl;
	cout << "1. Load a phonebook." << endl;
	cout << "2. Print all records." << endl;
	cout << "3. Sort the records by ascending order of the name." << endl;
	cout << "4. Search the records by partial match of the name." << endl;
	cout << "5. Save the phonebook." << endl;
	cout << "6. Add a new record." << endl;
	cout << "0. Quit. " << endl;
	cout << "Please enter your choice: ";

	// read user selection
	cin >> choice;
	cout << endl;
	
	return choice;
}

int load_phonebook(string filename, PhoneRec * &pb, int &pb_size)
{
    ifstream fin;
    fin.open(filename.c_str());
    if (fin.fail())
    {
        cout << "Error in file opening." << endl;
        return 0;
    }
    
    int i = 0;
    string line;
    while (getline(fin, line))
    {
		if (i >= pb_size)
			grow_phonebook(pb, pb_size, 3);
			
		// extract a name and a phone no. from a line
		if (i < pb_size) {
	        istringstream iss(line);
	        if (!getline(iss, pb[i].name,','))
	            break;
	        if (!getline(iss, pb[i].phone_no))
	            break;
	        ++i;
	    }
    }
        
    fin.close();
    return i;
}

void print_phonebook(PhoneRec pb[], int nRec)
{
    int i;
    
    for (i = 0; i < nRec; i++)
    {
        cout << "Name:\t" << pb[i].name << endl;
        cout << "Phone#:\t" << pb[i].phone_no << endl << endl;
    }
}

void sort_phonebook(PhoneRec pb[], int nRec)
{
    int i, j ,idx;
    string min;
    // selection sort
    for (i = 0; i < nRec - 1; i++)
    {
        min = pb[i].name;
        idx = i;
        
        for (j = i + 1; j < nRec; j++)
        {
            if (pb[j].name < min)
            {
                min = pb[j].name;
                idx = j;
            }
        }
        
        if (idx != i)
        {
            PhoneRec temp;
            // swap pb[i] & pb[idx]
            temp    = pb[i];
            pb[i]   = pb[idx];
            pb[idx] = temp;           
        }
    }
}

int search_phonebook(string str, PhoneRec pb[], int nRec)
{
	int i, count = 0;
	for (i = 0; i < nRec; i++)
	{
		// extract the name from a record
		string name = pb[i].name;
		// search the name for any occurrence of str
		// both the name and str are converted into upper case to
		// make the search case insensitive
		if (upper_case(name).find(upper_case(str)) != string::npos)
		{
			// output the record to the screen
			cout << "Name:\t" << pb[i].name << endl;
        	cout << "Phone#:\t" << pb[i].phone_no << endl << endl;
        	// increase the count
        	count++;
		}
	}
	return count;
}

int save_phonebook(string filename, PhoneRec pb[], int nRec)
{
    ofstream fout;
    fout.open(filename.c_str());
    if (fout.fail())
    {
        cout << "Error in file opening." << endl;
        return 0;
    }

    int i;
    for (i = 0; i < nRec; i++)
    {
        fout << pb[i].name << "," << pb[i].phone_no << endl;
    }
    
    fout.close();
    return i;
}

int add_record(PhoneRec pb[], int nRec)
{
	char ans;
	string str;
	
	getline(cin, str); // flush the keyboard buffer
	cout << "Please enter a name: ";
	getline(cin, pb[nRec].name);
	cout << "Please enter a phone number: ";
	getline(cin, pb[nRec].phone_no);
	cout << endl;
	cout << "Name:\t" << pb[nRec].name << endl;
    cout << "Phone#:\t" << pb[nRec].phone_no << endl << endl;
    cout << "Add to phonebook (y/n)? ";
	cin >> ans;
	if (ans == 'y')
	{
		cout << "1 record added." << endl;
		nRec++;
	}
		
	return nRec;
}

string upper_case(string str)
{
	int i, n = str.length();
	for (i = 0; i < n; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
	}
	
	return str;
}

void grow_phonebook(PhoneRec * &pb, int &pb_size, int n)
{
	// Step 1:
	// create a new dynamic array with a new size = max_size + n
	
	// Step 2:
	// copy all the records from the original array to the new dynamic array

	// Step 3:
	// destroy the old dynamic array to free up the memory allocated to it

	// assign the pointer to the new dynamic array to the pointer variable

	// Step 4:
	// update the size of the array


	cout << "--->phonebook size enlarged to hold a maximum of " << pb_size << " records." << endl;
	
	return;
}

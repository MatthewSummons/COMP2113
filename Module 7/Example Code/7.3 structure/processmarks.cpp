#include<iostream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<fstream>

using namespace std;
const int MAX = 200; // Global variable, maximum number of students

/******************************************************
   Task 1. Add array declaration and initialization
 ******************************************************/
string name[MAX];
int subclass[MAX] = {0};
int year[MAX] = {0};
int month[MAX] = {0};
int day[MAX] = {0};
double mark[MAX] = {0};

int numStudents = 0;



// function to read in the class mark data
void load_data(){
   // Step 1. Declare ifstream object.
   ifstream fin;
   // Step 2. Open the file.
   fin.open("classmarks.txt");
   // Step 3. Check if the file is opened successfully.
   if ( fin.fail() ){
      cout << "Error in opening the file!\n";
      exit(1);
   }else{

      // Step 4. Load data into the corresponding variables.
      int i = 0;
      while( fin >> name[i]  ){
         /***********************************************************************
           Task 2. Add your code to load the data into the array variables here.
          ***********************************************************************/
         char dummy;  // for skipping the '/' character in the date
         fin >> subclass[i] >> year[i]>> dummy >> month[i] >> dummy >> day[i] >> mark[i];
         i++;

      }

      /**************************************************************************
           Task 2. save the number of records in the global variable numStudents
       **************************************************************************/
      numStudents = i;

   }
   // Step 5. Close the file.
   fin.close();
}


void show_data(){

    /**************************************************************************
        Task 3. Modify this function so that
                - it displays all student records stored in the arrays
                - it has formatted output
     **************************************************************************/

     cout << "------------Marks------------" << endl;
     int i;
     for (i=0 ; i < numStudents; i++){
         cout << setw(10) << left << name[i];
         cout << right << subclass[i] << "  ";
         cout << year[i] << "-";
         cout << setfill('0') << setw(2) << month[i] << "-";
         cout << setw(2) << day[i] << setfill(' ');
         cout << fixed << setprecision(1) << setw(6) << mark[i] << endl;
     }
     cout << "-----------------------------" << endl;
}

void late_penalty(double deduct)
{
    for (int i = 0 ; i < numStudents ; i++){
        if ((day[i]>28 && month[i]==10) || month[i]>10)
           mark[i]=mark[i]-mark[i]*deduct/100;
    }

}

void save_data()
{
    ofstream fout;
    fout.open("classmarks_new.txt");

    if (fout.fail())
    {
        cout << "Error in file opening!" << endl;
        exit(1);
    }

    fout << fixed << setprecision(1);

     for (int i=0 ; i < numStudents; i++){
         fout << name[i] << ' ';
         fout << subclass[i] << ' ';
         fout << year[i] << "/" << month[i] << "/" << day[i] << " ";
         fout << mark[i] << endl;
     }

    fout.close();
}

void top_student()
{
     int id[3] = {0};
     double highest_mark[3] = {0};
     int i;

     for (i = 0 ; i< numStudents ; i++){
         if (mark[i] > highest_mark[subclass[i]]){
            highest_mark[subclass[i]] = mark[i];
            id[subclass[i]] = i;
         }
     }

     for (i = 0 ; i<3 ; i++){
       cout << "Class" << i << " highest mark : " << highest_mark[i] << " by " << name[id[i]] << endl;
     }

}


void swap( int &a, int &b )
{
      int tmp = a;
      a = b;
      b = tmp;
}


void show_sorted_marks()
{
    int id[MAX] = {0};   // an array storing the id of students.
    int i;
    for (i=0 ; i < numStudents ; i ++){
        id[i] = i;
    }

    int j;
    double max_value;
    int slot_id_of_max_value;

    // i indicates the i-th iteration
    for( i = 0 ; i < numStudents - 1; i++ ){
         // Initialize max_value and the slot_id in each iteration
         max_value = mark[id[i]];
         slot_id_of_max_value = i;

         // Find the maximum in the i-th iteration
         for( j = i  ; j < numStudents ; j++ ){
              if ( mark[id[j]] > max_value ){
                   max_value = mark[id[j]];
                   slot_id_of_max_value = j;
              }
         }
         swap( id[i], id[slot_id_of_max_value] );

    }

     cout << "---------Sorted Marks--------" << endl;
     for (i=0 ; i < numStudents; i++){
         cout << setw(10) << left << name[id[i]];
         cout << right << subclass[id[i]] << "  ";
         cout << year[id[i]] << "-";
         cout << setfill('0') << setw(2) << month[id[i]] << "-";
         cout << setw(2) << day[id[i]] << setfill(' ');
         cout << fixed << setprecision(1) << setw(6) << mark[id[i]] << endl;
     }
     cout << "-----------------------------" << endl;

}

int main(){

    /******************************************
      write the function calls one-by-one here
     ******************************************/
    load_data();
    show_data();

    late_penalty(10);
    show_data();

    save_data();

    top_student();

    show_sorted_marks();

    return 0;
}

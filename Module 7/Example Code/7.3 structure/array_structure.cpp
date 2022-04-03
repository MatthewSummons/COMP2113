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
struct Student_rec {
	string name;
	int subclass;
	int year;
	int month;
	int day;
	double mark;
};

Student_rec student[MAX];

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
      while( fin >> student[i].name  ){
         /***********************************************************************
           Task 2. Add your code to load the data into the array variables here.
          ***********************************************************************/
         char dummy;  // for skipping the '/' character in the date
         fin >> student[i].subclass >> student[i].year >> dummy
            >> student[i].month >> dummy >> student[i].day >> student[i].mark;
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
         cout << setw(10) << left << student[i].name;
         cout << right << student[i].subclass << "  ";
         cout << student[i].year << "-";
         cout << setfill('0') << setw(2) << student[i].month << "-";
         cout << setw(2) << student[i].day << setfill(' ');
         cout << fixed << setprecision(1) << setw(6) << student[i].mark << endl;
     }
     cout << "-----------------------------" << endl;
}

void late_penalty(double deduct)
{
    for (int i = 0 ; i < numStudents ; i++){
        if ((student[i].day>28 && student[i].month==10) || student[i].month>10)
           student[i].mark=student[i].mark-student[i].mark*deduct/100;
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
         fout << student[i].name << ' ';
         fout << student[i].subclass << ' ';
         fout << student[i].year << "/" << student[i].month << "/" << student[i].day << " ";
         fout << student[i].mark << endl;
     }

    fout.close();
}

void top_student()
{
     int id[3] = {0};
     double highest_mark[3] = {0};
     int i;

     for (i = 0 ; i< numStudents ; i++){
         if (student[i].mark > highest_mark[student[i].subclass]){
            highest_mark[student[i].subclass] = student[i].mark;
            id[student[i].subclass] = i;
         }
     }

     for (i = 0 ; i<3 ; i++){
       cout << "Class" << i << " highest mark : " << highest_mark[i] << " by " << student[id[i]].name << endl;
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
         max_value = student[id[i]].mark;
         slot_id_of_max_value = i;

         // Find the maximum in the i-th iteration
         for( j = i  ; j < numStudents ; j++ ){
              if ( student[id[j]].mark > max_value ){
                   max_value = student[id[j]].mark;
                   slot_id_of_max_value = j;
              }
         }
         swap( id[i], id[slot_id_of_max_value] );

    }

     cout << "---------Sorted Marks--------" << endl;
     for (i=0 ; i < numStudents; i++){
         cout << setw(10) << left << student[id[i]].name;
         cout << right << student[id[i]].subclass << "  ";
         cout << student[id[i]].year << "-";
         cout << setfill('0') << setw(2) << student[id[i]].month << "-";
         cout << setw(2) << student[id[i]].day << setfill(' ');
         cout << fixed << setprecision(1) << setw(6) << student[id[i]].mark << endl;
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

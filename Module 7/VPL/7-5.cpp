// Handling user commands
// Modified by Shaheer Ziya

#include <iostream>
#include <string>
using namespace std;

struct Course
{
  string courseCode;
  string courseName;
  string lecturer;

  // Print the courseName & Lecturer
  void show()
  {
    cout << "Name: "  << courseName << ", Lecturer: " << lecturer << endl;
  }
};


int main()
{
  Course courseRecord [100];
  int courseCount = 0;
  
  string input;
  cin >> input;
  while (input != "exit")
  {
    if (input == "add")
    {
      string courseCode, courseName, lecturer;
      cin >> courseCode >> courseName >> lecturer;
      
      Course newCourse = {courseCode, courseName, lecturer};
      
      courseRecord[courseCount] = newCourse;
      courseCount++;
    }
    if (input == "show")
    {
      string input;
      cin >> input;
      for (int i{0}; i < courseCount; i++)
      {
        if (input == courseRecord[i].courseCode)
        {
          courseRecord[i].show();
        }
      }
    }
    cin >> input;
  }
  return 0;
}
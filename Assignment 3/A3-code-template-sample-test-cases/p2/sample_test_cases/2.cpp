// STL - Log Analyzer
// Print the most popular pages & activity of most active users from a log file
// Last Modified by Shaheer Ziya on Apr 26, 2022

#include <iostream>     // For cout & cin
#include <algorithm>    // For sort() and lower_bound() [which expects a sorted input]
#include <string>       // For C++ Strings
#include <map>          // For STL Maps
#include <vector>       // For STL Vectors

using namespace std;

// Contains the page "id" and "path" to the page, along with a "counter" to store the visits to the page
struct Page {
  int id;
  string path;
  int counter;

  Page(int id, string path) {
    this -> id = id;
    this -> path = path;
    counter = 0;
  };
};

// This function can facilitate sorting
bool operator<(const Page & a, const Page & b) {
  return (a.id < b.id);
}

// Store all the pages on the website/log
vector<Page> pages;

struct User {
  int id;
  vector<string> visits;
    
  User(int id) {
    this->id = id;
  };

  void add_visit(int page_id) {
    Page p(page_id, "");

    vector<Page>::iterator iter = lower_bound(pages.begin(), pages.end(), p);
    
    if(iter -> id == page_id)
      visits.push_back(iter -> path);
  };
    
  int size() const {
    return visits.size();
  };

  void print_visits() {
    // The list of pages a user visit must be printed in lexicographical ascending order
    sort(visits.begin(), visits.end());
    vector<string>::iterator iter;
    for(iter = visits.begin(); iter != visits.end(); iter++) {
      cout << "- " << *iter << endl;
    }
  }
};

// Store all the users
vector<User> users;

// Function to facilitate the sorting of users
bool operator<(const User &a, const User &b) {
  // If two users visit the same number of pages, the users are ordered by their id ascendingly
  if (a.size() == b.size())
    return a.id < b.id;
  
  // To ensure sorting occurs in a descending order
  return (a.size() > b.size());
}

// Add a page entry to the global vector storing all the pages
void add_page(const Page & p) {
  pages.push_back(p);
}

// Compare the visit counts to each page
// return a.counter < b.counter
bool cmp_page_count(const Page &a, const Page &b) {
  // If two pages are equally popular, the pages are ordered lexicographically by the path.
  if (a.counter  == b.counter)
    return a.path < b.path;
  
  return (a.counter > b.counter);
}

// Print the first "number" pages from the global vector 'pages' in the format {visit_count:page_path}
void print_pages(int number) {
  vector<Page>::iterator iter = pages.begin();
  
  for (int i = 0; i < number; i++) {
    cout << (*iter).counter << ":" << (*iter).path << endl;
    iter++;   // Move the iterator
  }
}

// Add a user record to the global vector "users" that stores all users
void add_user(User u) {
  users.push_back(u);
}

// Please implement the following function
void add_visit(int page_id) {
  // Users will never be empty because VISITS will appear in input after a USER is logged
  // Otherwise if users is empty may lead to undefined behaviour

  // The last user in the users vector is the one logging visits
  // Add the visit to the last
  // sort(pages.begin(), pages.end());
  users.back().add_visit(page_id);
}

// Print the users in the format {number_of_pages_visisted:user_id}
void print_users(int number) {
  vector<User>::iterator iter = users.begin();
  for (int i = 0; i < number; i++) {
    cout << (*iter).size() << ":" << iter -> id << endl;
    (*iter).print_visits();
    iter++;     // Move the iterator
  }
}



int main() {

  string type;
  while(cin >> type) {

    // Add users
    // USER <user id>
    if(type == "USER") {
      int user_id;
      cin >> user_id;
      User u(user_id);
      add_user(u);
    }

    // Add pages
    // PAGE <page id> <page url>
    else if(type == "PAGE") {
      int page_id;
      string page_path;
      cin >> page_id;
      cin >> page_path;
      Page p(page_id, page_path);
      add_page(p);
    }

    // Add visits
    // VISIT <page id>
    else if(type == "VISIT") {
      int page_id;
      cin >> page_id;
      Page p(page_id, "");

      // This is absolutely crucial to perform as lowerbound() expects the template to be ordered
      // You can learn more about the required function in the following link:
      // https://www.cplusplus.com/reference/algorithm/lower_bound/
      // Not sorting before calling this function leads to undefined behaviour and should've been addressed or mentioned either 
      // in the assignment pdf or the template code
      sort(pages.begin(), pages.end());
      
      vector<Page>::iterator iter = lower_bound(pages.begin(), pages.end(), p);
      // Increment page visit counter
      if(iter -> id == p.id) {
        iter -> counter++;
      }
      // Add visit to user's visit vector
      add_visit(p.id);
    }
  }

  // Sort pages in descending order
  sort(pages.begin(), pages.end(), cmp_page_count);
  
  cout << "*** 5 most popular pages ***" << endl;
  print_pages(5);

  sort(pages.begin(), pages.end());
  sort(users.begin(), users.end());

  cout << "*** 5 most active users ***" << endl;
  print_users(5);

  return 0;
}

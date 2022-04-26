#include <iostream>
using namespace std;
int main()
{
    int num_seats, num_votes, num_lists;
    int quota, idx_list, vote, seat;
    cout << "Total number of seats: ";
    cin >> num_seats;
    cout << "Total number of votes: ";
    cin >> num_votes;
    cout << "Total number of lists: ";
    cin >> num_lists;
    quota = num_votes / num_seats;
    idx_list = 1;
    while (idx_list <= num_lists) {
        cout << "Votes for list " << idx_list << ": ";
        cin >> vote;
        cout << "Automatic seat for list " << idx_list << ": ";
        seat = vote / quota;
        cout << seat << endl;
        cout << "Remainder for list " << idx_list << ": ";
        cout << vote - seat * quota << endl;
        idx_list++;
    }
    return 0;     
}

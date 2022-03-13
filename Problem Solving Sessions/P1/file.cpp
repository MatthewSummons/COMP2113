#include <iostream>
#include <string>
using namespace std;


void UpdateYear(int &ten, int &five, int &year){
	cout << "Start of function";
    cout << "ten = " << ten << " five = " << five << " year = " << year << endl;
    
    
    int divisor = ten;
	ten = year/divisor;
	year %= divisor;
	if (year >= divisor/2){
        five = (year>=(divisor*9/10))?2:1;
        year -= (five==2)?(divisor*9/10):divisor/2;
    }
	cout << "End of function";
    cout << "ten = " << ten << " five = " << five << " year = " << year << endl;
    cout << "divisor = " << divisor << endl;
}

int main()
{
    int year, m=1000, d=0, c=100, l=0, x=10, v=0;
    cin >> year;
    while (year != 0){
        UpdateYear(m, d, year);
        UpdateYear(c, l, year);
        UpdateYear(x, v, year);
        cout << string(m,'M') << ((d==2)?"CM":string(d,'D')) << ((c==4)?"CD":string(c,'C')) << ((l==2)?"XC":string(l,'L')) << ((x==4)?"XL":string(x,'X')) << ((v==2)?"IX":string(v,'V')) << ((year==4)?"IV":string(year,'I')) << endl;
        cin >> year;
    }
    return 0;
}
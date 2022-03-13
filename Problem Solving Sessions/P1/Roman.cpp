// Roman.cpp
// Print the roman equivalent year in [1000,2999]
// Modified by Shaheer Ziya on 22-02-2022 UTC 02:40

#include <iostream>

void roman(int year)
{
    // Extract the digits from year, where year is radix-10
    
    int thousandths =  year / 1000;
    int hundreths =   (year % 1000) / 100;
    int tens =        (year % 100) / 10;
    int units =       (year % 10) / 1;
    
    //! Debug line
    //std::cout << thousandths << hundreths << tens << units << std::endl;

    // Initialize strings (DxN), where N is the power of the base (10) 
    int Dx3 = thousandths, Dx2 = hundreths, Dx1 = tens, Dx0 = units;
    // Initialize an array for iteration so the characters can be replaced by their roman counterparts
    int year_array [4] = {Dx3, Dx2, Dx1, Dx0};
    // !!!!
    std::string Rx3, Rx2, Rx1, Rx0;
    std::string roman_year [4] = {Rx3, Rx2, Rx1, Rx0};

    for (int i=0; i <= 3; i++){
        // 
        int DxN = year_array[i];
        std::string RxN = roman_year[i];
        switch(DxN)
        {
            std::cout << "Entered switch clause";
            case 1:
                RxN = "I";
                break;
            case 2:
                RxN = "II";
                break;
            case 3:
                RxN = "III";
                break;
            case 4:
                RxN = "IV";
                break;
            case 5:
                RxN = "V";
                break;
            case 6:
                RxN = "VI";
                break;
            case 7:
                RxN = "VII";
                break;
            case 8:
                RxN = "VIII";
                break;
            case 9:
                RxN = "IX";
                break;

        } 
        std::cout << DxN << ":" << RxN << std::endl;
        
    }

}

int main()
{
    // Obtain the year in Arabic Numeral representation in [1000,2999]
    
    std::cout << "Input a year in the interval [1000,2999]: ";
    int year;
    std::cin >> year;

    //
    roman(year);
    
    return 0;
}
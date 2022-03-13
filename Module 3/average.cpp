#include <iostream>

int main()
{
    // Declare running sum and loop counter variables 
    double sum = 0;
    int count = 0;
    
    // Declare temporary variable which holds data from Output Stream
    double input = 0;
    while (input != -1)
    {
        std::cin >> input;
        sum += input;
        // Increment loop-counter
        count++;
    } 
    
    // Solve fencepost-issues (Remove -1 from sum and decrement loop counter)
    sum += 1;
    count--;

    // Calculate the average and output it to screen
    std::cout <<  sum / count;
    
    return 0;
}
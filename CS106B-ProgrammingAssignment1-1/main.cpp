//
//  main.cpp
//  CS106B-ProgrammingAssignment1-1
//
//  Identify all of the 'perfect' numbers from 0 to 10000
//  Print out the perfect numbers
//
//
//  Created by John Pierce on 10/3/16.
//  Copyright © 2016 JohnPierce. All rights reserved.
//

#include <iostream>

/* When I first looked at this project I imagined putting the
 * putting the divisible numbers in an array/vector and then summing
 * the vector in the end to determine if it was a perfect number.
 *
 * Took I believe a much more efficient route of calculating the sum on each
 * iteration of a valid divisor.
 * 
 * Implemented both since I still wanted to explore vectors
 */
#include <vector>



// int divisor(int eval); // good example of prototyping functions

// bool IsDivisor(int checkIncrementalInt); // good example of prototyping functions

bool IsPerfect(int eval);


int main(int argc, const char * argv[]) {
    // insert code here...
    // std::cout << "Hello, World!\n";
    int i;

    /* debug code removed
    int a = 5;
    int b = 10;
    int c = 11;
    
    std::cout << " b / a " << b/a << "\n";
    std::cout << " b % a " << b % a << "\n";
    std::cout << " c % a " << c % a << "\n";
     */
    
    for (i = 0; i < 10000; i++)
    {
        if (IsPerfect(i))
            std::cout << "Perfect number: " << i << "\n";
        
    }
    return 0;
}

/* Function IsPerfect
 * Usage: bool IsPerfect(integer);
 * ------------------------------------------------------------
 * This function takes as input an integer. The function determines if that integer is a 'perfect'
 * number as defined by sum of all divisors = number. Reference 'greek perfect number'
 *
 * Function IsPerfect returns a boolean true or false used to print out the number.
 */

bool IsPerfect(int eval){
    std::vector<int> divisorNumbers;
    int sumDivisors = 0;
    //int i=0;
    //int eachVal;
    
    int increment=eval -1; // set increment to the number we are evaluating less 1
    
    bool returnVal=false; // initialize the return value to false requires enter into loop
    
    while ( increment-- > 1){ // establish a while loop where increment needs to be greater than one eliminating 0 and 1
       // std::cout << increment << "increment \n";
        if ( (eval % increment) == 0 ) // if there is no left over from the division increment is a valid divisor of eval
        {
            divisorNumbers.push_back(increment); // push increment onto the vector stack
            sumDivisors += increment; // start accumulating the divisor numbers
            // std::cout << "increment: " << increment << " eval: " << eval << "\n";
            // std::cout << "divisorNumbers length: " << divisorNumbers.size() << "\n";
            
        }
        if (sumDivisors != 0 && sumDivisors != 1 &sumDivisors == eval){ // check to see if it is a perfect number
            // std::cout << "sumDivisors :" << sumDivisors << "\n"; // debug code
            returnVal = true;
        }
        else
            returnVal = false;
    }

    
    /* The following code was used to check out a for loop that enabled use to go through the vector: divisorNumbers that we were storing valid divide by numbers */
    /*
    sumDivisors = 0;
    for ( auto &eachVal : divisorNumbers )
    {
        sumDivisors += eachVal;
    }
    if(sumDivisors == eval){
        // std::cout << "sumDivisors :" << sumDivisors << "\n"; // debug code
        returnVal = true;
    }
    else
        returnVal = false;
     */
    
    return returnVal;
    
    
}

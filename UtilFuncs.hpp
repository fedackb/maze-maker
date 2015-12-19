//-----------------------------------------------------------------------------
// Requirement #19: Demonstrate a self-made header file.
//-----------------------------------------------------------------------------

#ifndef FEDACKB_UTILFUNCS_H
#define FEDACKB_UTILFUNCS_H

#include <string>

//-----------------------------------------------------------------------------
// Requirement #18: Demonstrate a custom namespace.
//-----------------------------------------------------------------------------
namespace UtilFuncs {

    // Declare a function to clear the terminal/console.
    void ClearScreen();

    // Declare a function to generate a pseudo-random integer.
    int GenRandInt(int, int);

    // Declare a function to retrieve from the user an integer that is within a
    // specified inclusive range.
    int InputIntInRange(int, int, const std::string & = "", bool = false);

    // Declare a function to determine if a string represents an integer.
    bool IsStrInt(std::string);

    // Declare a function to form a random permutation of an array.
    template <typename T> void RandPermutation(T *, int);

    // Declare a function that pauses for a number of seconds.
    void Wait(double);
}

// Templates should be prototyped and defined in the same file, or the
// implementation file should be included at the end of the interface.

//-----------------------------------------------------------------------------
// Requirement #11: Demonstrate pass by value to a pointer parameter.
//-----------------------------------------------------------------------------
/*
Purpose:    This function is a type generalized algorithm to form a random
            permutation of an array.

Entry:      "ptr" holds the address of the first element in the array.

            "numberOfElements" is the number of elements to sort.

Exit:       The array being pointed to is modified.
*/
template <typename T>
void UtilFuncs::RandPermutation(T *ptr, int numberOfElements)
{
    int randomIndex; // Stores a random index in the array

    // Randomly sort elements to form a permutation.
    for (int i = 0; i < numberOfElements; ++i) {
        
        // Select a random index in the unsorted portion of the array.
        randomIndex = GenRandInt(i, numberOfElements - 1);

        // Move the element that is associated with the selected index
        // backwards from its current position until is arrives at the end of
        // the sorted portion of the array.
        for (int j = randomIndex; j > i; --j) {

            // Move the element backs by swapping it with the preceding one.
            T tmp = ptr[j];
            ptr[j] = ptr[j - 1];
            ptr[j - 1] = tmp;
        }
    }
}

#endif

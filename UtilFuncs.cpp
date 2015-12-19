#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include "UtilFuncs.hpp"

//-----------------------------------------------------------------------------
// Requirement #08: Demonstrate a function definition.
//-----------------------------------------------------------------------------
/*
Purpose:    This function clears the screen by printing newlines.

Entry:      None

Exit:       None

*/
void UtilFuncs::ClearScreen()
{
    // Clear the terminal/console screen with 100 newlines.
    std::cout << std::string(100, '\n');
}

//-----------------------------------------------------------------------------
// Requirement #11: Demonstrate pass by value.
//-----------------------------------------------------------------------------
/*
Purpose:    This function returns a pseudo-random integer in the closed
            interval defined by the specified limits.

Enter:      "min" is the minimum possible value of the random integer. 
            "max" is the maximum possible value of the random integer.

Exit:       The pseudo-randomly generated integer is returned.
*/
int UtilFuncs::GenRandInt(int min, int max)
{
    static bool randHasBeenSeeded = false; // srand should be called only once

    // Seed the random number generator, if necessary.
    if (!randHasBeenSeeded) {
        srand(time(NULL));
        randHasBeenSeeded = true;
    }

    //-------------------------------------------------------------------------
    // Requirement #05: Demonstrate a random integer.
    //-------------------------------------------------------------------------
    // Generate and return a random integer.
    return rand() % (max - min + 1) + min;
}

//-----------------------------------------------------------------------------
// Requirement #01: Demonstrate input/output.
//-----------------------------------------------------------------------------
/*
Purpose:    This function retrieves from the user an integer within the
            specified inclusive range.

Entry:      "lowerBound" is the lower end of the interval.

            "upperBound" is the upper end of the interval.

            "preMsg" is the string to display prior to receiving input.

Exit:       The validated integer is returned.
*/
int UtilFuncs::InputIntInRange(int lowerBound, int upperBound,
                                const std::string &preMsg, bool clear)
{
    bool userInputIsValid = false;
    std::string input; // Stores the user's input
    int intConversion; // Stores the converted input

    // Clear the screen if necessary.
    if (clear) UtilFuncs::ClearScreen();

    // Display the pre-input message to the user.
    if (!preMsg.empty()) std::cout << preMsg;

    // Get a valid integer.
    while (!userInputIsValid) {

        // Get the user's input.
        std::getline(std::cin, input);

        // Validate the user's input.
        if (
            UtilFuncs::IsStrInt(input) &&
            (intConversion = atoi(input.c_str())) >= lowerBound &&
            intConversion <= upperBound
        ) {
            userInputIsValid = true;
        }

        // The user's input is invalid.
        else {
            std::cout << '"' << input << '"' << " is invalid. Choose again: ";
        }
    }

    return intConversion;
}

/*
Purpose:    This function determines if a string represents an integer.

Entry:      "inputStr" is the string that may represent an integer.

Exit:       Whether or not the string represents an integer is returned.
*/
bool UtilFuncs::IsStrInt(std::string inputStr)
{
    std::string::iterator pos; // Stores a position in the input string.

    // Remove leading whitespace characters.
    while (*(pos = inputStr.begin()) == ' ' || *pos == '\t') {
        inputStr.erase(pos);
    }

    // Remove trailing whitespace characters.
    while (*(pos = inputStr.end() - 1) == ' ' || *pos == '\t') {
        inputStr.erase(pos);
    }

    // Insert the input string into a string stream.
    std::istringstream strStream(inputStr);

    // The string is an integer if all of the contents of the stream can be
    // successfully extracted in a single operation.
    int intConversion;
    return (strStream >> intConversion && strStream.eof());
}

/*
Purpose:    This function pauses for a specified number of seconds.

Entry:      "sec" is the pause duration in seconds.

Exit:       None
*/
void UtilFuncs::Wait(double sec)
{
    clock_t start = clock();

    //-------------------------------------------------------------------------
    // Requirement #02: Demonstrate explicit type casting.
    //-------------------------------------------------------------------------
    // Pause until the specified amount of time has passed.
    while (((clock() - start) / (double) CLOCKS_PER_SEC) < sec);
    // or while (((clock() - start) / static_cast<double>(CLOCKS_PER_SEC)) < sec);
}

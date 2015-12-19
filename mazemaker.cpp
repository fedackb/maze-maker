/*
Author: Brett Fedack
Date Created: 28 August 2014
Last Modification Date: 31 August 2014
Final Project
File name: mazemaker.cpp

Overview:   This program creates a random maze and saves it to a file.  The
            user can specify four options to affect the maze making process:

                (1) Start at a random position.
                (2) End at a random position.
                (3) Solve the maze.
                (4) Animate the process.
*/

#include <fstream>
#include <iostream>
#include <string>
#include "Constants.hpp"
#include "Maze.hpp"
#include "Menus.hpp"
#include "Puzzle.hpp"
#include "UtilFuncs.hpp"

using UtilFuncs::InputIntInRange;

int main(int argc, char *argv[])
{
    int sel; // Stores the user's menu selection.

    //-------------------------------------------------------------------------
    // Requirement #16: Demonstrate the use of a class instance (object).
    //-------------------------------------------------------------------------
    Maze maze;
    // or Maze maze = Maze();

    //-------------------------------------------------------------------------
    // Requirement #15: Demonstrate the use of a command line argument.
    //-------------------------------------------------------------------------
    // At most one argument in addition to the program name is allowed.
    if (argc != 2) {
        std::cout << "Usage: mazemaker <output filename>\n";
        exit(-1);
    }

    //-------------------------------------------------------------------------
    // Requirement #12: Demonstrate a string object and a null terminated
    //                  character array.
    //-------------------------------------------------------------------------
    std::string filename = argv[1];
    int filenameSize = filename.size();
    char cStringFilename[filenameSize + 1];
    for (int i = 0; i < filenameSize; ++i) {
        cStringFilename[i] = filename.at(i);
    }
    cStringFilename[filenameSize] = '\0';

    //-------------------------------------------------------------------------
    // Requirement #06: Demonstrate a syntax error.
    //------------------------------------------------------------------------- 
    // Attempting to assign a value of the wrong type to a variable that has no
    // rules for automatic type conversion will result in a syntax error.
    // cStringFilename[filenameSize] = "\0";

    //-------------------------------------------------------------------------
    // Requirement #06: Demonstrate a run-time error.
    //------------------------------------------------------------------------- 
    // A file that cannot be opened, perhaps due to access privileges, is an
    // example of a run-time error.
    //-------------------------------------------------------------------------
    // Requirement #23: Demonstrate file I/O.
    //------------------------------------------------------------------------- 
    // Verify that the file can be opened, truncating any exiting data in the
    // process.
    std::ofstream ofs(cStringFilename);
    if (ofs.fail()) {
        std::cout << '"' << argv[1] << '"' << " could not be opened.\n";
        exit(-1);
    }

    // Process selections from the main main until the user chooses to run the
    // maze maker or quit.
    while ((sel = InputIntInRange(1, 3, MAIN_MENU, true)) == 2) {

        // Set the maze options accordingly.
        while ((sel = InputIntInRange(1, 5, buildOptionsMenu(maze), true)) != 5) {
            switch (sel) {
                case 1:
                    maze.toggle(RANDOM_START_BIT);
                    break;
                case 2:
                    maze.toggle(RANDOM_END_BIT);
                    break;
                case 3:
                    maze.toggle(SOLVE_BIT);
                    break;
                case 4:
                    maze.toggle(ANIMATE_BIT);
                    break;
                default:
                    break;
            }
        }
    }

    // Run the maze maker.
    //-------------------------------------------------------------------------
    // Requirement #06: Demonstrate a logical error.
    //------------------------------------------------------------------------- 
    // If an assignment operator is used when an equality operator is intended,
    // a logical error may result. In the following example, the condition will
    // always evaluate to true, which is not the desired behavior.
    // if (sel = 1) {
    if (sel == 1) {

        //---------------------------------------------------------------------
        // Requirement #24: Demonstrate polymorphism.
        //---------------------------------------------------------------------
        //---------------------------------------------------------------------
        // Requirement #17: Demonstrate a pointer to an object.
        //---------------------------------------------------------------------
        Puzzle *ptrToPuzzle = &maze;
        ptrToPuzzle->run();

        // Write the maze to the output file.
        ofs << maze;
        if (!ofs.fail()) {
            std::cout << "Maze successfully written to "
                      << '"' << filename << '"' << ".\n";
        }
        ofs.close();
    }

    return 0;
}

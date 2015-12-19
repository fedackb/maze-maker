#ifndef FEDACKB_MAZE_H
#define FEDACKB_MAZE_H

#include <iostream>
#include <string>
#include "Cell.hpp"
#include "Puzzle.hpp"

//-----------------------------------------------------------------------------
// Requirement #16: Demonstrate a class definition.
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Requirement #24: Demonstrate inheritance.
//-----------------------------------------------------------------------------
class Maze: public Puzzle {
    public:
        Maze(); // Default constructor
        Maze(const Maze &); // Copy constructor
        ~Maze(); // Destructor

        // Interface
        void disable(unsigned char); // Disables all passed options
        void enable(unsigned char); // Enables all passed options
        bool query(unsigned char) const; // Determines if an option is enabled
        void toggle(unsigned char); // Toggles the passed options

        void run(); // Runs the maze maker

    private:
        bool isSolved; // Stores whether a not a solution has been found
        Cell **cells; // A dynamically allocated two-dimensional array of cells
        Cell *start; // Points to the start cell
        Cell *end; // Points to the end cell
        unsigned char options; // Stores the boolean bit options

        void build(Cell &); // Recursively generates a random maze
        void display(bool = false); // Prints the maze to standard output
        void linkCells(); // Links each cell to its four neighbor cells.
        void reset(unsigned char); // Resets the maze's state
        void solve(Cell &); // Finds the solution path
        void verifyCellWallIntegrity(); // Debugging member function

        friend std::ostream & operator<<(std::ostream &, const Maze &);
};

#endif

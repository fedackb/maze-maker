#include <iostream>
#include <string>
#include "Cell.hpp"
#include "Constants.hpp"
#include "Maze.hpp"
#include "UtilFuncs.hpp"

// Define an enumeration for the cardinal directions.
enum {NORTH = 0, EAST, SOUTH, WEST};

//-----------------------------------------------------------------------------
// Requirement #10: Demonstrate variable scope.
//-----------------------------------------------------------------------------
// This constant variable--yes, technically a variable--is defined outside of
// any function, conditional, loop, etc.  Therefore, it is global in scope.
// However, the "static" keyword restricts the scope to a single source file.
// Specifically, the variable is only visible to and accessible from the
// functions defined within this file.
static const int NUM_NEIGHBORS = 4; // Each cell has, at most, four neighbors

//-----------------------------------------------------------------------------
// Requirement #21: Demonstrate a default constructor.
//-----------------------------------------------------------------------------
Maze::Maze()
{
    // Set the default options.
    this->enable(SOLVE_BIT | ANIMATE_BIT);
    this->disable(RANDOM_START_BIT | RANDOM_END_BIT | SOLVE_BIT | ANIMATE_BIT);

    //-------------------------------------------------------------------------
    // Requirement #25: Demonstrate exception handling.
    //-------------------------------------------------------------------------
    try
    {
        //---------------------------------------------------------------------
        // Requirement #14: Demonstrate a dynamically allocated array.
        //---------------------------------------------------------------------
        // Dynamically allocate memory for the "cells" data member.
        this->cells = new Cell * [CELLS_PER_ROW];
        for (int x = 0; x < CELLS_PER_ROW; ++x) {
            this->cells[x] = new Cell [CELLS_PER_COL];
        }
    }
    catch(std::bad_alloc &e)
    {
        std::cout << "Memory allocation error encountered. Exiting...\n";
        exit(-1);
    }

    // Link the pointer data members for each cell.
    this->linkCells();
}

//-----------------------------------------------------------------------------
// Requirement #21: Demonstrate a copy constructor.
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Requirement #08: Demonstrate an overloaded function.
//-----------------------------------------------------------------------------
// Although constructors are special kinds of functions, they can still be
// overloading in the same manner as normal functions.  Specifically, when two
// or more constructors share the same identifier, one is called over the other
// based on the number and type of arguments passed.
// e.g.     Maze a = Maze(); // Default constructor called
//          Maze b = Maze(a); // Copy constructor called
Maze::Maze(const Maze &other)
{
    Cell *ptrToCell = NULL; // References a cell in the copy target
    Cell *ptrToOtherCell = NULL; // References a cell in the copy source

    try
    {
        // Dynamically allocate memory for the "cells" data member.
        this->cells = new Cell *[CELLS_PER_ROW];
        for (int x = 0; x < CELLS_PER_ROW; ++x) {
            this->cells[x] = new Cell [CELLS_PER_COL];
        }
    }
    catch(std::bad_alloc &e)
    {
        std::cout << "Memory allocation error encountered. Exiting...\n";
        exit(-1);
    }

    // Copy the boolean values from each cell in the copy source to the
    // corresponding cell in the copy target.
    for (int x = 0; x < CELLS_PER_ROW; ++x) {
        for (int y = 0; y < CELLS_PER_COL; ++y) {

            // Reference the pair of corresponding cells.
            ptrToCell = &this->cells[x][y];
            ptrToOtherCell = &other.cells[x][y];

            // Copy the boolean values.
            ptrToCell->isInSolutionPath = ptrToOtherCell->isInSolutionPath;
            ptrToCell->isVisited = ptrToOtherCell->isVisited;
            ptrToCell->northWallIsUp = ptrToOtherCell->northWallIsUp;
            ptrToCell->eastWallIsUp = ptrToOtherCell->eastWallIsUp;
            ptrToCell->southWallIsUp = ptrToOtherCell->southWallIsUp;
            ptrToCell->westWallIsUp = ptrToOtherCell->westWallIsUp;
        }
    }

    // Link the pointer data members for each cell.
    this->linkCells();

    // Ensure that the start and end pointers reference cells in the copy
    // target, not the copy source.
    for (int x = 0; x < CELLS_PER_ROW; ++x) {
        for (int y = 0; y < CELLS_PER_COL; ++y) {

            // Point to the copied start cell.
            if (other.start == &other.cells[x][y]) {
                this->start = &this->cells[x][y];
            }

            // Point to the copied end cell.
            else if (other.end == &other.cells[x][y]) {
                this->end = &this->cells[x][y];
            }
        }
    }

    // Copy the options bits.
    this->options = other.options;
}

//-----------------------------------------------------------------------------
// Requirement #21: Demonstrate a destructor.
//-----------------------------------------------------------------------------
Maze::~Maze()
{
    //-------------------------------------------------------------------------
    // Requirement #04: Demonstrate a loop.
    //-------------------------------------------------------------------------
    // Release the allocated memory for the "cells" data member.
    for (int i = 0; i < CELLS_PER_ROW; ++i) {
        delete[] this->cells[i];
    }
    delete this->cells;
}

/*
Purpose:    This member function disables one or more maze options.

Entry:      "bits" is an 8-bit number where each bit corresponds to a
            particular boolean option.

Exit:       The data member "options" is modified.
*/
void Maze::disable(unsigned char bits)
{
    //-------------------------------------------------------------------------
    // Requirement #03: Demonstrate bitwise XOR and bitwise AND operators.
    //-------------------------------------------------------------------------
    // Disable options.
    this->options &= (bits ^ INVERSION_MASK);
}

/*
Purpose:    This member function enables one or more maze options.

Entry:      "bits" is an 8-bit number where each bit corresponds to a
            particular boolean option.

Exit:       The data member "options" is modified.
*/
void Maze::enable(unsigned char bits)
{
    //-------------------------------------------------------------------------
    // Requirement #03: Demonstrate bitwise OR operator.
    //-------------------------------------------------------------------------
    // Enable options.
    this->options |= bits;
}

/*
Purpose:    This member function determines if a specific maze option is
            enabled.

Entry:      "bits" is an 8-bit number where each bit corresponds to a
            particular boolean option.

Exit:       Whether or not all of the bits of interest are enabled is returned.
*/
bool Maze::query(unsigned char bits) const
{
    //-------------------------------------------------------------------------
    // Requirement #03: Demonstrate logical OR, logical AND, negation, and
    //                 equivalence operators.
    //-------------------------------------------------------------------------
    unsigned char A, B, C, D;
    A = RANDOM_START_BIT;
    B = RANDOM_END_BIT;
    C = SOLVE_BIT;
    D = ANIMATE_BIT;
    if (
        !(bits == A || bits == B || bits == C || bits == D) &&
         (bits != A && bits != B && bits != C && bits != D)
    ) {
        std::cout << "Unrecognized option encountered." << std::endl;
    }

    // Determine if the bits are enabled.
    return (this->options & bits) > 0;
}

/*
Purpose:    This member function toggles one or more options.

Entry:      "bits" is an 8-bit number where each bit corresponds to a
            particular boolean option.

Exit:       The data member "options" is modified.
*/
void Maze::toggle(unsigned char bits)
{
    // Toggle options.
    this->options ^= bits;
}

//-----------------------------------------------------------------------------
// Requirement #09: Demonstrate functional decomposition.
//-----------------------------------------------------------------------------
/*
Purpose:    This member function is responsible for running the maze puzzle.
*/
void Maze::run()
{
    int randX; // Stores a random x-coordinate for a cell
    int randY; // Stores a random y-coordinate for a cell

    // Completely reset the maze.
    this->reset(
        RESET_VISITS_BIT |
        RESET_WALLS_BIT |
        RESET_SOLUTION_BIT |
        RESET_ENDPOINTS_BIT
    );

    // Recursively build the maze, starting from a random cell.
    randX = UtilFuncs::GenRandInt(0, CELLS_PER_ROW - 1);
    randY = UtilFuncs::GenRandInt(0, CELLS_PER_COL - 1);
    this->build(this->cells[randX][randY]);

    // Reset each cell's visit flag.
    this->reset(RESET_VISITS_BIT);

    // Solve the maze.
    if (this->query(SOLVE_BIT)) {
        this->solve(*this->start);
    }

    // Clear the screen, and display the maze.
    this->display(true);
}

//-----------------------------------------------------------------------------
// Requirement #11: Demonstrate pass by reference.
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Requirement #13: Demonstrate recursion.
//-----------------------------------------------------------------------------
/*
Purpose:    This member function recursively builds a random maze using a depth
            first search algorithm.

Entry:      "cell" is a reference to a cell in the maze.

Exit:       The data members "cells" is modified.
*/
void Maze::build(Cell &cell)
{
    // Mark the cell as visited.
    cell.isVisited = true;

    // If the option to animate the process is enabled, display the maze and
    // pause briefly.
    if (this->query(ANIMATE_BIT)) {
        this->display(true);
        UtilFuncs::Wait(PAUSE_PERIOD);
    }

    // Create a random permutation of the directions to neighbor cells.
    int directions[] = {NORTH, EAST, SOUTH, WEST};
    UtilFuncs::RandPermutation(directions, NUM_NEIGHBORS);

    // For each adjacent cell in random order, lower the separating wall and
    // invoke a recursive call on the neighbor if it has not yet been visited.
    for (int i = 0; i < NUM_NEIGHBORS; ++i) {

        // North neighbor
        if (directions[i] == NORTH && cell.northCell != NULL) {
            if (!cell.northCell->isVisited) {

                // Lower the wall separating the cells.
                cell.northWallIsUp = false;
                cell.northCell->southWallIsUp = false;

                // Invoke a recursive call on the north cell.
                build(*cell.northCell);
            }
        }

        // East neighbor
        else if (directions[i] == EAST && cell.eastCell != NULL) {
            if (!cell.eastCell->isVisited) {

                // Lower the wall separating the cells.
                cell.eastWallIsUp = false;
                cell.eastCell->westWallIsUp = false;

                // Invoke a recursive call on the east cell.
                build(*cell.eastCell);
            }
        }

        // South neighbor
        else if (directions[i] == SOUTH && cell.southCell != NULL) {
            if (!cell.southCell->isVisited) {

                // Lower the wall separating the cells.
                cell.southWallIsUp = false;
                cell.southCell->northWallIsUp = false;

                // Invoke a recursive call on the south cell.
                build(*cell.southCell);
            }
        }

        // West neighbor
        else if (directions[i] == WEST && cell.westCell != NULL) {
            if (!cell.westCell->isVisited) {

                // Lower the wall separating the cells.
                cell.westWallIsUp = false;
                cell.westCell->eastWallIsUp = false;

                // Invoke a recursive call on the west cell.
                build(*cell.westCell);
            }
        }
    }
}

/*
Purpose:    This member function displays the maze by inserting it into the
            standard output stream.

Entry:      "clearScreen" is a flag for clearing the screen prior to displaying
            the maze.

Exit:       None
*/
void Maze::display(bool clearScreen)
{
    if (clearScreen) UtilFuncs::ClearScreen();

    std::cout << *this;
}

/*
Purpose:    This member function links each cell to its four neighbors cells.

Entry:      None

Exit:       The data member "cells" is modified.
*/
void Maze::linkCells()
{
    Cell *ptrToCell = NULL; // Stores a reference to a single cell in the maze

    // Link the cells.
    for (int x = 0; x < CELLS_PER_ROW; ++x) {
        for (int y = 0; y < CELLS_PER_COL; ++y) {
            ptrToCell = &this->cells[x][y];

            // Link the cell to its four neighbors.
            if (x > 0) {
                ptrToCell->westCell = &this->cells[x - 1][y];
            }
            else {
                ptrToCell->westCell = NULL;
            }
            if (x < CELLS_PER_ROW - 1) {
                ptrToCell->eastCell = &this->cells[x + 1][y];
            }
            else {
                ptrToCell->eastCell = NULL;
            }
            if (y > 0) {
                ptrToCell->northCell = &this->cells[x][y - 1];
            }
            else {
                ptrToCell->northCell = NULL;
            }
            if (y < CELLS_PER_COL - 1) {
                ptrToCell->southCell = &this->cells[x][y + 1];
            }
            else {
                ptrToCell->southCell = NULL;
            }
        }
    }
}

/*
Purpose:    This member function resets the maze according by doing one or more
            of the following:

                (1) Flag each cell as unvisited.
                (2) Raise all cell walls.
                (3) Reset the solution.
                (4) Reset the start and end positions.

Entry:      "bits" is an 8-bit number where each bit corresponds to a
            particular boolean option.

Exit:       The data members "cells" is modified.
*/
void Maze::reset(unsigned char bits)
{
    int randX; // Stores a random x-coordinate for a cell
    int randY; // Stores a random y-coordinate for a cell

    //-------------------------------------------------------------------------
    // Requirement #17: Demonstrate a pointer to a struct.
    //-------------------------------------------------------------------------
    Cell *ptrToStruct = NULL;
    // Flag each cell as unvisited.
    if ((bits & RESET_VISITS_BIT) > 0) {
        for (int x = 0; x < CELLS_PER_ROW; ++x) {
            for (int y = 0; y < CELLS_PER_COL; ++y) {
                ptrToStruct = &this->cells[x][y];

                //-------------------------------------------------------------
                // Requirement #16: Demonstrate the use of a struct.
                //-------------------------------------------------------------
                ptrToStruct->isVisited = false;
                // or (*ptrToStruct).isVisited = false;
                // or (*(ptrToStruct + 0)).isVisited = false;
                // or ptrToStruct[0].isVisited = false;
            }
        }
    }

    // Raise all cell walls.
    if ((bits & RESET_WALLS_BIT) > 0) {
        for (int x = 0; x < CELLS_PER_ROW; ++x) {
            for (int y = 0; y < CELLS_PER_COL; ++y) {
                this->cells[x][y].northWallIsUp = true;
                this->cells[x][y].eastWallIsUp = true;
                this->cells[x][y].southWallIsUp = true;
                this->cells[x][y].westWallIsUp = true;
            }
        }
    }

    // Reset the solution.
    if ((bits & RESET_SOLUTION_BIT) > 0) {

        // Flag each cell as not in the solution path.
        for (int x = 0; x < CELLS_PER_ROW; ++x) {
            for (int y = 0; y < CELLS_PER_COL; ++y) {
                this->cells[x][y].isInSolutionPath = false;
            }
        }

        // Indicate that the maze is unsolved.
        this->isSolved = false;
    }

    // Reset the start and end positions, ensuring that they are not the same.
    if ((bits & RESET_ENDPOINTS_BIT) > 0) {
        do {
            // Set the start position to either the upper left corner or a
            // random cell.
            if (this->query(RANDOM_START_BIT)) {
                randX = UtilFuncs::GenRandInt(0, CELLS_PER_ROW - 1);
                randY = UtilFuncs::GenRandInt(0, CELLS_PER_COL - 1);
                this->start = &this->cells[randX][randY];
            }
            else {
                this->start = &this->cells[0][0];
            }

            // Set the end position to either the lower right corner or a
            // random cell.
            if (this->query(RANDOM_END_BIT)) {
                randX = UtilFuncs::GenRandInt(0, CELLS_PER_ROW - 1);
                randY = UtilFuncs::GenRandInt(0, CELLS_PER_COL - 1);
                this->end = &this->cells[randX][randY];
            }
            else {
                this->end = &this->cells[CELLS_PER_ROW - 1][CELLS_PER_COL - 1];
            }
        } while (this->start == this->end);
    }
}

/*
Purpose:    This member function recursive finds a path from the specified cell
            to the end of the maze using a depth first search algorithm.

Entry:      "cell" is a reference to a cell in the maze.

Exit:       The data members "cells" is modified.
*/
void Maze::solve(Cell &cell)
{
    // Mark the cell as both visited and part of the solution path.
    cell.isVisited = true;
    cell.isInSolutionPath = true;

    // If the option to animate the process is enabled, display the maze and
    // pause briefly.
    if (this->query(ANIMATE_BIT)) {
        this->display(true);
        UtilFuncs::Wait(PAUSE_PERIOD);
    }

    // Flag the maze as solved if the path has arrived at the end of the maze.
    if (&cell == this->end) this->isSolved = true;

    // Create a random permutation of the directions to neighbor cells.
    int directions[] = {NORTH, EAST, SOUTH, WEST};
    UtilFuncs::RandPermutation(directions, NUM_NEIGHBORS);

    // For each adjacent cell in random order, invoke a recursive call on the
    // neighbor if it can be reached and has not yet been visited before the
    // maze is solved.
    for (int i = 0; i < NUM_NEIGHBORS; ++i) {

        // North neighbor
        if (directions[i] == NORTH && cell.northCell != NULL) {
            if (!cell.northCell->isVisited && !cell.northWallIsUp && !this->isSolved) {

                // Invoke a recursive call on the north cell.
                solve(*cell.northCell);
            }
        }

        // East neighbor
        if (directions[i] == EAST && cell.eastCell != NULL) {
            if (!cell.eastCell->isVisited && !cell.eastWallIsUp && !this->isSolved) {

                // Invoke a recursive call on the east cell.
                solve(*cell.eastCell);
            }
        }

        // South neighbor
        if (directions[i] == SOUTH && cell.southCell != NULL) {
            if (!cell.southCell->isVisited && !cell.southWallIsUp && !this->isSolved) {

                // Invoke a recursive call on the south cell.
                solve(*cell.southCell);
            }
        }

        // West neighbor
        if (directions[i] == WEST && cell.westCell != NULL) {
            if (!cell.westCell->isVisited && !cell.westWallIsUp && !this->isSolved) {

                // Invoke a recursive call on the west cell.
                solve(*cell.westCell);
            }
        }
    }

    // If this function returns before the maze is solved then the cell is not
    // part of the solution path.
    if (!this->isSolved) {
        cell.isInSolutionPath = false;

        // Animate the removal of the cell from the solution path.
        if (this->query(ANIMATE_BIT)) {
            this->display(true);
            UtilFuncs::Wait(PAUSE_PERIOD);
        }
    }
}

//-----------------------------------------------------------------------------
// Requirement #07: Demonstrate a debugging trick.
//-----------------------------------------------------------------------------
// Print statements are useful in determining at what point an unexpected value
// is encountered, which can help in directing the programmer to an error.  A
// slightly more sophisticated approach is to have a function that runs a
// specific debugging test and prints the result.
/*
Purpose:    This member function is for debugging purposes, specifically for
            confirming that both sides of each ell wall have the same state.

Entry:      None

Exit:       None
*/
void Maze::verifyCellWallIntegrity()
{
    Cell *ptrToCell; // Stores a reference to an individual cell in the maze

    // Each cell has two sides; vertical walls have east and west sides, and
    // horizontal walls have north and south sides.  Confirm that the sides of
    // each wall are in agreement with regard to whether or not the wall is up,
    // starting with the assumption that this is true.
    bool wallSidesAreSynchronized = true;

    // Test the assumption.
    for (int x = 0; x < CELLS_PER_ROW && wallSidesAreSynchronized; ++x) {
        for (int y = 0; y < CELLS_PER_COL && wallSidesAreSynchronized; ++y) {
            ptrToCell = &this->cells[x][y];

            // Check the north wall.
            if (ptrToCell->northCell != NULL) {
                if (ptrToCell->northWallIsUp != ptrToCell->northCell->southWallIsUp) {
                    wallSidesAreSynchronized = false;
                }
            }

            // Check the east wall.
            if (ptrToCell->eastCell != NULL) {
                if (ptrToCell->eastWallIsUp != ptrToCell->eastCell->westWallIsUp) {
                    wallSidesAreSynchronized = false;
                }
            }

            // Check the south wall.
            if (ptrToCell->southCell != NULL) {
                if (ptrToCell->southWallIsUp != ptrToCell->southCell->northWallIsUp) {
                    wallSidesAreSynchronized = false;
                }
            }

            // Check the west wall.
            if (ptrToCell->westCell != NULL) {
                if (ptrToCell->westWallIsUp != ptrToCell->westCell->eastWallIsUp) {
                    wallSidesAreSynchronized = false;
                }
            }
        }
    }

    if (wallSidesAreSynchronized) {
        std::cout << "The sides of each wall are in sync.\n";
    }
    else {
        std::cout << "The sides of at least one wall are out of sync.\n";
    }
}

//-----------------------------------------------------------------------------
// Requirement #22: Demonstrate operator overloading.
//-----------------------------------------------------------------------------
/*
Purpose:    This friend of the Maze class defines the operation that is
            associated with the stream insertion operator when a maze appears
            as the right-hand-side operand.

Entry:      "out" is a reference to the output stream

            "rhs" is the maze operand being inserted into the stream.

Exit:       The output stream reference is returned.
*/
std::ostream & operator<<(std::ostream &out, const Maze &rhs)
{
    Cell *ptrToCell = NULL; // Stores a reference to a single cell in the maze
    char centerSymbol; // Stores a character to display at the center of a cell
    int centerX, centerY; // Coordinates of a cell's center in the maze display
    int offsetX; // Distance from a cell's center to its east and west walls
    int offsetY; // Distance from a cell's center to its north and south walls
    offsetX = CELL_WIDTH / 2;
    offsetY = CELL_HEIGHT / 2;

    //-------------------------------------------------------------------------
    // Requirement #14: Demonstrate a two-dimensional array.
    //-------------------------------------------------------------------------
    char mazeDisplay[MAZE_WIDTH][MAZE_HEIGHT];

    // Initialize each element of the maze display as a space character.
    //-------------------------------------------------------------------------
    // Requirement #17: Demonstrate a pointer to an array.
    //-------------------------------------------------------------------------
    // The value of an array is the address of its zeroth element.  In the case
    // of a two-dimensional array, it is the address of an array, which can be
    // stored in a pointer variable.
    char (*ptrToArray)[MAZE_HEIGHT] = mazeDisplay;
    for (int x = 0; x < MAZE_WIDTH; ++x) {
        for (int y = 0; y < MAZE_HEIGHT; ++y) {
            ptrToArray[x][y] = ' ';
        }
    }

    // Write each cell to the maze display.
    for (int x = 0; x < CELLS_PER_ROW; ++x) {
        for (int y = 0; y < CELLS_PER_COL; ++y) {
            ptrToCell = &rhs.cells[x][y];

            // Determine the coordinates of the cell's center in the maze
            // display.
            centerX = x * (CELL_WIDTH - 1) + offsetX;
            centerY = y * (CELL_HEIGHT - 1) + offsetY;

            // Use special characters to denote cells at the start end or in
            // the solution path of the maze.
            if (ptrToCell == rhs.start) {
                centerSymbol = 'o';
            }
            else if (ptrToCell == rhs.end) {
                centerSymbol = 'x';
            }
            else if (ptrToCell->isInSolutionPath) {
                centerSymbol = '*';
            }
            else {
                centerSymbol = ' ';
            }
            mazeDisplay[centerX][centerY] = centerSymbol;

            // Write the cell's corners to the maze display.
            mazeDisplay[centerX - offsetX][centerY + offsetY] = '+';
            mazeDisplay[centerX + offsetX][centerY + offsetY] = '+';
            mazeDisplay[centerX + offsetX][centerY - offsetY] = '+';
            mazeDisplay[centerX - offsetX][centerY - offsetY] = '+';

            // Write the cell's walls to the maze display.
            if (ptrToCell->northWallIsUp) {
                for (int x = centerX - offsetX + 1; x < centerX + offsetX; ++x) {
                    mazeDisplay[x][centerY - offsetY] = '-';
                }
            }
            if (ptrToCell->southWallIsUp) {
                for (int x = centerX - offsetX + 1; x < centerX + offsetX; ++x) {
                    mazeDisplay[x][centerY + offsetY] = '-';
                }
            }
            if (ptrToCell->eastWallIsUp) {
                for (int y = centerY - offsetY + 1; y < centerY + offsetY; ++y) {
                    mazeDisplay[centerX + offsetX][y] = '|';
                }
            }
            if (ptrToCell->westWallIsUp) {
                for (int y = centerY - offsetY + 1; y < centerY + offsetY; ++y) {
                    mazeDisplay[centerX - offsetX][y] = '|';
                }
            }
        }
    }

    // Insert the maze display into the output stream.
    for (int y = 0; y < MAZE_HEIGHT; ++y) {
        for (int x = 0; x < MAZE_WIDTH; ++x) {
            out << mazeDisplay[x][y];
        }
        out << std::endl;
    }

    return out;
}

#ifndef FEDACKB_CONSTANTS_H
#define FEDACKB_CONSTANTS_H

#include <string>

// The maze should fit within an 80x24 SSH session.
const int MAX_WIDTH = 80;
const int MAX_HEIGHT = 24;

// Each cell is five characters wide by three characters high.
const int CELL_WIDTH = 5;
const int CELL_HEIGHT = 3;

// Each cell wall is one character thick and overlaps with the adjacent wall of
// another cell (two sides of the same wall).  Accounting for this, determine
// how many cells fit within the maximum maze dimensions.
const int CELLS_PER_ROW = (MAX_WIDTH - 1) / (CELL_WIDTH - 1);
const int CELLS_PER_COL = (MAX_HEIGHT - 1) / (CELL_HEIGHT - 1);

// Determine the dimensions of the maze in character units.
const int MAZE_WIDTH = (CELL_WIDTH - 1) * CELLS_PER_ROW + 1;
const int MAZE_HEIGHT = (CELL_HEIGHT - 1) * CELLS_PER_COL + 1;

// An unsigned char is a 1-byte nonnegative number, allowing up to eight
// boolean values to be stored in a single variable.
const unsigned char RANDOM_START_BIT = 1; // Binary 0000 0001
const unsigned char RANDOM_END_BIT = 2; // Binary 0000 0010
const unsigned char SOLVE_BIT = 4; // Binary 0000 0100
const unsigned char ANIMATE_BIT = 8; // Binary 0000 1000
const unsigned char RESET_VISITS_BIT = 16; // Binary 0001 0000
const unsigned char RESET_WALLS_BIT = 32; // Binary 0010 0000
const unsigned char RESET_SOLUTION_BIT = 64; // Binary 0100 0000
const unsigned char RESET_ENDPOINTS_BIT = 128; // Binary 1000 0000
const unsigned char INVERSION_MASK = 255; // Binary 1111 1111

// Define an animation driver.
const double PAUSE_PERIOD = 0.075;

#endif

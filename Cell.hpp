#ifndef FEDACKB_CELL_H
#define FEDACKB_CELL_H

//-----------------------------------------------------------------------------
// Requirement #16: Demonstrate a struct definition.
//-----------------------------------------------------------------------------
struct Cell {
    bool isVisited;
    bool isInSolutionPath;
    bool northWallIsUp;
    bool eastWallIsUp;
    bool southWallIsUp;
    bool westWallIsUp;

    // Store adjacency information in the cell.
    Cell *northCell;
    Cell *eastCell;
    Cell *southCell;
    Cell *westCell;
};

#endif

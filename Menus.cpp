#include <string>
#include "Constants.hpp"
#include "Maze.hpp"
#include "Menus.hpp"

/*
Purpose:    This function uses a maze's data to builds a string to display for
            the options menu.

Entry:      "mazeData" is the maze from which to read data.

Exit:       The generated string is returned.
*/
std::string buildOptionsMenu(const Maze &mazeData)
{
    // Create the options menu.
    std::string optionsMenu = "";
    optionsMenu.append("1:   Start from a random position ");
    optionsMenu.append(mazeData.query(RANDOM_START_BIT) ? "[x]\n" : "[ ]\n");
    optionsMenu.append("2:   End at a random position ");
    optionsMenu.append(mazeData.query(RANDOM_END_BIT) ? "[x]\n" : "[ ]\n");
    optionsMenu.append("3:   Solve the maze ");
    optionsMenu.append(mazeData.query(SOLVE_BIT) ? "[x]\n" : "[ ]\n");
    optionsMenu.append("4:   Animate the process ");
    optionsMenu.append(mazeData.query(ANIMATE_BIT) ? "[x]\n" : "[ ]\n");
    optionsMenu.append("5:   Back\n");
    optionsMenu.append("Select a menu option: ");

    return optionsMenu;
}

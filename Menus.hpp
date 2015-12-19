#ifndef FEDACKB_MENUS_H
#define FEDACKB_MENUS_H

#include <string>
#include "Maze.hpp"

const std::string MAIN_MENU = R"(
  __  __                 __  __       _             
 |  \/  |               |  \/  |     | |            
 | \  / | __ _ _______  | \  / | __ _| | _____ _ __ 
 | |\/| |/ _` |_  / _ \ | |\/| |/ _` | |/ / _ \ '__|
 | |  | | (_| |/ /  __/ | |  | | (_| |   <  __/ |   
 |_|  |_|\__,_/___\___| |_|  |_|\__,_|_|\_\___|_|   
                                                    
1.   Run
2.   Options
3.   Quit
Select a menu option: )";

// Declare a function to build the options menu string from a maze's data.
std::string buildOptionsMenu(const Maze &);

#endif

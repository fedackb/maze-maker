# **MazeMaker**

![maze](https://cloud.githubusercontent.com/assets/8960984/11910785/b3757a90-a5bc-11e5-94d8-8133e5df538f.gif)

This project was created in fulfillment of a freshman level programming assignment. Given a list of programming concepts and C++ features, students were tasked with creating any program that effectively demonstrates each item from the specification. I chose to create a random maze generator that can optionally find the solution path and animate the entire process.

### **Concept/Feature Listing**

| Demonstrate...                             | Filename      | Line Number                                                                 |
| ------------------------------------------ | ------------- | --------------------------------------------------------------------------- |
| input/output                               | UtilFuncs.cpp | [55](https://github.com/fedackb/maze-maker/blob/master/UtilFuncs.cpp#L55)   |
| explicit type casting                      | UtilFuncs.cpp | [148](https://github.com/fedackb/maze-maker/blob/master/UtilFuncs.cpp#L148) |
| bitwise XOR and AND operators              | Maze.cpp      | [154](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L154)      |
| bitwise OR operator                        | Maze.cpp      | [171](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L171)      |
| logical and equivalence operators          | Maze.cpp      | [189](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L189)      |
| loop                                       | Maze.cpp      | [134](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L134)      |
| random integer                             | UtilFuncs.cpp | [48](https://github.com/fedackb/maze-maker/blob/master/UtilFuncs.cpp#L48)   |
| syntax error                               | mazemaker.cpp | [60](https://github.com/fedackb/maze-maker/blob/master/mazemaker.cpp#L60)   |
| run-time error                             | mazemaker.cpp | [67](https://github.com/fedackb/maze-maker/blob/master/mazemaker.cpp#L67)   |
| logical error                              | mazemaker.cpp | [109](https://github.com/fedackb/maze-maker/blob/master/mazemaker.cpp#L109) |
| debugging trick                            | Maze.cpp      | [585](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L585)      |
| overloaded function                        | Maze.cpp      | [58](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L58)        |
| function definition                        | UtilFuncs.cpp | [9](https://github.com/fedackb/maze-maker/blob/master/UtilFuncs.cpp#L9)     |
| functional decomposition                   | Maze.cpp      | [223](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L223)      |
| variable scope                             | Maze.cpp      | [12](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L12)        |
| pass by reference                          | Maze.cpp      | [259](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L259)      |
| pass by value                              | UtilFuncs.cpp | [26](https://github.com/fedackb/maze-maker/blob/master/UtilFuncs.cpp#L26)   |
| pass by value to a pointer parameter       | UtilFuncs.hpp | [39](https://github.com/fedackb/maze-maker/blob/master/UtilFuncs.hpp#L39)   |
| string object & null terminated char array | mazemaker.cpp | [48](https://github.com/fedackb/maze-maker/blob/master/mazemaker.cpp#L48)   |
| recursion                                  | Maze.cpp      | [262](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L262)      |
| dynamically allocated array                | Maze.cpp      | [36](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L36)        |
| two-dimensional array                      | Maze.cpp      | [677](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L677)      |
| use of a command line argument             | mazemaker.cpp | [39](https://github.com/fedackb/maze-maker/blob/master/mazemaker.cpp#L39)   |
| struct definition                          | Cell.hpp      | [5](https://github.com/fedackb/maze-maker/blob/master/Cell.hpp#L5)          |
| use of a class instance                    | mazemaker.cpp | [33](https://github.com/fedackb/maze-maker/blob/master/mazemaker.cpp#L33)   |
| class definition                           | Maze.hpp      | [10](https://github.com/fedackb/maze-maker/blob/master/Maze.hpp#L10)        |
| pointer to an object                       | mazemaker.cpp | [121](https://github.com/fedackb/maze-maker/blob/master/mazemaker.cpp#L121) |
| pointer to a struct                        | Maze.cpp      | [427](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L427)      |
| pointer to an array                        | Maze.cpp      | [683](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L683)      |
| custom namespace                           | UtilFuncs.hpp | [11](https://github.com/fedackb/maze-maker/blob/master/UtilFuncs.hpp#L11)   |
| self-made header file                      | UtilFuncs.hpp | [2](https://github.com/fedackb/maze-maker/blob/master/UtilFuncs.hpp#L2)     |
| makefile                                   | makefile      | [2](https://github.com/fedackb/maze-maker/blob/master/makefile#L2)          |
| default constructor                        | Maze.cpp      | [22](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L22)        |
| copy constructor                           | Maze.cpp      | [55](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L55)        |
| destructor                                 | Maze.cpp      | [129](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L129)      |
| operator overloading                       | Maze.cpp      | [653](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L653)      |
| file I/O                                   | mazemaker.cpp | [72](https://github.com/fedackb/maze-maker/blob/master/mazemaker.cpp#L72)   |
| polymorphism                               | mazemaker.cpp | [118](https://github.com/fedackb/maze-maker/blob/master/mazemaker.cpp#L118) |
| inheritance                                | Maze.hpp      | [13](https://github.com/fedackb/maze-maker/blob/master/Maze.hpp#L13)        |
| exception handling                         | Maze.cpp      | [31](https://github.com/fedackb/maze-maker/blob/master/Maze.cpp#L31)        |

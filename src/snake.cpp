

// game loop
//  frame rate
//  watch for up/down arrow change
//
// snake class
//  :fields
//  :methods
//    move(direction)
//
// grid class
//  :fields
//    screen_buffer
//  :methods
//    place_food()
//    print()
//    create_border()
//
//
//  ____________________________________________________
// |                                                    |
// |                                                    |
// |                                                    |
// |     #####                                          |
// |         #                                          |
// |         #                                          |
// |         #########    .                             |
// |                                                    |
// |                                                    |
// |                                                    |
// |                                                    |
// |                                                    |
// |                                                    |
// |                                                    |
// |                                                    |
// |                                                    |
// |                                                    |
// |                                                    |
//  ____________________________________________________

#include <iostream>
#include <iostream>
#include "conio.h"
#include "utils.h"

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67

//ENUM_MACRO_4(ArrowPress, Up, Down, Left, Right)

enum class ArrowPress { Unknown, Up, Down, Left, Right };

ArrowPress getArrowPress() {
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;

    while(c3 == 0)
    {
        if (c1 == 0)
        {
            c1 = getch();
            std::cout << "c1=" << c1 << '\n';
        }
        else if (c2 == 0)
        {
            c2 = getch();
            std::cout << "c2=" <<  c2 << '\n';
        }
        if (c1 != 27)
        {
            return ArrowPress::Unknown;
        }
        else if (c1 == 27 && c2 == 0)
        {
            continue;
        }
        else if (c1 == 27 && c2 != 91)
        {
            return ArrowPress::Unknown;
        }
        else
        {
            switch((c3=getche())) {
            case KEY_UP:
                std::cout << std::endl << "Up" << std::endl;    //key up
                return ArrowPress::Up;
            case KEY_DOWN:
                std::cout << std::endl << "Down" << std::endl;  // key down
                return ArrowPress::Down;
            case KEY_LEFT:
                std::cout << std::endl << "Left" << std::endl;  // key left
                return ArrowPress::Left;
            case KEY_RIGHT:
                std::cout << std::endl << "Right" << std::endl; // key right
                return ArrowPress::Right;
            default:
                std::cout << std::endl << "null: " << c3 << std::endl;  // not arrow
                return ArrowPress::Unknown;
            }
        }
    }
    return ArrowPress::Down;
}

int main()
{
    getArrowPress();
    return 0;
}

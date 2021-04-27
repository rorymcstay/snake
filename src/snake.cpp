#include <exception>
#include <thread>
#include <memory>

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
#include <stdexcept>
#include "conio.h"
#include "utils.h"

/*
 * c1=0 c2=0 c3=0 c1=91 c2=91 c3=65 Snake will move Left
 * c1=0 c2=0 c3=0 c1=91 c2=91 c3=66 Snake will move Right
 * c1=0 c2=0 c3=0 c1=91 c2=91 c3=67 Snake will move Down
 * c1=0 c2=0 c3=0 c1=91 c2=91 c3=68 Snake will move  Snake will move

 */

#define KEY_DOWN 65
#define KEY_LEFT 66
#define KEY_UP 67
#define KEY_RIGHT 68

ENUM_MACRO_4(ArrowPress, Up, Down, Left, Right)

//enum class ArrowPress { Unknown, Up, Down, Left, Right };

ArrowPress getArrowPress() {
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;

    while(c3 == 0)
    {
        if (c1 == 0)
        {
            c1 = getch();
        }
        else if (c2 == 0)
        {
            c2 = getch();
        }
        if (c1 != 27)
        {
            std::cout << "c1=" << c2 << " c2=" << c2 <<  " c3=" <<  c3 << ' ';
            return ArrowPress::UnknownArrowPress;
        }
        else if (c1 == 27 && c2 == 0)
        {
            std::cout << "c1=" << c2 << " c2=" << c2 <<  " c3=" <<  c3 << ' ';
            continue;
        }
        else if (c1 == 27 && c2 != 91)
        {
            std::cout << "c1=" << c2 << " c2=" << c2 <<  " c3=" <<  c3 << ' ';
            return ArrowPress::UnknownArrowPress;
        }
        else
        {
            switch((c3=getche())) {
            case KEY_UP:
                std::cout << "c1=" << c2 << " c2=" << c2 <<  " c3=" <<  c3;
                return ArrowPress::Up;
            case KEY_DOWN:
                std::cout << "c1=" << c2 << " c2=" << c2 <<  " c3=" <<  c3;
                return ArrowPress::Down;
            case KEY_LEFT:
                std::cout << "c1=" << c2 << " c2=" << c2 <<  " c3=" <<  c3;
                return ArrowPress::Left;
            case KEY_RIGHT:
                std::cout << "c1=" << c2 << " c2=" << c2 <<  " c3=" <<  c3;
                return ArrowPress::Right;
            default:
                std::cout << "c1=" << c2 << " c2=" << c2 <<  " c3=" <<  c3;
                throw std::out_of_range("Invalid char press");
            }
        }
    }
    return ArrowPress::Down;
}

class Snake
{
    /*
    int _length;
    int _position;
    */

public:
    void move(ArrowPress direction_)
    {
        std::cout << " Snake will move " << direction_ << '\n';
    }

};

void user_input_game_loop(std::shared_ptr<Snake> snake_)
{
    while (true)
    {
        ArrowPress direction = getArrowPress();
        snake_->move(direction);
    }
}

int main()
{
    auto snake = std::make_shared<Snake>();
    std::thread game_loop_thread(user_input_game_loop, snake);
    game_loop_thread.join();

}

#include <exception>
#include <vector>
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
#define KEY_UP 'A'
#define KEY_RIGHT 'C'
#define KEY_DOWN 'B'
#define KEY_LEFT 'D'

ENUM_MACRO_4(ArrowPress, Up, Down, Left, Right)

//enum class ArrowPress { Unknown, Up, Down, Left, Right };
//
//
ArrowPress getArrowPress()
{
    char ch =  getch();
    if (ch == '\033') { // if the first value is esc
        getch(); // skip the [
        switch(getch()) { // the real value
            case KEY_UP: return ArrowPress::Up;
            case KEY_DOWN: return ArrowPress::Down;
            case KEY_RIGHT: return ArrowPress::Right;
            case KEY_LEFT: return ArrowPress::Left;
        }
    }
    return ArrowPress::UnknownArrowPress;

}


struct Location
{
    unsigned int x_cood;
    unsigned int y_cood;
};


class Snake
{
    /*
    int _length;
    int _position;
    */
    Location _location;

public:
    using Ptr = std::shared_ptr<Snake>;
    void move(ArrowPress direction_)
    {
        std::cout << "moved from x=" << _location.x_cood << " y=" << _location.y_cood;
        switch(direction_)
        {
            case ArrowPress::Up: 
            {
                _location.y_cood++;
                break;
            }
            case ArrowPress::Down: 
            {
                _location.y_cood--;
                break;
            }
            case ArrowPress::Right:
            {
                _location.x_cood++;
                break;
            }
            case ArrowPress::Left: 
            {
                _location.x_cood--;
                break;
            }
            default:
            {
                throw std::out_of_range("Invalid direction passed to Snake::move!");
            }
        }
        std::cout << " " << direction_ << " to x=" << _location.x_cood << " y=" << _location.y_cood << '\n';
    }
};


class Grid
{

    int _size;
    Snake::Ptr _snake;


public:
    Grid(int size_, Snake::Ptr snake_)
    :   _size(size_)
    ,   _snake(snake_)
    {
    }

    int size()
    {
        return _size;
    }
};

void user_input_game_loop(Snake::Ptr snake_)
{
    while (true)
    {
        std::cout << "User Input: ";
        ArrowPress direction = getArrowPress();

        snake_->move(direction);
    }
}


int main()
{
    auto snake = std::make_shared<Snake>();
    auto grid = std::make_shared<Grid>(100, snake);
    std::thread game_loop_thread(user_input_game_loop, snake);
    game_loop_thread.join();
    return 0; 
}

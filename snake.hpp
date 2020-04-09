#ifndef _SNAKE_H
#define _SNAKE_H

#include<SFML/Config.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<vector>

namespace snake{
    
    struct snake_piece{
        sf::Vector2i position;
        snake_piece(int x, int y) : position(x, y){}
    };

    enum class Direction{Start, Up, Down, Left, Right}; //start is the init state where the snake is not moving.


    class Snake{
        std::vector<snake_piece> snake_body;
        int score; //snake is the player here
        float velocity;
        Direction direction;
        int block_size;  //unit grid square size;
        sf::RectangleShape body_rectangle;
    
        bool check_collision();
    
    public:
        Snake(int size);  //size is block_size
        ~Snake();
        bool lost_state;
    
        //getters
        Direction get_direction();
        float get_velocity();
        int get_score();
        sf::Vector2i get_position(); //getter for snake head(snake head is the first piece of snake_body)
    
        //setters
        void set_direction(Direction dir);
    
        //modifiers
        void increase_score();
        void extend();
        void init();
        void move();
    
        void update();
        void render(sf::RenderWindow& window);
    
    
    };
}
#endif

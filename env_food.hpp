/* this header handles both environment and the food. */

#ifndef _ENV_H
#define _ENV_H

#include"snake.hpp"
#include<SFML/Config.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

namespace snake{
    
    class Env{
        sf::Vector2u window_size;
        sf::Vector2i food_position;
        int blocksize;
        
        sf::CircleShape food;
        sf::RectangleShape walls[4];
        
        sf::SoundBuffer food_buffer;
        sf::Sound food_sound;
        sf::SoundBuffer over_buffer;
        sf::Sound over_sound;
    public:
        Env(sf::Vector2u wind_size);
        ~Env();
        
        void regenerate_food();
        int get_blocksize();
        
        void update(Snake& snake);
        void render(sf::RenderWindow& window);
        
    };
    
    int random_generator(int min, int max);
}

#endif

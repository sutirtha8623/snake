//for displaying "GAME OVER" and score

#ifndef _OVER_H
#define _OVER_H

#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>

namespace snake
{
    class Over{
        sf::Font font;
        sf::Text over_text;
        sf::Vector2u window_size;
    public:
        Over(int score, sf::Vector2u wind_size);
        ~Over();
        void set_score(int);
        void render(sf::RenderWindow& window);
        
        int score;
    };
}

#endif

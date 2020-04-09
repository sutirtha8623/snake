
#ifndef _GAME_H
#define _GAME_H

#include"snake.hpp"
#include"env_food.hpp"
#include<SFML/Config.hpp>
#include<SFML/Window.hpp>

class Game{
public:
    Game();
    void run();
    
    void process_events();
    void update();
    void render();
    
    sf::Time get_elapsed_time();
    void restart_clock();
    void handle_player_input();
    
private:
    sf::RenderWindow window;
    sf::Clock clock;
    float time_elapsed;
    
    snake::Env env;
    snake::Snake player;
};
#endif

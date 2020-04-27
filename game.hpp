
#ifndef _GAME_H
#define _GAME_H

#include"snake.hpp"
#include"env_food.hpp"
#include"over.hpp"

class Game{
public:
    Game();
    void run();
    
    void process_events();
    void update();
    void render();
    
    void handle_player_input();
    
    
private:
    sf::RenderWindow window;
    sf::Clock clock;
    float time_elapsed;
    
    snake::Env env;
    snake::Snake player;
    snake::Over over;
    
    //sf::SoundBuffer over_buffer;
    sf::SoundBuffer restart_buffer;
    //sf::Sound over_sound;
    sf::Sound restart_sound;
};
#endif

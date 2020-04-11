#include<SFML/Graphics.hpp>
#include"game.hpp"


Game::Game()
: window(sf::VideoMode(800, 600), "Snake", sf::Style::Default)
, env(sf::Vector2u(800, 600))
, player(env.get_blocksize())
{
    window.setVerticalSyncEnabled(true);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timestep = sf::seconds(1.0f/player.get_velocity());
    sf::Time time_elapsed = sf::Time::Zero;
    while(window.isOpen())
    {
        process_events();
        time_elapsed += clock.restart();
        while(time_elapsed > timestep){
            time_elapsed -= timestep;
            process_events();
            update();
        }
        render();
    }
}


void Game::handle_player_input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player.get_direction()!=snake::Direction::Down){
        
        player.set_direction(snake::Direction::Up);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player.get_direction()!=snake::Direction::Up){
        
        player.set_direction(snake::Direction::Down);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.get_direction()!=snake::Direction::Right){
        
        player.set_direction(snake::Direction::Left);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.get_direction()!=snake::Direction::Left){
        
        player.set_direction(snake::Direction::Right);
    }
}

void Game::process_events()
{
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::KeyPressed)
        {
            handle_player_input();
        }
        else if(event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void Game::update()
{
    player.update();
    env.update(player);
    if(player.lost_state == true)
    {
        player.init();
    }
}

void Game::render()
{
    window.clear(sf::Color::Black);
    env.render(window);
    player.render(window);
    window.display();
}






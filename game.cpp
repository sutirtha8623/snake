#include<SFML/Graphics.hpp>
#include"game.hpp"


Game::Game()
: window(sf::VideoMode(800, 600), "Snake", sf::Style::Default)
, env(sf::Vector2u(800, 600))
, player(env.get_blocksize())
, over(0, sf::Vector2u(600, 400))
{
    clock.restart();
    
    restart_buffer.loadFromFile("res/audio/restart.ogg");
    restart_sound.setBuffer(restart_buffer);
    
    window.setVerticalSyncEnabled(true);
}

void Game::run()
{
    while(window.isOpen())
    {
        handle_player_input();
        update();
        render();
    }
}

void Game::handle_player_input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player.get_direction()!=snake::Direction::Down)
    {
        player.set_direction(snake::Direction::Up);
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.get_direction()!=snake::Direction::Left){
        
        player.set_direction(snake::Direction::Right);
    }    
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player.get_direction()!=snake::Direction::Up){
        
        player.set_direction(snake::Direction::Down);
    }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.get_direction()!=snake::Direction::Right){
        
        player.set_direction(snake::Direction::Left);
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && player.lost_state == true)
    {
        player.change_lost();
        player.init();
        run();
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
    process_events();
    float timestep = 500 - 10*player.get_velocity();
    if(clock.getElapsedTime().asMilliseconds() >= timestep)
    {
        player.update();
        env.update(player);
        clock.restart();
    }
}

void Game::render()
{
    window.clear(sf::Color::Black);
    env.render(window);
    player.render(window);
    if(player.lost_state == true)
    {
        window.clear(sf::Color::Black);
        over.set_score(player.get_score());
        over.render(window);
    }
    window.display();
}






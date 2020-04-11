#include"env_food.hpp"
#include<random>

namespace snake{
    
    int random_generator(int min, int max){
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(min, max);
        
        return distribution(generator);
    }
    
    Env::Env(sf::Vector2u wind_size){
        blocksize = 10;
        
        window_size = wind_size;
        regenerate_food();
        food.setFillColor(sf::Color::Red);
        food.setRadius(blocksize/2);
        
        for(int i=0; i<4; i++){
            walls[i].setFillColor(sf::Color(255,69,0));
            if((i%2)==0){
                walls[i].setSize(sf::Vector2f(blocksize, window_size.y));
            }
            else{
                walls[i].setSize(sf::Vector2f(window_size.x, blocksize));
            }
            
            if(i < 2){
                walls[i].setPosition(0, 0);
            }
            else{
                walls[i].setOrigin(walls[i].getSize());
                walls[i].setPosition(sf::Vector2f(window_size));
                
            }    
        }
    }
    
    Env::~Env(){
        
    }
    
    void Env::regenerate_food(){
        int max_x = (window_size.x/blocksize) - 4;
        int max_y = (window_size.y/blocksize) - 4;
        
        food_position = sf::Vector2i(random_generator(1, max_x), random_generator(1, max_y));
        
        food.setPosition(food_position.x*blocksize, food_position.y*blocksize);
        
    }
    
    void Env::update(Snake& snake)
    {
        if(snake.get_position() == food_position){
            snake.extend();
            snake.increase_score();
            regenerate_food();
        }
        
        int viable_region_x = window_size.x/blocksize - 1;
        int viable_region_y = window_size.y/blocksize - 1;
        
        if(snake.get_position().x <= 0 ||
            snake.get_position().y <= 0 ||
            snake.get_position().x >= viable_region_x ||
            snake.get_position().y >= viable_region_y
        ){
            snake.lost_state = true;
        }
    }
    
    void Env::render(sf::RenderWindow& window)
    {
        for(int i=0; i<4; ++i){
            window.draw(walls[i]);
        }
        window.draw(food);
    }
    
    int Env::get_blocksize(){
        return blocksize;
    }
}

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"snake.hpp"

namespace snake{
    
    Snake::Snake(int size) : block_size(size){
        body_rectangle.setSize(sf::Vector2f(size-1, size-1));
        init();
    }
    
    Snake::~Snake(){
    }
    
    Direction Snake::get_direction(){
        return direction;
    }
    
    float Snake::get_velocity(){
        return velocity;
    }
    
    int Snake::get_score(){
        return score;
    }
    
    void Snake::increase_score(){
        ++score;
    }
    
    sf::Vector2i Snake::get_position(){
        if(!snake_body.empty()){
            return snake_body.front().position;
        }
        else
            return sf::Vector2i(1, 1);
    }
    
    void Snake::set_direction(Direction dir)
    {
        direction = dir;
    }

    
    void Snake::init(){
        snake_body.clear();
        snake_body.push_back(snake_piece(7, 9));
        snake_body.push_back(snake_piece(7, 8));
        snake_body.push_back(snake_piece(7, 7));
        
        score = 0;
        velocity = 15;
        set_direction(Direction::Start);
        lost_state = false;
        
    }
    
    void Snake::extend(){
        if(snake_body.empty()){return;}
        snake_piece& tail_end = snake_body[snake_body.size()-1];
        snake_piece& tail_penultimate = snake_body[snake_body.size()-2];
        
        if(tail_end.position.x == tail_penultimate.position.x){
            if(tail_end.position.y > tail_penultimate.position.y){
                snake_body.push_back(snake_piece(tail_end.position.x, tail_end.position.y+1));
            }
            else if(tail_end.position.y < tail_penultimate.position.y){
                snake_body.push_back(snake_piece(tail_end.position.x, tail_end.position.y-1));
            }
        }
        else if(tail_end.position.y == tail_penultimate.position.y){
            if(tail_end.position.x > tail_penultimate.position.x){
                snake_body.push_back(snake_piece(tail_end.position.x+1, tail_end.position.y));
            }
            else if(tail_end.position.x < tail_penultimate.position.x){
                snake_body.push_back(snake_piece(tail_end.position.x-1, tail_end.position.y));
            }
        }
    }
    
    void Snake::move(){
        for(int i = 1; i < snake_body.size(); ++i){
            snake_body[i].position = snake_body[i-1].position;
        }
        switch(direction){ //for changing the position of head
            case Direction::Up :
                --snake_body[0].position.y;
                break;
            
            case Direction::Down :
                ++snake_body[0].position.y;
                break;
                
            case Direction::Left :
                --snake_body[0].position.x;
                break;
                
            case Direction::Right :
                ++snake_body[0].position.x;
                break;
            case Direction::Start :
                break;
            default:
                break;
        }
    }
    
    bool Snake::check_collision(){
        if(snake_body.size() <= 4){
            return false;
        }
        snake_piece& head = snake_body.front();
        for(auto i=snake_body.begin()+1; i != snake_body.end(); ++i){
            if(i->position == head.position){
                lost_state = true;
                break;
            }
        }
        return lost_state;
    }
    
    void Snake::update(){
        if(snake_body.empty() || direction == Direction::Start){
            return;
        }
        move();
        check_collision();
    }
    
    void Snake::render(sf::RenderWindow& window){
        if(snake_body.empty()){return;}
        
        snake_piece& head = snake_body.front();
        body_rectangle.setFillColor(sf::Color::Yellow);
        body_rectangle.setPosition(head.position.x * block_size, head.position.y * block_size);
        window.draw(body_rectangle);
        
        body_rectangle.setFillColor(sf::Color::Cyan);
        for(auto i = snake_body.begin()+1; i != snake_body.end(); ++i){
            body_rectangle.setPosition(i->position.x * block_size, i->position.y * block_size);
            window.draw(body_rectangle);
        }
    }

    
    


}

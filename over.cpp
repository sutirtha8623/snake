#include"over.hpp"

namespace snake
{
    Over::Over(int score, sf::Vector2u wind_size)
    : font()
    , over_text()
    , window_size(wind_size)
    {
        font.loadFromFile("res/game_over.ttf");

        over_text.setFont(font);

        auto text_rectangle = over_text.getLocalBounds();
        over_text.setOrigin(text_rectangle.left + text_rectangle.width/2.0f, text_rectangle.top + text_rectangle.height/2.0f);
        over_text.setPosition(sf::Vector2f(wind_size.x/2.0f, wind_size.y/2.0f));

        over_text.setCharacterSize(50);
    }

    Over::~Over()
    {

    }

    void Over::set_score(int sc)
    {
        score = sc;
    }

    void Over::render(sf::RenderWindow& window)
    {
        over_text.setString(
            "GAME OVER!!\nYour score : " + std::to_string(score) + "\n" +
            "Press Enter to restart"
        );
        window.clear(sf::Color::Black);
        window.draw(over_text);
        window.display();
    }
}

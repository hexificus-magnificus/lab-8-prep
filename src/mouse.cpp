#include "sprite.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode({256, 256}), "Sprites lab", sf::State::Windowed);
    sf::Texture texture("C:/Users/John Epp/Documents/school/2026-2027/Fall/CMPUT 350/Labs/8/lab-8-prep/assets/sword_diamond.png");
    sf::Texture texture2("C:/Users/John Epp/Documents/school/2026-2027/Fall/CMPUT 350/Labs/8/lab-8-prep/assets/spritesheet_items.png");
    Sprite s(texture);
    // Sprite s(texture2, { 0, 512 }, { 128, 640 }); // should be equivalent to using texture
    s.origin() = {114, 14};
    s.position() = {128, 128};
    s.scale().x = -1;
    // window.setMouseCursorVisible(false); // you can use this to hide the mouse

    std::cout << "entering loop\n";
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                return 0;
            }
        }
        s.position() = sf::Vector2f(sf::Mouse::getPosition(window));
        sf::RenderStates states{};
        window.clear(sf::Color::White);
        s.draw(window, states);
        window.display();
    }

    return 0;
}

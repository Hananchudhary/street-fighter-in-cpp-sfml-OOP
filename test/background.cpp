#include"background.h"
#include"spriteloader.h"
background::background() {}
background::background(const string& filename, sf::RenderWindow& window) {
    spriteloader utility;
    utility.load(this->bgs, this->bgt, filename, window);
}
void background::set(const string& filename, sf::RenderWindow& window) {
    try {
        if (!bgt.loadFromFile(filename)) {
            throw ("Sprite could not load");
        }
    }
    catch (String err) {
        cout << err;
    }
    bgs.setTexture(bgt);
    float xdir = window.getSize().x / bgs.getGlobalBounds().width;
    float ydir = window.getSize().y / bgs.getGlobalBounds().height;
    bgs.setScale(sf::Vector2f(xdir, ydir));
}
void background::display(sf::RenderWindow& window) {
    window.draw(bgs);
}
#include"background.h"
#include"spriteloader.h"
background::background() {}
background::background(const string& filename, sf::RenderWindow& window) {
    spriteloader utility;
    utility.load(this->bgs, this->bgt, filename, window);
}
void background::set(const string& filename, sf::RenderWindow& window) {
    spriteloader utility;
    utility.load(this->bgs, this->bgt, filename, window);
}
void background::display(sf::RenderWindow& window) {
    window.draw(bgs);
}
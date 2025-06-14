#include"background.h"
#include"spriteloader.h"
background::background() = default;
background::background(const string& filename, sf::RenderWindow& window) {
    spriteloader utility;
    if (filename == "bg1.jpg")
        idx = 0;
    else if (filename == "bg2.jpg")
        idx = 1;
    else if (filename == "bg3.jpg")
        idx = 2; 
    else if (filename == "bg4.jpg")
        idx = 3; 
    else if (filename == "bg5.jpg")
        idx = 4; 
    else
        idx = 5;
    utility.load(this->bgs, this->bgt, filename, window);
}
int background::get_id() {
    return this->idx;
}
void background::set(const string& filename, sf::RenderWindow& window) {
    spriteloader utility;
    utility.load(this->bgs, this->bgt, filename, window);
    if (filename == "bg1.jpg")
        idx = 0;
    else if (filename == "bg2.jpg")
        idx = 1;
    else if (filename == "bg3.jpg")
        idx = 2;
    else if (filename == "bg4.jpg")
        idx = 3;
    else if (filename == "bg5.jpg")
        idx = 4;
    else
        idx = 5;
}
void background::display(sf::RenderWindow& window) {
    window.draw(bgs);
}
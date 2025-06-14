#pragma once
#include<SFML/Graphics.hpp>
#include"mystr.h"
#include<cstring>
class background {
    sf::Texture bgt;
    sf::Sprite bgs;
    int idx;
public:
    background();
    int get_id();
    background(const string& filename, sf::RenderWindow& window);
    void set(const string& filename, sf::RenderWindow& window);
    void display(sf::RenderWindow& window);
    ~background() = default;
};
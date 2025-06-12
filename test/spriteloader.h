#pragma once
#include<iostream>
#include"SFML/Graphics.hpp"
using namespace std;
class spriteloader {
public:
    spriteloader() = default;
	void load(sf::Sprite& bgs, sf::Texture& bgt, string filename, sf::RenderWindow& window) {
        try {
            if (!bgt.loadFromFile(filename)) {
                throw ("Sprite could not load");
            }
        }
        catch (const char* err) {
            cout << err;
        }
        bgs.setTexture(bgt);
        float xdir = window.getSize().x / bgs.getGlobalBounds().width;
        float ydir = window.getSize().y / bgs.getGlobalBounds().height;
        bgs.setScale(sf::Vector2f(xdir, ydir));
	}
};
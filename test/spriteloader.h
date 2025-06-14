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
        float xdir = static_cast<float>(window.getSize().x) / bgt.getSize().x;
        float ydir = static_cast<float>(window.getSize().y) / bgt.getSize().y;
        bgs.setScale(xdir, ydir);
	}
    ~spriteloader() = default;
};
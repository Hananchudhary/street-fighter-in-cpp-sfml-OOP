#pragma once
#include<SFML/Graphics.hpp>
#include<cstring>
#include<iostream>
using namespace std;
class character
{
protected:
	sf::Texture chrt;
	sf::Sprite chrs;
	float jumpHeight;
	float moveLength;
	float jumpSpeed;
	float moveSpeed;
	float groundY;
	float groundX;
	bool isJumping;
	bool goingUp;
	bool isleftmove;
	bool isrightmove;
	bool isSit;
public:
	character(sf::IntRect box, string name, float _jh, float _ml, float _js, float _ms, float _sx,float _sy, float _px, float _py) : jumpHeight{ _jh }, moveLength{ _ml }, jumpSpeed{ _js }, moveSpeed{ _ms }, isJumping{ false }, isleftmove{ false }, isrightmove{ false }, goingUp{ true }, isSit{false}{
		try {
			if (!chrt.loadFromFile(name)) {
				throw ("file of character cannot open");
			}
		}
		catch (string err) {
			cout << err;
		}
		chrt.setSmooth(true);
		chrs.setTexture(chrt);
		chrs.setTextureRect(box);
		chrs.setScale(_sx, _sy);
		chrs.setPosition(_px, _py);
		this->groundX = chrs.getPosition().x;
		this->groundY = chrs.getPosition().y;
	}
	void set_left_move(bool flag) {
		this->isleftmove = flag;
	}
	void set_right_move(bool flag) {
		this->isrightmove = flag;
	}
	void set_jumping(bool flag) {
		this->isJumping = flag;
	}
	bool get_jump() const { return this->isJumping; }
	void set_goingup(bool flag) {
		this->goingUp = flag;
	}
	bool isSitting()const {
		return this->isSit;
	}
	void set_place(float x, float y) {
		chrs.setPosition(x, y);
	}
	void set_sit(bool flag) {
		this->isSit = flag;
	}
	void set_box(sf::IntRect box) {
		chrs.setTextureRect(box);
	}
	float get_x()const {
		return this->chrs.getPosition().x;
	}
	float get_y()const {
		return this->chrs.getPosition().y;
	}
	float get_GroundY()const { return this->groundY; }
	bool get_leftMoving()const {
		return this->isleftmove;
	}
	bool get_rightMoving()const {
		return this->isrightmove;
	}
};
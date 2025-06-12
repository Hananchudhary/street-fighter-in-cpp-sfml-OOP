#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include"character.h"
#include"dynamic_array.h"
#include"Attack.h"
using namespace std;
class Fighter : public character{
private:
	sf::RectangleShape back_health;
protected:
	sf::Keyboard::Key up;
	sf::Keyboard::Key down;
	sf::Keyboard::Key left;
	sf::Keyboard::Key right;
	sf::Keyboard::Key punch1;
	sf::Keyboard::Key punch2;
	sf::Keyboard::Key kick1;
	sf::Keyboard::Key kick2;
	sf::IntRect start;
	sf::IntRect normal;
	sf::IntRect move;
	sf::IntRect sit;
	sf::IntRect sit_move;

	Dynamic_array<Attack> powers;
	float health;
	sf::RectangleShape health_bar;
	bool is_attack;
public:
	Fighter(sf::IntRect box, string name, float _jh, float _ml, float _js, float _ms, float _sx, float _sy, float _px, float _py, float _hx, float _hsx, sf::Keyboard::Key _u, sf::Keyboard::Key _d, sf::Keyboard::Key _l, sf::Keyboard::Key _r, sf::Keyboard::Key lp, sf::Keyboard::Key mp, sf::Keyboard::Key lk, sf::Keyboard::Key mk) : character(box, name, _jh, _ml, _js, _ms, _sx, _sy, _px, _py), up{ _u }, down{ _d }, left{ _l }, right{ _r }, health{ 100.f }, punch1{ lp }, punch2{ mp }, kick1{ lk }, kick2{mk}, is_attack { false } {
		back_health.setSize(sf::Vector2f(450.f, 20.f));
		back_health.setPosition(sf::Vector2f(_hx, 30.f));
		back_health.setScale(sf::Vector2f(_hsx, 1.5f));
		back_health.setFillColor(sf::Color::Red);
		back_health.setOutlineColor(sf::Color::Black);
		back_health.setOutlineThickness(2.f);

		health_bar.setSize(sf::Vector2f(450.f, 20.f));
		health_bar.setPosition(sf::Vector2f(_hx, 30.f));
		health_bar.setScale(sf::Vector2f(_hsx, 1.5f));
		health_bar.setFillColor(sf::Color::Yellow);
		health_bar.setOutlineColor(sf::Color::Black);
		health_bar.setOutlineThickness(2.f);
	}
	float get_health()const { return this->health; }
	Dynamic_array<Attack> get_powers()const {
		return this->powers;
	}
	void set_attack(bool flag) {
		this->is_attack = flag;
	}
	bool get_attack_status() const { return this->is_attack; }
	bool get_sitting() {
		return this->isSit;
	}
	void computer_movement(bool collission, bool& flag, sf::Clock& clk) {
		sf::IntRect box1, box2;
		box1 = start;
		box2 = normal;
		if (isJumping) {
			if (goingUp) {
				chrs.move(0.f, -jumpSpeed);
				if (chrs.getPosition().y <= groundY - jumpHeight)
					goingUp = false;
			}
			else {
				chrs.move(0.f, jumpSpeed);
				if (chrs.getPosition().y >= groundY) {
					chrs.setPosition(chrs.getPosition().x, groundY);
					isJumping = false;
					goingUp = true;
				}
			}
		}
		if (isrightmove) {
			if (this->get_x() < 1070) {
				chrs.move(moveSpeed, 0.f);
				if (chrs.getPosition().x >= groundX + moveLength) {
					groundX = chrs.getPosition().x;
					isrightmove = false;
				}
			}
			else {
				isrightmove = false;
			}
		}
		if (isleftmove) {
			if (this->get_x() > 20 && !collission) {
				chrs.move(-moveSpeed, 0.f);
				if (chrs.getPosition().x <= groundX - moveLength) {
					groundX = chrs.getPosition().x;
					isleftmove = false;
				}
			}
			else {
				isleftmove = false;
			}
		}
		if (this->isSit && !this->isJumping) {
			box1 = sit;
			chrs.setPosition(chrs.getPosition().x, groundY);
		}
		if (isrightmove || isleftmove) {
			if (isSit) {
				box1 = sit;
				box2 = sit_move;
			}
			else {
				box1 = start;
				box2 = move;
			}
		}
		else {
			if (isSit) {
				box1 = sit;
				box2 = sit;
			}
			else {
				box1 = start;
				box2 = normal;
			}
		}
		if (!flag) {
			chrs.setTextureRect(box1);
		}
		else {
			chrs.setTextureRect(box2);
		}
		if (clk.getElapsedTime().asSeconds() > 0.35f) {
			clk.restart();
			if (flag)
				flag = false;
			else
				flag = true;
		}
	}
	void move_character(bool& flag, sf::Clock& clk) {
		sf::IntRect box1, box2;
		box1 = start;
		box2 = normal;
		if (isJumping) {
			if (goingUp) {
				chrs.move(0.f, -jumpSpeed);
				if (chrs.getPosition().y <= groundY - jumpHeight)
					goingUp = false;
			}
			else {
				chrs.move(0.f, jumpSpeed);
				if (chrs.getPosition().y >= groundY) {
					chrs.setPosition(chrs.getPosition().x, groundY);
					isJumping = false;
				}
			}
		}
		if (isrightmove) {
			chrs.move(moveSpeed, 0.f);
			if (chrs.getPosition().x >= groundX + moveLength) {
				groundX = chrs.getPosition().x;
				isrightmove = false;
			}
		}
		if (isleftmove) {
			chrs.move(-moveSpeed, 0.f);
			if (chrs.getPosition().x <= groundX - moveLength) {
				groundX = chrs.getPosition().x;
				isleftmove = false;
			}
		}
		if (this->isSit && !this->isJumping) {
			box1 = sit;
			chrs.setPosition(chrs.getPosition().x, groundY);
		}
		if (isrightmove || isleftmove) {
			if (isSit) {
				box1 = sit;
				box2 = sit_move;
			}
			else {
				box1 = start;
				box2 = move;
			}
		}
		else {
			if (isSit) {
				box1 = sit;
				box2 = sit;
			}
			else {
				box1 = start;
				box2 = normal;
			}
		}
		if (!flag) {
			chrs.setTextureRect(box1);
		}
		else {
			chrs.setTextureRect(box2);
		}
		if (clk.getElapsedTime().asSeconds() > 0.35f) {
			clk.restart();
			if (flag)
				flag = false;
			else
				flag = true;
		}
	}
	virtual int get_attack_condition() = 0;
	virtual int attack_idx() = 0;
	void display(sf::RenderWindow& window) {
		window.draw(this->chrs);
		window.draw(this->back_health);
		set_health_bar();
		window.draw(health_bar);
	}
	void set_health(float val) {
		this->health = val;
	}
	sf::Keyboard::Key get_right_key()const {
		return this->right;
	}
	sf::Keyboard::Key get_left_key()const {
		return this->left;
	}
	sf::Keyboard::Key get_up_key()const {
		return this->up;
	}
	sf::Keyboard::Key get_down_key()const {
		return this->down;
	}
	void set_health_bar() {
		health_bar.setSize(sf::Vector2f(450.f * (this->health / 100.f), 20.f));
	}
	void reduce_health(float val) {
		this->health = this->health - val;
	}
	virtual sf::IntRect get_attack_box() = 0;
	bool is_attacking() const {
		if (this->get_y() > this->groundY - 20.f) {
			if (sf::Keyboard::isKeyPressed(this->punch1) || sf::Keyboard::isKeyPressed(this->punch2) || sf::Keyboard::isKeyPressed(this->kick1) || sf::Keyboard::isKeyPressed(this->kick2)) {
				return true;
			}
		}
		return false;
	}
	virtual float attack() = 0;
	sf::IntRect get_defaultbox()const {
		return this->start;
	}
	virtual ~Fighter() = default;
};
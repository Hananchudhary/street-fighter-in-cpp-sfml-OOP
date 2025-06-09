#pragma once
#include"Fighter.h"
#include"Attack.h"
class chun_li : public Fighter {
public:
	chun_li(sf::IntRect box, string name, float _jh, float _ml, float _js, float _ms, float _sx, float _sy, float _px, float _py, float _hx, float _hsx, sf::Keyboard::Key _u, sf::Keyboard::Key _d, sf::Keyboard::Key _l, sf::Keyboard::Key _r, sf::Keyboard::Key lp, sf::Keyboard::Key mp,  sf::Keyboard::Key lk, sf::Keyboard::Key mk) :Fighter(box, name, _jh, _ml, _js, _ms, _sx, _sy, _px, _py, _hx, _hsx, _u, _d, _l, _r, lp, mp, lk, mk) {
		Dynamic_array<sf::Keyboard::Key> _a;
		_a.push(lp);
		Attack temp(_a, 7.f, sf::IntRect({ 62,84 }, { 40,50 }), 0); // 2,2
		powers.push(temp);
		_a.insert_at(0, mp); // 3,2
		temp.set(_a, 5.f, sf::IntRect({ 55,152 }, { 40,50 }), 2);
		powers.push(temp);
		_a.insert_at(0, lk); // 4,2
		temp.set(_a, 7.f, sf::IntRect({ 175,291 }, { 45,90 }), 1);
		powers.push(temp);
		_a.insert_at(0, mk); // 5,2
		temp.set(_a, 10.f, sf::IntRect({ 65,291 }, { 45,90 }), 1);
		powers.push(temp);
		_a.insert_at(0, this->up); // 5,2
		_a.insert_at(1, mk); 
		temp.set(_a, 14.f, sf::IntRect({ 10,291 }, { 40,90 }), 2);
		powers.push(temp);
		_a.insert_at(0, this->down); // 5,2
		_a.insert_at(1, lp);
		temp.set(_a, 10.f, sf::IntRect({ 210,87 }, { 50,80 }), 1);
		powers.push(temp);
		_a.insert_at(0, this->up); // 5,2
		_a.insert_at(1, mp);
		temp.set(_a, 18.f, sf::IntRect({ 325,154 }, { 50,80 }), 2);
		powers.push(temp);
		this->move = sf::IntRect({ 175,24 }, { 25,50 });
		this->normal = sf::IntRect({ 52,24 }, { 25,50 });
		this->start = sf::IntRect({ 10,24 }, { 25,50 });
		this->sit = sf::IntRect({ 392,24 }, { 25,50 });
		this->sit_move = sf::IntRect({ 330, 24 }, { 25,50 });
	}
	Attack AI_select_attack(float enemy_x, float enemy_y) {}
	int attack_idx() override{
		int idx = -1;
		if (sf::Keyboard::isKeyPressed(this->up) && sf::Keyboard::isKeyPressed(this->punch2)) {
			idx = 6;
		}
		else if (sf::Keyboard::isKeyPressed(this->down) && sf::Keyboard::isKeyPressed(this->punch1)) {
			idx = 5;
		}
		else if (sf::Keyboard::isKeyPressed(this->up) && sf::Keyboard::isKeyPressed(this->kick2)) {
			idx = 4;
		}
		else if (sf::Keyboard::isKeyPressed(this->punch2)) {
			idx = 1;
		}
		else if (sf::Keyboard::isKeyPressed(this->punch1)) {
			idx = 0;
		}
		else if (sf::Keyboard::isKeyPressed(this->kick2)) {
			idx = 3;
		}
		else if (sf::Keyboard::isKeyPressed(this->kick1)) {
			idx = 2;
		}
		else {
			idx = -1;
		}
		return idx;
	}
	float attack() override {
		int idx = attack_idx();
		if (idx != -1) {
			return this->powers[idx].get_damage();
		}
		return 0;
	}
	sf::IntRect get_attack_box()override {
		int idx = attack_idx();
		if (idx != -1) {
			return this->powers[idx].get_box();
		}
		return sf::IntRect({ 1000,1000 }, { 1000,1000 });
	}
	int get_attack_condition() override {
		int idx = attack_idx();
		if (idx != -1) {
			return this->powers[idx].get_condition();
		}
		return 0;
	}
};
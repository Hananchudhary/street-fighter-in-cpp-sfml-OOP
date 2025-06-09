#pragma once
#include"Fighter.h"
#include"dynamic_array.h"
#include"Attack.h"
#include"Player.h"
using namespace std;
class Ryu : public Fighter{
public:
	Ryu(sf::IntRect box, string name, float _jh, float _ml, float _js, float _ms, float _sx, float _sy, float _px, float _py, float _hx, float _hsx, sf::Keyboard::Key _u, sf::Keyboard::Key _d, sf::Keyboard::Key _l, sf::Keyboard::Key _r, sf::Keyboard::Key lp, sf::Keyboard::Key mp, sf::Keyboard::Key lk, sf::Keyboard::Key mk) :Fighter(box, name, _jh, _ml, _js, _ms, _sx, _sy, _px, _py, _hx, _hsx, _u, _d, _l, _r, lp, mp, lk, mk) {
		Dynamic_array<sf::Keyboard::Key> _a;
		_a.push(lp); // 3,3
		Attack temp(_a, 5, sf::IntRect({ 53,100 }, {25,50}), 2);
		powers.push(temp);
		_a.insert_at(0, mp); // 3,8
		temp.set(_a, 7.f, sf::IntRect({ 200,100 }, { 30,50 }), 2);
		powers.push(temp);
		_a.insert_at(0, lk); // 5,2
		temp.set(_a, 4.f, sf::IntRect({ 76,225 }, { 33,50 }), 2);
		powers.push(temp);
		_a.insert_at(0, mk); // 5,4
		temp.set(_a, 6.f, sf::IntRect({ 230,225 }, { 33,50 }), 2);
		powers.push(temp);
		_a.insert_at(0, this->up); 
		_a.insert_at(1, mp); // 4,3
		temp.set(_a, 14.f, sf::IntRect({ 58,162 }, { 25,58 }),2);
		powers.push(temp);
		_a.insert_at(0, this->down);
		_a.insert_at(1,mk); //6,8
		temp.set(_a, 17.f, sf::IntRect({ 186,162 }, { 28,50 }), 0);
		powers.push(temp);
		_a.insert_at(0, this->down);
		_a.insert_at(1, mp); //4,11
		temp.set(_a, 20.f, sf::IntRect({ 96,433 }, { 30,50 }), 1);
		powers.push(temp);
		this->move = sf::IntRect({ 135,0 }, { 25,50 });
		this->normal = sf::IntRect({ 26,0 }, { 25,50 });
		this->start = sf::IntRect({ 0,0 }, { 25,50 });
		this->sit = sf::IntRect({ 180,0 }, { 25,50 });
		this->sit_move = sf::IntRect({ 206,0 }, { 25,50 });
	}
	Attack AI_select_attack(float enemy_x, float enemy_y){}
	int attack_idx() override{
		if (sf::Keyboard::isKeyPressed(this->down) && sf::Keyboard::isKeyPressed(this->punch2)) {
			return 6;
		}
		else if (sf::Keyboard::isKeyPressed(this->down) && sf::Keyboard::isKeyPressed(this->kick2)) {
			return 5;
		}
		else if (sf::Keyboard::isKeyPressed(this->up) && sf::Keyboard::isKeyPressed(this->punch2)) {
			return 4;
		}
		else if (sf::Keyboard::isKeyPressed(this->punch2)) {
			return 1;
		}
		else if (sf::Keyboard::isKeyPressed(this->punch1)) {
			return 0;
		}
		else if (sf::Keyboard::isKeyPressed(this->kick2)) {
			return 3;
		}
		else if (sf::Keyboard::isKeyPressed(this->kick1)) {
			return 2;
		}
		else {
			return -1;
		}
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
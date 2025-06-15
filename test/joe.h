#pragma once
#include"Fighter.h"
#include"dynamic_array.h"
#include"Attack.h"
#include"Player.h"
#include"mystr.h"
using namespace std;
class Joe : public Fighter {
	String name;
public:
	Joe(sf::IntRect box, string name, float _jh, float _ml, float _js, float _ms, float _sx, float _sy, float _px, float _py, float _hx, float _hsx, sf::Keyboard::Key _u, sf::Keyboard::Key _d, sf::Keyboard::Key _l, sf::Keyboard::Key _r, sf::Keyboard::Key lp, sf::Keyboard::Key mp, sf::Keyboard::Key lk, sf::Keyboard::Key mk) :Fighter(box, name, _jh, _ml, _js, _ms, _sx, _sy, _px, _py, _hx, _hsx, _u, _d, _l, _r, lp, mp, lk, mk), name{ "joe" } {
		Dynamic_array<sf::Keyboard::Key> _a;
		_a.push(lp); // 3,3
		Attack temp(_a, 5.f, sf::IntRect({ 272,7 }, { 35,57 }), 2);
		powers.push(temp);
		_a.insert_at(0, mp); // 3,8
		temp.set(_a, 8.f, sf::IntRect({ 38,75 }, { 40,57 }), 2);
		powers.push(temp);
		_a.insert_at(0, lk); // 5,2
		temp.set(_a, 7.f, sf::IntRect({ 252,75 }, { 40,57 }), 1);
		powers.push(temp);
		_a.insert_at(0, mk); // 5,4
		temp.set(_a, 10.f, sf::IntRect({ 55,148 }, { 44,57 }), 0);
		powers.push(temp);
		_a.insert_at(0, this->up);
		_a.insert_at(1, mp); // 4,3
		temp.set(_a, 20.f, sf::IntRect({ 228,357 }, { 48,57 }), 2);
		powers.push(temp);
		_a.insert_at(0, this->up);
		_a.insert_at(1, lk); //6,8
		temp.set(_a, 15.f, sf::IntRect({ 80,215 }, { 35,57 }), 0);
		powers.push(temp);
		
		this->move = sf::IntRect({ 80,7 }, { 28,57 });
		this->normal = sf::IntRect({ 6,7 }, { 28,57 });
		this->start = sf::IntRect({ 42,7 }, { 28,57 });
		this->sit = sf::IntRect({ 152,215 }, { 28,57 });
		this->sit_move = sf::IntRect({ 185,215 }, { 28,57 });
	}
	int attack_idx() override {
		if (sf::Keyboard::isKeyPressed(this->up) && sf::Keyboard::isKeyPressed(this->kick1)) {
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
	String get_name()const override {
		return this->name;
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
	~Joe() = default;
};
#pragma once
#include"Fighter.h"
#include"dynamic_array.h"
#include"Attack.h"
#include"Player.h"
#include"mystr.h"
using namespace std;
class guile : public Fighter {
	String name;
public:
	guile(sf::IntRect box, string name, float _jh, float _ml, float _js, float _ms, float _sx, float _sy, float _px, float _py, float _hx, float _hsx, sf::Keyboard::Key _u, sf::Keyboard::Key _d, sf::Keyboard::Key _l, sf::Keyboard::Key _r, sf::Keyboard::Key lp, sf::Keyboard::Key mp, sf::Keyboard::Key lk, sf::Keyboard::Key mk) :Fighter(box, name, _jh, _ml, _js, _ms, _sx, _sy, _px, _py, _hx, _hsx, _u, _d, _l, _r, lp, mp, lk, mk), name{ "guile" } {
		
			chrs.setOrigin(chrs.getLocalBounds().width, 0.f);
		
		Dynamic_array<sf::Keyboard::Key> _a;
		_a.push(lp); // 3,3
		Attack temp(_a, 4.f, sf::IntRect({ 3,235 }, { 30,50 }), 2);
		powers.push(temp);
		_a.insert_at(0, mp); // 3,8
		temp.set(_a, 8.f, sf::IntRect({ 30,305 }, { 30,50 }), 1);
		powers.push(temp);
		_a.insert_at(0, lk); // 5,2
		temp.set(_a, 10.f, sf::IntRect({ 135,305 }, { 40,50 }), 1);
		powers.push(temp);
		_a.insert_at(0, mk); // 5,4
		temp.set(_a, 12.f, sf::IntRect({ 140,400 }, { 40,50 }), 2);
		powers.push(temp);
		this->move = sf::IntRect({ 245,15 }, { 20,50 });
		this->normal = sf::IntRect({ 2,15 }, { 20,50 });
		this->start = sf::IntRect({ 25,15 }, { 20,50 });
		this->sit = sf::IntRect({ 97,15 }, { 20,50 });
		this->sit_move = sf::IntRect({ 97,15 }, { 20,50 });
	}
	int attack_idx() override {
		if (sf::Keyboard::isKeyPressed(this->punch2)) {
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
	~guile() = default;
};
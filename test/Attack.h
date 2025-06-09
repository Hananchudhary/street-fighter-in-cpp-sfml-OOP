#pragma once
#include<iostream>
#include"dynamic_array.h"
#include<SFML/Graphics.hpp>
class Attack {
	Dynamic_array<sf::Keyboard::Key> keys;
	sf::IntRect animation_box;
	float damage;
	int condition;
public:
	Attack() :keys(), damage{ 0.f }, condition{-1} {}
	Attack(Dynamic_array<sf::Keyboard::Key> _k, float _d, sf::IntRect box, int _c) : keys{ _k }, damage{ _d }, animation_box{ box }, condition{_c} {}
	Dynamic_array<sf::Keyboard::Key> get_keys() { return this->keys; }
	float get_damage() { return this->damage; }
	sf::IntRect get_box()const { return this->animation_box; }
	void set(Dynamic_array<sf::Keyboard::Key> _k, float _d, sf::IntRect box, int _c) {
		keys = _k;
		damage = _d;
		animation_box = box;
		condition = _c;
	}
	int get_condition()const {
		return this->condition;
	}
};
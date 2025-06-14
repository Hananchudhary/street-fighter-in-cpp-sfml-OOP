#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include"background.h"
#include"collission.h"
#include"Player.h"
class Ring {
	Player* p1;
	Player* p2;
	background bg;
public:
	Ring() :p1(nullptr), p2(nullptr), bg() {}
	Ring(const string& filename, sf::RenderWindow& window, Player* _p1, Player* _p2) : bg(filename,window), p1{ _p1 }, p2{ _p2 } {}
	void set(const string& filename, sf::RenderWindow& window, Player* _p1,Player* _p2) {
		this->bg.set(filename, window);
		this->p1 = _p1;
		this->p2 = _p2;
	}
	void display(sf::RenderWindow& window) {
		bg.display(window);
		p1->display(window);
		p2->display(window);
	}
	void attack(bool& flag, sf::Clock& clk, bool& flag2, sf::Clock& clk2, bool twoplayer) {
		if ((p2->get_attack_status() || !twoplayer) && (p2->get_y()) > (p2->get_GroundY() - 20.f) && !p1->get_leftMoving()) {
			p2->set_place(p2->get_x(), p2->get_GroundY());
			p2->attack(p1, flag2, clk2);
			if (twoplayer) {
				p2->set_jumping(false);
			}
		}
		else if (clk2.getElapsedTime().asSeconds() > 0.2f) {
			p2->set_attack(false);
		}
		if (p1->get_attack_status() && p1->get_y() > (p1->get_GroundY() - 20.f) && !p2->get_rightMoving() ) {
			p1->set_place(p1->get_x(), p1->get_GroundY());
			p1->attack(p2, flag, clk);
			p1->set_jumping(false);
		}
		else if (clk.getElapsedTime().asSeconds() > 0.2f) {
			p1->set_attack(false);
		}
	}
	int is_match_end() {
		if (this->p1->get_health() <= 0.f) {
			return 2;
		}
		else if (this->p2->get_health() <= 0.f) {
			return 1;
		}
		return 0;
	}
	~Ring() = default;
};
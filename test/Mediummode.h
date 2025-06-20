#pragma once
#include"computer.h"
using namespace std;
class Mediummode :public computer {
public:
	String get_name()const {
		return this->name;
	}
	Mediummode(Fighter* _f) :computer(_f) { this->name = "medium"; }
	Attack select_attack() {
		Dynamic_array<Attack> res = this->f->get_powers();
		srand(time(0));
		int size = res.size();
		while (true) {
			int idx = rand() % size;
			Attack atk = res[idx];
			collission<Mediummode, int> shart;
			if (shart.check_attack_condition(this, atk.get_condition())) {
				return atk;
			}
		}
	}
	void attack(Player* p2, bool& flag, sf::Clock& clk) {
		collission<Player, Player> takkar;
		srand(time(0));
		int random = 0;
		if (takkar.check_collission(*this, *p2) && p2->get_attack_status()) {
			random = rand() % 10;
			if (random == 0) {
				this->set_right_move(true);
			}
		}
		else if (takkar.check_collission(*this, *p2) && !p2->get_attack_status()) {
			if (!flag) {
				this->set_attack(true);
				flag = true;
				Attack atk = this->select_attack();
				this->set_jumping(false);
				this->set_sit(false);
				this->set_right_move(false);
				this->set_left_move(false);
				p2->set_health(p2->get_health() - atk.get_damage());
				this->set_box(atk.get_box());
				clk.restart();
			}
		}
		this->select_movement(p2);
		if (clk.getElapsedTime().asSeconds() > 0.2f) {
			this->set_box(this->get_defaultbox());
		}
		if (clk.getElapsedTime().asSeconds() > 1.f) {
			clk.restart();
			this->set_attack(false);
			flag = false;
		}
	}
	~Mediummode() = default;
};
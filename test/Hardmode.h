#pragma once
#include"computer.h"
using namespace std;
class Hardmode :public computer {
public:
	Hardmode(Fighter* _f):computer(_f){}
	Attack select_attack() {
		Dynamic_array<Attack> atks = this->f->get_powers();
		int size = atks.size();
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				if (atks[j].get_damage() > atks[i].get_damage()) {
					Attack temp = atks[i];
					atks[i] = atks[j];
					atks[j] = temp;
				}
			}
		}
		collission<Hardmode, int> shart;
		for (int i = 0; i < size; i++) {
			if (shart.check_attack_condition(this, atks[i].get_condition())) {
				return atks[i];
			}
		}
		return Attack();
	}
	void attack(Player* p2, bool& flag, sf::Clock& clk) {
		collission<Player, Player> takkar;
		if (takkar.check_collission(*this, *p2) && p2->get_attack_status()) {
			srand(time(0));
			int random = rand() % 5;
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
		if (clk.getElapsedTime().asSeconds() > 0.8f) {
			clk.restart();
			this->set_attack(false);
			flag = false;
		}
	}
};
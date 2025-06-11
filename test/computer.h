#pragma once
#include"Player.h"
using namespace std;
class computer : public Player {

public:
	computer(Fighter* _f):Player(_f){
		this->set_attack(true);
	}
	Attack select_attack() {
		return this->f->select_attack();
	}
	void attack(Player* p2, bool& flag, sf::Clock& clk) {
		float distance = this->get_x() - p2->get_x();
		if (distance < 0) {
			distance = distance * (-1);
		}
		collission<Player, Player> takkar;
		if (takkar.check_collission(*this, *p2) && p2->get_attack_status()) {
			this->set_right_move(true);
		}
		else if(takkar.check_collission(*this, *p2) && !p2->get_attack_status()){
			if (!flag) {
				flag = true;
				Attack atk = this->select_attack();
				this->set_jumping(false);
				this->set_sit(false);
				this->set_right_move(false);
				this->set_left_move(false);
				p2->set_health(p2->get_health() - atk.get_damage());
			}
			if (clk.getElapsedTime().asSeconds() > 0.2f) {
				clk.restart();
				this->set_box(this->get_defaultbox());
				flag = false;
			}
		}
		else  {
			if (isIdle()) {
				srand(time(0));
				int random = rand() % 4;
			}
		}
	}
};
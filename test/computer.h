#pragma once
#include"Player.h"
using namespace std;
class computer : public Player {

public:
	computer(Fighter* _f):Player(_f){
		this->set_attack(false);
		this->set_goingup(true);
	}
	void move_character(Player* p2, bool& flag, sf::Clock& clk) {
		collission<Player, Player> takkar;
		bool fl = takkar.check_collission(*this, *p2);
		f->computer_movement(fl, flag, clk);
	}
	Attack select_attack() {
		return this->f->select_attack();
	}
	void select_movement() {
		srand(time(0));
		int random = rand() % 2;
		if (random == 0) {
			random = rand() % 2;
			if (random == 0) {
				random = rand() % 2;
				if (random == 0) {
					this->set_sit(false);
					this->set_jumping(true);
				}
				else if(!this->get_jump()){
					this->set_sit(true);
				}
			}
			random = rand() % 2;
			if (random == 0 && !this->get_rightMoving()) {
				this->set_left_move(true);
			}
			else if(!this->get_leftMoving()){
				this->set_right_move(true);
			}
		}
	}
	void attack(Player* p2, bool& flag, sf::Clock& clk) {
		collission<Player, Player> takkar;
		if (takkar.check_collission(*this, *p2) && p2->get_attack_status()) {
			//this->set_right_move(true);
		}
		else if(takkar.check_collission(*this, *p2) && !p2->get_attack_status()){
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
		/*else  {
			this->select_movement();
		}*/
		if (clk.getElapsedTime().asSeconds() > 0.2f) {
			this->set_box(this->get_defaultbox());
		}
		if (clk.getElapsedTime().asSeconds() > 1.5f) {
			clk.restart();
			this->set_attack(false);
			flag = false;
		}
	}
};
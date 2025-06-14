#pragma once
#include"Player.h"
using namespace std;
class computer : public Player {
protected:
	String name;
public:
	computer(Fighter* _f) :Player(_f) {
		this->set_attack(false);
		this->set_goingup(true);
	}
	void move_character(Player* p2, bool& flag, sf::Clock& clk) {
		collission<Player, Player> takkar;
		bool fl = takkar.check_collission(*this, *p2);
		f->computer_movement(fl, flag, clk);
	}
	virtual Attack select_attack() = 0;
	void select_movement(Player* p2) {
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
	virtual void attack(Player* p2, bool& flag, sf::Clock& clk) = 0;
	virtual ~computer() = default;
};
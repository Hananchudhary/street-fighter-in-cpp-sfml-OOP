#pragma once
#include"Fighter.h"
#include"collission.h"
class Player {
protected:
	Fighter* f;
public:
	Player() :f { nullptr } {}
	Player(Fighter* _f):f{_f}{}
	void set_left_move(bool flag) {
		f->set_left_move(flag);
	}
	void set_right_move(bool flag) {
		f->set_right_move(flag);
	}
	void set_jumping(bool flag) {
		f->set_jumping(flag);
	}
	bool get_jump() const { return f->get_jump(); }
	void set_goingup(bool flag) {
		f->set_goingup(flag);
	}
	void set_place(float x, float y) {
		f->set_place(x, y);
	}
	void set_sit(bool flag) {
		f->set_sit(flag);
	}
	float get_x() const {
		return f->get_x();
	}
	virtual String get_name()const { return String(); }
	String get_fighter_name()const { return this->f->get_name(); }
	float get_y() const {
		return f->get_y();
	}
	bool get_attack_status() const { return f->get_attack_status(); }
	bool get_sitting()const { return f->get_sitting(); }
	void set_attack(bool flag) {
		f->set_attack(flag);
	}
	virtual void move_character(Player* p2,bool& flag, sf::Clock& clk) {
		f->move_character(flag, clk);
	}
	void set_box(sf::IntRect box) {
		f->set_box(box);
	}
	void display(sf::RenderWindow& window) const {
		f->display(window);
	}
	bool is_attacking()const {
		return f->is_attacking();
	}
	sf::Keyboard::Key get_right_key()const {
		return this->f->get_right_key();
	}
	sf::Keyboard::Key get_left_key()const {
		return this->f->get_left_key();
	}
	sf::Keyboard::Key get_up_key()const {
		return this->f->get_up_key();
	}
	sf::Keyboard::Key get_down_key()const {
		return this->f->get_down_key();
	}
	int get_condition() const {
		return f->get_attack_condition();
	}
	float get_health() const  {
		return f->get_health();
	}
	virtual void attack(Player* p2,bool& flag, sf::Clock& clk) {
		collission<Player, Player> takkar;
		collission<Player, int> condition;
		if (!flag && takkar.check_collission(*this,*p2) && condition.check_attack_condition(p2,this->get_condition())) {
			p2->set_health(p2->get_health() - f->attack());
			f->set_jumping(false);
			flag = true;
		}
		if (clk.getElapsedTime().asSeconds() > 0.2f) {
			flag = false;
			clk.restart();
			f->set_attack(false);
		}
	}
	sf::IntRect get_box() {
		return f->get_attack_box();
	}
	float get_GroundY() const { return f->get_GroundY(); }
	bool get_leftMoving()const { return f->get_leftMoving(); }
	bool get_rightMoving()const { return f->get_rightMoving(); }
	void set_health(float val) {
		f->set_health(val);
	}
	bool isSitting()const {
		return f->isSitting();
	}
	sf::IntRect get_defaultbox()const {
		return f->get_defaultbox();
	}
	bool isIdle()const {
		if (!f->get_jump() && !get_sitting() && !get_leftMoving() && !get_rightMoving()) {
			return true;
		}
		return false;
	}
	virtual ~Player() = default;
};
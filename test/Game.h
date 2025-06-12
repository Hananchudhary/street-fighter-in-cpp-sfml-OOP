#pragma once
#include"Ring.h"
#include"mystr.h"
#include"dynamic_array.h"
#include"background.h"
#include"ryu.h"
#include"chun-li.h"
#include"Player.h"
#include"Ring.h"
#include"collission.h"
#include"computer.h"
#include"Hardmode.h"
#include"Mediummode.h"
#include"Easymode.h"
#include<fstream>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class game {
    Ring match;
    sf::RenderWindow window;
    bool istwoplayer;
    bool play_again() {}
    void select_mode() {}
    Player select_player() {}
    string get_bg() {}
    void select_difficulty() {}
    void handle_processes(Player* ryu, Player* chun, sf::RenderWindow& window, sf::Clock& atk_clk, sf::Clock& atk_clk2) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();

                if (event.key.code == sf::Keyboard::W) {
                    if (!ryu->get_jump()) {
                        ryu->set_jumping(true);
                        ryu->set_goingup(true);
                    }
                }
                if (event.key.code == sf::Keyboard::Up && istwoplayer) {
                    if (!chun->get_jump()) {
                        chun->set_jumping(true);
                        chun->set_goingup(true);
                    }
                }
                if (ryu->is_attacking() && !ryu->get_attack_status()) {
                    atk_clk.restart();
                    ryu->set_attack(true);
                    sf::IntRect temp = ryu->get_box();
                    if (temp != sf::IntRect({ 1000,1000 }, { 1000,1000 })) {
                        ryu->set_box(temp);
                    }
                }
                if (chun->is_attacking() && !chun->get_attack_status() && istwoplayer) {
                    atk_clk2.restart();
                    chun->set_attack(true);
                    sf::IntRect temp = chun->get_box();
                    if (temp != sf::IntRect({ 1000,1000 }, { 1000,1000 })) {
                        chun->set_box(temp);
                    }
                }
            }
        }
    }
    void handle_movements(Player* ryu, Player* chun, collission<Player, Player>& takkar) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ryu->get_x() < 1190 && !takkar.check_collission(*ryu, *chun)) {

            ryu->set_left_move(false);
            ryu->set_right_move(true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && chun->get_x() < 1070 && istwoplayer) {
            chun->set_left_move(false);
            chun->set_right_move(true);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && ryu->get_x() > 131) {
            ryu->set_left_move(true);
            ryu->set_right_move(false);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && chun->get_x() > 20 && istwoplayer && !takkar.check_collission(*ryu, *chun)) {
            chun->set_left_move(true);
            chun->set_right_move(false);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !ryu->get_jump()) {
            ryu->set_sit(true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !chun->get_jump() && istwoplayer) {
            chun->set_sit(true);
        }

        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            ryu->set_sit(false);
        }
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && istwoplayer) {
            chun->set_sit(false);
        }
    }
    void update_frame(Player* ryu, Player* chun, bool& flag, sf::Clock& clk) {
        if (!ryu->get_attack_status()) {
            ryu->move_character(chun,flag, clk);
        }
        if (!chun->get_attack_status()/* || !istwoplayer*/) {
            chun->move_character(ryu,flag, clk);
        }
    }
    void store_data(Player* ryu, Player* chun) {
        ofstream fout("data.bin", ios::binary);
        try {
            if (!fout) {
                throw ("file cannot open to write");
            }
        }
        catch (const char* err) {
            cout << err << endl;
        }
        float val1 = ryu->get_x(), val2 = chun->get_x();
        int val3 = 0;
        if (istwoplayer)
            val3 = 1;
        else
            val3 = 0;

        fout.write((char*)&val1, sizeof(val1));
        fout.write((char*)&val2, sizeof(val2));
        fout.write((char*)&val3, sizeof(val3));
        fout.close();
    }
    void load_data(Player* ryu, Player* chun) {
        ifstream fin("data.bin", ios::binary);
        try {
            if (!fin) {
                throw ("file cannot open to write");
            }
        }
        catch (const char* err) {
            cout << err << endl;
        }
        float val1, val2;
        int val3;
        fin.read((char*)&val1, sizeof(val1));
        fin.read((char*)&val2, sizeof(val2));
        fin.read((char*)&val3, sizeof(val3));
        fin.close();
        ryu->set_place(val1, ryu->get_GroundY());
        chun->set_place(val2, chun->get_GroundY());
        if (val3 == 0)
            istwoplayer = false;
        else
            istwoplayer = true;
    }
    void match_start() {
        sf::Clock clk, atk_clk, atk_clk2;
        collission<Player, Player> takkar;
        bool flag = false;
        bool attack_flag = false, attack_flag2 = false;
        Ryu* ryu1 = new Ryu(sf::IntRect({ 0,0 }, { 25,50 }), "ryu.png", 210.f, 13.f, 0.2f, 0.09f, -6.f, 6.f, 483.f, 260.f, 30.f, 1.f, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::R, sf::Keyboard::T, sf::Keyboard::F, sf::Keyboard::G);
        chun_li* chun2 = new chun_li(sf::IntRect({ 10,24 }, { 25,50 }), "chun-li.png", 210.f, 13.f, 0.2f, 0.09f, 4.5f, 4.5f, 733.f, 320.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);
        Player ryu(ryu1);
        Easymode chun(chun2);
        match.set("bg6.jpg", window, &ryu, &chun);
        this->load_data(&ryu, &chun);
        while (window.isOpen()) {
            handle_processes(&ryu, &chun, window, atk_clk, atk_clk2);
            handle_movements(&ryu, &chun, takkar);
            match.attack(attack_flag, atk_clk, attack_flag2, atk_clk2,this->istwoplayer);

            update_frame(&ryu, &chun, flag, clk);
            
            window.clear();
            match.display(window);
            window.display();
            if (match.is_match_end()) {
                break;
            }
        }
        this->store_data(&ryu, &chun);
        delete ryu1;
        delete chun2;
    }
public:
    game() :window(sf::VideoMode(1200, 600), "Street Fighter 2"), istwoplayer{false} {}
	
	void run() {
        this->match_start();
	}
};
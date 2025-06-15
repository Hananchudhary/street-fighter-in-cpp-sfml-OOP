#pragma once
#include"Ring.h"
#include"mystr.h"
#include"dynamic_array.h"
#include"background.h"
#include"ryu.h"
#include"chun-li.h"
#include"joe.h"
#include"guile.h"
#include"Player.h"
#include"Ring.h"
#include"collission.h"
#include"computer.h"
#include"Hardmode.h"
#include"Mediummode.h"
#include"Easymode.h"
#include<fstream>
#include"spriteloader.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class game {
    Ring match;
    sf::RenderWindow window;
    bool istwoplayer;
    void main_menu() {
        sf::Sprite bgs;
        sf::Texture bgt;
        spriteloader utility;
        utility.load(bgs, bgt, "main-menu.jpg", this->window);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return;
                }
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                        return;
                    }
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                if (pos.x > 400 && pos.x < 802 && pos.y>345 && pos.y < 380) {
                    this->delay(1.f);
                    this->select_mode();
                    break;
                }
                else if (pos.x > 412 && pos.x < 788 && pos.y>404 && pos.y < 434) {
                    this->delay(1.f);
                    Player* p1 = nullptr;
                    Player *p2 = nullptr;
                    string bg = this->load_data(p1, p2);
                    this->match_start(bg,p1,p2);
                    break;
                }
            }
            window.clear();
            window.draw(bgs);
            window.display();
        }
    }
    void show_victory(int cntrl) {
        sf::Clock clk;
        sf::Sprite bgs;
        sf::Texture bgt;
        spriteloader utility;
        if (cntrl == 1) {
            utility.load(bgs, bgt, "p1-win.png", this->window);
        }
        else {
            utility.load(bgs, bgt, "p2-win.png", this->window);
        }
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                }
            }
            if (clk.getElapsedTime().asSeconds() > 2.f) {
                break;
            }
            window.clear();
            window.draw(bgs);
            window.display();
        }
        this->play_again();
    }
    void play_again() {
        sf::Sprite bgs;
        sf::Texture bgt;
        spriteloader utility;
        utility.load(bgs, bgt, "play-again.png", this->window);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                if (pos.x > 231 && pos.x < 967 && pos.y > 285 && pos.y < 334) {
                    this->delay(1.f);
                    this->select_mode();
                    break;
                }
                else if (pos.x > 462 && pos.x < 755 && pos.y > 386 && pos.y < 436) {
                    return;
                }
            }
            window.clear();
            window.draw(bgs);
            window.display();
        }
    }
    void select_mode() {
        sf::Sprite bgs;
        sf::Texture bgt;
        Player* p1 = nullptr;
        Player* p2 = nullptr;
        spriteloader utility;
        utility.load(bgs, bgt, "modes.png", this->window);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return;
                }
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                        return;
                    }
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                if (pos.x > 118 && pos.x < 985 && pos.y > 218 && pos.y < 277) {
                    this->istwoplayer = false;
                    this->delay(1.f);
                    this->select_difficulty();
                    break;
                }
                else if (pos.x > 136 && pos.x < 984 && pos.y > 320 && pos.y < 370) {
                    this->istwoplayer = true;
                    this->delay(1.f);
                    p1 = this->select_player(true);
                    if (p1 != nullptr) {
                        this->delay(1.f);
                        p2 = this->select_player(false);
                        if (p2 != nullptr) {
                            this->delay(1.f);
                            this->match_start(this->get_bg(), p1, p2);
                        }
                    }
                    break;
                }
            }
            window.clear();
            window.draw(bgs);
            window.display();
        }
    }
    Player* select_player(bool flag) {
        Ryu* ryu1 = new Ryu(sf::IntRect({ 0,0 }, { 25,50 }), "ryu.png", 210.f, 13.f, 0.2f, 0.09f, -6.f, 6.f, 483.f, 260.f, 30.f, 1.f, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::R, sf::Keyboard::T, sf::Keyboard::F, sf::Keyboard::G);
        chun_li* chun1 = new chun_li(sf::IntRect({ 10,24 }, { 25,50 }), "chun-li.png", 210.f, 13.f, 0.2f, 0.09f, 4.5f, 4.5f, 733.f, 320.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);
        Ryu* ryu2 = new Ryu(sf::IntRect({ 0,0 }, { 25,50 }), "ryu.png", 210.f, 13.f, 0.2f, 0.09f, 6.f, 6.f, 700.f, 260.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);
        chun_li* chun2 = new chun_li(sf::IntRect({ 10,24 }, { 25,50 }), "chun-li.png", 210.f, 13.f, 0.2f, 0.09f, -4.5f, 4.5f, 485.f, 320.f, 30.f, 1.f, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::R, sf::Keyboard::T, sf::Keyboard::F, sf::Keyboard::G);
        guile* guile1 = new guile(sf::IntRect({ 2,15 }, { 20,50 }), "guile.png", 210.f, 13.f, 0.2f, 0.09f, 5.5f, 5.5f, 470.f, 272.f, 30.f, 1.f, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::R, sf::Keyboard::T, sf::Keyboard::F, sf::Keyboard::G);
        Joe* joe2 = new Joe(sf::IntRect({ 6,7 }, { 28,57 }), "joe.png", 210.f, 13.f, 0.2f, 0.09f, 4.5f, 4.5f, 660.f, 287.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);
        guile* guile2 = new guile(sf::IntRect({ 2,15 }, { 20,50 }), "guile.png", 210.f, 13.f, 0.2f, 0.09f, -5.5f, 5.5f, 710.f, 272.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);
        Joe* joe1 = new Joe(sf::IntRect({ 6,7 }, { 28,57 }), "joe.png", 210.f, 13.f, 0.2f, 0.09f, -4.5f, 4.5f, 530.f, 287.f, 30.f, 1.f, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::R, sf::Keyboard::T, sf::Keyboard::F, sf::Keyboard::G);

        Player* res = nullptr;
        sf::Sprite bgs;
        sf::Texture bgt;
        spriteloader utility;
        utility.load(bgs, bgt, "players.jpg", this->window);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                    return nullptr;
                }
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                        return nullptr;
                    }
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                if (pos.x > 522 && pos.x < 625 && pos.y > 275 && pos.y < 322) {
                    if (flag) {
                        res = new Player(ryu1);
                    }
                    else {
                        res = new Player(ryu2);
                    }
                    return res;
                }
                else if (pos.x > 522 && pos.x < 630 && pos.y > 340 && pos.y < 390) {
                    if (flag) {
                        res = new Player(chun2);
                    }
                    else {
                        res = new Player(chun1);
                    }
                    return res;
                }
                else if (pos.x > 535 && pos.x < 628 && pos.y > 425 && pos.y < 470) {
                    if (flag) {
                        res = new Player(joe1);
                    }
                    else {
                        res = new Player(joe2);
                    }
                    return res;
                }
                else if (pos.x > 530 && pos.x < 630 && pos.y > 487 && pos.y < 527) {
                    if (flag) {
                        res = new Player(guile1);
                    }
                    else {
                        res = new Player(guile2);
                    }
                    return res;
                }
                cout << pos.x << "  " << pos.y << endl;
            }
            window.clear();
            window.draw(bgs);
            window.display();
        }
        
        return nullptr;
    }
    void delay(float time) {
        sf::Clock clock;
        sf::Vector2f center(window.getSize().x / 2.f, window.getSize().y / 2.f);
        const float PI = 3.14159265f;
        const float radius = 100.f;
        const float drawTimeSeconds = time; // Total time to complete the circle
        const int maxSegments = 360;
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                }
            }

            float elapsed = clock.getElapsedTime().asSeconds();
            float percent = std::min(elapsed / drawTimeSeconds, 1.f);
            int segmentsToDraw = static_cast<int>(percent * maxSegments);
            if (elapsed >= time) {
                return;
            }
            sf::VertexArray circle(sf::TriangleFan, segmentsToDraw + 2);
            circle[0].position = center;
            circle[0].color = sf::Color::Green;

            for (int i = 0; i <= segmentsToDraw; ++i) {
                float angle = i * 2 * PI / maxSegments;
                float x = center.x + radius * std::cos(angle);
                float y = center.y + radius * std::sin(angle);
                circle[i + 1].position = sf::Vector2f(x, y);
                circle[i + 1].color = sf::Color::Yellow;
                
            }
            if (elapsed >= time) {
                return;
            }
            window.clear(sf::Color::Black);
            window.draw(circle);
            window.display();
        }
    }
    Fighter* computer_select_fighter() {
        srand(time(0));
        int idx = rand() % 4;
        Ryu* ryu2 = new Ryu(sf::IntRect({ 0,0 }, { 25,50 }), "ryu.png", 210.f, 13.f, 0.2f, 0.09f, 6.f, 6.f, 700.f, 260.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);
        chun_li* chun1 = new chun_li(sf::IntRect({ 10,24 }, { 25,50 }), "chun-li.png", 210.f, 13.f, 0.2f, 0.09f, 4.5f, 4.5f, 733.f, 320.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);
        Joe* joe2 = new Joe(sf::IntRect({ 6,7 }, { 28,57 }), "joe.png", 210.f, 13.f, 0.2f, 0.09f, 4.5f, 4.5f, 660.f, 287.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);
        guile* guile2 = new guile(sf::IntRect({ 2,15 }, { 20,50 }), "guile.png", 210.f, 13.f, 0.2f, 0.09f, -5.5f, 5.5f, 710.f, 272.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);

        Fighter* res = nullptr;
        if (idx == 0) {
            res = (ryu2);
        }
        else if (idx == 1) {
            res = joe2;
        }
        else if (idx == 2) {
            res = guile2;
        }
        else {
            res = (chun1);
        }
        return res;
    }
    string set_bg(int idx) {
        try {
            if (idx == 0) {
                return string("bg1.jpg");
            }
            else if (idx == 1) {
                return string("bg2.jpg");
            }
            else if (idx == 2) {
                return string("bg3.jpg");
            }
            else if (idx == 3) {
                return string("bg4.jpg");
            }
            else if (idx == 4) {
                return string("bg5.jpg");
            }
            else if (idx == 5) {
                return string("bg6.jpg");
            }
            else {
                throw ("Wrong bg");
            }
        }
        catch (const char* err) {
            cout << err << endl;
        }
        return string("bg6.jpg");
    }
    string get_bg() {
        srand(time(0));
        int random = rand() % 6;
        return set_bg(random);
    }
    void select_difficulty() {
        Player* p1 = select_player(true);
        this->delay(1.f);
        sf::Sprite bgs;
        sf::Texture bgt;
        spriteloader utility;
        utility.load(bgs, bgt, "difficulty.png", this->window);
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape)
                        window.close();
                }
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i pos = sf::Mouse::getPosition(window);
                if (pos.x > 201 && pos.x < 840 && pos.y > 206 && pos.y < 266) {
                    Easymode* p2 = new Easymode(this->computer_select_fighter());
                    this->delay(1.f);
                    this->match_start(this->get_bg(), p1, p2);
                    break;
                }
                else if (pos.x > 200 && pos.x < 990 && pos.y > 295 && pos.y < 345) {
                    Mediummode* p2 = new Mediummode(this->computer_select_fighter());
                    this->delay(1.f);
                    this->match_start(this->get_bg(), p1, p2);
                    break;
                }
                else if (pos.x > 215 && pos.x < 870 && pos.y > 370 && pos.y < 415) {
                    Hardmode* p2 = new Hardmode(this->computer_select_fighter());
                    this->delay(1.f);
                    this->match_start(this->get_bg(), p1, p2);
                    break;
                }
            }
            window.clear();
            window.draw(bgs);
            window.display();
        }
    }
    bool handle_processes(Player* ryu, Player* chun, sf::RenderWindow& window, sf::Clock& atk_clk, sf::Clock& atk_clk2) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return false;
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                    return false;
                }

                if (event.key.code == ryu->get_up_key()) {
                    if (!ryu->get_jump()) {
                        ryu->set_jumping(true);
                        ryu->set_goingup(true);
                    }
                }
                if (event.key.code == chun->get_up_key() && istwoplayer) {
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
        return true;
    }
    void handle_movements(Player* p1,Player* p2, collission<Player, Player>& takkar) {
        
        if (sf::Keyboard::isKeyPressed(p2->get_right_key()) && p2->get_x() < 1070 && istwoplayer) {
                p2->set_left_move(false);
                p2->set_right_move(true);
            }
        if (sf::Keyboard::isKeyPressed(p1->get_right_key()) && p1->get_x() < 1190 && !takkar.check_collission(*p1, *p2)) {
                p1->set_left_move(false);
                p1->set_right_move(true);
            }
        

        if (sf::Keyboard::isKeyPressed(p1->get_left_key()) && p1->get_x() > 131) {
                p1->set_left_move(true);
                p1->set_right_move(false);
            }
        if (sf::Keyboard::isKeyPressed(p2->get_left_key()) && p2->get_x() > 131 && !takkar.check_collission(*p1, *p2) && istwoplayer) {
                p2->set_left_move(true);
                p2->set_right_move(false);
            }

        if (sf::Keyboard::isKeyPressed(p2->get_right_key()) && p2->get_x() < 1070/* && !takkar.check_collission(*p1, *p2)*/ && istwoplayer) {
                p2->set_left_move(false);
                p2->set_right_move(true);
            }
        if (sf::Keyboard::isKeyPressed(p1->get_right_key()) && p1->get_x() < 1070 && !takkar.check_collission(*p1, *p2)) {
                p1->set_left_move(false);
                p1->set_right_move(true);
            }

        if (sf::Keyboard::isKeyPressed(p1->get_left_key()) && p1->get_x() > 20/* && !takkar.check_collission(*p1, *p2)*/) {
                p1->set_left_move(true);
                p1->set_right_move(false);
            }
        if (sf::Keyboard::isKeyPressed(p2->get_left_key()) && p2->get_x() > 20 && istwoplayer && !takkar.check_collission(*p1, *p2)) {
                p2->set_left_move(true);
                p2->set_right_move(false);
            }

        if (sf::Keyboard::isKeyPressed(p2->get_down_key()) && !p2->get_jump()) {
                p2->set_sit(true);
            }
        if (sf::Keyboard::isKeyPressed(p1->get_down_key()) && !p1->get_jump()) {
                p1->set_sit(true);
            }

        if (!sf::Keyboard::isKeyPressed(p1->get_down_key())) {
                p1->set_sit(false);
            }
        if (!sf::Keyboard::isKeyPressed(p2->get_down_key())) {
                p2->set_sit(false);
            }
    }
    void update_frame(Player* ryu, Player* chun, bool& flag, sf::Clock& clk) {
        if (!ryu->get_attack_status()) {
            ryu->move_character(chun,flag, clk);
        }
        if (!chun->get_attack_status()) {
            chun->move_character(ryu,flag, clk);
        }
    }
    void store_data(bool flag,Player* ryu, Player* chun) {
        ofstream fout("data.bin", ios::binary);
        try {
            if (!fout) {
                throw ("file cannot open to write");
            }
        }
        catch (const char* err) {
            cout << err << endl;
        }
        float val1 = ryu->get_x(), val2 = chun->get_x(), health1 = ryu->get_health(), health2 = chun->get_health();
        int players = 0, fighter1 = 1, fighter2 = 1, data = 0, mode = 0, bg = this->match.get_bg();
        String name1 = ryu->get_fighter_name(), name2 = chun->get_fighter_name();
        if (name1 == "chun")
            fighter1 = 0;
        if (name1 == "joe") {
            fighter1 = 2;
        }
        if (name1 == "guile") {
            fighter1 = 3;
        }
        if (name2 == "chun")
            fighter2 = 0;
        if (name2 == "joe") {
            fighter2 = 2;
        }
        if (name2 == "guile") {
            fighter2 = 3;
        }
        if (istwoplayer) 
            players = 1;
        if (!istwoplayer) {
            if (chun->get_name() == "medium")
                mode = 1;
            if (chun->get_name() == "hard")
                mode = 2;
        }
        
        if (flag)
            data = 1;
        
        fout.write((char*)&data, sizeof(data));
        fout.write((char*)&bg, sizeof(bg));
        fout.write((char*)&players, sizeof(players));
        fout.write((char*)&fighter1, sizeof(fighter1));
        fout.write((char*)&val1, sizeof(val1));
        fout.write((char*)&health1, sizeof(health1));
        if (!istwoplayer) {
            fout.write((char*)&mode, sizeof(mode));
        }

        fout.write((char*)&fighter2, sizeof(fighter2));
        fout.write((char*)&val2, sizeof(val2));
        fout.write((char*)&health2, sizeof(health2));

        fout.close();
    }
    string load_data(Player*& ryu, Player*& chun) {
        Ryu* ryu1 = new Ryu(sf::IntRect({ 0,0 }, { 25,50 }), "ryu.png", 210.f, 13.f, 0.2f, 0.09f, -6.f, 6.f, 483.f, 260.f, 30.f, 1.f, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::R, sf::Keyboard::T, sf::Keyboard::F, sf::Keyboard::G);
        chun_li* chun1 = new chun_li(sf::IntRect({ 10,24 }, { 25,50 }), "chun-li.png", 210.f, 13.f, 0.2f, 0.09f, 4.5f, 4.5f, 733.f, 320.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);
        Ryu* ryu2 = new Ryu(sf::IntRect({ 0,0 }, { 25,50 }), "ryu.png", 210.f, 13.f, 0.2f, 0.09f, 6.f, 6.f, 700.f, 260.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);
        chun_li* chun2 = new chun_li(sf::IntRect({ 10,24 }, { 25,50 }), "chun-li.png", 210.f, 13.f, 0.2f, 0.09f, -4.5f, 4.5f, 485.f, 320.f, 30.f, 1.f, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::R, sf::Keyboard::T, sf::Keyboard::F, sf::Keyboard::G);
        guile* guile1 = new guile(sf::IntRect({ 2,15 }, { 20,50 }), "guile.png", 210.f, 13.f, 0.2f, 0.09f, 5.5f, 5.5f, 470.f, 272.f, 30.f, 1.f, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::R, sf::Keyboard::T, sf::Keyboard::F, sf::Keyboard::G);
        Joe* joe2 = new Joe(sf::IntRect({ 6,7 }, { 28,57 }), "joe.png", 210.f, 13.f, 0.2f, 0.09f, 4.5f, 4.5f, 660.f, 287.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);
        guile* guile2 = new guile(sf::IntRect({ 2,15 }, { 20,50 }), "guile.png", 210.f, 13.f, 0.2f, 0.09f, -5.5f, 5.5f, 710.f, 272.f, 700.f, 1.f, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::I, sf::Keyboard::O, sf::Keyboard::K, sf::Keyboard::L);
        Joe* joe1 = new Joe(sf::IntRect({ 6,7 }, { 28,57 }), "joe.png", 210.f, 13.f, 0.2f, 0.09f, -4.5f, 4.5f, 530.f, 287.f, 30.f, 1.f, sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::R, sf::Keyboard::T, sf::Keyboard::F, sf::Keyboard::G);

        ifstream fin("data.bin", ios::binary);
        try {
            if (!fin) {
                throw ("file cannot open to write");
            }
        }
        catch (const char* err) {
            cout << err << endl;
        }
        float val1 = 0, val2 = 0, health1 = 0, health2 = 0;
        int players = 0, fighter1 = 1, fighter2 = 1, data = 0,bg = 5, mode = 0;
        fin.read((char*)&data, sizeof(data));
        if (data == 0) {
            this->select_mode();
            return this->get_bg();
        }
        fin.read((char*)&bg, sizeof(bg));
        string back = set_bg(bg);
        fin.read((char*)&players, sizeof(players));
        fin.read((char*)&fighter1, sizeof(fighter1));
        fin.read((char*)&val1, sizeof(val1));
        fin.read((char*)&health1, sizeof(health1));
        if (fighter1 == 0)
            ryu = new Player(chun2);
        else if (fighter1 == 2)
            ryu = new Player(joe1);
        else if (fighter1 == 3)
            ryu = new Player(guile1);
        else
            ryu = new Player(ryu1);
        if (players != 1) {
            this->istwoplayer = false;
            fin.read((char*)&mode, sizeof(mode));
        }
        else {
            this->istwoplayer = true;
        }
        fin.read((char*)&fighter2, sizeof(fighter2));
        fin.read((char*)&val2, sizeof(val2));
        fin.read((char*)&health2, sizeof(health2));
        if (players != 1) {
            if (fighter2 == 1) {
                if (mode == 1) {
                    Mediummode* p2 = new Mediummode(ryu2);
                    chun = p2;
                }
                else if (mode == 2) {
                    Hardmode* p2 = new Hardmode(ryu2);
                    chun = p2;
                }
                else {
                    Easymode* p2 = new Easymode( ryu2);
                    chun = p2;
                }
            }
            else if (fighter2 == 2) {
                if (mode == 1) {
                    Mediummode* p2 = new Mediummode(joe2);
                    chun = p2;
                }
                else if (mode == 2) {
                    Hardmode* p2 = new Hardmode(joe2);
                    chun = p2;
                }
                else {
                    Easymode* p2 = new Easymode(joe2);
                    chun = p2;
                }
            }
            else if (fighter2 == 3) {
                if (mode == 1) {
                    Mediummode* p2 = new Mediummode(guile2);
                    chun = p2;
                }
                else if (mode == 2) {
                    Hardmode* p2 = new Hardmode(guile2);
                    chun = p2;
                }
                else {
                    Easymode* p2 = new Easymode(guile2);
                    chun = p2;
                }
            }
            else {
                if (mode == 1) {
                    Mediummode* p2 = new Mediummode(chun1);
                    chun = p2;
                }
                else if (mode == 2) {
                    Hardmode* p2 = new Hardmode(chun1);
                    chun = p2;
                }
                else {
                    Easymode* p2 = new Easymode(chun1);
                    chun = p2;
                }
            }
        }
        else {
            if (fighter2 == 0) {
                chun = new Player(chun1);
            }
            else if (fighter2 == 2)
                chun = new Player(joe2);
            else if (fighter2 == 3)
                chun = new Player(guile2);
            else {
                chun = new Player(ryu2);
            }
        }
        ryu->set_place(val1, ryu->get_GroundY());
        chun->set_place(val2, chun->get_GroundY());
        chun->set_health(health2);
        ryu->set_health(health1);
        fin.close();
        return back;
    }
    void match_start(string filename,Player* p1,Player* p2) {
        sf::Clock clk, atk_clk, atk_clk2;
        collission<Player, Player> takkar;
        bool flag = false;
        int cntrl = 0;
        bool attack_flag = false, attack_flag2 = false;
        match.set(filename, window, p1, p2);
        while (window.isOpen()) {
            if (handle_processes(p1, p2, window, atk_clk, atk_clk2)) {}
            else
                break;

            handle_movements(p1, p2, takkar);
            match.attack(attack_flag, atk_clk, attack_flag2, atk_clk2,this->istwoplayer);

            update_frame(p1, p2, flag, clk);
            
            window.clear();
            match.display(window);
            window.display();
            cntrl = match.is_match_end();
            if (cntrl == 1 || cntrl == 2) {
                break;
            }
        }
        if (cntrl != 0) {
            this->show_victory(cntrl);
            this->store_data(false, p1, p2);
        }
        else {
            this->store_data(true, p1, p2);
        }
        delete p1;
        delete p2;
    }
public:
    game() :window(sf::VideoMode(1200, 600), "Street Fighter 2"), istwoplayer{true} {}
	
	void run() {
        this->main_menu();
	}
    ~game() = default;
};
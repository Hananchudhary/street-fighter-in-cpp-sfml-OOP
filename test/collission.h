#pragma once
template <typename T1, typename T2>
class collission {
public:
	bool check_collission(T1 p1,T2 p2) const {
        if (p1.get_x() < p2.get_x()) {
            if (p1.get_x() + 20.f > p2.get_x()) {
                return true;
            }
        }
        else {
            if (p2.get_x() + 20.f > p1.get_x()) {
                return true;
            }
        }
        return false;
	}
    bool check_attack_condition(T1 player1, T2 condition) {
        try {
            if (condition == 1) {
                if (player1.get_y() < player1.get_GroundY() - 50.f) {
                    return false;
                }
                return true;
            }
            else if (condition == 2) {
                if (player1.is_sitting()) {
                    return false;
                }
                return true;
            }
            else if (condition == 0) {
                return true;
            }
            else {
                throw("attack not bounded");
            }
        }
        catch (String err) {
            cout << err;
        }
        return true;
    }

};
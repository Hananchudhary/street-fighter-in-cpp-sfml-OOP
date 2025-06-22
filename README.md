Project title : Street Fighter 2 (2D fighting game)

Language : C++

Graphics Library : SFML (Simple and Fast Multimedia Library)

Introduction :

This project is a 2D arcade-style fighting game inspired by Street Fighter 2. The core idea is to allow two characters (either player vs player or player vs computer) to fight. The game includes multiple moves (punches, kicks, combos), jumping, sitting and backgrounds. The game provides a rich user experience with keyboard-controlled characters and mouse navigation based menus.

Features :

•	Continue recent game: Users can continue from where they last left off, with all same things settings and states preserved.

•	Dynamic Background: Random background selection from 6 unique environments at the start of every new fight.

•	Two-player mode: Both characters are user-controlled on same keyboard using different sets of keys for movement and attack.

•	Single-player mode: AI opponent with different difficulty levels (Easy, Medium or Hard).

•	Computer movement and attacks: AI uses randomization in movements (left, right, jump and crouch), attack and block strategies depends on difficulty level selected by user.

•	Dynamic character selection: In single-player mode, the computer randomly selects a fighter from Ryu, Chun-Li, Joe, or Guile.

•	Jumping/Crouching/Movement: Smooth character movements including move, jump or crouch either by user-controlled keys or AI.

•	Attack Types: Besides with simple punches and kicks, includes combos jump-punch, crouch-kick, etc.

•	Attack Blocking: Attacks can be blocked by moving opposite to the enemy and if that specific attack has some special block condition like jump or crouch.

•	Timer-based Logic: Uses sf::Clock for time-sensitive events like attack intervals, animations and jumps.

•	Animations: Character are animated using timer-based logics and different rects in sprite-sheet of character.

•	Character Options: 4 characters (Ryu, Chun-Li, Joe and Guile) each with unique attack styles and damage values.

•	Collision Detection: Prevents character from passing through each other and exiting the window.

•	Health system: Characters lose health depending upon the attack's damage he took by the opponent.

•	State saving: Game state (settings, fighters, their health and position) is saved in a binary file if the player exits mid-match.

•	Play Again Option: Players can restart or exit after a match ends.

Challenges and Solutions :

•	When the user clicks in first menu same click was being done in second menu. To solve this, I added circle animations (delay) between all the events.

•	Background didn't scale correctly on second playthrough because texture was loaded and scaled once, but SFML retained the old scale. To solve this, I Reset the texture scale explicitly on each game start using updated window size.

•	Loading new textures for each animation frame slowed the game. Instead I used sprite sheets and modified texture rects for animations.

•	Jump was not done correctly, because it cannot be done while player hold the key like the other movements. To solve this, I detect jump key status and initialized set_jump() function to perform proper jump.

•	The character was not moving right or left along with jump because of SFML input handling; if you're holding the Right key and then press Up, you're no longer getting KeyPressed events for Right — it's already being held. To solve this, I checked the movements (left and right) keys status outside the event loop.

•	Collision detection weas affected due to default origin at the top-left corner. To solve this, I set corrected origins manually at the time of fighter (object) creation depending on the character's facing direction.

•	Health of opponent was decreasing rapidly to 0 on attack because attack() function was called in every frame and in one-press of a key there are many frames. To solve this, I set the condition that the player can only attack after 0.2 second of its previous attack using sf::Clock.

•	Combo attacks (like up + kick, down + punch, etc) were not working because I was trying to detect the all keys status in one frame which is difficult since one frame is of microseconds. To solve this, I changed the logic and checked character movements flags and the attacking keys status.

•	There was a frame gap in which the sprite was undefined when it was going from attack mode to normal mode because in the last microseconds of key pressed its status becomes true in checking attack status (is_attacking() function) but its status becomes false in getting the rect box (get_box() function) of attack animation. To solve this, I explicitely checked if the get_box() returns a valid box or not and decided accordingly.

•	Basic AI was too predictable. To solve this, I introduced randomization (srand, rand) in decisions (move forward/backward, attack, block, idle).

•	match_start() function became difficult to maintain. So, I broke it down into smaller functions like handle_processes(), update_frame() and handle_movement().

•	It was difficult to find logical errors in SFML programs because they cannot be debug line by line. I used to print things at many places and functions.

Video demo :

https://drive.google.com/file/d/19nGuq4PfqTyaucDzAP_zviqS3WgNwH4Q/view?usp=sharing

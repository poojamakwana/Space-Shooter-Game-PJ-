# Space-Shooter-Game
This is a simple console-based space shooter game implemented in C++. The game involves controlling a spaceship to shoot down aliens while avoiding space debris. The game screen is represented by a 2D character array, and the gameplay logic is implemented in the game function.

The game function initializes variables to control various aspects of the game, such as the positions of aliens, bullets, score, lives, and level. It uses nested loops to update the game screen, handle player controls, and manage the movement and collision detection of aliens and bullets.

The game loop continuously updates the game screen and handles player input. The position of the spaceship is updated based on the player's input, and bullets are fired by pressing the spacebar. Collision detection is performed to check if a bullet hits an alien, destroying it. The positions of the aliens are updated in each iteration, and if an alien reaches the bottom row, the player loses a life.

The game loop continuously displays the game's current state, including the spaceship, aliens, bullets, score, lives, and level. If the player loses all lives, a game-over screen is displayed, giving the option to restart the game or quit.

#ifndef GAME_STATE_H
#define GAME_STATE_H

enum GameMode {
    GAME_MODE_PVP = 0,
    GAME_MODE_CPU = 1,
    GAME_MODE_EDIT = 2,
    GAME_MODE_QUIT = 3,
    GAME_MODE_CONTINUE = 4,
    GAME_MODE_SAVE = 5,
    GAME_MODE_LOAD = 6,
    GAME_MODE_MAIN_MENU = 7,
    GAME_MODE_PAUSE = 8,
    GAME_MODE_TOTAL = 9
};

typedef enum GameMode GameMode;

struct GameState {
    int pause;
    GameMode gameState;
};

typedef struct GameState GameState;

GameState* createGameState();
void destroyGameState(GameState* gameState);
GameMode getGameState(const GameState* gameState);
void setGameState(GameState* gameState, GameMode gameMode);
void startStateMachine(GameState* gameState, GameMode gameMode);
void renderPauseMenu();
void renderPVP();
void renderMainMenu();
void renderEditMode();
void renderCPU();

#endif

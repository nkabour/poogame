#include "game.h"
#include <assert.h>
#include <iostream>
#include <raylib.h>
#include <string>

Game::Game(int width, int height, int fps, std::string title)
    : board(15, width - 100, height - 100, 5) {

  assert(!GetWindowHandle());
  SetTargetFPS(fps);
  InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept {
  assert(GetWindowHandle());
  CloseWindow();
}

bool Game::GameShouldClose() const { return WindowShouldClose(); }
void Game::Tick() {

  BeginDrawing();
  Update();
  Draw();
  EndDrawing();
}

void Game::Draw() {

  board.Draw();
  board.DrawDude();
  board.DrawPoo();
  ClearBackground(BLACK);
}

void Game::Update() {

  board.moveDude();
  board.DrawDude();
  board.DrawPoo();
  ClearBackground(BLACK);
}

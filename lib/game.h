#pragma once
#include <string>
#include "board.c"

class Game {
public:
  Game(int width, int height, int fps, std::string title);
  ~Game() noexcept;
  //Rule of Five thing - https://www.foonathan.net/2019/02/special-member-functions
  Game(const Game& other) = delete;
  Game& operator=(const Game& other) = delete;

  bool GameShouldClose() const;
  void Tick();

private:
  void Draw();
  void Update();
  Board board;

};

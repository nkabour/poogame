#pragma once
#include <raylib.h>
#include <vector>

class Board {

private:
  class Poo {
  public:
    Poo(Board &br);
    void SetColor(Color c);
    void updateLoc(int x, int y);
    Color getColor() const;
    int *getLoc();
    int getSize() const;

  private:
    Board &br;
    Color color;
    int size;
    int loc[2]; // where loc[0] is x and loc[1] is y
    int limits[3];
  };
  class Dude {
  public:
    Dude(Board &br);
    void setScore();
    void updateLoc(int x, int y);
    int getScore() const;
    Color getColor() const;
    int *getLoc();

  private:
    Board &br;
    Color color;
    int score;
    int loc[2];
    int limits[3];
  };

public:
  Board(int padding, int width, int height, int boarderSize);
  void DrawPoo();
  void DrawDude();
  void Draw() const;

private:
  int padding;
  int boarderSize;
  int width;
  int height;
  Poo poo = Board::Poo(*this);
  Dude dude =  Board::Dude(*this);
  void DrawBoarder() const;
  void DrawScore() const;

};

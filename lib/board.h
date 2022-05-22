#pragma once
#include <raylib.h>
#include <vector>

class Board {


private:
  struct Limits {
      int top;
      int left;
      int right;
      int bottom;
  };

  class Poo {
  public:
    Poo(Board &br);
    void SetColor(Color c);
    Color getColor() const;
    int *getLoc();
    Limits lim;
    int getSize() const;

  private:
    Board &br;
    Color color;
    int size;
    int loc[2]; // where loc[0] is x and loc[1] is y
  };

  class Dude {
  public:
    Dude(Board &br);
    void setScore();
    int getScore() const;
    Color getColor() const;
    Limits lim;
    int *getLoc();

  private:
    Board &br;
    Color color;
    int score;
    int loc[2];

  };

public:
  Board(int padding, int width, int height, int boarderSize);

  void DrawPoo();
  void DrawDude();
  void moveDude();
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

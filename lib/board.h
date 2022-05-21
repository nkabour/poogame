#pragma once
#include <raylib.h>
#include <vector>

class Board {

private:
  class Poo {
  public:
    Poo();
    void SetColor(Color c);
    void updateLoc(int x, int y);
    Color getColor() const;
    int *getLoc();
    int getSize() const;

  private:
    Color color;
    int size;
    int loc[2]; // where loc[0] is x and loc[1] is y
  };
  class Dude {
  public:
    Dude();
    void setScore();
    void updateLoc(int x, int y);
    int getScore() const;
    Color getColor() const;
    int *getLoc();

  private:
    Color color;
    int score;
    int loc[2];
  };

public:
  Board(int padding, int width, int height, int boarderSize);
  void DrawPoo();
  void DrawDude();
  void Draw() const;

private:
  static int padding;
  static int boarderSize;
  static int width;
  static int height;

  Poo poo;
  Dude dude;
  void DrawBoarder() const;
  void DrawScore() const;
};

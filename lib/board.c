#include "board.h"
#include <iostream>
#include <math.h>
#include <string>
#include <assert.h>

using namespace std;

int Board::width;
int Board::padding;
int Board::height;
int Board::boarderSize;

Board::Board(int padding, int width, int height, int boarderSize) {
  Board::width = width;
  Board::padding = padding;
  Board::height = height;
  Board::boarderSize = boarderSize;

  std::cout << "Width: " <<width << " Height: " << height << endl;
  std::cout << "Padding: " << padding << " BoarerSize: " << boarderSize << endl;
}

Board::Dude::Dude() : score(0), color(GREEN) {
  // int location
//limit dude's location 
  int limits[3] = {
    Board::padding + Board::boarderSize, //top
    Board::height - Board::boarderSize, //bottom
    Board::width - Board::boarderSize, //right
  };

  loc[0] = (Board::width + Board::padding) / 2;
  loc[1] = (Board::height + Board::padding) / 2;
  std::cout << "Dude's location is x: " << loc[0] << " y: " << loc[1] << endl;
  std::cout << "Width: " << Board::width << " Height: " << Board::height << endl;
  std::cout << "Padding: " << Board::padding << " BoarerSize: " << Board::boarderSize << endl;
  /*assert(loc[0] > Board::padding && loc[0] < Board::width - Board::padding);*/
  /*assert(loc[1] > Board::padding && loc[1] < Board::height - Board::padding);*/
}

int Board::Dude::getScore() const { return score; }

int *Board::Dude::getLoc() { return loc; }

Color Board::Dude::getColor() const { return color; }

Board::Poo::Poo() : size(rand() % 10 + 1), color(BROWN) {

  loc[0] = rand() % 10 + 1;
  loc[1] = rand() % 10 + 1;


  std::cout << "Poo's location is x: " << loc[0] << " y: " << loc[1] << endl;
  std::cout << "Poo's size is: " << size <<endl ;

}

int *Board::Poo::getLoc() { return loc; }

Color Board::Poo::getColor() const { return color; }
int Board::Poo::getSize() const { return size; }

void Board::DrawPoo() {

  int *pooLoc = poo.getLoc();
  DrawRectangle(pooLoc[0], pooLoc[1], poo.getSize(), poo.getSize(), poo.getColor());
}
void Board::DrawDude() {

  int *dudeLoc = dude.getLoc();
  DrawRectangle(dudeLoc[0], dudeLoc[1], 10, 10, dude.getColor());
}

void Board::DrawBoarder() const {

  // drawing a boarder
  // x, y, width, height, size
  // TopBoarder
  DrawRectangle(padding, padding, width, boarderSize, Color(BLUE));
  // LeftBoarder
  DrawRectangle(padding, padding, boarderSize, height, Color(BLUE));
  // RightBoarder
  DrawRectangle(width + padding, padding, boarderSize, height + boarderSize,
                Color(BLUE));
  // Bottom Boarder
  DrawRectangle(padding, height + padding, width, boarderSize, Color(BLUE));
}

void Board::DrawScore() const {

  DrawText(("Score: " + std::to_string(dude.getScore())).c_str(), padding,
           height + padding * 2, 20, Color(ORANGE));
}

void Board::Draw() const {

  DrawScore();
  DrawBoarder();
}

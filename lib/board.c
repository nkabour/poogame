#include "board.h"
#include <ctime>
#include <assert.h>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

Board::Board(int padding, int width, int height, int boarderSize)
    : padding(padding), width(width), height(height), boarderSize(boarderSize) {

  std::cout << "Width: " << width << " Height: " << height << endl;
  std::cout << "Padding: " << padding << " BoarerSize: " << boarderSize << endl;
}

Board::Dude::Dude(Board &br) : score(0), color(GREEN), br(br) {
  // limit dude's location - lame but works for now :^)
  limits[0] = br.padding + br.boarderSize; // top
  limits[1] = br.height - br.boarderSize;  // bottom
  limits[2] = br.width - br.boarderSize;   // right


  loc[0] = (br.width + br.padding) / 2;
  loc[1] = (br.height + br.padding) / 2;
  std::cout << "Dude's location is x: " << loc[0] << " y: " << loc[1] << endl;
  std::cout << "Width: " << br.width << " Height: " << br.height << endl;
  std::cout << "Padding: " << br.padding << " BoarerSize: " << br.boarderSize << endl;
  std::cout << "Limits " << limits[0] << " " << limits[1] << " " << limits[2]<< endl;

  assert(loc[0] > limits[0] && loc[0] < limits[1]); // out of x boundreys
  assert(loc[1] > limits[0] && loc[1] < limits[2]); // out of y boundreys
}

int Board::Dude::getScore() const { return score; }

int *Board::Dude::getLoc() { return loc; }

Color Board::Dude::getColor() const { return color; }


Board::Poo::Poo(Board &br)
    : color(BROWN), br(br) {

  // limit dude's location - lame but works for now :^)
  srand(time(0));

  size = rand() % 50 + 10;
  limits[0] = br.padding + br.boarderSize; // top
  limits[1] = br.height - br.boarderSize;  // bottom
  limits[2] = br.width - br.boarderSize;   // right

  loc[0] = rand() % 100 + br.padding;
  loc[1] = rand() % 100 + br.padding;

  std::cout << "Poo's location is x: " << loc[0] << " y: " << loc[1] << endl;
  std::cout << "Poo's size is: " << size << endl;
}

int *Board::Poo::getLoc() { return loc; }

Color Board::Poo::getColor() const { return color; }
int Board::Poo::getSize() const { return size; }

void Board::DrawPoo() {

  int *pooLoc = poo.getLoc();
  DrawRectangle(pooLoc[0], pooLoc[1], poo.getSize(), poo.getSize(),
                poo.getColor());
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

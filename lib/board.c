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
  lim.top = lim.left = br.padding + br.boarderSize; // top
  lim.bottom = br.height - br.boarderSize;  // bottom
  lim.right = br.width - br.boarderSize;   // right


  loc[0] = (br.width + br.padding) / 2;
  loc[1] = (br.height + br.padding) / 2;
  std::cout << "Dude's location is x: " << loc[0] << " y: " << loc[1] << endl;
  std::cout << "Width: " << br.width << " Height: " << br.height << endl;
  std::cout << "Padding: " << br.padding << " BoarerSize: " << br.boarderSize << endl;

  assert(loc[0] > lim.left && loc[0] < lim.right); // out of x boundreys
  assert(loc[1] > lim.top && loc[1] < lim.bottom); // out of y boundreys
}

int Board::Dude::getScore() const { return score; }

int *Board::Dude::getLoc() { return loc; }
Limits *Board::Dude::getLimits() { return lim; }

Color Board::Dude::getColor() const { return color; }


Board::Poo::Poo(Board &br)
    : color(BROWN), br(br) {

  // limit dude's location - lame but works for now :^)
  srand(time(0));

  size = rand() % 50 + 10;
  lim.top = lim.left = br.padding + br.boarderSize; // top
  lim.bottom = br.height - br.boarderSize;  // bottom
  lim.right = br.width - br.boarderSize;   // right

  loc[0] = rand() % 100 + br.padding;
  loc[1] = rand() % 100 + br.padding;

  std::cout << "Poo's location is x: " << loc[0] << " y: " << loc[1] << endl;
  std::cout << "Poo's size is: " << size << endl;
}

int *Board::Poo::getLoc() { return loc; }
Limits *Board::Poo::getLimits() { return lim; }

Color Board::Poo::getColor() const { return color; }
int Board::Poo::getSize() const { return size; }

void Board::moveDude() {

  int *dudeLoc = dude.getLoc();
  int *limits = dude.getLimits();

  if(IsKeyDown(KEY_RIGHT)) dudeLoc[0] +=1;
  if(IsKeyDown(KEY_LEFT)) dudeLoc[0] -=1;
  if(IsKeyDown(KEY_DOWN)) dudeLoc[1] +=1;
  if(IsKeyDown(KEY_UP)) dudeLoc[1] -=1;

}

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

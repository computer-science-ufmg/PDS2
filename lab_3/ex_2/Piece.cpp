#include "Piece.hpp"
#include <string>
#include <cstring>

std::pair<char, int> Piece::stringToPair(std::string pair_string){
  std::pair<char, int> position;
  position.first = pair_string.c_str()[0];
  position.second = (int)(pair_string.c_str()[1] - '0');
  return position;
}

Rook::Rook(std::string symbol, std::string current_position, std::string candidate_position){
  this->symbol = symbol;
  this->position = Piece::stringToPair(current_position);
}

void Rook::setMovements(){

}

void Rook::printPossibleMoves(){

}

void Rook::checkMovement(){

}

Bishop::Bishop(std::string symbol, std::string current_position, std::string candidate_position){
  if(symbol.at(0) != 'R') exit(0);
  this->symbol = symbol;
  this->position = Piece::stringToPair(current_position);
}

void Bishop::setMovements(){

}

void Bishop::printPossibleMoves(){

}

void Bishop::checkMovement(){

}

Knight::Knight(std::string symbol, std::string current_position, std::string candidate_position){
  if(symbol.at(0) != 'R') exit(0);
  this->symbol = symbol;
  this->position = Piece::stringToPair(current_position);
}

void Knight::setMovements(){

}

void Knight::printPossibleMoves(){

}

void Knight::checkMovement(){

}

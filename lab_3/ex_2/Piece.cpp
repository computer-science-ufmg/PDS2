#include <cstdlib>
#include "Piece.hpp"

Piece::Piece(std::string symbol, std::string current_position, std::string candidate_position){
  this->symbol = symbol;
  this->position.first = current_position.at(0);
  this->position.second = std::atoi(current_position.at(1));
}

void Rook::setMovements(){

}

void Bishop::setMovements(){

}

void Knight::setMovements(){

}

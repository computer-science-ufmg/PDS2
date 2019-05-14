#include "Piece.hpp"
#include <utility>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

Piece::Piece(std::string symbol, std::string current_position, std::string candidate_position){
  this->symbol = symbol;
  this->current_position = Piece::stringToPair(current_position);
  this->candidate_position = Piece::stringToPair(candidate_position);
}

void Piece::setNextPosition(std::string candidate_position){
  this->candidate_position = Piece::stringToPair(candidate_position);
}

void Piece::checkMovement(){
  if(Piece::positionPresent(this->possible_movements, this->candidate_position)){
    std::cout << "Moving from (" << this->current_position.first << this->current_position.second << ") to (" << this->candidate_position.first << this->candidate_position.second << ')' << std::endl;
    this->current_position = this->candidate_position;
  }
  else{
    std::cout << "I cannot move from (" << this->current_position.first << this->current_position.second << ") to (" << this->candidate_position.first << this->candidate_position.second << ')' << std::endl;
  }
}

bool Piece::positionPresent(std::vector<std::pair<char, int>> positions, std::pair<char, int> position){
  for (std::vector<std::pair<char, int>>::iterator it = positions.begin(); it != positions.end(); ++it) {
    std::pair<char, int> candidate = *it;
    if(candidate.first == position.first && candidate.second == position.second){
      return true;
    }
  }
  return false;
}

int Piece::numericValue(char letter){
  return (int)letter - (int)'a' + 1;
}

char Piece::letterValue(int number){
  return (char)(number + (int)'a' - 1);
}

std::pair<char, int> Piece::stringToPair(std::string pair_string){
  std::pair<char, int> position;
  position.first = pair_string.c_str()[0];
  position.second = (int)(pair_string.c_str()[1] - '0');
  return position;
}

Rook::Rook(std::string symbol, std::string current_position, std::string candidate_position): Piece(symbol, current_position, candidate_position){}

void Rook::setMovements(){
  this->possible_movements.clear();
  char letter;
  int number;
  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      std::pair<char, int> position;
      letter = Piece::letterValue(i);
      number = j;
      if (letter == this->current_position.first && number == this->current_position.second) {
        continue;
      }
      if(letter != this->current_position.first && number != this->current_position.second){
        continue;
      }
      position.first = letter;
      position.second = number;
      this->possible_movements.push_back(position);
    }
  }
}

void Rook::printPossibleMoves(){
  std::vector<std::pair<char, int>> movements;
  movements = this->possible_movements;
  std::cout << "(Rook) Current Position: (" << this->current_position.first << this->current_position.second << ')' << std::endl;
  std::cout << "I have " << movements.size() << " legal movements." << std::endl;
  for (std::vector<std::pair<char, int>>::iterator it = movements.begin(); it != movements.end(); ++it) {
    std::pair<char, int> candidate_position = *it;
    std::cout << '(' << this->current_position.first << this->current_position.second << ")->(" << candidate_position.first << candidate_position.second << ')' << std::endl;
  }
}

Bishop::Bishop(std::string symbol, std::string current_position, std::string candidate_position): Piece(symbol, current_position, candidate_position){}

void Bishop::setMovements(){
  this->possible_movements.clear();
  char letter;
  int number, number_variation, letter_variation;
  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      std::pair<char, int> position;
      letter = Piece::letterValue(i);
      number = j;
      if (letter == this->current_position.first && number == this->current_position.second) {
        continue;
      }
      letter_variation = Piece::numericValue(this->current_position.first) - Piece::numericValue(letter);
      number_variation = this->current_position.second - number;
      if(number_variation == letter_variation || number_variation == -letter_variation){
        position.first = letter;
        position.second = number;
        this->possible_movements.push_back(position);
      }
    }
  }
}

void Bishop::printPossibleMoves(){
  std::vector<std::pair<char, int>> movements;
  movements = this->possible_movements;
  std::cout << "(Bishop) Current Position: (" << this->current_position.first << this->current_position.second << ')' << std::endl;
  std::cout << "I have " << movements.size() << " legal movements." << std::endl;
  for (std::vector<std::pair<char, int>>::iterator it = movements.begin(); it != movements.end(); ++it) {
    std::pair<char, int> candidate_position = *it;
    std::cout << '(' << this->current_position.first << this->current_position.second << ")->(" << candidate_position.first << candidate_position.second << ')' << std::endl;
  }
}

Knight::Knight(std::string symbol, std::string current_position, std::string candidate_position): Piece(symbol, current_position, candidate_position){}

void Knight::setMovements(){
  this->possible_movements.clear();
  char letter;
  int number;
  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      std::pair<char, int> position;
      letter = Piece::letterValue(i);
      number = j;
      if (letter == this->current_position.first && number == this->current_position.second) {
        continue;
      }
      if(letter == this->current_position.first+2 || letter == this->current_position.first-2){
        if (number == this->current_position.second+1 || number == this->current_position.second-1) {
          position.first = letter;
          position.second = number;
          this->possible_movements.push_back(position);
        }
      }
      else if(number == this->current_position.second+2 || number == this->current_position.second-2){
        if (letter == this->current_position.first+1 || letter == this->current_position.first-1) {
          position.first = letter;
          position.second = number;
          this->possible_movements.push_back(position);
        }
      }
    }
  }
}

void Knight::printPossibleMoves(){
  std::vector<std::pair<char, int>> movements;
  movements = this->possible_movements;
  std::cout << "(Knight) Current Position: (" << this->current_position.first << this->current_position.second << ')' << std::endl;
  std::cout << "I have " << movements.size() << " legal movements." << std::endl;
  for (std::vector<std::pair<char, int>>::iterator it = movements.begin(); it != movements.end(); ++it) {
    std::pair<char, int> candidate_position = *it;
    std::cout << '(' << this->current_position.first << this->current_position.second << ")->(" << candidate_position.first << candidate_position.second << ')' << std::endl;
  }
}

#ifndef PIECE_H
#define PIECE_H

#include <utility>
#include <string>
#include <vector>
#include <iostream>

class Piece{
	public:
		std::string symbol;
		std::pair<char, int> current_position;
		std::pair<char, int> candidate_position;
		std::vector<std::pair<char, int>> possible_movements;

		Piece(std::string symbol, std::string current_position, std::string candidate_position);

		virtual void setMovements() = 0;
		virtual void printPossibleMoves() = 0;
		void setNextPosition(std::string candidate_position);
		void checkMovement();
		static bool positionPresent(std::vector<std::pair<char, int>> positions, std::pair<char, int> position);
		static std::pair<char, int> stringToPair(std::string pair_string);
		static int numericValue(char letter);
		static char letterValue(int number);
};

class Rook : public Piece{
	public:

		Rook(std::string symbol, std::string current_position, std::string candidate_position);

		void setMovements() override;
		void printPossibleMoves() override;
};

class Bishop : public Piece{
	public:

		Bishop(std::string symbol, std::string current_position, std::string candidate_position);

		void setMovements() override;
		void printPossibleMoves() override;
};

class Knight : public Piece{
	public:

		Knight(std::string symbol, std::string current_position, std::string candidate_position);

		void setMovements() override;
		void printPossibleMoves() override;
};

#endif

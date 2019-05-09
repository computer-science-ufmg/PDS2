#ifndef PIECE_H
#define PIECE_H

#include <utility>
#include <string>

class Piece{
	public:
		std::string symbol;
		std::pair<char, int> position;

		static std::pair<char, int> stringToPair(std::string pair_string);
		virtual void setMovements() = 0;
		virtual void printPossibleMoves() = 0;
		virtual void checkMovement() = 0;
};

class Rook : public Piece{
	public:
		Rook(std::string symbol, std::string current_position, std::string candidate_position);

		void setMovements() override;
		void printPossibleMoves() override;
		void checkMovement() override;
};

class Bishop : public Piece{
	public:
		Bishop(std::string symbol, std::string current_position, std::string candidate_position);

		void setMovements() override;
		void printPossibleMoves() override;
		void checkMovement() override;
};

class Knight : public Piece{
	public:
		Knight(std::string symbol, std::string current_position, std::string candidate_position);

		void setMovements() override;
		void printPossibleMoves() override;
		void checkMovement() override;
};

#endif

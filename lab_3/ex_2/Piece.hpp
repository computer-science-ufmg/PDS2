#ifndef PIECE_H
#define PIECE_H

#include <utility>
#include <string>

class Piece{
	public:
		std::string symbol;
		std::pair<char, int> position;

		Piece(std::string symbol, std::string current_position, std::string candidate_position);
		
		virtual void setMovements();
};

class Rook : public Piece{
	public:
	void setMovements() override;
};

class Bishop : public Piece{
	public:
	void setMovements() override;
};

class Knight : public Piece{
	public:
	void setMovements() override;
};

#endif

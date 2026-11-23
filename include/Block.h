#ifndef BLOCK_H
#define BLOCK_H

#include "BlockType.h"
#include "RotationState.h"
#include "Cell.h"

#include <array>

class Block
{
public:
	Block(int row, int column, BlockType type);

	std::array<Cell, 4> getCells() const;
	static BlockType getRandomBlockType();

	void rotate();
	void moveLeft();
	void moveRight();
	void moveDown();

	RotationState rotationState;
	BlockType type;
	Cell anchorBlock;

};

#endif // BLOCK_H

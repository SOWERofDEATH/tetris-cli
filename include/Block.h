#ifndef BLOCK_H
#define BLOCK_H

#include "BlockType.h"
#include "RotationState.h"
#include <array>
#include "Cell.h"

class Block
{
public:
	Block(int row, int column, BlockType type);

private:
		int row;
		int column;
		RotationState rotationState;
		const BlockType type;

		std::array<Cell, 4> getCells() const;

};

#endif // BLOCK_H

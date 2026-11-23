#include "Block.h"
#include "BlockType.h"
#include "RotationState.h"
#include <array>

Block::Block(int row, int column, BlockType type) : anchorBlock({row, column }), type(type), rotationState(RotationState::DEG0) {}

void Block::rotate()
{
	switch (rotationState)
	{
		case RotationState::DEG0:
			rotationState = RotationState::DEG90;
			break;

		case RotationState::DEG90:
			rotationState = RotationState::DEG180;
			break;

		case RotationState::DEG180:
			rotationState = RotationState::DEG270;
			break;

		case RotationState::DEG270:
			rotationState = RotationState::DEG0;
			break;
	}
}

void Block::moveLeft()
{
	anchorBlock.column -= 1;
}

void Block::moveRight()
{
	anchorBlock.column += 1;
}

void Block::moveDown()
{
	anchorBlock.row += 1;
}

std::array<Cell, 4> Block::getCells() const
{
	std::array<Cell, 4> cells{};

	switch (type)
	{
		case BlockType::T:
			switch (rotationState)
			{
				case RotationState::DEG0:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row,     anchorBlock.column - 1};
					cells[2] = {anchorBlock.row,     anchorBlock.column + 1};
					cells[3] = {anchorBlock.row + 1, anchorBlock.column};
					break;

				case RotationState::DEG90:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row - 1, anchorBlock.column};
					cells[2] = {anchorBlock.row + 1, anchorBlock.column};
					cells[3] = {anchorBlock.row,     anchorBlock.column + 1};
					break;

				case RotationState::DEG180:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row,     anchorBlock.column - 1};
					cells[2] = {anchorBlock.row,     anchorBlock.column + 1};
					cells[3] = {anchorBlock.row - 1, anchorBlock.column};
					break;
				case RotationState::DEG270:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row - 1, anchorBlock.column};
					cells[2] = {anchorBlock.row + 1, anchorBlock.column};
					cells[3] = {anchorBlock.row,     anchorBlock.column - 1};
					break;

			}
			break;

		case BlockType::I:
			switch (rotationState)
			{
				case RotationState::DEG0:
				case RotationState::DEG180:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row, anchorBlock.column - 1};
					cells[2] = {anchorBlock.row, anchorBlock.column + 1};
					cells[3] = {anchorBlock.row, anchorBlock.column + 2};
					break;

				case RotationState::DEG90:
				case RotationState::DEG270:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row - 1, anchorBlock.column};
					cells[2] = {anchorBlock.row + 1, anchorBlock.column};
					cells[3] = {anchorBlock.row + 2, anchorBlock.column};
					break;

			}
			break;

		case BlockType::O:
			cells[0] = anchorBlock;
			cells[1] = {anchorBlock.row,     anchorBlock.column + 1};
			cells[2] = {anchorBlock.row + 1, anchorBlock.column};
			cells[3] = {anchorBlock.row + 1, anchorBlock.column + 1};
			break;

		case BlockType::S:
			switch (rotationState)
			{
				case RotationState::DEG0:
				case RotationState::DEG180:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row,     anchorBlock.column + 1};
					cells[2] = {anchorBlock.row + 1, anchorBlock.column - 1};
					cells[3] = {anchorBlock.row + 1, anchorBlock.column};
					break;

				case RotationState::DEG90:
				case RotationState::DEG270:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row - 1, anchorBlock.column};
					cells[2] = {anchorBlock.row,     anchorBlock.column + 1};
					cells[3] = {anchorBlock.row + 1, anchorBlock.column + 1};
					break;

			}
			break;

		case BlockType::Z:
			switch (rotationState)
			{
				case RotationState::DEG0:
				case RotationState::DEG180:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row,     anchorBlock.column - 1};
					cells[2] = {anchorBlock.row + 1, anchorBlock.column};
					cells[3] = {anchorBlock.row + 1, anchorBlock.column + 1};
					break;

				case RotationState::DEG90:
				case RotationState::DEG270:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row - 1, anchorBlock.column + 1};
					cells[2] = {anchorBlock.row,     anchorBlock.column + 1};
					cells[3] = {anchorBlock.row + 1, anchorBlock.column};
					break;

			}
			break;

		case BlockType::J:
			switch (rotationState)
			{
				case RotationState::DEG0:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row,     anchorBlock.column - 1};
					cells[2] = {anchorBlock.row,     anchorBlock.column + 1};
					cells[3] = {anchorBlock.row - 1, anchorBlock.column - 1};
					break;

				case RotationState::DEG90:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row - 1, anchorBlock.column};
					cells[2] = {anchorBlock.row + 1, anchorBlock.column};
					cells[3] = {anchorBlock.row - 1, anchorBlock.column + 1};
					break;

				case RotationState::DEG180:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row,     anchorBlock.column - 1};
					cells[2] = {anchorBlock.row,     anchorBlock.column + 1};
					cells[3] = {anchorBlock.row + 1, anchorBlock.column + 1};
					break;
				case RotationState::DEG270:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row - 1, anchorBlock.column};
					cells[2] = {anchorBlock.row + 1, anchorBlock.column};
					cells[3] = {anchorBlock.row + 1, anchorBlock.column - 1};
					break;

			}
			break;

		case BlockType::L:
			switch (rotationState)
			{
				case RotationState::DEG0:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row,     anchorBlock.column - 1};
					cells[2] = {anchorBlock.row,     anchorBlock.column + 1};
					cells[3] = {anchorBlock.row - 1, anchorBlock.column + 1};
					break;

				case RotationState::DEG90:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row - 1, anchorBlock.column};
					cells[2] = {anchorBlock.row + 1, anchorBlock.column};
					cells[3] = {anchorBlock.row + 1, anchorBlock.column + 1};
					break;

				case RotationState::DEG180:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row,     anchorBlock.column - 1};
					cells[2] = {anchorBlock.row,     anchorBlock.column + 1};
					cells[3] = {anchorBlock.row + 1, anchorBlock.column - 1};
					break;

				case RotationState::DEG270:
					cells[0] = anchorBlock;
					cells[1] = {anchorBlock.row - 1, anchorBlock.column};
					cells[2] = {anchorBlock.row + 1, anchorBlock.column};
					cells[3] = {anchorBlock.row - 1, anchorBlock.column - 1};
					break;

			}
			break;
	}

	return cells;
}

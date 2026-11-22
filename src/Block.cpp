#include "Block.h"
#include "RotationState.h"

Block::Block(int row, int column, BlockType type) : row(row), column(column), type(type), rotationState(RotationState::FIRST) {}

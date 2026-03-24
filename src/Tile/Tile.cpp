#include "Tile.h"
#include "DxLib.h"

Tile::Tile(float x, float y, int image) : TileBase(x, y, image)
{
}

Tile::~Tile()
{
}

void Tile::Initialize()
{
}

void Tile::Update()
{
}

void Tile::Draw() const
{
	DrawGraphF(location.x, location.y, tileImage, TRUE);
}

void Tile::Finalize()
{
}

bool Tile::IsWalkable()
{
	return true;
}

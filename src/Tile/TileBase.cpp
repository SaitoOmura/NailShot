#include "TileBase.h"
#include "DxLib.h"

TileBase::TileBase(float x, float y, int image)
{
	location.x = x;
	location.y = y;

	tileImage = image;
}

void TileBase::Initialize()
{
	box_size = 32.0f;
}

void TileBase::Update()
{
}

void TileBase::Draw() const
{
	Vector2D a = location;
	Vector2D b = location + box_size;
}

void TileBase::Finalize()
{
}

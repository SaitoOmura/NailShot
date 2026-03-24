#pragma once
#include "TileBase.h"
class Tile : public TileBase
{
public:
	Tile(float x, float y, int image);
	~Tile();

	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Draw()const override;
	virtual void Finalize()override;

	bool IsWalkable()override;
};


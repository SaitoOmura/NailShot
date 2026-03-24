#pragma once

#include "../ObjectBase.h"
class TileBase : public ObjectBase
{
protected:
	int tileImage;
public:
	TileBase(float x, float y, int image);

	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Draw()const override;
	virtual void Finalize()override;
};


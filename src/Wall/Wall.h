#pragma once
#include "../ObjectBase.h"

class Wall : public ObjectBase
{
public:
	Wall();
	~Wall();

public:
	virtual void Initialize()override;
	virtual void Draw()const override;
	virtual void Finalize()override;

};


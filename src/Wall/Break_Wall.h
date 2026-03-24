#pragma once
#include "../ObjectBase.h"

class Break_Wall : public ObjectBase
{
private:
	bool break_flag;
public:
	Break_Wall();
	~Break_Wall();

public:
	virtual void Initialize()override;
	virtual void Draw()const override;
	virtual void Finalize()override;

	virtual void OnHitCollision(ObjectBase* target) override;
};


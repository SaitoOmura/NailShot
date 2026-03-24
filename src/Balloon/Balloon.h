#pragma once
#include "../ObjectBase.h"

class Balloon : public ObjectBase
{
private:
	std::vector<int> break_animation;		//����镗�D�̃A�j���[�V����
	int direction = 0;
	float animation_count;					//���̉摜�ɕύX����܂ł̎��Ԍv�Z�p
	int animation_num;						//�`�悷��A�j���[�V�����̔ԍ�
	bool break_flag;						//����邩�ǂ���

public:
	Balloon();
	~Balloon();

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Draw()const override;
	virtual void Finalize()override;
	virtual void OnHitCollision(ObjectBase* target) override;
	void AnimationControl();

};


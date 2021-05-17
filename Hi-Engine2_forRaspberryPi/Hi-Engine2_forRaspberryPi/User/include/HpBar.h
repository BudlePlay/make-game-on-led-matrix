#pragma once
#include "../../Engine/include/Object.h"

class HpBar : public Object
{
public:
	HpBar(const FPosition& p, const std::string& name, const Area& Area,
	      const std::string& Type);

	~HpBar() override;
	void Work() override;
	void OnCollision(Object* other) override;
};

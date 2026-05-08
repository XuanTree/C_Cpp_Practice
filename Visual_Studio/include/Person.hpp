#pragma once
#include <string>

class Person {
protected:
	std::string codeName;
	std::string gender;
	std::string animalType;
	float damage;
	float health;
public:
	Person() = default;
	inline Person(std::string _codeName, std::string _gender, std::string _animalType, float health = 0,
		float damage = 0) : codeName(_codeName), gender(_gender), animalType(_animalType),
		damage(damage), health(health) {};
	virtual ~Person() {}
	
	virtual std::string GetCodeName() = 0;
	virtual std::string GetGender() = 0;
	virtual std::string GetAnimalType() = 0;
	virtual float GetDamage() = 0;
	virtual float GetHealth() = 0;
	virtual void SetHealth(float _health) = 0;
	virtual void Attack(Person& target) = 0;
	virtual void Skill() = 0;
};

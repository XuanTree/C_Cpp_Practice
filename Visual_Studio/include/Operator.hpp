#pragma once
#include <iostream>
#include <string>
#include "Person.hpp"

class Operator : public Person {
public:
	Operator() = default;
	Operator(std::string _name, std::string _gender, std::string _animalType, float health = 0, float damage = 0)
		: Person(_name, _gender, _animalType, health, damage) { }
	~Operator() override {
		std::cout << "Operator has been deleted ! " << std::endl;
	}

	std::string GetCodeName() override { return this->codeName; }
	std::string GetGender() override { return this->gender; }
	std::string GetAnimalType() override { return this->animalType; }
	void SetHealth(float newHealth) override;
	float GetDamage() override { return this->damage; }
	float GetHealth() override { return this->health; }
	void Attack(Person& target) override;
	void Skill() override;
};

class Enemy : public Person {
public:
	Enemy() = default;
	Enemy(std::string _name, std::string _gender, std::string _animalType, float health = 0.f, float damage = 0.f)
		: Person(_name, _gender, _animalType, health, damage) { }
	~Enemy() override {
		std::cout << "Enemy has been deleted ! " << std::endl;
	}

	std::string GetCodeName() override { return this->codeName; }
	std::string GetGender() override { return this->gender; }
	std::string GetAnimalType() override { return this->animalType; }
	void SetHealth(float newHealth) override;
	float GetDamage() override { return this->damage; }
	float GetHealth() override { return this->health; }
	void Attack(Person& target) override;
	void Skill() override;

	void PrintSayHi() const;
};

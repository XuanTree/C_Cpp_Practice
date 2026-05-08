#include <iostream>
#include "Operator.hpp"

void Operator::SetHealth(float newHealth) {
	this->health = newHealth;
}

void Enemy::SetHealth(float newHealth) {
	this->health = newHealth;
}

void Operator::Attack(Person& target) {
	if (target.GetHealth() <= 0) {
		std::cout << "enemy has been defeated ! " << std::endl;
	}
	else {
		std::cout << "Operator attacks! Damage dealt: " << this->damage << std::endl;
		target.SetHealth(target.GetHealth() - this->damage);
	}
	// 修改敌人的生命值
	
}

void Operator::Skill() {
	std::cout << "Operator uses skill!" << std::endl;
}

void Enemy::Attack(Person& target) {
	if (target.GetHealth() <= 0) {
		std::cout << "Operator has been defeated !" << std::endl;
	}
	else {
		std::cout << "Enemy attacks! Damage dealt: " << this->damage << std::endl;
		target.SetHealth(target.GetHealth() - this->damage);
	}
}

void Enemy::Skill() {
	std::cout << "Enemy uses skill!" << std::endl;
}
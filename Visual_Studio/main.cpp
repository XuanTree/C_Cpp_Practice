#include <iostream>
#include "Test.hpp"
#include "Operator.hpp"

int main() {
    std::cout << "Hello Cmake From Visual Studio !" << std::endl;

    //const Test test(64);

    //test.print();

    //const PrintThings<std::string> printThings("Hello Message From Templates!");

    //printThings.Print();

    //Student Jack("Jack", 18);

    //Jack.PrintMessages();
    //Jack.SayHi();
    //Jack.ChangeTheJob("Worker");
    //Jack.PrintMessages();

    //std::string hello = "Hello";
    //std::string world = "World";

    //SwapTwoThings<std::string> swap(hello, world);

    //swap.Swap();

    Operator Amiya("Amiya", "Female", "cactus", 2400, 2625.f);

    Enemy enemy("FrostStar", "Female", "cactus", 2500.f, 265.f);

    bool isAmiyaDead = false;

    while (Amiya.GetHealth() > 0 && enemy.GetHealth() > 0) {
        if (Amiya.GetHealth() <= 0) {
            isAmiyaDead = true;
            break;
        }
        else {
            Amiya.Attack(enemy);

            enemy.Attack(Amiya);
        }
    }

    if (isAmiyaDead) {
        std::cout << "Amiya Died!" << std::endl;
    }
    else {
        std::cout << "Amiya Won!" << std::endl;
    }


    return 0;
}
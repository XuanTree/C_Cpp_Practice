#include <random>
float GenRandomPos(){
   std::mt19937 gen(std::random_device{}());
   std::uniform_real_distribution<float> dis(0.f,600.f);

   return dis(gen);
}
float GenRandomTime(){
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<float> dis(0.8f,2.1f);
    
    return dis(gen);
}
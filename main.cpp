#include <iostream>
#include "Gait_generator.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Gait_generator gg;
    vector<vector<float>> theta;
    for (int i = 0; i < 800; i++)
    {
        gg.t = i/100;
        theta = gg.runner(gg.t);
    }

    return 0;
}




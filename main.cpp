#include "Simulation.h"

int main()
{
    Simulation sim;

    while(sim.running())
    {
        srand(static_cast<unsigned>(time(0)));
        //std::this_thread::sleep_for(std::chrono::nanoseconds(25000000));
        sim.update();

        sim.render();
    }

    return 0;
}
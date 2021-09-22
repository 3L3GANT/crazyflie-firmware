#include "mbed.h"
#include "crazyflie.h"
#include "mixer.h"  // dar um jeito de colocar o mixer.h em crazyflie.h sem redundancia


//Declara mixer
Mixer mixer;


// Main program
int main()
{
    wait(3);

    mixer.arm();
    //acionamento para decolagem vertical
    mixer.actuate(0.7*m*g, 0, 0, 0); //70% da massa do drone de acionamento


    wait(5);

    //parando motores
    mixer.actuate(0, 0, 0, 0);
    

    wait(3);

//-------------------------------------------------

    //testes de atuador:

    //mixer.arm();
    //mixer.actuate(0.2, 0, 0, 0); //teste 1
    //mixer.actuate(0, 0.005, 0, 0); //teste 2
    //mixer.actuate(0, 0, 0.005, 0); //teste 3
    //mixer.actuate(0, 0, 0, 0.001); //teste 4
    mixer.actuate(0.2, 0, 0.001, 0); //teste 5

    wait(5);

    //desligando motores
    mixer.disarm();


    while(true)
    {
        
    }
}

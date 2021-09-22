#include "mbed.h"
#include "crazyflie.h"
#include "mixer.h"  // dar um jeito de colocar o mixer.h em crazyflie.h sem redundancia



int t; // variável contador tempo

// Define all LEDs as digital output objects
//Leds iniciam desligados
DigitalOut led_rr(LED_RED_R,!false); //True = desligado, False = ligado
DigitalOut led_rl(LED_RED_L,!false); //True = desligado, False = ligado
DigitalOut led_gr(LED_GREEN_R,!false); //True = desligado, False = ligado
DigitalOut led_gl(LED_GREEN_L,!false); //True = desligado, False = ligado
DigitalOut led_blue(LED_BLUE_L,false); //True = ligado, False = desligado


//Declara mixer
Mixer mixer;


// Main program
int main()
{
    //pisca leds para indicar inicialização
    for (t=0; t<=10; t++) {
        led_rr = !led_rr;
        led_rl = !led_rl; 
        wait(0.5);
    }
    
    led_rr = true; // desliga led 
    led_rl = true;
    wait(0.5);

    //acionamento para decolagem vertical
    mixer.actuate(0.7*m*g, 0, 0, 0); //70% da massa do drone de acionamento


    wait(5);

    //desligando motores
    mixer.actuate(0, 0, 0, 0); 

    wait(3);

//-------------------------------------------------

    //testes de atuador:

    //mixer.actuate(0.2, 0, 0, 0); //teste 1
    //mixer.actuate(0, 0.005, 0, 0); //teste 2
    //mixer.actuate(0, 0, 0.005, 0); //teste 3
    //mixer.actuate(0, 0, 0, 0.001); //teste 4
    mixer.actuate(0.2, 0, 0.001, 0); //teste 5

    wait(5);

    //desligando motores
    mixer.actuate(0, 0, 0, 0);


    while(true)
    {
        
    }
}

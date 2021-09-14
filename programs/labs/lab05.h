#include "mbed.h"
#include "crazyflie.h"
#include "functions.h" //programa contendo as funções utilizadas no programa principal

int t; // variável contador tempo

// Define all LEDs as digital output objects
//Leds iniciam desligados
DigitalOut led_rr(LED_RED_R,!false); //True = desligado, False = ligado
DigitalOut led_rl(LED_RED_L,!false); //True = desligado, False = ligado
DigitalOut led_gr(LED_GREEN_R,!false); //True = desligado, False = ligado
DigitalOut led_gl(LED_GREEN_L,!false); //True = desligado, False = ligado
DigitalOut led_blue(LED_BLUE_L,false); //True = ligado, False = desligado


// Define all motors as PWM objects //já definido em functions.h
//PwmOut motor_1(MOTOR1);
//PwmOut motor_2(MOTOR2);
//PwmOut motor_3(MOTOR3);
//PwmOut motor_4(MOTOR4);


//Variáveis de frequencia dos motores
int f = 500; //frequência de 500Hz 
int f1; 
int f2;
int f3;
int f4;


// Main program
int main()
{
    for (t=0; t<=10; t++) {  //pisca leds para indicar inicialização
        led_rr = !led_rr;
        led_rl = !led_rl; 
        wait(0.5);
    }
    
    led_rr = true; // desliga led 
    led_rl = true;
    wait(0.5);

//definindo frequência dos motores (para 500 Hz)
    motor_1.period(1.0/f);
    motor_2.period(1.0/f);
    motor_3.period(1.0/f);
    motor_4.period(1.0/f);

    
    //acionamento para decolagem vertical
    actuate(0.7*m*g, 0, 0, 0); //70% da massa do drone de acionamento


    wait(5);

    //desligando motores
    actuate(0, 0, 0, 0); 

    wait(3);

//-------------------------------------------------

    //testes de atuador:

    //actuate(0.2, 0, 0, 0); //teste 1
    //actuate(0, 0.005, 0, 0); //teste 2
    //actuate(0, 0, 0.005, 0); //teste 3
    actuate(0, 0, 0, 0.001); //teste 4

    wait(5);

    //desligando motores
    actuate(0, 0, 0, 0);


    while(true)
    {
        
    }
}

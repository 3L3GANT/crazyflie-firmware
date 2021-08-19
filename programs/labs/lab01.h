#include "mbed.h"
#include "crazyflie.h"


int t; // variável contador tempo

// Define all LEDs as digital output objects
//Leds iniciam desligados
DigitalOut led_rr(LED_RED_R,!false); //True = desligado, False = ligado
DigitalOut led_rl(LED_RED_L,!false); //True = desligado, False = ligado
DigitalOut led_gr(LED_GREEN_R,!false); //True = desligado, False = ligado
DigitalOut led_gl(LED_GREEN_L,!false); //True = desligado, False = ligado
DigitalOut led_blue(LED_BLUE_L,false); //True = ligado, False = desligado


// Define all motors as PWM objects
PwmOut motor_1(MOTOR1);
PwmOut motor_2(MOTOR2);
PwmOut motor_3(MOTOR3);
PwmOut motor_4(MOTOR4);

//Variáveis de frequencia dos motores
int f1; 
int f2;
int f3;
int f4;


// Main program
int main()
{
    //Testando Leds

    //led_rr = false;  //ligado
    //led_rl = false;  //ligado
    //led_gr = false;   //ligado
    //led_gl = false;   //ligado
    //led_blue = true;      //ligado
    //wait(5);

    // Blink blue LED indicating inicialization (5 seconds)
    
    for (t=0; t<=10; t++) {
    led_blue = !led_blue;
    //led_gr = !led_gr; 
    wait(0.5);
    }
    
    led_blue = false; // desliga led azul
    //led_gr = true;
    wait(0.5);
    

    // Turn on red LEDs indicating motors are armed

    led_rr = false;
    led_rl = false;
    wait(2);


    // Test all motors with different frequencies (to make different noises)

    //frequências dos motores
    f1 = 400;
    f2 = 600;
    f3 = 800;
    f4 = 1000;


    motor_1.period(1.0/f1);
    motor_1 = 0.1;  //ligando motor com 10% da potência total
    wait(3);
    motor_1 = 0;

    motor_2.period(1.0/f2);
    motor_2 = 0.1;  //ligando motor com 10% da potência total
    wait(3);
    motor_2 = 0;

    motor_3.period(1.0/f3);
    motor_3 = 0.1;  //ligando motor com 10% da potência total
    wait(3);
    motor_3 = 0;

    motor_4.period(1.0/f4);
    motor_4 = 0.1;  //ligando motor com 10% da potência total
    wait(3);
    motor_4 = 0;


    // Turn off red LEDs indicating motors are disarmed

    led_rr = true;
    led_rl = true;


    // Blink green LEDs indicating end of program

    for (t=0; t<=20; t++) {
        led_gr = !led_gr;
        led_gl = !led_gl; 
        wait(0.5);
    }
    
    
    led_gr = true; //desligando LEDs depois de indicar fim de programa
    led_gl = true;


    while(true)
    {
        
    }
}

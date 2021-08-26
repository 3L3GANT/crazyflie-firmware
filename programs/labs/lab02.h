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

 // Converts desired angular velocity (rad/s) to PWM signal (%)
 float control_motor ( float omega_r )
 {
     float a2 = 1.174e-07; //valores da função de transferência
     float a1 = 3.274e-12;
     float a0 = 0;

     float PWM = (a2*(omega_r*omega_r)) + (a1*omega_r) + a0;
     
     return PWM; 
 }

//Variáveis de frequencia dos motores
int f = 500; //frequência de 500Hz 
int f1; 
int f2;
int f3;
int f4;


// Main program
int main()
{
    for (t=0; t<=10; t++) {
        led_rr = !led_rr;
        led_rl = !led_rl; 
        wait(0.5);
    }
    
    led_rr = true; // desliga led 
    led_rl = true;
    wait(0.5);

//definindo frequência dos motores
    motor_1.period(1.0/f);
    motor_2.period(1.0/f);
    motor_3.period(1.0/f);
    motor_4.period(1.0/f);

    motor_1 = control_motor(1000.0); //define valor de pwm para 1000 rad/s
    wait(1);
    motor_1 = 0.0;

    wait(1);

    motor_2 = control_motor(1000.0); //define valor de pwm para 1000 rad/s
    wait(1);
    motor_2 = 0.0;

    wait(1);

    motor_3 = control_motor(1000.0); //define valor de pwm para 1000 rad/s
    wait(1);
    motor_3 = 0.0;

    wait(1);

    motor_4 = control_motor(1000.0); //define valor de pwm para 1000 rad/s
    wait(1);
    motor_4 = 0.0;



    while(true)
    {
        
    }
}

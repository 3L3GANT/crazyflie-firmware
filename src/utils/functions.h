#ifndef functions_h
#define functions_h

#include <cmath>
#include "parameters.h"
#include "crazyflie.h"


// Definindo as variáveis de velocidade amgular (rad/s) do drone
float w1;
float w2;
float w3;
float w4;

// Define all motors as PWM objects
PwmOut motor_1(MOTOR1);
PwmOut motor_2(MOTOR2);
PwmOut motor_3(MOTOR3);
PwmOut motor_4(MOTOR4);


// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor ( float omega_r )   //função para controlar velocidade angular desejada (rad/s -> PWM)
 {
    float a2 = 1.174e-07; //valores da função de transferência
    float a1 = 3.274e-12;
    float a0 = 0;

    float PWM = (a2*(omega_r*omega_r)) + (a1*omega_r) + a0;
     
    return PWM; 
 }


// Função calcula as velocidades angulares necessárias para as forças e torques desejados
void mixer (float f_t, float t_phi, float t_theta, float t_psi)
{
    float sigma = 1/(4*kl*l);
    
    w1 = sqrt( (1/(4*kl)*f_t) - (sigma*t_phi) - (sigma*t_theta) - (1/(4*kd)*t_psi) );
    w2 = sqrt( (1/(4*kl)*f_t) - (sigma*t_phi) + (sigma*t_theta) + (1/(4*kd)*t_psi) );
    w3 = sqrt( (1/(4*kl)*f_t) + (sigma*t_phi) + (sigma*t_theta) - (1/(4*kd)*t_psi) );
    w4 = sqrt( (1/(4*kl)*f_t) + (sigma*t_phi) - (sigma*t_theta) + (1/(4*kd)*t_psi) );

    //resolver problema de casos em que possa ocorrer raiz quadrada de número negativo, já que o sistema não permite mudar sentido de rotação das hélices

}

// Função de atuação dos motores para as forças e torques desejados (chama a função mixer em seu interior)
void actuate ( float f_t , float tau_phi , float tau_theta , float tau_psi )
 {
 mixer (f_t , tau_phi , tau_theta , tau_psi );
 motor_1 = control_motor ( w1 );
 motor_2 = control_motor ( w2 );
 motor_3 = control_motor ( w3 );
 motor_4 = control_motor ( w4 );
 }

#endif
#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

// Constante do Drone
const float kl = 1.726e-08; //(N*s^2) Constante de sustentação (lift constant)
const float kd = 8.939e-10; //(N*m*s^2) Constante de arrasto (drag constant)

//parâmetros do filtro passa-baixas do estimador de atitude
const float wc = 0.1; //frequência de corte (rad/s)
const float dt = 0.002; //tempo de amostragem (2ms)
const float alpha = (wc*dt)/(1+(wc*dt)); //fator de suavização

//Ganhos dos controladores de atitude 
// Os ganhos de roll e pitch (phi e theta) devem ser iguais pela simetria do drone
//%OS = % e Ts = s 
const float kp_rp = 260.51; //ganho proporcional de roll e pitch (phi e theta)
const float kd_rp = 26.67; //ganho derivativo de roll e pitch (phi e theta)

//%OS = 0.1% e Ts = 0.5s
const float kp_psi = 93.8; //ganho proporcional de yaw (psi)
const float kd_psi = 16.0; //ganho derivativo de yaw (psi)

#endif
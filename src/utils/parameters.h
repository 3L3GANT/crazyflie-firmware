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
const float wc = 1.0; //frequência de corte (rad/s)
const float dt = 0.002; //tempo de amostragem (2ms)
const float alpha = (wc*dt)/(1+(wc*dt)); //fator de suavização

//Ganhos dos controladores de atitude 
// Os ganhos de roll e pitch (phi e theta) devem ser iguais pela simetria do drone
//%OS = 0.5% e Ts = 0.3s 
const float kp_rp = 240.28; //ganho proporcional de roll e pitch (phi e theta)
const float kd_rp = 26.67; //ganho derivativo de roll e pitch (phi e theta)

//%OS = 0.5% e Ts = 0.6s
const float kp_psi = 60.07; //ganho proporcional de yaw (psi)
const float kd_psi = 13.33; //ganho derivativo de yaw (psi)

//parâmetros para o estimador vertical (altitude)
const float dt_range = 0.05; //tempo de amostragem do sensor de range (20ms)

//parâmetros do observador de estados do estimador vertical (altitude)
const float wc_range = 10; //frequência de corte (rad/s)
const float zeta = sqrt(2)/2; //fator de amortecimento

const float l1 = wc_range*wc_range; //ganho do estimador
const float l2 =2*zeta*wc_range;

//Ganhos do controlador vertical
//%OS = 0.5% e Ts = 2s 
const float kp_z = 5.40;
const float kd_z = 4.00;

//Parâmetros do estimador horizontal
const float sigma = 2*tan((42*pi/180)/2)/(420*dt);
const float wc_hz = 50; //frequência de corte do estimador horizontal (rad/s)
const float l_hz = wc_hz; //ganho do estimador horizontal (observador de estados)


#endif
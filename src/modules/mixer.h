# ifndef mixer_h
# define mixer_h

# include "mbed.h"
# include "crazyflie.h"


// Mixer class
class Mixer
{

public :

// Class constructor
Mixer ();

// Actuate motors with desired total trust force (N) and torques (N.m)
void actuate ( float f_t , float tau_phi , float tau_theta , float tau_psi );

// funções para controle do estado do motor
bool armed;
void arm ();
void disarm();

DigitalOut led_rr, led_rl, led_gr, led_gl, led_blue; // pinagem dos leds

int t; // variável contador tempo

//-------------------------------------------------------------------------------

private :

// Motors PWM outputs
PwmOut motor_1 , motor_2 , motor_3 , motor_4 ;

// Angular velocities ( rad /s)
float omega_1 , omega_2 , omega_3 , omega_4 ;

// Convert total thrust force (N) and torques (N.m) to angular velocities (rad/s)
void mixer ( float f_t , float tau_phi , float tau_theta , float tau_psi ); //declara função que vai ser feita no arquivo de implementação (mixer.cpp)

// Convert desired angular velocity ( rad /s) to PWM signal (%)
float control_motor ( float omega );
};

# endif
# include "mixer.h"


// Class constructor
Mixer :: Mixer () : motor_1 ( MOTOR1 ), motor_2 ( MOTOR2 ), motor_3 ( MOTOR3 ), motor_4 ( MOTOR4 ),
                    led_rr (LED_RED_R), led_rl (LED_RED_L), led_gr (LED_GREEN_R), led_gl (LED_GREEN_L), led_blue (LED_BLUE_L)
{
    motor_1.period (1.0/500.0) ;
    motor_2.period (1.0/500.0) ;
    motor_3.period (1.0/500.0) ;
    motor_4.period (1.0/500.0) ;
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;

    armed = false; // motores começam desarmados

    led_rr = true; // todos os leds desligados no início
    led_rl = true; 
    led_gr = true; 
    led_gl = true;
    led_blue = false;
}


// Convert total trust force (N) and torques (N.m) to angular velocities ( rad /s)
// Função calcula as velocidades angulares necessárias para as forças e torques desejados
void Mixer :: mixer ( float f_t , float tau_phi , float tau_theta , float tau_psi )
{
    float sigma = 1/(4*kl*l);
    
    omega_1 = sqrt( (1/(4*kl)*f_t) - (sigma*tau_phi) - (sigma*tau_theta) - (1/(4*kd)*tau_psi) );
    omega_2 = sqrt( (1/(4*kl)*f_t) - (sigma*tau_phi) + (sigma*tau_theta) + (1/(4*kd)*tau_psi) );
    omega_3 = sqrt( (1/(4*kl)*f_t) + (sigma*tau_phi) + (sigma*tau_theta) - (1/(4*kd)*tau_psi) );
    omega_4 = sqrt( (1/(4*kl)*f_t) + (sigma*tau_phi) - (sigma*tau_theta) + (1/(4*kd)*tau_psi) );

}


// Convert desired angular velocity ( rad /s) to PWM signal (%)
//função para controlar velocidade angular desejada (rad/s -> PWM)
float Mixer :: control_motor ( float omega ) 
{
    float a2 = 1.174e-07; //valores da função de transferência
    float a1 = 3.274e-12;
    float a0 = 0;

    float PWM = (a2*(omega*omega)) + (a1*omega) + a0;
     
    return PWM;

}


// Actuate motors with desired total trust force (N) and torques (N.m)
// Função de atuação dos motores para as forças e torques desejados (chama a função mixer em seu interior)
void Mixer :: actuate ( float f_t , float tau_phi , float tau_theta , float tau_psi )
{
    if (armed==true){
        mixer (f_t , tau_phi , tau_theta , tau_psi );
        motor_1 = control_motor ( omega_1 );
        motor_2 = control_motor ( omega_2 );
        motor_3 = control_motor ( omega_3 );
        motor_4 = control_motor ( omega_4 );
    }

    else {  
        for (t=0; t<=10; t++) {  //pisca leds verdes se não estiver armado
        led_rr = !led_rr;
        led_rl = !led_rl; 
        wait(0.5);
        }
    
    led_rr = true;  // deixa leds verdes ligados
    led_rl = true;
    led_gr = false;
    led_gl = false;
    }

    

}


// Funções de armar e desarmar os motores

// Função de desarme dos motores
void Mixer :: disarm()
{
    armed = false;

    //desliga motores
    motor_1 = 0.0; 
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;

    //Desliga leds vermelhos
    led_rr = true; 
    led_rl = true;
 

    //pisca leds verdes se não estiver armado
    for (t=0; t<=10; t++) {
        led_gr = !led_gr;
        led_gl = !led_gl; 
        wait(0.5);
    }
    //deixa leds verdes ligados
    led_gr = false;
    led_gl = false;
}


// Função de armação dos motores
void Mixer :: arm()
{
    armed = true;

    //Desliga leds verdes
    led_gr = true;
    led_gl = true;

    //pisca leds para indicar inicialização
    for (t=0; t<=10; t++) {
        led_rr = !led_rr;
        led_rl = !led_rl; 
        wait(0.5);
    }

    led_rr = false;  // deixa leds vermelhos ligados
    led_rl = false;
}
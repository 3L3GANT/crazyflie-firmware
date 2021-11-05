# ifndef attitude_controller_h
#define attitude_controller_h

# include "mbed.h"
# include "crazyflie.h"

// Attitude controller class
class AttitudeController
{
    public :
    // Class constructor
    AttitudeController ();
    
    // Control torques (N.m) given reference angles (rad) (_r) and current angles (rad) and angular velocities (rad/s)
    void control ( float phi_r , float theta_r , float psi_r , float phi , float theta ,
    float psi , float p, float q, float r);
    
    // Torques (N.m)
    float tau_phi , tau_theta , tau_psi ;
    
    
    private :
    // Control torque (N.m) given reference angle ( rad ) and current angle ( rad) and angular velocity ( rad /s) with given controller gains
    float control_siso (float angle_r, float angle, float rate, float kp, float kd);

    //Ângulos de referência
    float phi_r;
    float theta_r;
    float psi_r;

    //velocidades de ângulos de referência
    //Como se deseja que o drone fique parado pode-se considerar as velocidades de referência como zero.
    float vel_phi_r = 0;
    float vel_theta_r = 0;
    float vel_psi_r = 0;

    //aceleração de ângulos de referência
    float acel_phi_r;
    float acel_theta_r;
    float acel_psi_r;
};

#endif
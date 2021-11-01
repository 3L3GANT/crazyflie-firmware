#include "attitude_estimator.h"

// Class constructor
AttitudeEstimator :: AttitudeEstimator () : imu ( IMU_SDA , IMU_SCL )
{
    //ângulos de euler
    phi = 0;
    theta = 0;
    psi = 0;

    //velocidades angulares 
    p = 0;
    q = 0;
    r = 0;
}

// Initialize class
void AttitudeEstimator :: init ()
{
    imu.init();
    for(int i=0; i<500;i++)
    {
        imu.read();

        p_bias=(p_bias+imu.gx)/500;
        q_bias=(q_bias+imu.gy)/500;
        r_bias=(r_bias+imu.gz)/500;

        wait(dt);
    }
}

// Estimate Euler angles (rad ) and angular velocities ( rad /s)
void AttitudeEstimator :: estimate () 
{
    imu.read();

    p = imu.gx - p_bias;
    float phi_g = phi_g+(p*dt); //solução linear
    //phi = (1-alpha)*phi_g;
    float phi_a = atan2(-imu.ay, -imu.az);
    //phi = (1-alpha)*phi+(alpha*phi_a);
    phi = ((1-alpha)*phi_g) + (alpha*phi_a);

    q = imu.gy - q_bias;
    float theta_g = theta_g+(q*dt); //solução linear
    float theta_a = atan2(imu.ax, -imu.az); //solução linear
    theta = ((1-alpha)*theta_g) + (alpha*theta_a);

    r = imu.gz - r_bias;
    float psi_g = psi_g+(r*dt); //solução linear 
    psi = psi_g;

    //Implementar soluções não lineares para o theta_a e phi, theta e psi _g.
}
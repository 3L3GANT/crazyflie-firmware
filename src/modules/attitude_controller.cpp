# include "attitude_controller.h"

// Class constructor
AttitudeController :: AttitudeController ()
{
    tau_phi = 0;
    tau_theta = 0;
    tau_psi = 0;
}

// Control torques (N.m) given reference angles ( rad) and current angles ( rad ) and angular velocities ( rad /s)
void AttitudeController :: control ( float phi_r , float theta_r , float psi_r , float phi, float theta , float psi , float p, float q, float r)
{
    acel_phi_r = control_siso(phi_r, phi,(vel_phi_r-p), kp_rp, kd_rp);
    acel_theta_r = control_siso(theta_r, theta, (vel_theta_r-q), kp_rp, kd_rp);
    acel_psi_r = control_siso(psi_r, psi, (vel_psi_r-r), kp_psi, kd_psi);

    tau_phi = I_xx*acel_phi_r;
    tau_theta = I_yy*acel_theta_r;
    tau_psi = I_zz*acel_psi_r;
}

// Reference angular aceleration (rad/s^2) given reference angle ( rad ) and current angle ( rad ) and angular velocity ( rad /s) with given controller gains
float AttitudeController :: control_siso ( float angle_r , float angle , float rate ,float kp , float kd)
{
   //rate = vel_ang_ref - vel_ang_est
   float acel_r = kp*(angle_r-angle) + kd*(rate);
   return acel_r;
}

//Projetar os ganhos do sistema em malha fechada para controlador regulador de estados
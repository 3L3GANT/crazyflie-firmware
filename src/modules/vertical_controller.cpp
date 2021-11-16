#include "vertical_controller.h"

//Class constructor
VerticalController::VerticalController()
{
    f_t = 0;
    w_ref = 0.0; //a velocidade de referência é assumida como sendo sempre zero (drone estático)
}

// Control thrust force (N) given vertical position (m) and  velocity (m/s)
void VerticalController::control(float z_r, float z, float w)
{
    float acel_zr = control_siso(z_r, z, w, kp_z, kd_z);
    f_t = m*(g+acel_zr);
}

// Control aceleration given reference position (m) andd current position (m) and velocity (m/s) with given controller gains
// Controlador regulador de estados
float VerticalController::control_siso(float pos_r, float pos, float vel, float kp, float kd)
{
    return kp*(pos_r-pos)+kd*(w_ref-vel);
}
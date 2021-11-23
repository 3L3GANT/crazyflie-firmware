#ifndef crazyflie_h
#define crazyflie_h

// Crazyflie utility variables
#include "utils/pin_names.h"
#include "utils/parameters.h"

// Crazyflie 2.0 hardware abstraction layer
// #include "drivers/mpu9250.h"    // IMU sensor

// Flow deck hardware abstraction layer
// #include "drivers/vl53l0x.h"    // Range sensor
// #include "drivers/pmw3901.h"    // Optical flow sensor

// Crazyflie 2.1 hardware abstraction layer
#include "drivers/bmi088.h"     // IMU sensor

// Flow deck v2 hardware abstraction layer
#include "drivers/vl53l1x.h"    // Range sensor
#include "drivers/pmw3901.h"    // Optical flow sensor


//Inclui a classe mixer e suas funções 
#include "modules/mixer.h"


//Inclui a classe estimador de atitude
#include "attitude_estimator.h"

//Inclui a classe controlador de atitude
#include "attitude_controller.h"


//Inclui a classe estimador vertical (altura)
#include "vertical_estimator.h"

//Inclui a classe controlador vertical
#include "vertical_controller.h"


//Inclui a classe estimador horizontal
#include "horizontal_estimator.h"

//Incluia a classe controlador horizontal
//#include "horizontal_controller.h"

#endif
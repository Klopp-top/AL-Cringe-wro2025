#ifndef CONFIG_H
#define CONFIG_H

#define XSHUT1 11
#define XSHUT2 10
#define XSHUT3 9

#define ENCA 2 
#define ENCB 3

#define SERVO_ROTATE 8
#define SERVO_CAM 7

#define TRIGGER_LEFT  19
#define ECHO_LEFT     18

#define MAX_DISTANCE   300

#define TRIGGER_RIGHT  22  
#define ECHO_RIGHT     24 

#define MOTOR_DIR_BACK 5
#define MOTOR_DIR_FRONT 6
#define MOTOR_PWM 4

#define MOTOR_DIR_BACK2 26
#define MOTOR_DIR_FRONT2 28
#define MOTOR_PWM2 44

#define KNOPKA 12

#define S0 13
#define S1 14
#define S2 17
#define S3 16

#define sensorOut 15

extern float Kp, Ki, Kd;
extern float error, previousError, integral, derivative, error2, previousError2, integral2, derivative2;

extern int servoAngle;
extern const int servoNeutral;
extern const int servoLeft;
extern const int servoRight;

extern int distance_left, distance_center, distance_right;
extern int laser_right, laser_center, laser_left;

extern String color;

extern int redFrequency;
extern int greenFrequency;
extern int blueFrequency;

extern int redColor;
extern int greenColor;
extern int blueColor;

extern int motorSpeed;

extern bool obstacle_detected;

extern int pos;
extern volatile int posi;

extern int target_ticks;

extern bool start;

extern float turnCount;

extern bool redLine;

extern bool firstTurn;

#endif

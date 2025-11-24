#include "config.h"

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

int redColor = 0;
int greenColor = 0;
int blueColor = 0;

float Kp = 1.5; // 0.8
float Ki = 0.0;
float Kd = 0.3; // 0.17

float error = 0;
float previousError = 0;
float integral = 0;
float derivative = 0;

float error2 = 0;
float previousError2 = 0;
float integral2 = 0;
float derivative2 = 0;

int motorSpeed = 120;

int servoAngle = 77;
const int servoNeutral = 77;
const int servoLeft = servoNeutral + 14;
const int servoRight = servoNeutral - 14;

String color;

long prevT = 0;
float eprev = 0;
float eintegral = 0;

int distance_left = 1;
int distance_right = 1;

int laser_right = 0;
int laser_left = 0;
int laser_center = 0;
int left_laser = 0;
int right_laser = 0;

bool firstTurn = false;

bool start = false;

bool redLine = false;

bool stayLeft = false;

float turnCount = 0.0;

int target_ticks = 700;

bool obstacle_detected = false;

volatile int posi = 0;

bool executed = false;

int pos = 0;

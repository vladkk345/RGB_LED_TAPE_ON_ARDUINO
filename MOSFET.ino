/*LED tape on MOSFET transistors with possible control
brightness using PWM and using potentiometer
*/
#define SIGNAL_R 6  // output signal from MOSFET for red
#define SIGNAL_G 9  // output signal from MOSFET for green
#define SIGNAL_B 10 // output signal from MOSFET for blue
#define AN_SIGNAL_ONE   5 // analog signal
#define AN_SIGNAL_TWO   6 // analog signal
#define AN_SIGNAL_THREE 7 // analog signal

int PWM_R, PWM_G, PWM_B; // declaration variables for 3 basic color

void setup() 
{ 
  // Settings 3 signal as output
  pinMode(SIGNAL_R, OUTPUT);
  pinMode(SIGNAL_G, OUTPUT);
  pinMode(SIGNAL_B, OUTPUT); 
}

void loop() 
{
  // Getting data for first transistor
  PWM_R = analogRead(AN_SIGNAL_ONE); // reading value from signal А5(analog) и assingment variable PWM_R
  PWM_R = map(PWM_R, 0, 1023, 0, 255); // converting data from digital format to analog
  PWM_R = constrain(PWM_R, 0, 255); // constrain range
  analogWrite(SIGNAL_R, PWM_R); // setting data in value SIGNAL_R
  
  // Getting data for second transistor (analogically)
  PWM_G = analogRead(AN_SIGNAL_TWO); // reading from signal А6
  PWM_G = map(PWM_G, 0, 1023, 0, 255);
  PWM_G = constrain(PWM_G, 0, 255);
  analogWrite(SIGNAL_G, PWM_G);
  
  // Getting data for third transistor (analogically)
  PWM_B = analogRead(AN_SIGNAL_THREE);// reading from signal А7
  PWM_B = map(PWM_B, 0, 1023, 0, 255);
  PWM_B = constrain(PWM_B, 0, 255);
  analogWrite(SIGNAL_B, PWM_B);
}

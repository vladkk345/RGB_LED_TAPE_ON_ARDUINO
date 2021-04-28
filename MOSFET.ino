/*Светодиодная лента на MOSFET транзисторах с возможностью регулировки
яркости посредством ШИМ, используя потенциометр
*/
#define SIGNAL_R 6  // выходной сигнал с MOSFET для красного
#define SIGNAL_G 9  // выходной сигнал с MOSFET для зеленого
#define SIGNAL_B 10 // выходной сигнал с MOSFET для синего
#define AN_SIGNAL_ONE   5 // аналоговый сигнал
#define AN_SIGNAL_TWO   6 // аналоговый сигнал
#define AN_SIGNAL_THREE 7 // аналоговый сигнал

int PWM_R, PWM_G, PWM_B; // объявление переменных для 3 основных цветов

void setup() 
{ 
  // Настройка 3 сигналов как выходы
  pinMode(SIGNAL_R, OUTPUT);
  pinMode(SIGNAL_G, OUTPUT);
  pinMode(SIGNAL_B, OUTPUT); 
}

void loop() 
{
  // Получение данных для первого транзистора
  PWM_R = analogRead(AN_SIGNAL_ONE); // чтение значения с сигнала А5(аналоговый) и присваивание переменной PWM_R
  PWM_R = map(PWM_R, 0, 1023, 0, 255); // преобразование данных из цифрового формата в аналоговый
  PWM_R = constrain(PWM_R, 0, 255); // ограничение диапазона
  analogWrite(SIGNAL_R, PWM_R); // запись данных в значение SIGNAL_R
  
  // Получение данных для второго транзистора (аналогично)
  PWM_G = analogRead(AN_SIGNAL_TWO); // чтение с сигнала А6
  PWM_G = map(PWM_G, 0, 1023, 0, 255);
  PWM_G = constrain(PWM_G, 0, 255);
  analogWrite(SIGNAL_G, PWM_G);
  
  // Получение данных для третьего транзистора (аналогично)
  PWM_B = analogRead(AN_SIGNAL_THREE);// чтение с сигнала А7
  PWM_B = map(PWM_B, 0, 1023, 0, 255);
  PWM_B = constrain(PWM_B, 0, 255);
  analogWrite(SIGNAL_B, PWM_B);
}

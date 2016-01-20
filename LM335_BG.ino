/*************************************************
* Температурен сензор с LM335 и Arduino
* Temperature Sensor LM335 and Arduino
* -----------------
* http://dobrishinov.info
*************************************************/

int analogPin = 0;  //Задаваме пина по който ще приемаме аналоговите данни 

float tempK=0, tempC=0, tempF=0; //Дефинираме променливи за калвини, градуси и фаренхайт

void setup(){
 
Serial.begin(9600);    //Настройваме конзолата на 9600 bps
}
 
void loop(){
 
tempK = analogRead(analogPin) * 0.004882812 * 100;    //Прочитаме температурата в келвини
 
tempC = tempK - 273.15;    //Конвертираме келвините в градуси (това са официални данни от wikipedia, ако нямате 10К потенциометър за финна настройка на LM335, 
                           //е възможно да промените числото с 10 нагоре или надолу, така ще калибрирате сензора до подходящата околна температура) 
 
tempF = ((tempK) * 9 / 5) - 459.67;    //Конвертираме от келвини във фаренхайт
 
//Показва всички стойности в конзолата
Serial.print("Kelvin: "); Serial.println(tempK);
Serial.print("Celsius: "); Serial.println(tempC);
Serial.print("Fahrenheit: "); Serial.println(tempF);
Serial.println();    //Print Blank Line
 
delay(1000);    //Опресняване през 1 секунда
}

/* Embedded Systems Development Task
 * 
 * Switch whenever it goes from LOW to HIGH The led will toggle
 * when the switch is pressed sends "pressed" to the serial monitr
 * when the led toggles it sends its state to the serial monitor
 * sends continuous serial data comes from temperature sensor with 3 second rate  
 *
 * Salma Khaled El Gendy
 * 26/6/2018
 */
int sensorPin = 0;     // the number of the input pin "temprature sensor"
int inPin = 2;         // the number of the input pin with interrupts "switch"
int outPin = 13;       // the number of the output pin "Led in the arduino"

volatile int buttonflag;
int readingSensor;
int state = HIGH;      // the current state of the output pin

long time = 0;         // the last time the output pin was toggled
long time2 = 0;
long debounce = 200;   // the debounce time, increase if the output flickers
long secounds = 3000;  // time for temprature to take another read
void setup()
{
  pinMode(inPin, INPUT);
  pinMode(outPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(inPin),ISR_button,RISING);
  Serial.begin(9600);
}

void loop()
{
  ////// switch

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if ( millis() - time > debounce && buttonflag) {
    Serial.println("pressed");
    if (state == HIGH)
    {
      state = LOW;
      Serial.println("OFF");
    }
    else
    {
      state = HIGH;
      Serial.println("ON");
    }

    time = millis();
    buttonflag = 0;    
  }

  digitalWrite(outPin, state);
  
  //// temprature sensor

  //getting the voltage reading from the temperature sensor
  if(millis() - time2 > secounds)
  {
  int reading = analogRead(sensorPin);
  // converting that reading to voltage
   float voltage = reading * 5.0;
  voltage /= 1024.0; 
 
  //print out the temperature in celsius
  float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                                //to degrees ((voltage - 500mV) times 100)
  Serial.print(temperatureC); Serial.println(" degrees C");
  time2 = millis();
  }
}
void ISR_button()
{
    buttonflag = 1;
}


  /*
       Source code repo : https://github.com/adriens/arduino-led-snake/
  	 
    */
  const int NB_LEDS = 6; // total amount of leds
  const int LED_STEP = 2; // step between two pins : 2 means 1/2
  const int LED_START_POS = 2; // pin of the first led

  const int DELAY_BETWEEN_TWO_LEDS = 100; // time setup : time between two leds
  const int DELAY_BETWEEN_TWO_LOOPS = 100; // time setup : time between two loops

  int pinLed[NB_LEDS];

  void setup() {
    Serial.begin(9600);

    Serial.println("Setup ..."); // assign led positions to pinLeds
    Serial.println("Filling leds positions ...");
    int ledPos = LED_START_POS;
    for (int i = 0; i < NB_LEDS; i++) {
      Serial.print("Setting led <");
      Serial.print(i);
      Serial.print("> at position <");
      Serial.print(ledPos);
      Serial.println(">");
      pinLed[i] = ledPos;
      ledPos = ledPos + LED_STEP;
    }
    Serial.println("Leds positions set.");

    Serial.println("Putting leds to OUTPUT mode...");
    for (int i = 0; i < NB_LEDS; i++) {
      pinMode(pinLed[i], OUTPUT);
    }
  }

  void loop() {
    for (int i = 0; i <= NB_LEDS; i++) {
      digitalWrite(pinLed[i], HIGH);
      delay(DELAY_BETWEEN_TWO_LEDS); // Wait for 1000 millisecond(s)
      digitalWrite(pinLed[i], LOW);
      delay(DELAY_BETWEEN_TWO_LEDS); // Wait for 1000 millisecond(s)
    }
    Serial.print("Waiting <");
    Serial.print(DELAY_BETWEEN_TWO_LOOPS);
    Serial.println("> ms. before next loop ...");
    delay(DELAY_BETWEEN_TWO_LOOPS);
  }

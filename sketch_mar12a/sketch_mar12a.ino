// Police Siren with Flashing LEDs and Fading LED
// Buzzer on pin 11
// LEDs on pins 9 and 10
// Fading LED on pin 6

int buzzer = 11;
int fadeLED = 6;

int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(fadeLED, OUTPUT);
}

void loop() {

  // Siren going up (lower pitch to higher)
  for (int freq = 400; freq <= 900; freq += 8) {

    tone(buzzer, freq);

    // Flash police lights
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);

    // Fade LED
    analogWrite(fadeLED, brightness);
    brightness += fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }

    delay(40);

    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);

    analogWrite(fadeLED, brightness);
    brightness += fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }

    delay(40);
  }

  // Siren going down
  for (int freq = 900; freq >= 400; freq -= 8) {

    tone(buzzer, freq);

    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);

    analogWrite(fadeLED, brightness);
    brightness += fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }

    delay(40);

    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);

    analogWrite(fadeLED, brightness);
    brightness += fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount;
    }

    delay(40);
  }
}
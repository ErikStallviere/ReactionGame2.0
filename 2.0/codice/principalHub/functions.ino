
boolean debounce(int n)
{
  boolean current = (digitalRead(buttonPins[n]));
  if (lastButtonsState[n] != current)
  {
    delay(1);
    current = digitalRead(buttonPins[n]);
  }
  return current;
}

void setNextButton()
{
  while (true)
  {
    currentNumber = random(0, dimensions);

    if (currentNumber != lastNumber)
    {
      break;
    }
  }
  lastNumber = currentNumber;

  for (int i = 0; i < dimensions; i++)
  {
    digitalWrite(ledPins[i], LOW);
  }
  digitalWrite(ledPins[currentNumber], HIGH);
  return;
}

void stampLCD() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Tempo: ");
  lcd.setCursor(0, 2);
  lcd.print("Punteggio: ");

  lcd.setCursor(0, 1);
  int timerSecond = (int)(ceil(timerGame / 1000 + 0.001));
  lcd.print(timerSecond);

  lcd.setCursor(0, 3);
  lcd.print(score);
  Serial.print("Tempo: ");
  Serial.println(timerSecond);
  Serial.print("Puntegggio: ");
  Serial.println(score);
}

void stampThirdLCD(int colpi) {

  lcd.clear();
  Serial.print("Punteggio: ");
  Serial.println(score);
  Serial.print("Colpi: ");
  Serial.print(colpi - shot);
  Serial.print(" / ");
  Serial.println(colpi);
  lcd.setCursor(0, 0);
  lcd.print("Tiri: ");
  lcd.setCursor(0, 3);
  lcd.print(score);
  lcd.setCursor(0, 2);
  lcd.print("Punteggio: ");
  lcd.setCursor(0, 1);
  lcd.print(colpi - shot);
  lcd.setCursor(3, 1);
  lcd.print(" / ");
  lcd.setCursor(7, 1);
  lcd.print(colpi);

}


void clearVariables() {
  timer = 0;
  dimensions = 0;
  score = 0;
  countdown = 0;

  countdownLoop = 0;


  timerGame = 0;

  hz = 0;

  pressed = false;

  timeReflection = 1000;
  shot = 100;
  error = false;

  scheme = 0;
  counter = 0;
  numButtons = 0;
  flash = true;
}

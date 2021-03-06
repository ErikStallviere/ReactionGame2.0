

void secondModGroup(int dim, int colpi)
{
  dimensions = dim;
  shot = colpi;
  timer = millis();
  countdown = 180000;
  setNextButton(true);

  while (true) {
    for (int i = 0; i < dimensions; i++)
    {
      currentButtonsState[i] = debounce(i);

      if (currentButtonsState[i] == true && currentButtonsState[i] != lastButtonsState[i] && i == currentNumber)
      {
        score++;
        incrementScore();
        setNextButton(true);
        digitalWrite(buzzerPin, HIGH);
        digitalWrite(buzzerPin2, HIGH);
        delay(delayValue);
        delay(1);
      }
      timerGame = millis() - timer;
      if (timerGame >= countdown || score == shot)
      {
        for (int i = 0; i < dimensions; i++)
        {
          digitalWrite(ledPins[i], LOW);
        }
        scores[0] = timerGame;
        scores[1] = score;
        clearVariables();
        return;
      }
    }
  }
}


struct Leaf {
  int leafIndex;
  int numLEDs;
  CRGB *ledsLeft;
  CRGB *ledsRight;

  void setLED(int index, CRGB color) {
#ifdef DEBUG
    if (index < 8) {
      ledsLeft[index] = color;
      ledsRight[index] = color;
    } else {
      ledsLeft[index] = CRGB::Black;
      ledsRight[index] = CRGB::Black;
    }
#else
    ledsLeft[index] = color;
    ledsRight[index] = color;
#endif
  }

  void setAll(CRGB color) {
    for (int i = 0; i < numLEDs; i++) {
#ifdef DEBUG
      if (i < 8) {
        setLED(i, color);
      } else {
        setLED(i, CRGB::Black);
      }
#else
      setLED(i, color);
#endif
    }
  }
};

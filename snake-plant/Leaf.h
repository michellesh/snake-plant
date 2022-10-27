struct Leaf {
  int leafIndex;
  int numLEDs;
  CRGB *ledsLeft;
  CRGB *ledsRight;

  void setLED(int index, CRGB color) {
    ledsLeft[index] = color;
    ledsRight[index] = color;
  }

  void setAll(CRGB color) {
    for (int i = 0; i < numLEDs; i++) {
      setLED(i, color);
    }
  }
};

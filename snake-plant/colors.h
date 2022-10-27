#define SECONDS_PER_PALETTE 15

CRGB leafColors[] = {CRGB::White, CRGB::Yellow, CRGB::Green, CRGB::Lime,
                     CRGB::Violet};

DEFINE_GRADIENT_PALETTE(_greenPalette){0,   0, 255, 0,  // CRGB::Lime
                                       85,  0, 255, 0,  // CRGB::Lime
                                       170, 0, 255, 0,  // CRGB::Lime
                                       255, 0, 255, 0}; // CRGB::Lime
CRGBPalette16 greenPalette = _greenPalette;

DEFINE_GRADIENT_PALETTE(_leafPalette){0,   34,  139, 34,   // CRGB::ForestGreen
                                      85,  0,   255, 0,    // CRGB::Lime
                                      170, 255, 215, 0,    // CRGB::Gold
                                      255, 255, 255, 255}; // CRGB::White
CRGBPalette16 leafPalette = _leafPalette;

DEFINE_GRADIENT_PALETTE(_coolPalette){0,   224, 240, 255,  // light blue
                                      127, 31,  147, 255,  // medium blue
                                      255, 238, 130, 238}; // CRGB::Violet
CRGBPalette16 coolPalette = _coolPalette;

DEFINE_GRADIENT_PALETTE(_fairyPalette){0,   63,  57,  11,   // "QuarterFairy"
                                       127, 127, 114, 22,   // "HalfFairy"
                                       224, 255, 227, 45,   // CRGB::FairyLight
                                       255, 255, 255, 255}; // full white
CRGBPalette16 fairyPalette = _fairyPalette;

// clang-format off
CRGBPalette16* activePalettes[] = {
  &greenPalette,
  &leafPalette,
  &coolPalette,
  &fairyPalette
};
// clang-format on

CRGBPalette16 currentPalette = *(activePalettes[0]);
CRGBPalette16 targetPalette = *(activePalettes[0]);

void setNextColorPalette() {
  const uint8_t numberOfPalettes =
      sizeof(activePalettes) / sizeof(activePalettes[0]);
  static uint8_t whichPalette = -1;
  whichPalette = addmod8(whichPalette, 1, numberOfPalettes);

  targetPalette = *(activePalettes[whichPalette]);
}

void setCurrentColorPalette(uint8_t paletteIndex) {
  currentPalette = *(activePalettes[paletteIndex]);
  targetPalette = *(activePalettes[paletteIndex]);
}

void cycleColorPalette() {
  EVERY_N_SECONDS(SECONDS_PER_PALETTE) { setNextColorPalette(); }

  EVERY_N_MILLISECONDS(10) {
    nblendPaletteTowardPalette(currentPalette, targetPalette, 12);
  }
}

//Basic sine wave animation for NeoPixel Ring Bangle Bracelet
//by Dano Wall and Becky Stern for Adafruit Industries
#include <Adafruit_NeoPixel.h>

#define PIN       3 // Marked D1 on GEMMA
#define NUM_LEDS 18

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type:
//   NEO_GRB  Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB  Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB);

uint32_t color = strip.Color(75, 250, 100); // Change RGB color value here

// These are the pixels in order of animation-- 36 pixels in total:
int sine[] = {
   4,  3,  2,  1,  0, 15, 14, 13, 12 };

void setup() {
  strip.begin();
  strip.show();            // Initialize all pixels to 'off'
  strip.setBrightness(40); // 40/255 brightness (about 15%)
}

void loop() {
  for(int i=0; i<9; i++) {
    strip.setPixelColor(sine[i], color);             // Draw 'head' pixel
    strip.setPixelColor(sine[(i + 9 - 8) % 9], 0); // Erase 'tail'
    strip.show();
    delay(40);
  }
}

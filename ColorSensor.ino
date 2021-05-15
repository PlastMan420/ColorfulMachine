void sense() {
  red = tcs.colorRead('r');   //reads color value for red
  green = tcs.colorRead('g');   //reads color value for green
  blue = tcs.colorRead('b');    //reads color value for blue
  clear = tcs.colorRead('c');    //reads color value for white(clear)

  sum = clear;
  r = red; g = green; b = blue;
  r /= sum; g /= sum; b /= sum;
  r *= 256; g *= 256; b *= 256;

  log(r, "R");
  log(g, "G");
  log(b, "B");
  log(sum, "C");
  delay(200);
}

void log(int val, char c) {
  Serial.print(c);
  Serial.print(" = ");
  Serial.print(val);
  Serial.print("  ");
  Serial.println();

}
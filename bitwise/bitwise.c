#include <stdio.h>
#include <stdint.h>

uint32_t process_vbits(uint32_t val) {
  uint8_t byte = (val >> 8) & 0xff;
  uint8_t reversed = 0;

  for (int i = 0; i < 8; i++) {
    if (byte & (1 << i))
      reversed |= (1 << (7 - i));
  }

  val &= ~(0xff << 8);
  val |= (reversed << 8);

  printf("%d", val);
}

int main() {

  uint32_t number = 32323232;

  process_vbits(number);
  
  return 0;
}

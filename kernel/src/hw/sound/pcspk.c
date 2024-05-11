#include "hw/sound/pcspk.h"
#include "io/pio.h"
#include <stdint.h>

void play_sound(u32 freq) {
  u32 div;
  uint8_t tmp;

  div = 1193180 / freq;
  outb(0x43, 0xb6);
  outb(0x42, (uint8_t)(div));
  outb(0x42, (uint8_t)(div >> 8));
  tmp = inb(0x61);
  if (tmp != (tmp | 3))
    outb(0x61, tmp | 3);
}

void nosound() { outb(0x61, inb(0x61) & 0xFC); }

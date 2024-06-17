static unsigned int next = 1;

int krand(void) {
  next = next * 1103515245 + 12345;
  return (unsigned int)(next / 65536) % 32768;
}

void ksrand(unsigned int seed) { next = seed; }

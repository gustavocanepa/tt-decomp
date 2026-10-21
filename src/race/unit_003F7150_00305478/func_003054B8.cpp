/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_002E4CB8(void *);
extern "C" void *func_002F04D8(void *, int);
extern "C" int func_003054B8(char *self, int row, unsigned char col, short *out) {
 *out = func_002E4CB8(func_002F04D8(self, row));
 return *(int *)(self + ((row * 16 + col) * 4) + 0x21480);
}

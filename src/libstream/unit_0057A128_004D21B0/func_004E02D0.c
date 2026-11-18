/* compiler: ee-gcc2.9-991111 */
#define BCD(x) (((x) / 10) * 16 + (x) % 10)
unsigned char *func_004E02D0(int i, unsigned char *p) {
 i += 150;
 p[2] = BCD(i % 75);
 i /= 75;
 p[1] = BCD(i % 60);
 i /= 60;
 p[0] = BCD(i);
 return p;
}

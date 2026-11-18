/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_00458018(int x, int y, int pitch, int valid) {
if (valid) { x = (x + 511) / 512; return (pitch / 256) * x + y / 512; } return 0;
}

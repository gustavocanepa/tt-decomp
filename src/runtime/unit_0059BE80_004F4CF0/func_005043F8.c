/* compiler: ee-gcc2.9-991111 */
extern int D_005A4118;

unsigned int func_005043F8(void) {
    if (D_005A4118 < 0)
        return 0x80008001;
    return *(volatile unsigned int *)0x10001010 & 3;
}

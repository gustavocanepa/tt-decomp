/* compiler: ee-gcc2.9-991111 */
extern char *func_004DA008(void);
extern int func_004D5118(char *p, int size, int flag);

int func_004D2978(void) {
    char *p = func_004DA008();
    if ((int)p & 3)
        return -1;
    while (func_004D5118(p, 0x10, 1) >= 0)
        p += 0x20;
    return 0;
}

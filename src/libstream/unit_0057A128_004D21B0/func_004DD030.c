/* compiler: ee-gcc2.9-991111 */
typedef struct {
    int used;
    char pad[0x330];
} Slot;

extern int D_005A0D10;
extern Slot D_007869D0[16];

int func_004DD1A0(int index);

int func_004DD030(void)
{
    int i;
    int r;

    D_005A0D10 = 0;
    for (i = 0; i < 16; i++) {
        if (D_007869D0[i].used) {
            r = func_004DD1A0(i);
            if (r < 0)
                return r;
        }
    }
    return 1;
}

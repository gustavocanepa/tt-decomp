typedef int s32;
typedef unsigned char u8;

extern char D_005CA040[];
/* Returns this, so the next temporary avoids $v0 as in the original. */
char *func_003227F8(char *self);

void func_00326068(char *arg0) {
    char *a1;

    func_003227F8(arg0);
    a1 = arg0 + 0x300;
    *(s32 *)arg0 = (s32)D_005CA040;
    *(u8 *)a1 = 0;
    *(u8 *)(a1 + 1) = 0;
    *(s32 *)a1 = *(s32 *)a1 & 0xFF00FFFF;
    *(u8 *)(a1 + 3) = 0;
    *(s32 *)(arg0 + 0x304) = -1;
}

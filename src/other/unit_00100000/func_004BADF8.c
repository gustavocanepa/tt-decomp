typedef int s32;

extern void func_004FB6E8(s32);

s32 func_004BADF8(s32 unused, s32 arg) {
    if (*(volatile s32 *)0x10002010 & 0x4000)
        func_004FB6E8(arg);
    __asm__ volatile("sync
	ei");
    return 0;
}

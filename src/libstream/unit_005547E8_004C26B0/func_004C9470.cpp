/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;

struct AudioTransferState {
    int argumentForContextWait;
    u8 unknown04[0x3C];
    u8 payload[0x3B8];
    int dirty;
};

extern AudioTransferState D_00779680;
extern u8 D_00779E80[];

extern "C" void func_004F4348(int argument);
extern "C" int func_005038D8(void);
extern "C" int func_004F45D8(AudioTransferState *, int, int, const void *, int);

extern "C" void func_004C9470(const void *source) {
    // The global's first word is passed through to this helper; its role is unknown.
    func_004F4348(D_00779680.argumentForContextWait);
    int interruptsWereEnabled = func_005038D8();
    __builtin_memcpy(D_00779680.payload, source, 0x3B8);
    if (interruptsWereEnabled != 0) {
        __asm__ volatile("ei" ::: "memory");
    }
    D_00779680.dirty = 1;
    func_004F45D8(&D_00779680, 4, 1, D_00779E80, 0x80);
}

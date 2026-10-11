typedef struct Slot {
    char pad0[0x64];
    int pending;
    char pad68[0x4];
} Slot;

typedef struct Port {
    char pad0[0xC];
    Slot slots[4];
} Port;

typedef struct State {
    char pad0[0x6C];
    Port ports[1];
} State;

extern State *D_0059834C;
int func_005038D8(void);

int func_004B8228(int n) {
    int enabled = func_005038D8();
    int port = n / 4;
    int slot = n % 4;
    Slot *s = &D_0059834C->ports[port].slots[slot];
    int v = s->pending;
    s->pending = 0;
    if (enabled)
        __asm__ volatile("ei");
    return v;
}

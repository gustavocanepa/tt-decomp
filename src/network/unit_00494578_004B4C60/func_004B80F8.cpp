/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Port { char pad[0x70]; int count; char tail[0x1bc-0x74]; };
struct State { Port ports[2]; };
extern State *D_0059834C;
extern "C" int func_005038D8(void);
extern "C" int func_004B80F8(int n) {
    State *state = D_0059834C;
    int enabled = func_005038D8();
    int result = 0;
    int port = n / 4;
    if (n < 8) {
        Port *entry = (Port *)((char *)state + port * 0x1bc);
        result = n % 4 < entry->count;
    }
    if (enabled) __asm__ volatile("ei");
    return result;
}

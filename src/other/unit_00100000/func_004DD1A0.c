/* compiler: ee-gcc2.9-991111 */
typedef struct Port {
    int state;
    int unk4;
    int unk8;
    int unkC;
    char pad[0x334 - 0x10];
} Port;

extern Port D_007869D0[];
extern int func_004DDF58(int port);

int func_004DD1A0(int port) {
    int r = func_004DDF58(port);
    if (r < 0)
        return r;
    D_007869D0[port].state = 0;
    D_007869D0[port].unk4 = 0;
    D_007869D0[port].unkC = 0;
    return 1;
}

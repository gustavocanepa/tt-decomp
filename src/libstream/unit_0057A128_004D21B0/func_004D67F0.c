/* compiler: ee-gcc2.9-991111 */
typedef struct Ctx {
    int unk0;
    int unk4;
    int doneSema;
    int idleSema;
    int request;
} Ctx;

extern Ctx D_00782900;
extern int func_004FA740(void);
extern int func_004D6848(int);
extern int func_004FA840(int);

void func_004D67F0(void *arg) {
    for (;;) {
        func_004FA740();
        if (func_004D6848(D_00782900.request)) {
            D_00782900.request = 0;
            func_004FA840(D_00782900.doneSema);
        } else {
            func_004FA840(D_00782900.idleSema);
        }
    }
}

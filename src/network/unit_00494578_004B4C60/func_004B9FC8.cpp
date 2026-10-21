/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Wait { Wait *next; int thread; int result; };
struct State { char pad[0x49c]; int active; int result; Wait *head; };
extern State *D_0059834C;
extern "C" int func_004FA710(void);
extern "C" void func_004FA740(void);
extern "C" int func_005038D8(void);
extern "C" int func_004B9FC8(void) {
    Wait wait;
    State *s = D_0059834C;
    int enabled = func_005038D8();
    int sleeping = 0;
    if (s->active) {
        wait.next = s->head;
        wait.thread = func_004FA710();
        sleeping = 1;
        s->head = &wait;
    } else {
        wait.result = s->result;
    }
    if (enabled) { __asm__ volatile("ei"); }
    if (sleeping) func_004FA740();
    return wait.result;
}

/* compiler: ee-gcc2.9-991111 */
struct State {
    int pad0[2];
    int active;
    int pad1;
    int count;
};
extern volatile struct State D_005A4110;

int func_00504CA8(int *used, int *func_00575DA0)
{
    volatile struct State *s = &D_005A4110;
    if (s->active < 0)
        return 0x80008001;
    if (used)
        *used = s->count;
    if (func_00575DA0)
        *func_00575DA0 = 0x80 - s->count;
    return 0;
}

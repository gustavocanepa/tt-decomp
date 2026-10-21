/* compiler: ee-gcc2.9-991111 */
extern int D_005A0BB0;
struct Result { char pad[12]; int value; };
extern struct Result *func_004D9E48(void *addr);
int func_004D4560(void *addr) {
    int result;
    struct Result *p;
    if (!D_005A0BB0) return 0x81058001;
    result = 0x8105902D;
    p = func_004D9E48(addr);
    if (p) result = p->value;
    return result;
}

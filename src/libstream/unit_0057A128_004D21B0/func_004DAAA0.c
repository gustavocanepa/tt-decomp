/* compiler: ee-gcc2.9-991111 */
extern short D_005A0BC8;
int func_004DA960(void);
void func_004FA8D0(void *);
int func_004DAAA0(void) {
    int status[4];
    int result;
    if (func_004DA960()) {
        result = D_005A0BC8;
    } else {
        func_004FA8D0(status);
        result = status[0] >> 21;
        if (((unsigned int)status[0] >> 13 & 7) == 0) result = 540;
    }
    return result;
}

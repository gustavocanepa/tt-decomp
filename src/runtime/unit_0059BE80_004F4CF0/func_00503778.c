/* compiler: ee-gcc2.9-991111 */
int func_004FAC30(int);
void func_004FACA0(void);
void func_00505AD0(int, int);

int func_00503778(void) {
    if (func_004FAC30(4) & 0x40000) {
        func_004FACA0();
        func_00505AD0(1, 1);
        func_00505AD0(0, 1);
        return 1;
    }
    return 0;
}

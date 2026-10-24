/* compiler: ee-gcc2.9-991111 */
extern int func_005039B0(void *, const void *, unsigned int);
extern int *D_005A3180;
int func_00503A48(int index) {
    int value;
    func_005039B0(&value, D_005A3180 + index, 4);
    return value;
}

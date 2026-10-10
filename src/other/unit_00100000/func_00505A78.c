/* compiler: ee-gcc2.9-991111 */
typedef struct {
    int m0;
    int pad[3];
} Entry_005B9448;

extern Entry_005B9448 D_00791BC8[];
extern Entry_005B9448 *D_005A4130;
extern unsigned int D_005A4134;

int func_00505A78(int id) {
    Entry_005B9448 *table;
    unsigned int count;
    if (id < 0) {
        id &= 0x7FFFFFFF;
        table = D_00791BC8;
        count = 0x20;
    } else {
        table = D_005A4130;
        count = D_005A4134;
    }
    if ((unsigned int)id >= count) {
        return -0x69;
    }
    table[id].m0 = 0;
    return 0;
}

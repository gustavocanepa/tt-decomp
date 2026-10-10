typedef unsigned char u8;

struct B {
    char pad[0x20B00];
    u8 cell[2][6];
};

extern "C" u8 func_003A1268(struct B *arg0, int row, int col) {
    return arg0->cell[row][col];
}

/* compiler: ee-gcc2.9-991111 */
typedef struct {
    char pad0[0xC];
    int size;
    char pad10[0x20];
    int pos;
} File_0058A208;

extern File_0058A208 D_00782940;

int func_004D8E48(int fd, void *unused, int offset, int whence) {
    int base = 0;
    switch (whence) {
    case 0:
        base = 0;
        break;
    case 1:
        base = D_00782940.pos;
        break;
    case 2:
        base = D_00782940.size;
        break;
    }
    base += offset;
    if (D_00782940.size < base) {
        base = D_00782940.size;
    }
    D_00782940.pos = base;
    return base;
}

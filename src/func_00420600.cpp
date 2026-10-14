/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S {
    char pad0[0x1c];
    unsigned short cols, rows;
    char p20[0xC];
    unsigned char count;
    unsigned char cur;
    char p2e[0x12];
    int sel;
    void ***grid;
    char p48[0x18];
    int *table;
};
extern "C" void func_00466CA0(void *, int);

extern "C" void func_00420600(S *self, int idx)
{
    if (idx != self->cur && idx < self->count) {
        self->cur = idx;
        self->sel = self->table[idx];
        if (self->grid != 0) {
            int rows = self->rows;
            int row = 0;
            if (rows) {
                do {
                    unsigned off = row * 4;
                    if (*(void ***)(off + (unsigned)self->grid)) {
                        int col = 0;
                        int cols = self->cols;
                        if (cols) {
                            do {
                                unsigned inner = col * 4;
                                ++col;
                                void *e = *(void **)(inner + (unsigned)*(void ***)(off + (unsigned)self->grid));
                                if (e) {
                                    func_00466CA0(e, idx);
                                    cols = self->cols;
                                }
                            } while (col < cols);
                            rows = self->rows;
                        }
                    }
                    ++row;
                } while (row < rows);
            }
        }
    }
}

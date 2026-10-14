/* compiler: ee-gcc2.96-no-strict-aliasing */
struct S {
    char pad[0x1c];
    unsigned short cols, rows;
    char p[0x24];
    void ***grid;
};
extern "C" void func_00466F88(void *, float, int);

extern "C" void func_004200F8(S *self, float t, int arg)
{
    unsigned short rows = self->rows;
    int row = 0;
    if (rows) {
        do {
            unsigned off = row * 4;
            if (*(void ***)(off + (unsigned)self->grid)) {
                int col = 0;
                if (self->cols) {
                    do {
                        unsigned inner = col * 4;
                        ++col;
                        func_00466F88(*(void **)(inner + (unsigned)*(void ***)(off + (unsigned)self->grid)), t, arg);
                    } while (col < self->cols);
                    rows = self->rows;
                }
            }
            ++row;
        } while (row < rows);
    }
}

struct Obj;

extern "C" void func_00466F18(Obj *o);

struct Obj {
    char pad0[0x1C];
    unsigned short n2;      /* 0x1C */
    unsigned short n1;      /* 0x1E */
    char pad1[0x44 - 0x20];
    Obj ***tbl;             /* 0x44 */
};

extern "C" void ModelSet2__DMAsafe(Obj *arg0)
{
    int i;
    int j;

    for (i = 0; i < arg0->n1; i++) {
        if (arg0->tbl[i] != 0) {
            for (j = 0; j < arg0->n2; j++) {
                func_00466F18(arg0->tbl[i][j]);
            }
        }
    }
}

struct func_00315018_Obj {
    char pad[0x566];
    unsigned char kind;
};

extern "C" int func_00315018(func_00315018_Obj *self) {
    switch (self->kind) {
    case 0:
    case 2:
        return 0;
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
        return 1;
    default:
        return 0;
    }
}

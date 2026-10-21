struct func_00356230_Obj {
    char pad[0x1C];
    int state;
};

extern "C" int func_003542A0(func_00356230_Obj *self, int dir);

extern "C" int func_00356230(func_00356230_Obj *self, int delta) {
    switch (self->state) {
    case 1:
    case 2:
    case 17:
    case 19:
        return func_003542A0(self, delta >= 0 ? 1 : 2);
    case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
    case 11: case 12: case 13: case 14: case 15: case 16:
        return -1;
    default:
        return -1;
    }
}

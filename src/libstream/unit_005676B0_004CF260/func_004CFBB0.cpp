struct S { char pad0[8]; int mode; char pad1[0x24]; int first[2][2], second[2][2]; int timing[2][2]; };
extern "C" int func_004CC568(int);
extern "C" void func_004CFA88(S *, int *, int, int);
extern "C" int func_004CFBB0(S *self, int i, int a, int b) {
    if (self->mode == 1) {
        func_004CFA88(self, self->first[i], a, b);
        self->second[i][0] = self->first[i][0];
        self->second[i][1] = self->first[i][1];
    } else {
        self->timing[0][i] = func_004CC568(1);
        func_004CFA88(self, self->first[i], a, b);
        self->timing[1][i] = func_004CC568(1);
        func_004CFA88(self, self->second[i], a, b);
    }
    return 0;
}

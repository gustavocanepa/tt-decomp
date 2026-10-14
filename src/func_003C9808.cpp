/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub { char p0[4]; int f4; int f8; int fC; int f10; };
struct LC {
    char p0[4];
    Sub *f4;
    char p8[0xC];
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    int f28;
    char p2C[0x10];
    char m3C[0x3C];
    int f78;
    int f7C;
    int f80;
};
struct Player { char p[0x10]; };
extern "C" int func_002F04D8(int, int);
extern "C" unsigned short func_0034AEE8(char *);
extern "C" void Concourse__init(LC *, int) throw();
extern "C" void func_003C8800(LC *, int, const char *) throw();
extern "C" void LicenseConcourse__Camera__init(void *, int, int) throw();
extern "C" void func_003C9630(LC *, int, char *, int) throw();
extern "C" void func_003C9758(LC *, int) throw();
extern "C" void func_003C97B0(LC *, float) throw();
extern "C" Player *func_003EEC90(Player *);
extern "C" void func_003EECA0(Player *, int, int);
extern "C" int GT4_Motion__MotionSetPlayer__getSkinningBufferSize(Player *);
extern "C" int func_004A4690(int, int);

extern "C" void LicenseConcourse__init(LC *self, int arg1, char *arg2) {
    Player pl;
    Concourse__init(self, 3);
    self->f14 = 0;
    self->f18 = 0;
    self->f1C = 0;
    self->f20 = 0;
    self->f24 = 0;
    self->f28 = 0;
    LicenseConcourse__Camera__init(self->m3C, self->f4->f8, 0);
    self->f78 = 0;
    self->f7C = 0;
    int n = func_0034AEE8(arg2);
    if (n > 0) {
        self->f18 = 1;
        if (n >= 2) {
            func_003C9630(self, 1, arg2, func_002F04D8(arg1, 0));
            self->f1C = 1;
        } else {
            func_003C9630(self, 0, arg2, func_002F04D8(arg1, 0));
        }
        func_003C97B0(self, 0.94f);
        func_003C9758(self, -1);
        func_003C8800(self, 0, "license_stand_master");
        func_003C8800(self, 1, "license_stand_staff_1");
        func_003C8800(self, 2, "license_stand_staff_2");
        if (self->f80 == 0) {
            func_003EEC90(&pl);
            func_003EECA0(&pl, self->f4->fC, self->f4->f4);
            int a = GT4_Motion__MotionSetPlayer__getSkinningBufferSize(&pl);
            func_003EECA0(&pl, self->f4->f10, self->f4->f4);
            int b = GT4_Motion__MotionSetPlayer__getSkinningBufferSize(&pl);
            self->f80 = func_004A4690(0x40, b < a ? a : b);
        }
    }
}

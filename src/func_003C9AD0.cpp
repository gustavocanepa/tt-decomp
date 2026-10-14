/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub { char p0[8]; int f8; };
struct LC {
    char p0[4];
    Sub *f4;
    char p8[0xC];
    int f14;
    int pad18;
    int f1C;
    float f20;
    int f24;
    int f28;
    char p2C[0x10];
    char m3C[0x38];
    int f74;
};
extern "C" int func_002F04D8(int, int);
extern "C" void func_003C8800(LC *, int, const char *) throw();
extern "C" void LicenseConcourse__Camera__init(void *, int, const char *) throw();
extern "C" void func_003C9630(LC *, int, int, int) throw();
extern "C" void func_003C9758(LC *, int) throw();
extern "C" float func_003CA100();
extern "C" float func_003CA110();

extern "C" void LicenseConcourse__update_mode(LC *self, int a1, int a2, float dt) {
    int st = self->f24;
    self->f28 = st;
    switch (st) {
    case 0:
        self->f20 = self->f20 + dt;
        if (self->f20 >= 2.0f) {
            self->f24 = 1;
            self->f20 = 0.0f;
        }
        break;
    case 1:
        self->f20 = self->f20 + dt;
        if (func_003CA100() <= self->f20) {
            self->f20 = 0.0f;
            self->f24 = 2;
            func_003C9630(self, 0, a2, func_002F04D8(a1, 0));
            self->f1C = st;
            if (self->f14 == st) {
                func_003C8800(self, 0, "license_success_master");
                func_003C8800(self, 1, "license_success_staff_1");
                func_003C8800(self, 2, "license_success_staff_2");
            } else if (self->f14 == 2) {
                func_003C8800(self, 0, "license_failed_master");
                func_003C8800(self, 1, "license_failed_staff_1");
                func_003C8800(self, 2, "license_failed_staff_2");
            }
            switch (self->f74) {
            case 0:
                LicenseConcourse__Camera__init(self->m3C, self->f4->f8, "license_cam01_seq");
                break;
            case 1:
                LicenseConcourse__Camera__init(self->m3C, self->f4->f8, "license_cam02_seq");
                break;
            case 2:
            default:
                LicenseConcourse__Camera__init(self->m3C, self->f4->f8, "license_cam03_seq");
                break;
            }
            self->f74 = self->f74 + 1;
            self->f74 = self->f74 % 3;
            func_003C9758(self, 0);
        }
        break;
    case 2:
        self->f20 = self->f20 + dt;
        if (func_003CA110() <= self->f20) {
            self->f20 = 0.0f;
            self->f24 = 3;
        }
        break;
    }
}

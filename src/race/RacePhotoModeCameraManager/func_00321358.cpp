/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;

struct Cam {
    char pad0[0x28];
    u8 b28;
    u8 b29;
    u8 b2A;
    u8 b2B;
};
struct Sub {
    char pad[4];
};
struct Input {
    int mode;
    int flag;
    int out;
};
struct Obj {
    char pad0[0xEA8];
    Cam cam;
    char padDD4[0xF00 - 0xEA8 - sizeof(Cam)];
    Sub sub;
    char padE2C[0x1008 - 0xF00 - sizeof(Sub)];
    int state;
};

extern "C" void func_003187A8(Sub *, Cam *) throw();
extern "C" void func_00318FD0(Sub *, Cam *) throw();
extern "C" void func_00319228(Sub *) throw();
extern "C" void func_00319260(Sub *);
extern "C" void func_003192B8(Sub *) throw();
extern "C" int func_003192E0(Sub *) throw();
extern "C" void func_003192F0(Sub *, Cam *);
extern "C" void func_00319570(Sub *) throw();
extern "C" void func_003195D8(Sub *) throw();
extern "C" void func_003195F8(Sub *) throw();
extern "C" int func_00319650(Sub *) throw();
extern "C" void func_003A5F88(Cam *, int);

extern "C" void func_00321358(Obj *self, int a1, int a2, Input *in) {
    Cam *cam = &self->cam;
    int moved = 0;
    Sub *sub = &self->sub;
    int mode = in->mode;
    if (in->flag != 0) {
        self->state = 1;
        if (mode == 2)
            func_00319228(sub);
        else
            func_00319570(sub);
    }
    func_003A5F88(cam, 1);
    int st = self->state;
    switch (st) {
    case 1:
        if (cam->b28 != 0) {
            if (mode == 2) {
                if (func_003192E0(sub) != 0) {
                    func_00319260(sub);
                    self->state = mode;
                }
            } else {
                if (func_00319650(sub) != 0) {
                    func_003195D8(sub);
                    self->state = 2;
                }
            }
            moved = 1;
        }
        if (cam->b2A != 0) {
            self->state = 3;
            if (mode == 2)
                func_003192B8(sub);
            else
                func_003195F8(sub);
            moved = 1;
        }
        break;
    case 2:
    case 3:
        moved = 1;
        if ((cam->b29 == 0) & (cam->b2B == 0)) {
            self->state = 0;
            in->out = moved;
        }
        break;
    }
    if (moved != 0) {
        func_003187A8(sub, cam);
        return;
    }
    if (mode == 2) {
        func_00318FD0(sub, cam);
        return;
    }
    func_003192F0(sub, cam);
}

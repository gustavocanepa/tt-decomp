/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

struct Limits {
    char pad0[0x28];
    f32 min_x;
    f32 min_y;
    f32 max_x;
    f32 max_y;
    char pad38[0x14];
    f32 lo_x;
    f32 lo_y;
    f32 hi_x;
    f32 hi_y;
};
struct Info { char pad0[0xCC]; Limits *limits; };
struct Owner { char pad0[4]; Info *info; };
struct Input { char pad0[0x30]; f32 move_x; f32 move_y; f32 turn; };
struct Cam {
    Owner *owner;
    char pad4[0x18];
    f32 unk1C;
    char pad20[0x8];
    f32 unk28[3];
    f32 x;
    f32 z38;
    f32 y;
    int unk40;
    char unk44[0x3C];
};

extern "C" f32 func_00318728(Cam *) throw();
extern "C" f32 func_00318B48(Input *, f32, f32) throw();
extern "C" f32 func_003188C8(Cam *, f32) throw();
extern "C" f32 func_00318908(Cam *, f32) throw();
extern "C" f32 func_00318000(void *, int, f32) throw();
extern "C" void func_00318E60(Cam *, f32, f32) throw();
extern "C" void func_00552A68(void *, void *);
extern "C" int func_003AA138(f32 *, Owner *, f32);

extern "C" void func_00318FD0(Cam *self, Input *in)
{
    f32 speed = 6.0f;
    Limits *lim = self->owner->info->limits;
    f32 my;
    f32 mx;
    f32 gx;
    f32 gy;
    f32 min_x;
    f32 max_x;
    f32 min_y;
    f32 max_y;
    f32 s;
    f32 tmp[4];
    int r;

    self->unk1C = func_00318B48(in, self->unk1C, func_00318728(self));
    my = in->move_y;
    mx = in->move_x;
    gx = func_003188C8(self, speed);
    gy = func_00318908(self, speed);
    min_x = lim->min_x;
    max_x = lim->max_x;
    min_y = lim->min_y;
    max_y = lim->max_y;
    if (max_x <= min_x || max_y <= min_y) {
        min_x = -500.0f;
        max_x = 500.0f;
        min_y = min_x;
        max_y = max_x;
    }
    if (min_x < lim->lo_x)
        min_x = lim->lo_x;
    if (lim->hi_x < max_x)
        max_x = lim->hi_x;
    if (min_y < lim->lo_y)
        min_y = lim->lo_y;
    if (lim->hi_y < max_y)
        max_y = lim->hi_y;
    {
        int moving = 0;
        if (my != 0.0f || mx != 0.0f)
            moving = 1;
        s = func_00318000(self->unk44, moving, 1.0f);
    }
    {
        f32 *px = &self->x;
        f32 *py;
        mx *= s;
        my *= s;
        *px += mx * gx;
        self->z38 = 0;
        py = &self->y;
        *py += my * gy;
        if (*px <= min_x)
            *px = min_x;
        if (max_x <= *px)
            *px = max_x;
        if (*py <= min_y)
            *py = min_y;
        if (max_y <= *py)
            *py = max_y;
        func_00318E60(self, *px, *py);
        func_00552A68(px, self->unk28);
        func_00552A68(px, tmp);
    }
    r = func_003AA138(tmp, self->owner, func_00318908(self, 24.0f));
    if (r >= 0)
        func_00552A68(tmp, self->unk28);
    self->unk40 = r;
}

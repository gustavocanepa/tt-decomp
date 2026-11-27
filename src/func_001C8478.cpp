/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Tex;
struct Rect { char pad0[0x8]; s32 width; };
struct Jitter { f32 x; f32 y; };

extern "C" void func_00104C88(Tex *) throw();
extern "C" void func_00104D10(Rect *) throw();
extern "C" s32 func_00104E00(Rect *) throw();
extern "C" void func_0046F0F8(s32);
extern "C" void func_004702D8(s32, f32);
extern "C" void func_00472268(s32, s32);
extern "C" void func_00472528(s32, s32, s32);
extern "C" void func_00474318(f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void func_00474520(f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void func_00477E30(f32, f32, f32, f32);
extern "C" void func_00478C98(s32);

/* Four sub-pixel offsets of the accumulation passes. */
extern Jitter D_005E8E70[4];

/* Draws the texture once at full weight, then blends four jittered copies over it with
   weights 2/5, 2/7, 2/9, 2/11; the strips a positive offset uncovers at the left and top
   edges are filled with the texture's first texel column / row. */
extern "C" void func_001C8478(Tex *tex, Rect *r) {
    f32 one = 1.0f;
    s32 w = r->width;
    s32 h = func_00104E00(r);
    func_00104D10(r);
    func_00104C88(tex);
    f32 fw = (f32)w;
    func_00472268(4, 2);
    f32 fh = (f32)h;
    func_00472268(5, 2);
    f32 zero = 0.0f;
    func_00472528(0, 0, w - 1);
    f32 weight = 3.0f;
    func_00472528(1, 0, h - 1);
    func_00478C98(5);
    func_00478C98(6);
    func_00477E30(one, one, one, one);
    func_00474318(zero, zero, fw, fh, zero, zero, fw, fh);
    func_00477E30(1.0f, 1.0f, 1.0f, 1.0f);
    func_0046F0F8(6);
    for (s32 i = 0; i < 4; i++) {
        f32 next = weight + 2.0f;
        weight = next;
        func_004702D8(100, 2.0f / next);
        f32 x = D_005E8E70[i].x;
        f32 y = D_005E8E70[i].y;
        func_00474520(x, y, (f32)(w + 1) + x, (f32)(h + 1) + y, 0.0f, 0.0f, (f32)(w + 1), (f32)(h + 1));
        if (0.0f < x) {
            func_00474318(0.0f, 0.0f, x, (f32)h, 0.0f, 0.0f, 1.0f, (f32)h);
        }
        if (0.0f < y) {
            func_00474318(0.0f, 0.0f, (f32)w, y, 0.0f, 0.0f, (f32)w, 1.0f);
        }
    }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Color { f32 r; f32 g; f32 b; f32 a; };
struct Sample { s32 a; s32 b; };
struct Wave { Sample data[2][0x4000]; s32 counts[2]; f32 step; };
struct Self { char pad[0x2B4]; Wave *wave; char pad2b8[0x2D4 - 0x2B8]; f32 start; char pad2d8[4]; f32 end; };
struct Chan { char pad[0x1D0]; s32 hidden; };

extern "C" s32 func_0011C7B0(Self *, s32);
extern "C" Chan *func_0011C628(s32);
extern "C" void func_0046D810(s32, void *, void *, void *, s32, s32);
extern "C" f32 *func_00473980(s32);
extern "C" s32 func_00477D28(f32, f32, f32, f32, f32);

extern "C" void func_0011AA60(Self *self, s32 ch, f32 (*fn)(Sample *), Color *col, f32 y0, f32 scale) {
    if (func_0011C7B0(self, ch) == 0) return;
    if (func_0011C628(ch)->hidden != 0) return;
    {
        Wave *wave = self->wave;
        f32 step = wave->step;
        f32 s = self->start;
        f32 e = self->end;
        f32 inv = 1.0f / step;
        s32 count = wave->counts[ch];
        s32 lo = (s32)(s * inv) - 1;
        s32 hi = (s32)(e * inv) + 1;
        if (lo < 0) lo = 0;
        if (!(hi < count)) hi = count - 1;
        f32 fl = (f32)lo * step;
        f32 fh = (f32)hi * step;
        if (e < fl) return;
        if (fh < s) return;
        {
            s32 diff = hi - lo;
            s32 stride = 1;
            if (diff >= 0x3E9) {
                f32 st0 = step;
                do {
                    stride++;
                    step += st0;
                } while (diff / stride >= 0x3E9);
            }
            f32 r = col->r;
            f32 g = col->g;
            f32 b = col->b;
            f32 a = col->a;
            f32 x = fl;
            s32 i;
            s32 n = 0;
            s32 col0 = func_00477D28(r, g, b, a, 128.0f);
            f32 *v = func_00473980(0x30);
            s32 *c = (s32 *)func_00473980(0x10);
            Sample *src = wave->data[ch];
            for (i = lo; i <= hi; i += stride) {
                f32 val = fn(&src[i]);
                f32 y = y0 + val * scale;
                s32 col1 = func_00477D28(r, g, b, a, val * 127.0f + 128.0f);
                v[n * 3] = x;
                v[n * 3 + 3] = x;
                v[n * 3 + 1] = y;
                v[n * 3 + 2] = 0.0f;
                v[n * 3 + 4] = y0;
                v[n * 3 + 5] = 0.0f;
                c[n] = col1;
                c[n + 1] = col0;
                n += 2;
                if (n == 0x40) {
                    func_0046D810(n, v, 0, c, 0, 0);
                    v = func_00473980(0x30);
                    c = (s32 *)func_00473980(0x10);
                    v[0] = x;
                    v[3] = x;
                    v[1] = y;
                    v[2] = 0.0f;
                    v[4] = y0;
                    v[5] = 0.0f;
                    c[0] = col1;
                    c[1] = col0;
                    n = 2;
                }
                x += step;
            }
            if (n >= 4) func_0046D810(n, v, 0, c, 0, 0);
        }
    }
}

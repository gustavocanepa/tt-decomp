struct Fog { float a, b, c, d, e, f; int enabled; };
struct Scene { char pad[0xE3B8]; Fog fog; };

extern "C" void func_002D07B8(Scene *s, float a, float b, float c, float d, float e, float f)
{
    s->fog.a = a;
    s->fog.b = b;
    s->fog.c = c;
    s->fog.d = d;
    s->fog.e = e;
    s->fog.f = f;
    s->fog.enabled = 1;
}

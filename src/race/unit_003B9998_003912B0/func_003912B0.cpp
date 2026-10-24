struct Self { int a; float x,y; int b,c,w,h,flags; };
extern "C" int func_003912B0(Self *s) {
    s->a = 0;
    s->x = 1.0f;
    s->y = 1.0f;
    s->b = 0;
    s->c = 1;
    s->w = 0x140;
    s->h = 0x70;
    s->flags &= ~0xFF;
}

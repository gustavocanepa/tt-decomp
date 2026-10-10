struct Widget {
    void *ctx;
    int pad4[3];
    int x, y, w, h;
};

extern "C" void func_004780F8(Widget *w);
extern "C" int GSBuffer__getBufferWidth(Widget *w);
extern "C" void func_00472E80(void *ctx, int a, int color, int x0, int y0, int x1, int y1, int b);

extern "C" void func_00104FE0(Widget *wd, int b, int a)
{
    func_004780F8(wd);
    func_00472E80(wd->ctx, a, GSBuffer__getBufferWidth(wd), wd->x, wd->y, wd->x + wd->w, wd->y + wd->h, b);
}

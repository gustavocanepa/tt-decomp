struct View {
    int target;
    char pad[0xC];
    int x, y, w, h;
};

extern "C" int GSBuffer__getBufferWidth(View *v);
extern "C" void func_00472C50(int target, int a, int b, int x0, int y0, int x1, int y1, int c);
extern "C" void func_0046FB08(int n);

extern "C" void func_00105050(View *v, int c, int a)
{
    func_00472C50(v->target, a, GSBuffer__getBufferWidth(v), v->x, v->y, v->x + v->w, v->y + v->h, c);
    func_0046FB08(1);
}

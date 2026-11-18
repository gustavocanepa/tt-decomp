/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { int a; int b; float w; int pad[3]; };
struct Ent { int f0; char data[0x300]; };
struct List { int count; int p4; int *arr; };
struct Self { char p[0x60]; List *list; };
extern "C" void func_003CAF78(Self *, void *) throw();
extern "C" int func_0040D3D8(void *, int);
extern "C" int func_0040D420(void *);
extern "C" float func_005357F8(int);

extern "C" void func_003CB2D0(Self *self, int arg1) {
    Ent buf[6];
    int n = self->list->count;
    int j;
    for (j = 0; j < n; j++) {
        char *e = (char *)self->list->arr[j] + 0xFD8;
        if (func_0040D420(e) == -1) {
            func_003CAF78(self, buf);
            Rec *r = (Rec *)buf[j].data;
            int c = r[0].a - 1;
            int i = 0;
            while (i < c) {
                if (func_005357F8(arg1) < r[i].w) break;
                i++;
            }
            Rec *selected = r + i;
            func_0040D3D8(e, selected->b);
        }
    }
}

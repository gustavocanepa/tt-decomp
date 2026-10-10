struct Pair { int a; int b; };
struct Key { int a; int b; int c; int d; };
struct Result { int w[6]; };

extern "C" Result func_0047DD30(int x, int y, const Key *k, int z);

extern "C" Result func_0047DCA0(int x, int y, const Pair *p, int z) {
    Key k;
    k.a = p->a;
    k.b = p->b;
    k.c = 0;
    k.d = 0;
    return func_0047DD30(x, y, &k, z);
}

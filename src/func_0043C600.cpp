/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { float a, b; };
struct Q { float a, b; int mode; };
extern "C" int func_0043C508(Q *, float, float, float, float, float, float) throw() __attribute__((const));

extern "C" int func_0043C600(Q *q, char *a, char *b) {
    if (a == 0 || b == 0) return 1;
    {
        {
            int m = q->mode;
            a += 0x90;
            b += 0x90;
            V *pa = (V *)a;
            V *pb = (V *)b;
            switch (m) {
            case 0:
                return func_0043C508(q, -pa->b, pa->a, -pb->b, pb->a, -q->b, q->a);
            case 1:
                return func_0043C508(q, pa->b, -pa->a, pb->b, -pb->a, q->b, -q->a);
            case 2:
                return func_0043C508(q, pa->a, pa->b, pb->a, pb->b, q->a, q->b);
            case 3:
                return func_0043C508(q, -pa->a, -pa->b, -pb->a, -pb->b, -q->a, -q->b);
            default:
                return 0;
            }
        }
    }
}

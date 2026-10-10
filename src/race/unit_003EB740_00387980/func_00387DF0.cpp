struct Query {
    float value;
    int pad4[3];
    int m10;
    int m14;
    int pad18[2];
};

struct State {
    int id;
    float value;
};

extern "C" void func_003EEC70(Query *q, int id, float cur, float x);
extern "C" int func_003F1200(void *ctx, Query *q);

extern "C" void func_00387DF0(State *s, void *ctx, int arg, float x) {
    if (ctx && s->id >= 0) {
        Query q;
        func_003EEC70(&q, s->id, s->value, x);
        q.m10 = 0;
        q.m14 = arg;
        if (func_003F1200(ctx, &q))
            s->value = q.value;
    }
}

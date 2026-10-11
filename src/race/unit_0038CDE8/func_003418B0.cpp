struct State {
    char pad[0x38];
    float base;
    char pad3C[0x88];
    float x;
    float y;
    float z;
};

extern "C" State *func_00341AD8(void *o);

extern "C" float func_003418B0(void *o) {
    if (func_00341AD8(o)->x == 0.0f && func_00341AD8(o)->y == 0.0f && func_00341AD8(o)->z == 0.0f)
        return 0.0f;
    return func_00341AD8(o)->y - func_00341AD8(o)->base;
}

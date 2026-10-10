struct Reader;
extern "C" int func_001F62B0(Reader *r);

extern "C" void func_001F6508(Reader *r, int depth) {
    while (depth == 0) {
        if (func_001F62B0(r) == '{')
            depth++;
    }
    while (depth > 0) {
        int c = func_001F62B0(r);
        if (c == '{')
            depth++;
        if (c == '}')
            depth--;
    }
}

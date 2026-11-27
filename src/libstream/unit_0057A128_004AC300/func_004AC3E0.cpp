/* Look a name up in a table of { value, name } pairs; store the value through `out` when given. */
struct Entry { int value; const char *name; };
struct Table { Entry *entries; unsigned count; };
extern "C" int func_004A8268(const char *, const char *); /* strcmp-like */
extern "C" int func_004AC3E0(Table *t, const char *name, int *out) {
    for (unsigned i = 0; i < t->count; i++) {
        if (func_004A8268(t->entries[i].name, name) == 0) {
            if (out) *out = t->entries[i].value;
            return 1;
        }
    }
    return 0;
}

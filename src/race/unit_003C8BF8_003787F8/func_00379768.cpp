struct List { short pad; unsigned short count; int *items; };
bool func_003796A8(int, int);

bool func_00379768(List *l, int arg) {
    bool r = false;
    for (int i = 0; i < l->count; i++) r ^= func_003796A8(l->items[i], arg);
    return r;
}

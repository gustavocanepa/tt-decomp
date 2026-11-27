struct Info {
    char pad0[0x23968];
    int size;
};

struct Grid {
    Info *info;
    unsigned short cost[6][6];
    unsigned char flag[6][6];
};

extern "C" void func_003D7820(Grid *g) {
    int n = g->info->size;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->cost[i][j] = 0;
            g->flag[i][j] = 0;
        }
    }
}

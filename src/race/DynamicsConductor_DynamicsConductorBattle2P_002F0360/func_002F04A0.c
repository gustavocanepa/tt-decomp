extern unsigned DynamicsConductor__getLimitTime(void);
int func_002F04A0(int x, unsigned i) {
    unsigned n = DynamicsConductor__getLimitTime();
    return n != 0 && i >= n;
}

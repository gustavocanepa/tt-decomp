extern int DynamicsConductor__getCourseType(void);
int func_002F0D10(void) {
    int r = DynamicsConductor__getCourseType();
    if (r == 2) return 1;
    if (r == 3) return 2;
    return 0;
}

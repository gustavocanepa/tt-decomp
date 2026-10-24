/* compiler: ee-gcc2.9-991111 */
extern int D_005A0DA8;
extern volatile int D_005A0DAC;
extern char D_005A2900[], D_005A23C0[], D_005A1F80[], D_005A1F50[], D_005A0E80[], D_005A0E00[];
int func_004DF9E8(int code, int *out) {
    int value;
    if (code != 0x8001) {
        if (code != 0x8003) {
            if (code != 0x8002) {
                if (code != 0x8004) {
                    if (code != 0x8011) {
                        value = code == 0x8013 ? (int)D_005A1F80 :
                                code == 0x8012 ? (int)D_005A23C0 :
                                code == 0x8014 ? (int)D_005A2900 : 0;
                    } else {
                        value = D_005A0DAC;
                        *out = value;
                        goto done;
                    }
                } else value = (int)D_005A1F50;
            } else value = (int)D_005A0E80;
        } else value = (int)D_005A0E00;
    } else value = D_005A0DA8;
    *out = value;
done:
    return 1;
}

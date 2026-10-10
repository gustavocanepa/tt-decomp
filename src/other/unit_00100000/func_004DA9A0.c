/* compiler: ee-gcc2.9-991111 */
struct OsdParam {
    unsigned int spdifMode : 1;
    unsigned int screenType : 2;
    unsigned int videoOutput : 1;
    unsigned int japLanguage : 1;
    unsigned int ps1drvConfig : 8;
    unsigned int version : 3;
    unsigned int language : 5;
    unsigned int timezoneOffset : 11;
};
extern unsigned char D_005A0BCC;
void func_004FA8D0(struct OsdParam *p);
int func_004DA960(void);

int func_004DA9A0(void)
{
    struct OsdParam p;
    int lang;

    func_004FA8D0(&p);
    if (func_004DA960()) {
        lang = D_005A0BCC;
    } else {
        func_004FA8D0(&p);
        if (p.version == 0)
            lang = p.japLanguage;
        else
            lang = p.language;
    }
    return lang;
}

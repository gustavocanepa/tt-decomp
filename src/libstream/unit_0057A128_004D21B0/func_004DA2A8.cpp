/* compiler: ee-gcc2.96-no-strict-aliasing */

typedef struct Extra Extra;
typedef struct Header Header;
typedef struct Info Info;
typedef struct Extra
{
  int word;
  unsigned short half;
} Extra;
typedef struct Header
{
  int pad0;
  int w4;
  int w8;
  int wC;
  int extra;
  int w14;
  int w18;
  int w1C;
  int w20;
  int w24;
  int w28;
  int w2C;
  int w30;
  int w34;
} Header;
typedef struct Info
{
  int tag;
  int extraWord;
  short extraHalf;
  short pad;
  int pad0C;
  int a;
  int b;
  int c;
  int d;
  int e;
  int f;
  int g;
  int h;
  int i;
  int j;
  int k;
  int l;
  int m;
} Info;
extern void func_004DA2A8(Header *h, Info *info)
{
  int new_var;
  char *new_var2;
  int extra;
  info->pad0C = 0;
  info->tag = 0;
  extra = h->extra;
  info->extraWord = 0;
 do { info->extraHalf = 0; info->pad = 0; if (new_var2 = ((char *) extra) + 1) { info->extraWord = ((Extra *) extra)->word; info->extraHalf = ((Extra *) extra)->half; } info->a = h->w4; info->b = h->w8; info->c = h->wC; info->d = h->w14; info->e = h->w18; info->f = h->w4; info->g = h->w1C; info->h = h->w20; info->i = h->w24; new_var = h->w28; info->j = new_var; info->k = h->w2C; info->l = h->w30; } while (0);
  info->m = h->w34;
}

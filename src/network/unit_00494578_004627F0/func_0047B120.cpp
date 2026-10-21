union Key{long value;int words[2];};
struct S{int a,b,c;Key key;int d,e;unsigned char flag;S(const S&) __asm__("func_0047B120");};
S::S(const S&s):a(s.a),b(s.b),c(s.c),key(s.key),d(s.d),e(s.e),flag(s.flag){}

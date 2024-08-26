
#define CTextScope(s,t)\
ctext_open(s, t);\
for(int snaunduwwqwetjsdvda = 0; snaunduwwqwetjsdvda < 1; ctext_close(s, t), ++snaunduwwqwetjsdvda)

#define CTextScope_format(s,t, ...)\
CTextStack_open_format(s,t,__VA_ARGS__);\
for(int snaunduwwqwetjsdvda = 0; snaunduwwqwetjsdvda < 1; ctext_close(s, t), ++snaunduwwqwetjsdvda)

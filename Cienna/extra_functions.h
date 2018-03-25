#ifndef EXTRA_FUNCTIONS_H_INCLUDED
#define EXTRA_FUNCTIONS_H_INCLUDED

//nest four functions are for comparing strings without case sensitivity.
inline bool caseInsCharCompareN(char a, char b);
inline bool caseInsCharCompareW(wchar_t a, wchar_t b);
bool caseInsCompare(const string& s1, const string& s2);
bool caseInsCompare(const wstring& s1, const wstring& s2);

int number_check(char *word);
int strcasestr(char*,char*);
char* word_char_remove(char*,int,int);
int getDayNumber(int dd,int mm,int yy);

#endif // EXTRA_FUNCTIONS_H_INCLUDED

#include <string>
#include<string.h>
#include<stdio.h>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cwctype>
#include<sstream>

using namespace std;

inline bool caseInsCharCompareN(char a, char b)
{
   return(toupper(a) == toupper(b));
}

inline bool caseInsCharCompareW(wchar_t a, wchar_t b)
{
   return(towupper(a) == towupper(b));
}

bool caseInsCompare(const string& s1, const string& s2)
{

   return((s1.size() == s2.size()) &&
            equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareN));
}

bool caseInsCompare(const wstring& s1, const wstring& s2)
{
   return((s1.size() == s2.size()) &&
            equal(s1.begin(), s1.end(), s2.begin(), caseInsCharCompareW));
}

int number_check(char *word)//checks whether a following str is a number or not.
{
    int e,f;
    string str1;
    char ch[2];
    str1.assign(word);
    for(int a=0;a<str1.length();a++)
    {
        ch[0]=str1.at(a);
        ch[1]='\0';
        f=ch[0];
        if(f<48||f>57)
        {
            e=0;
        }
        else
        {
            stringstream convert(word);//object from the class stringstream or sstream, used to convert string to int.
            convert>>e;
        }
    }
    //this function gives a big garbage value when any blank space is sent to it.
    /*if(e=4704656)
    {
        e=0;
    }*/
    //cout<<"e= "<<e<<", "<<"word= "<<word<<endl;
    return e;
}

int strcasestr(char *arraychar1,char *arraychar2)//checks if str1 present in str2 without case sensitivity.
{
    string str1,str2;
    str1.assign(arraychar1);
    str2.assign(arraychar2);
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);//converts buffer to upper case.
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    char a[1000],b[1000];
    strcpy(a,str1.c_str());
    strcpy(b,str2.c_str());
    if(strstr(a,b))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char* word_char_remove(char* word,int starting,int ending)
{
    string buffer;
    char word_modified[200];
    buffer.assign(word);
    buffer.erase(buffer.begin()+starting,buffer.end()-ending);
    strcpy(word_modified,buffer.c_str());
    return word_modified;
}

int getDayNumber(int dd,int mm,int yy)//yamamoto algorithm to find the day no from date.
{
   static int t[]={0,3,2,5,0,3,5,1,4,6,2,4};
   yy-=mm<3;
   return (yy+yy/4-yy/100+yy/400+t[mm-1]+dd)%7;
}


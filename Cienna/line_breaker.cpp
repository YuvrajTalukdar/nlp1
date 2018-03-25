#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<vector>

#include"cienna.h"

using namespace std;

int breaker(char *line,vector<grammer_lib_class>& y,vector<ram_save>& x,vector<hdd_save>& z,vector<time_quantity_lib>& time_quantity,vector<pronoun_sex_lib>& pronoun_sex)
{
   int j=0;
   string str_line;
   char ch[2];
   char word[1000][20]={'\0'};
   str_line.append(line);//to convert char array to string.
   for (unsigned int i=0;i<str_line.length();i++)
   {
      ch[0]=str_line.at(i);
      ch[1]='\0';
      if(ch[0]==','||ch[0]=='!'||ch[0]=='?'||ch[0]=='/'||ch[0]=='"'||ch[0]==':'||ch[0]=='('||ch[0]=='{'||ch[0]=='[')
      {
         j++;
         strcat(word[j],ch);
         j++;
         i++;
         ch[0]=str_line.at(i);
         ch[1]='\0';
      }
      else if(ch[0]==')'||ch[0]=='}'||ch[0]==']')
      {
          j++;
          strcat(word[j],ch);
          j++;
          i++;
          ch[0]=str_line.at(i);
          ch[1]='\0';
      }
      else if(ch[0]==' ')
      {
         j++;
         i++;
         ch[0]=str_line.at(i);//to get each letter of a string. Works only for string and not for char array.
         ch[1]='\0';
      }
      else if(ch[0]=='.')
      {
          j++;
          strcat(word[j],ch);
          break;
      }
      strcat(word[j],ch);
   }
   //in loops do remember to give <=j.
   search_word_pattern(word,j,y,x,z,time_quantity,pronoun_sex);//2d char sending rule.
   return 0;
}

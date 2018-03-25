#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<sstream>//for conversion of char to int.
#include<vector>
#include<algorithm>
#include<ctype.h>
#include<string>

#include"grammer_lib_class.h"
#include"hdd_save.h"
#include"ram_save.h"
#include"cienna.h"
#include"extra_functions.h"

using namespace std;

void date_detect_numeric(char word[][20],int j,vector<grammer_lib_class>& y,vector<hdd_save>& z,vector<ram_save>& x)
{
   int a,date_numbers[3],date_detect_no=z[x[0].si_no-1].date_detect_no;
   char date[20]={'\0'},str1[20]={'\0'},str2[20]={'\0'},str3[20]={'\0'};//needs to be nullified, other wise garbage values will get pushed in.
   //z::data data_matrix[500];
   for(a=0;a<j;a++)
   {
       if(number_check(word[a])!=0&&strcmp(word[a+1],"/")==0&&number_check(word[a+2])!=0&&strcmp(word[a+3],"/")==0&&number_check(word[a+4])!=0)
       {
           date_numbers[0]=number_check(word[a]);
           date_numbers[1]=number_check(word[a+2]);
           date_numbers[2]=number_check(word[a+4]);
           //numeric data entry.
           z[x[0].si_no-1].day_int[date_detect_no]=date_numbers[0];
           z[x[0].si_no-1].month_int[date_detect_no]=date_numbers[1];
           z[x[0].si_no-1].year_int[date_detect_no]=date_numbers[2];
            //alphabetic data entry.
           strcpy(z[x[0].si_no-1].day_name[date_detect_no],y[getDayNumber(z[x[0].si_no-1].day_int[date_detect_no],z[x[0].si_no-1].month_int[date_detect_no],z[x[0].si_no-1].year_int[date_detect_no])].days);
           strcpy(z[x[0].si_no-1].month_name[date_detect_no],y[date_numbers[1]-1].month);
           if(z[x[0].si_no-1].day_int[date_detect_no]>0&&z[x[0].si_no-1].month_int[date_detect_no]>0&&z[x[0].si_no-1].year_int[date_detect_no]>0)
           {
               sprintf(str1,"%ld",z[x[0].si_no-1].day_int[date_detect_no]);
               sprintf(str2,"%ld",z[x[0].si_no-1].month_int[date_detect_no]);
               sprintf(str3,"%ld",z[x[0].si_no-1].year_int[date_detect_no]);
               strcat(date,str1);
               strcat(date,"/");
               strcat(date,str2);
               strcat(date,"/");
               strcat(date,str3);
               strcpy(z[x[0].si_no-1].date[date_detect_no],date);
           }
           date_detect_no++;
           x[0].date_detect_no=date_detect_no;
       }
   }
   date_detect_word(word,j,y,z,x);
}

void date_detect_word(char word[][20],int j,vector<grammer_lib_class>& y,vector<hdd_save>& z,vector<ram_save>& x)
{
   int a,b,c,d,day_no,date_detect_no=x[0].date_detect_no-1,prefix_words_count,suffix_words_count,year_prefix=0,year_suffix=0;
   char buffer_prefix[20]={'\0'},buffer_suffix[20]={'\0'},date[20]={'\0'},str1[20]={'\0'},str2[20]={'\0'},str3[20]={'\0'};
   string buffer;
   for(a=0;a<j;a++)
   {
       for(b=0;b<12;b++)
       {
           if(caseInsCompare(word[a],y[b].month))
           {
               date_detect_no++;
               x[0].date_detect_no=date_detect_no;
               z[x[0].si_no-1].month_int[date_detect_no]=b+1;//month no set here.
               strcpy(z[x[0].si_no-1].month_name[date_detect_no],y[b].month);//month name set here.
               for(prefix_words_count=a,suffix_words_count=a;prefix_words_count>=0,suffix_words_count<j;prefix_words_count--,suffix_words_count++)
               {
                   year_prefix=number_check(word[prefix_words_count]);
                   year_suffix=number_check(word[suffix_words_count]);
                   //these if statements are its weak point needs replacement.
                   if(year_prefix>999&&year_prefix<999999)
                   {
                       z[x[0].si_no-1].year_int[date_detect_no]=year_prefix;
                   }
                   else if(year_suffix>999&&year_suffix<999999)
                   {
                       z[x[0].si_no-1].year_int[date_detect_no]=year_suffix;
                   }
                   //normal day prefix and suffix.
                   if(year_prefix>0&&year_prefix<32)
                   {
                       z[x[0].si_no-1].day_int[date_detect_no]=year_prefix;
                   }
                   else if(year_suffix>0&&year_suffix<32)
                   {
                       z[x[0].si_no-1].day_int[date_detect_no]=year_suffix;
                   }
                   strcpy(buffer_prefix,word[prefix_words_count]);

                   //for year buffer_prefix

                   buffer.assign(word[prefix_words_count]);
                   if(strcasestr(word[prefix_words_count],"AD")==0||strcasestr(word[prefix_words_count],"CE")==0)//searches for a string in another string.
                   {
                      strcpy(buffer_prefix,word_char_remove(word[prefix_words_count],buffer.length()-2,0));
                      stringstream convert(buffer_prefix);//object from the class stringstream or sstream, used to convert string to int.
                      convert>>c;
                      if(c>0)
                      {
                          z[x[0].si_no-1].year_int[date_detect_no]=c;
                          z[x[0].si_no-1].BC_AC[date_detect_no]=2;
                      }
                   }
                   else if(strcasestr(word[prefix_words_count],"BC")==0)//searches for a string in another string.
                   {
                      strcpy(buffer_prefix,word_char_remove(word[prefix_words_count],buffer.length()-2,0));
                      stringstream convert(buffer_prefix);//object from the class stringstream or sstream, used to convert string to int.
                      convert>>c;
                      if(c>0)
                      {
                          z[x[0].si_no-1].year_int[date_detect_no]=c;
                          z[x[0].si_no-1].BC_AC[date_detect_no]=1;
                      }
                   }
                   else if(strcasestr(word[prefix_words_count],"BCE")==0)
                   {
                      strcpy(buffer_prefix,word_char_remove(word[prefix_words_count],buffer.length()-3,0));
                      stringstream convert(buffer_prefix);//object from the class stringstream or sstream, used to convert string to int.
                      convert>>c;
                      if(c>0)
                      {
                          z[x[0].si_no-1].year_int[date_detect_no]=c;
                          z[x[0].si_no-1].BC_AC[date_detect_no]=1;
                      }
                   }

                   //for day buffer_prefix;

                   for(d=0;d<4;d++)
                   {
                       if(strcasestr(word[prefix_words_count],y[d].position_suffix)==0)
                       {
                          strcpy(buffer_prefix,word_char_remove(word[prefix_words_count],buffer.length()-2,0));
                          stringstream convert(buffer_prefix);//object from the class stringstream or sstream, used to convert string to int.
                          convert>>c;
                          if(c>0)
                          {
                              z[x[0].si_no-1].day_int[date_detect_no]=c;
                              break;
                          }
                       }
                   }

                   //for year buffer_suffix

                   buffer.assign(word[suffix_words_count]);
                   if(strcasestr(word[suffix_words_count],"AD")==0||strcasestr(word[suffix_words_count],"CE")==0)//searches for a string in another string.
                   {
                      strcpy(buffer_suffix,word_char_remove(word[suffix_words_count],buffer.length()-2,0));
                      stringstream convert(buffer_suffix);//object from the class stringstream or sstream, used to convert string to int.
                      convert>>c;
                      if(c>0)
                      {
                          z[x[0].si_no-1].year_int[date_detect_no]=c;
                          z[x[0].si_no-1].BC_AC[date_detect_no]=2;
                      }
                   }
                   else if(strcasestr(word[suffix_words_count],"BC")==0)//searches for a string in another string.
                   {
                      strcpy(buffer_suffix,word_char_remove(word[suffix_words_count],buffer.length()-2,0));
                      stringstream convert(buffer_suffix);//object from the class stringstream or sstream, used to convert string to int.
                      convert>>c;
                      if(c>0)
                      {
                         z[x[0].si_no-1].year_int[date_detect_no]=c;
                         z[x[0].si_no-1].BC_AC[date_detect_no]=1;
                      }
                   }
                   else if(strcasestr(word[suffix_words_count],"BCE")==0)
                   {
                      strcpy(buffer_suffix,word_char_remove(word[suffix_words_count],buffer.length()-3,0));
                      stringstream convert(buffer_suffix);//object from the class stringstream or sstream, used to convert string to int.
                      convert>>c;
                      if(c>0)
                      {
                          z[x[0].si_no-1].year_int[date_detect_no]=c;
                          z[x[0].si_no-1].BC_AC[date_detect_no]=1;
                      }
                   }

                   //for  day_int buffer_suffix.

                   for(d=0;d<4;d++)
                   {
                       if(strcasestr(word[suffix_words_count],y[d].position_suffix)==0)
                       {
                          strcpy(buffer_suffix,word_char_remove(word[suffix_words_count],buffer.length()-2,0));
                          stringstream convert(buffer_suffix);//object from the class stringstream or sstream, used to convert string to int.
                          convert>>c;
                          if(c>0)
                          {
                              z[x[0].si_no-1].day_int[date_detect_no]=c;
                              break;
                          }
                       }
                   }
                   //to get day name.
                   if(z[x[0].si_no-1].year_int[date_detect_no]>0&&z[x[0].si_no-1].day_int[date_detect_no]>0&&z[x[0].si_no-1].month_int[date_detect_no]>0)
                   {
                       day_no=getDayNumber(z[x[0].si_no-1].day_int[date_detect_no],z[x[0].si_no-1].month_int[date_detect_no],z[x[0].si_no-1].year_int[date_detect_no]);
                       strcpy(z[x[0].si_no-1].day_name[date_detect_no],y[4].days);
                   }
               }
               //joining of the units to form the date.
               if(z[x[0].si_no-1].day_int[date_detect_no]>0&&z[x[0].si_no-1].month_int[date_detect_no]>0&&z[x[0].si_no-1].year_int[date_detect_no]>0)
               {
                  sprintf(str1,"%ld",z[x[0].si_no-1].day_int[date_detect_no]);
                  sprintf(str2,"%ld",z[x[0].si_no-1].month_int[date_detect_no]);
                  sprintf(str3,"%ld",z[x[0].si_no-1].year_int[date_detect_no]);
                  strcat(date,str1);
                  strcat(date,"/");
                  strcat(date,str2);
                  strcat(date,"/");
                  strcat(date,str3);
                  strcpy(z[x[0].si_no-1].date[date_detect_no],date);
                  for(int str_clear=0;str_clear<20;str_clear++)
                  {
                      str1[str_clear]='\0';
                      str2[str_clear]='\0';
                      str3[str_clear]='\0';
                      date[str_clear]='\0';
                  }
               }
               x[0].date_detect_no=date_detect_no+1;
           }
       }
   }
   z[x[0].si_no-1].date_detect_no=x[0].date_detect_no;
   x[0].date_detect_no=0;
}

void date_type(char word[][20],int j,vector<grammer_lib_class>& y,vector<hdd_save>& z,vector<ram_save>& x)
{
   int a,b,c,d=0;//x[0].date_type_no;
   for(a=0;a<5;a++)
   {
       for(b=0;b<j;b++)
       {
          for(c=0;c<7;c++)
          {
             if(caseInsCompare(word[b],y[c].date_type[a]))
             //format y[vertical_access].date_type[horizontal_access]
             {
                strcpy(z[x[0].si_no-1].date_type[d],y[0].date_type[a]);
                d++;
                x[0].date_type_no=d;
             }
          }
       }
   }
   //x[0].date_detect_no=0;
}

void name_detect(char word[][20],int j,vector<grammer_lib_class>& y,vector<hdd_save>& z,vector<ram_save>& x)
{
   int a,b,d,word_count_suffix,word_count_prefix,name_count,name_word_no,c=0,e=0,f,month_found=0,g=0;
   name_count=x[0].si_no;
   char buffer1[20];
   string str1;
   for(a=0;a<j;a++)
   {
       for(b=0;b<21;b++)
       {
           if(caseInsCompare(word[a],y[b].helping_verb))//caseInsCompare is a function copied from the net to compare two strings without case sensitivity.
           {
              z[name_count].si_no=name_count;
              word_count_suffix=a;
              d=a;
              while(word_count_suffix!=0)
              {
                 word_count_suffix--;
                 c=number_check(word[word_count_suffix]);
                 if(c!=0)
                 {
                     word_count_prefix=word_count_suffix+1;
                     break;
                 }
                 for(f=0;f<12;f++)
                 {
                     if(strcmp(word[word_count_suffix],y[f].month)==0)
                     {
                         word_count_prefix=word_count_suffix+1;
                         month_found++;
                         break;
                     }
                 }
                 if(month_found>0)
                 {
                     break;
                 }
                 for(f=0;f<4;f++)
                 {
                     str1.assign(word[word_count_suffix]);
                     if(strcasestr(word[word_count_suffix],y[f].position_suffix)==0)
                     {
                         strcpy(buffer1,word_char_remove(word[word_count_suffix],str1.length()-2,0));
                         g=number_check(buffer1);
                         if(g!=0)
                         {
                             break;
                         }
                     }
                     if(g!=0)
                     {
                         break;
                     }
                 }
                 if(g!=0)
                 {
                     break;
                 }
                 for(f=0;f<4;f++)
                 {
                     if(strcasestr(word[word_count_suffix],y[f].ad_bc_word)==0)
                     {
                        str1.assign(word[word_count_suffix]);
                        if(f==3)
                        {
                            strcpy(buffer1,word_char_remove(word[word_count_suffix],str1.length()-3,0));
                            g=number_check(buffer1);
                            if(g!=0)
                            {
                               break;
                            }
                        }
                        if(g!=0)
                        {
                            break;
                        }
                        strcpy(buffer1,word_char_remove(word[word_count_suffix],str1.length()-3,0));
                        g=number_check(buffer1);
                        if(g!=0)
                        {
                            break;
                        }
                     }
                     if(g!=0)
                     {
                         break;
                     }
                 }
                 if(g!=0)
                 {
                     break;
                 }
                 word_count_prefix=word_count_suffix;
              }
              name_word_no=d-word_count_prefix;
              for(;word_count_prefix<d;word_count_prefix++)
              {
                 strcpy(z[name_count].name[e],word[word_count_prefix]);
                 e++;
              }
              z[name_count].name_word_no=name_word_no;
              name_count++;
              x[0].si_no=name_count;
           }
       }
   }
   date_detect_numeric(word,j,y,z,x);
}

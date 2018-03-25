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

void search_word_pattern(char word[][20],int j,vector<grammer_lib_class>& y,vector<ram_save>& x,vector<hdd_save>& z,vector<time_quantity_lib>& time_quantity,vector<pronoun_sex_lib>& pronoun_sex)//2d char sending rule.
{
   //name_detect(word,j,y,z,x);
   //date_detect_numeric(word,j,y,z,x);
   //date_detect_word(word,j,y,z,x);
   /*if(z[x[0].si_no-1].date_detect_no>0)
   {
       date_type(word,j,y,z,x);
   }*/
   line_words_type_check(word,j,y,x,z,time_quantity,pronoun_sex);
   for(int i=0;i<=j;i++)
   {
       cout<<i<<": "<<x[0].line_word_type_status[i]<<"\n";
   }
   //cout<<word[6];
}

void line_words_type_check(char word[][20],int j,vector<grammer_lib_class>& y,vector<ram_save>& x,vector<hdd_save>& z,vector<time_quantity_lib>& time_quantity,vector<pronoun_sex_lib>& pronoun_sex)
{
   int a=0,b,c,word_position;
   while(a<=j)
   {
       c=a;
       for(b=0;b<5;b++)
       {
           if(caseInsCompare(word[a],time_quantity[b].words))
           {
              strcpy(x[0].line_word_type_status[a],"GW");
              a++;
           }
       }
       for(b=0;b<4;b++)
       {
           if(caseInsCompare(word[a],pronoun_sex[b].words))
           {
              strcpy(x[0].line_word_type_status[a],"GW");
              a++;
           }
       }
       if(c==a)
       {
           strcpy(x[0].line_word_type_status[a],"NGW");
           a++;
       }
   }
   master_algorithm(word,j,y,x,z,time_quantity,pronoun_sex);
}

void master_algorithm(char word[][20],int j,vector<grammer_lib_class>& y,vector<ram_save>& x,vector<hdd_save>& z,vector<time_quantity_lib>& time_quantity,vector<pronoun_sex_lib>& pronoun_sex)
{
   int a,b,gw_type,gw_word_count=0;

   //Detection of GW position, count and foundation mixture it belongs to is done here.
   for(a=0;a<j;a++)//we are not using a<=j as we don't want the '.' here.
   {
      if(strcmp(x[0].line_word_type_status[a],"GW")==0)//==0 must be given here.
      {
          //GW type check.
          for(b=0;b<=5;b++)//checking for time_quantity
          {
              if(strcmp(word[a],time_quantity[b].words)==0)
              {
                  x[0].gw_position_type[gw_word_count][0]=a;//position of GW word.
                  x[0].gw_position_type[gw_word_count][1]=1;//which foundation class mixture it belongs to.
                  gw_word_count++;
              }
          }
          //checking pronoun_sex.
          for(b=0;b<=4;b++)
          {
              if(strcmp(word[a],pronoun_sex[b].words)==0)
              {
                  x[0].gw_position_type[gw_word_count][0]=a;//for  position
                  x[0].gw_position_type[gw_word_count][1]=2;//for type. 2 for pronoun_sex.
                  gw_word_count++;
              }
          }
      }
      else if(strcmp(x[0].line_word_type_status[a],"NGW")==0)
      {
          for(b=0;b<1000;b++)
          {
              if(caseInsCompare(word[a],y[b].verb_present_list))//present tense verb check.
              {
                 //set verb to present form.
                 //save algorithm
              }
          }
      }
   }
}
void save_algorithm(vector<ram_save>& x,vector<grammer_lib_class>& y,vector<hdd_save>& z,char buffer_word[][20],int element_si_no)
{
   int a=0;
   if(element_si_no==1)//1 is the si_no for verb.
   {
       if(z[x[0].record_no].action=='\0')
       {
          strcpy(z[x[0].record_no].action,buffer_word[0]);
       }
       else if(!caseInsCompare(z[x[0].record_no].action,buffer_word[0]))
       {
           x[0].record_no++;
           strcpy(z[x[0].record_no].action,buffer_word[0]);
           //copying the sub_obj data from the previous record to the current one.
           while(z[x[0].record_no-1].sub_obj[a]!='\0')
           {
               strcpy(z[x[0].record_no].sub_obj[a],z[x[0].record_no-1].sub_obj[a]);
               a++;
           }
       }
   }
   else if(element_si_no==2)//2 is the si_no of sub_obj.
   {
       if(z[x[0].record_no].sub_obj[0]=='\0')
       {
           a=0;
           //while()
       }
   }

}

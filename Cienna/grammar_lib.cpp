#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<vector>

#include"grammer_lib_class.h"
#include"cienna.h"


using namespace std;

void lib_load(vector<grammer_lib_class>& y,vector<time_quantity_lib>& time_quantity,vector<pronoun_sex_lib>& pronoun_sex)
{
   //information gets sent to the grammar lib class from here.
   days(y);
   month(y);
   position_suffix(y);
   ad_bc(y);
   helping_verb(y);
   pronoun(y);//not clear yet.
   date_type(y);
   verb_present_list(y);
   time_quantity_function(time_quantity);
   pronoun_sex_function(pronoun_sex);
}

void verb_present_list(vector<grammer_lib_class>& y)
{
    char ch,buffer[20];
    int a=0;
    ifstream file2("verb_present_list.txt",ios::in);
    while(file2)
    {
       file2>>buffer;
       strcpy(y[a].verb_present_list,buffer);
       a++;
    }
    file2.close();
}
void days(vector<grammer_lib_class>& y)
{
   char days[7][20]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
   for(int i=0;i<7;i++)
   {
       strcpy(y[i].days,days[i]);
   }
}

void month(vector<grammer_lib_class>& y)
{
   char month[12][20]={"january","february","march","april","may","june","july","august","september","october","november","december"};
   for(int i=0;i<12;i++)
   {
       strcpy(y[i].month,month[i]);
   }
}


void date_type(vector<grammer_lib_class>& y)
{
   char date_type[100][100][50]={
                            {"dob","dod","event","anniversary","jubilee"},
                            {"birth","death"," ","hundredth anniversary","golden jubilee"},
                            {"born","died"," ","100th anniversary","silver jubilee"},
                            {"came to this world","left this world"," "," ","golden jubilee"},
                            {" ","demise"," "," ","ruby jubilee"},
                            {" ","dead"," "," ","sapphire jubilee"},
                            {" ","killed"," "," ","platinum jubilee"}
                            };//'\o' cannot be put inside the array as an element so " " has been used.
   for(int i=0;i<7;i++)
   {
       for(int j=0;j<5;j++)
       {
            strcpy(y[i].date_type[j],date_type[i][j]);
            //format y[vertical_access].date_type[horizontal_access]
       }
   }
}

void position_suffix(vector<grammer_lib_class>& y)
{
    char position_suffix_char[4][20]={"st","nd","rd","th"};
    for(int i=0;i<4;i++)
    {
        strcpy(y[i].position_suffix,position_suffix_char[i]);
    }
}

void ad_bc(vector<grammer_lib_class>& y)
{
    char ad_bc[][20]={"AD","BC","CE","BCE"};
    for(int i=0;i<4;i++)
    {
        strcpy(y[i].ad_bc_word,ad_bc[i]);
    }
}

void pronoun(vector<grammer_lib_class>& y)
{
   char pronoun[][20]={"i","me","we","us","you","she","her","he","him","it","they","them",
   "that","which","who","whose","whichever","whoever","whomever","this","that","these","those",
   "anybody","anyone","anything","each","either","everybody","everyone","everything","neither",
   "nobody","no one","nothing","one","somebody","someone","something","both","few","many",
   "several","all","any","most","none","some","myself","ourselves","yourself","yourselves",
   "himself","herself","itself","themselves"};
   for(int i=0;i<56;i++)
   {
       strcpy(y[i].pronoun,pronoun[i]);
   }
}

void helping_verb(vector<grammer_lib_class>& y)
{
    char helping_verb[21][20]={"am","is","are","was","were","been","have","has","had",
                               "do","does","did","could","may","might","will","would",
                               "shall","should","must","ought to"};
    for(int i=0;i<21;i++)
    {
        strcpy(y[i].helping_verb,helping_verb[i]);
    }
}

void time_quantity_function(vector<time_quantity_lib>& time_quantity)
{
   char time_quantity_words[5][20]={"am","is","are","was","were"};
   char time_words[5][20]={"present","present","present","past","past"};
   char quantity_words[5][20]={"1","1","plural","1","plural"};
   for(int i=0;i<5;i++)
   {
        strcpy(time_quantity[i].words,time_quantity_words[i]);
        strcpy(time_quantity[i].time_words,time_words[i]);
        strcpy(time_quantity[i].quantity_words,quantity_words[i]);
   }
}

void pronoun_sex_function(vector<pronoun_sex_lib>& pronoun_sex)
{
   char pronoun_sex_words[4][20]={"he","she","his","her"};
   char sex_words[4][20]={"M","F","M","F"};
   for(int i=0;i<4;i++)
   {
       strcpy(pronoun_sex[i].words,pronoun_sex_words[i]);
       strcpy(pronoun_sex[i].sex_words,sex_words[i]);
   }
}


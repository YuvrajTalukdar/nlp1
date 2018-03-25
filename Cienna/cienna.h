#ifndef CIENNA_H_INCLUDED
#define CIENNA_H_INCLUDED

#include<vector>
#include<stdio.h>
#include<string.h>

#include"grammer_lib_class.h"
#include"hdd_save.h"
#include"ram_save.h"

using namespace std;

//reader
void read();
//line breaker
int breaker(char *line,vector<grammer_lib_class>& y,vector<ram_save>& x,vector<hdd_save>& z,vector<time_quantity_lib>& time_quantity,vector<pronoun_sex_lib>& pronoun_sex);
//master algorithm
void search_word_pattern(char word[][20],int,vector<grammer_lib_class>& y,vector<ram_save>& x,vector<hdd_save>& z,vector<time_quantity_lib>& time_quantity,vector<pronoun_sex_lib>& pronoun_sex);//2d char sending rule.
void line_words_type_check(char word[][20],int j,vector<grammer_lib_class>& y,vector<ram_save>& x,vector<hdd_save>& z,vector<time_quantity_lib>& time_quantity,vector<pronoun_sex_lib>& pronoun_sex);
void master_algorithm(char word[][20],int j,vector<grammer_lib_class>& y,vector<ram_save>& x,vector<hdd_save>& z,vector<time_quantity_lib>& time_quantity,vector<pronoun_sex_lib>& pronoun_sex);
//glib
void lib_load(vector<grammer_lib_class>& y,vector<time_quantity_lib>& time_quantity,vector<pronoun_sex_lib>& pronoun_sex);
void days(vector<grammer_lib_class>& y);
void month(vector<grammer_lib_class>& y);
void position_suffix(vector<grammer_lib_class>& y);
void helping_verb(vector<grammer_lib_class>& y);
void pronoun(vector<grammer_lib_class>& y);
void date_type(vector<grammer_lib_class>& y);
void ad_bc(vector<grammer_lib_class>& y);
void verb_present_list(vector<grammer_lib_class>& y);
//foundation class mix, glib
void time_quantity_function(vector<time_quantity_lib>& time_quantity);
void pronoun_sex_function(vector<pronoun_sex_lib>& pronoun_sex);
//search algorithm
void date_detect_numeric(char word[][20],int j,vector<grammer_lib_class>& y,vector<hdd_save>& z,vector<ram_save>& x);
void date_detect_word(char word[][20],int j,vector<grammer_lib_class>& y,vector<hdd_save>& z,vector<ram_save>& x);
void date_type(char word[][20],int j,vector<grammer_lib_class>& y,vector<hdd_save>& z,vector<ram_save>& x);
void name_detect(char word[][20],int j,vector<grammer_lib_class>& y,vector<hdd_save>& z,vector<ram_save>& x);



#endif // CIENNA_H_INCLUDED

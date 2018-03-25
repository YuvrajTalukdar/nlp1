#ifndef GRAMMER_LIB_CLASS_H
#define GRAMMER_LIB_CLASS_H

#include"foundation.h"

using namespace std;

class grammer_lib_class
{
    public:
        char position_suffix[20],tense[20],ad_bc_word[20],date[25],date_type[100][100],
             month[20],days[20],year[20],helping_verb[20],pronoun[20],verb_present_list[20];
    protected:

    private:
};

class time_lib
{
   public:
       char words[20];
};

class location_lib
{
   public:
       char words[20];
};

class pointer_lib
{
  public:
       char words[20];
};

class question_lib
{
   public:
       char words[20];
};

class logical_lib
{
  public:
       char words[20];
};

class number_lib
{
   public:
       char words[20];
};

class position_lib
{
  public:
       char words[20];
};

class quantity_lib
{
   public:
       char words[20];
};

class units_lib
{
   public:
       char words[20];
};

class time_question_lib: public time,public question
{
   public:
       char words[20];
};

class time_quantity_lib: public time,public quantity
{
   public:
       char words[20],prefered_ngw_prefix[2][20]={"subject_object"},
            prefered_ngw_suffix[2][20]={"verb"},word_type_sometimes[20]="verb";//when there 3 words
            //suffix may not have object as object comes after verb normally.
};

class pointer_quantity_lib: public pointer,public quantity
{
   public:
       char words[20],prefered_ngw_prefix[20],prefered_ngw_suffix[20];
};

class pronoun_sex_lib: public pronouns,public sex
{
   public:
       char words[20],prefered_ngw_prefix[2][20]={"verb","object"},
       prefered_ngw_suffix[2][20]={"verb","object"},word_type_sometimes[20]="subject";
};

#endif // GRAMMER_LIB_CLASS_H

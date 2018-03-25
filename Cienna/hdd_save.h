#ifndef HDD_SAVE_H
#define HDD_SAVE_H
#include<vector>
#include<iostream>

using namespace std;

class hdd_save
{
    public:
        char day_name[500][20],month_name[500][20],date[500][20],
             date_type[500][20],name[500][20],name_type[20];

        char action[20]={'\0'},sub_obj[100][20]={{'\0'}};

        int day_int[500],month_int[500]/*year_int=0*/,BC_AC[500]={2}/*1 FOR BC AND 2 FOR AC*/,
            si_no=0,name_word_no,year_int[500]={0},date_detect_no=0;
        //hdd_save();

    protected:
        //char date[20]={'\0'};

    private:
        //char date[20]={'\0'};
};


#endif // HDD_SAVE_H

#ifndef RAM_SAVE_H
#define RAM_SAVE_H

#include "hdd_save.h"


class ram_save : public hdd_save
{
    public:
        int used_words[100],date_detect_no=0,date_type_no=0,si_no=0;

        int gw_position_type[100][2],ngw_position_type[100][2],record_no=0;
        char line_word_type_status[100][20];
    protected:

    private:
};

#endif // RAM_SAVE_H

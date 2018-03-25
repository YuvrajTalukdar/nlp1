//some problem is there with ' .
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<string>
#include<vector>//required for vector.
/*Vector
Vectors are sequence containers representing arrays that can change in size.
Just like arrays, vectors use contiguous storage locations for their elements,
which means that their elements can also be accessed using offsets on regular
pointers to its elements, and just as efficiently as in arrays. But unlike arrays,
their size can change dynamically, with their storage being handled automatically
by the container.
Internally, vectors use a dynamically allocated array to store their elements.
This array may need to be reallocated in order to grow in size when new elements
are inserted, which implies allocating a new array and moving all elements to it.
This is a relatively expensive task in terms of processing time, and thus, vectors
do not reallocate each time an element is added to the container.
Instead, vector containers may allocate some extra storage to accommodate for
possible growth, and thus the container may have an actual capacity greater than
the storage strictly needed to contain its elements (i.e., its size). Libraries can
implement different strategies for growth to balance between memory usage and
reallocations, but in any case, reallocations should only happen at logarithmically
growing intervals of size so that the insertion of individual elements at the end of
the vector can be provided with amortized constant time complexity (see push_back).
Therefore, compared to arrays, vectors consume more memory in exchange for the
ability to manage storage and grow dynamically in an efficient way.
Compared to the other dynamic sequence containers (deques, lists and forward_lists),
vectors are very efficient accessing its elements (just like arrays) and relatively
efficient adding or removing elements from its end. For operations that involve
inserting or removing elements at positions other than the end, they perform worse
than the others, and have less consistent iterators and references than lists and
forward_lists.
*/
#include"cienna.h"
#include"grammer_lib_class.h"

using namespace std;

void read()
{
   char get_ch,ch[2],line[10000]={'\0'};
   int i;
   //grammer_lib_class y[1000];//total no of possible words available.
   vector<grammer_lib_class> y(2000);
   vector<time_quantity_lib> time_quantity(50);
   vector<pronoun_sex_lib> pronoun_sex(50);
   vector<hdd_save> z(1000);//
   vector<ram_save> x(1000);//these classes must be initialized only ones other wise data stored in it will be lost. So they are initialized in the reader itself.
   /*We are using vector here as array has a limited size of around 1000.
   Where as vector has unlimited memory. But vectors are slower than arrays.
   Speed difference is clearly noticeable here. Vectors are much more efficient
   in managing memory than arrays.*/
   lib_load(y,time_quantity,pronoun_sex);

   fstream file1("normal_text1.txt",ios::in);
   while(file1)
   {
       file1.get(get_ch);
       if(file1.eof())
       {
           break;
       }
       ch[0]=get_ch;
       ch[1]='\0';
       strcat(line,ch);
       if(get_ch=='.')
       {
           breaker(line,y,x,z,time_quantity,pronoun_sex);
           for(i=0;i<10000;i++)//for clearing the 'line' to make space for reading a new line.
           {
               line[i]='\0';
           }
           file1.get(get_ch);
           //char array sending process will go on here.
       }
   }
   file1.close();
   int o=0;
   char bc_ad[5];
   for(int h=0;h<x[0].si_no;h++)
   {
       while(o<z[h].name_word_no)
       {
           cout<<z[h].name[o]<<" ";
           o++;
       }
       o=0;//"from while to o=0" is the algorithm to display name.

       for(int l=0;l<z[h].date_detect_no;l++){
       if(z[h].BC_AC[l]==1)
       {
           strcpy(bc_ad," BC");
       }
       else if(z[h].BC_AC[l]==2)
       {
           strcpy(bc_ad," AD");
       }
       cout<<"\n"<<z[h].date[l]<<endl;
       cout<<"day="<<z[h].day_int[l]<<", "<<z[h].day_name[l]<<endl;
       cout<<"month="<<z[h].month_int[l]<<", "<<z[h].month_name[l]<<endl;
       cout<<"year="<<z[h].year_int[l]<<bc_ad<<endl;
       cout<<"Date_Type= "<<z[h].date_type[l]<<"\n\n\n";
       }
   }
   //cout<<"ram si_no="<<x[0].si_no<<endl;
   //cout<<"date_detect="<<x[0].date_detect_no<<endl;
   //cout<<"date_type_no="<<x[0].date_type_no<<endl;
}

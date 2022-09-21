#ifndef _Karen_HPP
#define _Karen_HPP
#include <iostream>
#include <string>

class Karen {
    private :

        void debug(void);
        void info(void);
        void warning(void);
        void error(void);

    public :
        typedef void (Karen::*ptr)(void);
        void complain(std::string level);

        typedef struct comment{
            std::string level;
            void (Karen::*levptr)(void);
        } cmt;

        typedef struct comment2{
            std::string level;
            ptr p;
        } cmt2;

};

#endif
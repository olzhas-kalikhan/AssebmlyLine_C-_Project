// Name: Olzhas Kalikhan
// Seneca Student ID: 102469186
// Seneca email: okalikhan@myseneca.ca
// Date of completion: 17/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>

class Utilities{
        size_t m_widthField = 1;
        static char m_delimiter;
    public:
        Utilities();
        void setFieldWidth(size_t);
        size_t getFieldWidth() const{ return m_widthField;}
        const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
        static void setDelimiter(const char del);
        const char getDelimiter() const{ return m_delimiter;}
};


#endif
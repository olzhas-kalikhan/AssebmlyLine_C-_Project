// Name: Olzhas Kalikhan
// Seneca Student ID: 102469186
// Seneca email: okalikhan@myseneca.ca
// Date of completion: 17/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"
char Utilities::m_delimiter =' ';
Utilities::Utilities(){}
void Utilities::setFieldWidth(size_t s){
    m_widthField = s;
}
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
    size_t firstPos = str.find(m_delimiter, next_pos+1);  
    std::string token;
    if(next_pos <=str.size())
        token = str.substr(next_pos, firstPos-next_pos);
    
    
    if(token.size()>0){
        more = true;
        if(m_widthField < token.size())
            m_widthField = token.size();    
    }
    else{
        more = false;
    }    
    return token;
}
void Utilities::setDelimiter(const char del){
    m_delimiter = del;
}
// Name: Olzhas Kalikhan
// Seneca Student ID: 102469186
// Seneca email: okalikhan@myseneca.ca
// Date of completion: 17/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <iomanip>
#include <string>
#include "Item.h"
#include "Utilities.h"

size_t Item::m_widthField = 1;
Item::Item(const std::string& str){
    Utilities newUtitliy;
    bool more = true;
    size_t nextPos=0;
    int i = 0;
    std::string token;
    while(more){
        if(i<3)
            m_widthField =std::max(m_widthField, newUtitliy.getFieldWidth());
        token = newUtitliy.extractToken(str, nextPos, more);
        if(more){
            
            switch (i)
            {
                case(0):m_name = token;break;
                case(1):m_serialNumber = std::stoul(token);break;
                case(2):m_quantity = std::stoul(token);break;
                case(3):m_description = token;break;
            }
            i++;
            nextPos += token.size()+1;
            }

    }
    
}
const unsigned int Item::getSerialNumber(){
    return m_serialNumber++;
}
void Item::updateQuantity(){
    if(m_quantity>0){
        m_quantity--;
    }
}
void Item::display(std::ostream& os, bool full) const{
    os<< std::setw(m_widthField)<<std::left<< m_name; 
    os<<" ["<<std::right <<std::setfill('0')<<std::setw(6)<< m_serialNumber <<"]";
    os.fill(' ');
    if(full){
        os<< " Quantity: " <<std::setw(m_widthField)<<std::left<<m_quantity;
        os<<" Description: "<<m_description;
    }
    os<<std::endl;
}
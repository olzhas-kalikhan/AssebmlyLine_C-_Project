// Name: Olzhas Kalikhan
// Seneca Student ID: 102469186
// Seneca email: okalikhan@myseneca.ca
// Date of completion: 17/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef ITEM_H
#define ITEM_H


class Item{
        std::string m_name;
        std::string m_description;
        unsigned int m_serialNumber;
        unsigned int m_quantity;
        static size_t m_widthField; 
    public:
        Item(const std::string& str);
        const std::string& getName() const{ return m_name; }
        const unsigned int getSerialNumber();
        const unsigned int getQuantity(){ return m_quantity; }
        void updateQuantity();
        void display(std::ostream& os, bool full) const;
}; 

#endif
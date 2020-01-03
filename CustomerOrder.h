// Name: Olzhas Kalikhan
// Seneca Student ID: 102469186
// Seneca email: okalikhan@myseneca.ca
// Date of completion: 24/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include <iostream>
#include "Utilities.h"
#include "Item.h"
struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;
	ItemInfo(std::string src) : m_itemName(src) {};
};
class CustomerOrder{
        std::string m_name;
        std::string m_product;
        unsigned int m_cntItem;
        ItemInfo** m_lstItem;
        static size_t m_widthField;
    public:
        CustomerOrder();
        CustomerOrder(const std::string&);
        CustomerOrder(const CustomerOrder&);
        CustomerOrder& operator=(const CustomerOrder&)=delete;
        CustomerOrder(CustomerOrder&&) noexcept;
        CustomerOrder& operator=(CustomerOrder&&);
        ~CustomerOrder();
        bool getItemFillState(std::string) const;
        bool getOrderFillState() const;
        void fillItem(Item& item, std::ostream&);
        void display(std::ostream&) const;
};

#endif
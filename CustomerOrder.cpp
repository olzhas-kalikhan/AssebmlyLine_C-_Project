// Name: Olzhas Kalikhan
// Seneca Student ID: 102469186
// Seneca email: okalikhan@myseneca.ca
// Date of completion: 24/11/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iomanip>
#include "CustomerOrder.h"
size_t CustomerOrder::m_widthField = 1;
CustomerOrder::CustomerOrder(){
    m_name = "";
    m_product = "";
    m_cntItem = 0;
    m_lstItem = nullptr;
}
CustomerOrder::CustomerOrder(const std::string& str){
    Utilities newUtitliy;
    bool more = true;
    size_t nextPos=0;
    m_cntItem = 0;
    unsigned int i = 0;
    std::string token;
    while(more){
        m_widthField =std::max(m_widthField, newUtitliy.getFieldWidth());
        token = newUtitliy.extractToken(str, nextPos, more);
        switch (i)
        {
            case(0):m_name = token;break;
            case(1):m_product = token;break;
            case(2):
                bool subMore = more;  
                size_t tmpPos = nextPos;  
                while(subMore){
                    token = newUtitliy.extractToken(str, tmpPos, subMore);
                    if(subMore){
                        tmpPos += token.size()+1;
                        m_cntItem++;
                    }
                }
                m_lstItem = new ItemInfo*[m_cntItem+1];
                for(size_t k = 0; k < m_cntItem && more; k++){
                    token = newUtitliy.extractToken(str, nextPos,more);
                    nextPos += token.size()+1;
                    m_lstItem[k] = new ItemInfo(token);
                }
                break;
           
        }
        i++;
        nextPos += token.size()+1;
        

    }
}
CustomerOrder::CustomerOrder(const CustomerOrder& src){
    std::cout<<"oops\n";
    throw "No copies";
}
CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept{
    *this = std::move(src);
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src){
    if(this!= &src){
        m_name = src.m_name;
        m_product = src.m_product;
        m_cntItem = src.m_cntItem;
        m_lstItem = src.m_lstItem;
        src.m_name = "";
        src.m_product = "";
        src.m_cntItem = 0;
        src.m_lstItem = nullptr;    
    }
    return *this;
}
CustomerOrder::~CustomerOrder(){
    delete [] m_lstItem;
    m_lstItem =nullptr;
}
bool CustomerOrder::getItemFillState(std::string str) const{
    bool itemsFilled = true;
    for(size_t i = 0; i < m_cntItem; i++){
        if(m_lstItem[i]->m_itemName == str ){
            if(!m_lstItem[i]->m_fillState)
                itemsFilled = false;
        }
    }
    return itemsFilled;
}
bool CustomerOrder::getOrderFillState() const{
    bool orderFilled=true;
    for( size_t i = 0; i<m_cntItem; i++){
        if(!m_lstItem[i]->m_fillState)
            orderFilled = false;
    }
    return orderFilled;
}
void CustomerOrder::fillItem(Item& item, std::ostream& os){
    
    for(size_t i = 0; i < m_cntItem; i++){
        if(item.getName() == m_lstItem[i]->m_itemName){
            if(item.getQuantity()>0 && !m_lstItem[i]->m_fillState){
                
                m_lstItem[i]->m_serialNumber = item.getSerialNumber();
                m_lstItem[i]->m_fillState = true;
                item.updateQuantity();
                os << "Filled "; 
            }else{
                os << "Unable to fill ";
            }
            os<< m_name << ", " << m_product <<"[" << item.getName() << "]\n"; 
        }
    }
    
}
void CustomerOrder::display(std::ostream& os) const{
    os << m_name << " - " << m_product<<std::endl;
    for(size_t i = 0; i < m_cntItem; i++){
        os<< "["<<std::setw(6)<<std::setfill('0')<<m_lstItem[i]->m_serialNumber<<"] "
        <<std::setw(m_widthField)<<std::setfill(' ')<<m_lstItem[i]->m_itemName<<" - "
        << (m_lstItem[i]->m_fillState? "FILLED":"MISSING")<<std::endl;
    }

}

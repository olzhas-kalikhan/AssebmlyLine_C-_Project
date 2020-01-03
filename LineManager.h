// Name: Olzhas Kalikhan
// Seneca Student ID: 102469186
// Seneca email: okalikhan@myseneca.ca
// Date of completion: 01/12/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include <vector>
#include <deque>
#include "Task.h"
#include "CustomerOrder.h"

class LineManager{
        std::vector<Task*> assemblyLine;
        std::deque<CustomerOrder> toBeFilled;
        std::deque<CustomerOrder> completed;
        unsigned int m_cntCustomerOrder=0;
        Task *firstTask;        
    public:
        LineManager(const std::string& file,std::vector<Task*>& tasks, std::vector<CustomerOrder>& orders);
        bool run(std::ostream&);
        void displayCompleted(std::ostream&) const;
        void validateTasks() const;
};

#endif
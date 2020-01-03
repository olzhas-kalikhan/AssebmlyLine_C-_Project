// Name: Olzhas Kalikhan
// Seneca Student ID: 102469186
// Seneca email: okalikhan@myseneca.ca
// Date of completion: 01/12/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <deque>
#include "Item.h"
#include "CustomerOrder.h"
class Task: public Item{
        std::deque<CustomerOrder> m_orders;
        Task* m_pNextTask = nullptr;
    public:
        Task(const std::string);
        Task(const Task& src) = delete;
        Task(Task&& src) = delete;
        Task& operator=(const Task& src) = delete;
        Task& operator=(Task&& src) = delete;
        void runProcess(std::ostream&);
        bool moveTask();
        void setNextTask(Task&);
        bool getCompleted(CustomerOrder&);
        void validate(std::ostream&);
        Task& operator+=(CustomerOrder&&);
        Task* getNextTask(){return m_pNextTask;}
};

#endif
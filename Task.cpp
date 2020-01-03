// Name: Olzhas Kalikhan
// Seneca Student ID: 102469186
// Seneca email: okalikhan@myseneca.ca
// Date of completion: 01/12/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <algorithm>
#include "Task.h"

Task::Task(const std::string str):Item(str){}
void Task::runProcess(std::ostream& os){
    if(!m_orders.empty()){
        m_orders.back().fillItem(*this,os);
    }
}
bool Task::moveTask(){
    bool moved=false;
    if(m_orders.empty()){
        moved = false;
    }
    else{
        if(m_orders.back().getItemFillState(getName())){
            if(m_pNextTask!=nullptr){
                (*m_pNextTask)+=std::move(m_orders.back());
                m_orders.pop_back();
                moved = true;
            }
        } 
    }
    return moved;
}
void Task::setNextTask(Task& task){
    m_pNextTask = &task;
}
bool Task::getCompleted(CustomerOrder& co){
    bool completed=false;
    if(m_orders.empty()){
        completed=false;
    }
    else{
        if(m_orders.back().getOrderFillState()){
            co = std::move(m_orders.back());
            m_orders.pop_back();
            completed=true;
        }    
    }
    return completed;
}
void Task::validate(std::ostream& os){
    os<< getName() << " --> ";
    if(m_pNextTask !=nullptr)
        os<< m_pNextTask->getName()<<std::endl;
    else
        os<< "END OF LINE"<<std::endl;
}
Task& Task::operator+=(CustomerOrder&& co){
    m_orders.push_front(std::move(co));
    return *this;
}
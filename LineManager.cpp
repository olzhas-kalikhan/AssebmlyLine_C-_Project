// Name: Olzhas Kalikhan
// Seneca Student ID: 102469186
// Seneca email: okalikhan@myseneca.ca
// Date of completion: 01/12/2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include "LineManager.h"
#include "Utilities.h"

LineManager::LineManager(const std::string& filename,std::vector<Task*>& tasks, std::vector<CustomerOrder>& orders){
    std::ifstream file(filename);
    if(!file){
        std::cout<<filename;
    }
    else{
        bool more = true;
        Utilities newUtitliy;
        std::string line, task, nextTask;
        size_t nextPos;
        while(!file.eof()){
            std::getline(file, line);
            nextPos=0;
            task = newUtitliy.extractToken(line, nextPos, more);
            nextPos += task.size()+1;
            nextTask = newUtitliy.extractToken(line, nextPos, more);
            nextPos +=nextTask.size()+1;
            auto itTask = std::find_if(tasks.begin(), tasks.end(), [&task](Task* t){
                return t->getName()==task;
            });
            auto itNextTask = std::find_if(tasks.begin(), tasks.end(), [&nextTask](Task* t){
                return t->getName()==nextTask;
            });
            if(itNextTask != tasks.end() && itTask!=tasks.end())
                (*itTask)->setNextTask(*(*itNextTask));
            
        }
        for(auto it= tasks.begin(); it!=tasks.end(); ++it){
            assemblyLine.push_back(*it);
        }
        for(auto it= orders.begin(); it!=orders.end(); ++it){
            toBeFilled.push_front(std::move(*it));
        }
        m_cntCustomerOrder=toBeFilled.size();
        for(auto it = assemblyLine.begin(); it != assemblyLine.end(); ++it){
           for(auto it2 = assemblyLine.begin(); it2 != assemblyLine.end(); ++it2){
                if((*it2)!=(*it)->getNextTask()){
                    firstTask = (*it);
                }
           }
        }
    }
    
}
bool LineManager::run(std::ostream& os){
    bool complete= false;
    if(!toBeFilled.empty()){
        (*firstTask)+=std::move(toBeFilled.back());
        toBeFilled.pop_back();
    }         
    for(Task* task : assemblyLine){
        task->runProcess(os);
    }
    CustomerOrder temp;
    for(Task* task : assemblyLine){
        task->moveTask();
        if(task->getCompleted(temp)){
            
            completed.push_back(std::move(temp));
            
            --m_cntCustomerOrder;
            if(m_cntCustomerOrder==0){
                
                complete = true;
            }
        }
    }    
    return complete;
}
    
    

void LineManager::displayCompleted(std::ostream& os) const{
    for(auto it = completed.begin();it!=completed.end(); ++it)
        it->display(os);
}
void LineManager::validateTasks() const{
    std::for_each(assemblyLine.begin(), assemblyLine.end(), [](Task* t){
        t->validate(std::cout); 
    });
}
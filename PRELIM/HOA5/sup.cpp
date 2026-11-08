#include <iostream>
#include "queueArr.h"

class Job{
    public:
        int jobID;
        std::string userName;
        int numberPages;
 
        Job(){
            jobID = 0;
            userName = "";
            numberPages = 0;
        }

        Job(int id, std::string name, int pages){
            jobID = id;
            userName = name;
            numberPages = pages;
        }
};
 
class Printer{
    private:
        queueArr<Job> jobQueue;
 
    public:
        Printer(size_t capacity) : jobQueue(capacity) {}
 
        void addJob(Job newJob){
            jobQueue.Enqueue(newJob);
            std::cout << "Added Job " << newJob.jobID << " (" << newJob.userName
                      << ", " << newJob.numberPages << " pages)\n";
        }
        void clearJobs(){
            jobQueue.Clear();
        }
        void showJob(){
            if(jobQueue.Empty()){
                std::cout << "Now Processing: (no jobs in queue)\n";
            }
            else{
                Job current = jobQueue.Front();
                std::cout << "Now Processing: Job " << current.jobID << " for "
                          << current.userName << " (" << current.numberPages << " pages)\n";
            }
        }
        void processNextJob(){
            if(jobQueue.Empty()){
                std::cout << "No jobs to process.\n";
                return;
            }
            Job current = jobQueue.Front();
            std::cout << "Printing Job " << current.jobID << " for "
                      << current.userName << " (" << current.numberPages << " pages)\n";
            jobQueue.Dequeue();
        }
};

int main(){

    Printer officePrinter(5);
    int choice = 0;
    int nextJobID = 1;
 
    while(choice != 4){
        std::cout << "====== PRINTER ======\n";
        officePrinter.showJob();
        std::cout << "\n\n"
                  << "1) Add Job\n"
                  << "2) Process Next Job\n"
                  << "3) Clear Jobs\n"
                  << "4) Exit\n"
                  << "Choice: ";
        std::cin >> choice;
 
        switch(choice){
            case 1: {
                std::string name;
                int pages;
 
                std::cout << "Enter user name: ";
                std::cin >> name;
                std::cout << "Enter number of pages: ";
                std::cin >> pages;
 
                officePrinter.addJob(Job(nextJobID, name, pages));
                nextJobID++;
                break;
            }
            case 2:
                officePrinter.processNextJob();
                break;
            case 3:
                officePrinter.clearJobs();
                std::cout << "Job queue cleared.\n";
                break;
            case 4:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, try again.\n";
                break;
        }
    }

    return 0;
}
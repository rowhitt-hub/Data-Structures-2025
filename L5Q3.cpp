/*
An operating system allocates a fixed time slot CPU time for processes using a round-robin
scheduling algorithm. The fixed time slot will be initialized before the start of the menu-driven
program. Implement the round-robin scheduling algorithm using the circular linked list. Implement
the program by including the appropriate header file. It consists of the following operaƟons.

1. Insert Process
2. Execute
3. Exit

The "Insert Process" will get an integer Ɵme from the user and add it to the queue.

The "Execute" operaƟon will execute a deletion in the beginning operaƟon and subtract the fixed
time from the process. If the processing time falls below 0 then the process is considered to have
completed its execution, otherwise, the remaining time aŌer subtracƟon is inserted at the end of the
circular linked list. 
*/
#include <iostream>
using namespace std;

class RoundRobinScheduler {
private:
    struct Process {
        int id;
        int time; // Time required for the process to execute
        Process* next;
    };
    Process* head;
    int timeSlot; // Fixed time slot for each process

public:
    RoundRobinScheduler(int tSlot);
    ~RoundRobinScheduler();
    
    void insertProcess(int processTime);
    void execute();
    void displayQueue();
};

// Constructor to initialize the round-robin scheduler with a fixed time slot
RoundRobinScheduler::RoundRobinScheduler(int tSlot) {
    head = nullptr;
    timeSlot = tSlot;
}

// Destructor to clean up allocated memory
RoundRobinScheduler::~RoundRobinScheduler() {
    if (head) {
        Process* temp = head;
        do {
            Process* nextProcess = temp->next;
            delete temp;
            temp = nextProcess;
        } while (temp != head);
    }
}

// Insert a new process into the circular linked list
void RoundRobinScheduler::insertProcess(int processTime) {
    Process* newProcess = new Process{processTime, processTime, nullptr};
    if (!head) {
        head = newProcess;
        head->next = head; // Pointing to itself, circular linked list
    } else {
        Process* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newProcess;
        newProcess->next = head;
    }
    cout << "Process with time " << processTime << " inserted.\n";
}

// Execute the processes in a round-robin manner
void RoundRobinScheduler::execute() {
    if (!head) {
        cout << "No processes in the queue.\n";
        return;
    }

    Process* temp = head;
    do {
        // Execute process for the fixed time slot
        cout << "Executing Process with initial time: " << temp->time << "\n";
        temp->time -= timeSlot;
        
        if (temp->time <= 0) {
            cout << "Process completed with remaining time: " << temp->time + timeSlot << "\n";
            // Delete the completed process
            if (temp == head && temp->next == head) {
                delete temp;
                head = nullptr;
                return;
            } else {
                Process* prev = head;
                while (prev->next != temp) {
                    prev = prev->next;
                }
                prev->next = temp->next;
                if (temp == head) {
                    head = temp->next;
                }
                delete temp;
            }
        } else {
            cout << "Process not completed, remaining time: " << temp->time << "\n";
            // Move the process to the end of the queue
            head = temp->next;
        }

        temp = head; // Move to the next process

    } while (head);
}

// Display the current queue of processes
void RoundRobinScheduler::displayQueue() {
    if (!head) {
        cout << "No processes in the queue.\n";
        return;
    }

    Process* temp = head;
    cout << "Current Process Queue: ";
    do {
        cout << temp->time << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int timeSlot;
    cout << "Enter the fixed time slot for processes: ";
    cin >> timeSlot;

    RoundRobinScheduler scheduler(timeSlot);
    int choice, processTime;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert Process\n";
        cout << "2. Execute\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter process time: ";
                cin >> processTime;
                scheduler.insertProcess(processTime);
                break;
            case 2:
                scheduler.execute();
                break;
            case 3:
                scheduler.displayQueue();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}

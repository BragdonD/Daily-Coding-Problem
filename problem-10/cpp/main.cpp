#include <iostream>
#include <chrono>
#include <thread>

class Scheduler
{
private:
    typedef void (*task)();
    typedef std::chrono::_V2::steady_clock::time_point time_p;
    int m_n;
    task m_task;
    time_p m_start;
    std::thread m_thread;
public:
    Scheduler(task _task, int _ms);
    ~Scheduler();
    void timer();
};

Scheduler::Scheduler(task _task, int _ms)
{
    m_n = _ms;
    m_task = _task;
    m_start = std::chrono::steady_clock::now();
    m_thread = std::thread(&Scheduler::timer, this);
}

void Scheduler::timer()
{
    while(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - m_start).count() < m_n) 
    {
    }
    m_task();
}

Scheduler::~Scheduler()
{
    m_thread.join(); // Not needed
}

void a_task()
{
    std::cout << "hello" << std::endl;
}

int main(int argc, char const *argv[])
{
    Scheduler temp(a_task,5000);
    std::cout << "here" << std::endl;
    return 0;
}


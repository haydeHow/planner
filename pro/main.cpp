#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

#define CLEAR() std::system("clear")
#define LOG(msg) std::cout << msg << std::endl
#define READ(msg) std::cin >> msg

#ifdef SLEEP
#undef SLEEP
#endif

#define SLEEP(secs) std::this_thread::sleep_for(std::chrono::seconds(secs))

namespace tasks
{
    void task1()
    {
        // Are you gay?
        LOG("Oh wad up");
        SLEEP(2);
        LOG("I was wondering....");
        SLEEP(2);
        LOG("Are you gay?");
        SLEEP(2);
        LOG("When you decide please enter.... y (yes) or n (no)");
        SLEEP(2);
        while (1)
        {
            char answer;
            READ(answer);

            if (answer == int('y'))
            {
                CLEAR();
                SLEEP(2);
                LOG(
                    "I thought so ");
                SLEEP(2);
                CLEAR();
                LOG("This video is for you then....");
                SLEEP(2);
                std::string command = "open ";
                command += "https://www.youtube.com/watch?v=4n4rBrs5-LY";
                system(command.c_str());
            }
            else if (answer == int('n'))
            {
                CLEAR();
                SLEEP(2);
                LOG(
                    "Don't lie to yourself");
                SLEEP(2);
                CLEAR();
                LOG("This article is for you");
                SLEEP(2);
                std::string command = "open ";
                command += "https://www.uwtsdunion.co.uk/articles/accepting-your-sexuality";
                system(command.c_str());
            }
            else
            {
                LOG("You fuck that was neither y or n");
                SLEEP(2);
                LOG("Try again");
                SLEEP(2);
                CLEAR();
                LOG("When you decide please enter.... y (yes) or n (no)");
            }
        }
    }

    void task2()
    {
    }

    void run()
    {

        std::thread t1(task1); // Start task 1
        t1.join();             // Wait for task 1 to finish

        // std::thread t2(task2); // Start task 2 after task 1 finishes
        // t2.join();
    }
}

int main()
{
    tasks::run();
    return 0;
}

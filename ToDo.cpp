#include <iostream>
#include <string>
#include <list>
#include <ctime>

int taskCount = 0;
class Task {
public:
    Task() : id(0), name(""), desc(""), completed(false) { taskCount++; };
    ~Task() { taskCount--; };

    void create(std::string newDesc) 
    {
        id = rand() % 100;
        desc = newDesc;
    }
    void changeName(std::string s)
    {
        name = s;
    }
    void changeDesc(std::string s)
    {
        desc = s;
    }
    std::string checkTask()
    {
        return completed ? "done" : "not done";
    }
    int getId()
    {
        return id;
    }
    void makeCompleted()
    {
        completed = true;
    }
    std::string getDescription() { return desc; }
private:
    int id;
    std::string name;
    std::string desc;
    bool completed;
};



int main()
{
    char input_option;
    int input_id;
    std::string input_description;
    std::list<Task> todoItems;
    std::list<Task>::iterator it;

    srand(time(NULL));

    todoItems.clear();

    while (1) {
        system("cls");
        std::cout << "Task Count: " << taskCount << std::endl << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++) {

            std::string completed = it->checkTask();
            std::cout << it->getId() << " | " << it->getDescription() << " | " << completed << std::endl;
        }

        if (todoItems.empty()) {
            std::cout << "Add your first todo!" << std::endl;
        }

        std::cout << std::endl << std::endl;

        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[c]omplete a Todo" << std::endl;
        std::cout << "[q]uit" << std::endl;

        std::cout << "choice: ";

        std::cin >> input_option;

        if (input_option == 'q') {
            std::cout << "Have a great day now!" << std::endl;
            break;
        }
        else if (input_option == 'a') {
            std::cout << "Add a new description: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_description);

            Task newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);

        }
        else if (input_option == 'c') {
            std::cout << "Enter id to mark completed: ";
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++) {

                if (input_id == it->getId()) {
                    it->makeCompleted();
                    break;
                }
            }

        }

    }

    return 0;
}
/*
* ToDo
* Task Count
* Change Desc
* Name
* Normal Button
*/
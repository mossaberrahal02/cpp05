#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat test("name" , 1);
    }
    catch (std::exception& e)
    {
        std::cout << e.what()<<endl;
    }
}
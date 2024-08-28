#include <iostream>
#include <exception>
#include <cstdlib>
#include "Anatex.h"

int main() 
{
    try 
    {
        Anatex anatex;
        anatex.initialize();
        anatex.annotateText();
        
        std::cout << "Processing completed successfully." << std::endl;
    } catch (const std::exception& e) 
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        std::cout << "Press Enter to exit...";
        std::cin.get();
        return EXIT_FAILURE;
    } catch (...) 
    {
        std::cerr << "An unknown error occurred." << std::endl;
        std::cout << "Press Enter to exit...";
        std::cin.get();
        return EXIT_FAILURE;
    }
    
    std::cout << "Press Enter to exit...";
    std::cin.get(); 
    return EXIT_SUCCESS;
}
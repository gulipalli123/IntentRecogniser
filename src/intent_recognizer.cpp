#include "intent_recognizer.h"

int main()
{
    
    while(true)
    {
        std::cout << "Enter Intent string or (q=quit)\n";
        std::string intent_str;
        if(!getline(std::cin, intent_str) || intent_str == "q")
            break;
	if(0 == intent_match(intent_str))
	   std::cout << "could not recognize the intent\n";
		
    }
    return 0;	
}

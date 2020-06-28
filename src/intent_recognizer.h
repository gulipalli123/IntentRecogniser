#ifndef INTENT_RECOGNIZER_H
#define INTENT_RECOGNIZER_H

#include <string>
#include <iostream>
#include <regex>

int intent_match(const std::string& intent_str) 
{
    auto const regex_weather = std::regex("What is the weather like(( )|( in (Paris|New York) ))today\\\?");

    auto const regex_calendar = std::regex("Am I free at ([1][2-9]|2[0]):([0-5][0-9]) PM tomorrow\\\?");

    auto const regex_fact = std::regex("Tell me an interesting fact\\.");

    std::smatch smatch;

    if(std::regex_match(intent_str, smatch, regex_weather))
	std::cout << "Intent: Get Weather " << smatch[4] << "\n";

    else if(std::regex_match(intent_str, smatch, regex_calendar))
	std::cout << "Intent: Check Calendar" << "\n";

    else if(std::regex_match(intent_str, smatch, regex_fact))
	std::cout << "Intent: Get Fact" << "\n";
    
    else
    {
	std::cout << "Invalid input: ";
	return 0;
    }
    return 1;
}

#endif //INTENT_RECOGNIZER_H

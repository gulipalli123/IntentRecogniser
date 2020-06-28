#include "gtest/gtest.h"
#include "../src/intent_recognizer.h"


TEST(IntentRecognitionTestCase, TestWeather1) 
{
    EXPECT_EQ(1, intent_match(std::string("What is the weather like today?")));
}

TEST(IntentRecognitionTestCase, TestWeather2) 
{
    EXPECT_EQ(1, intent_match(std::string("What is the weather like in New York today?")));
}

TEST(IntentRecognitionTestCase, TestWeather3) 
{
    EXPECT_EQ(1, intent_match(std::string("What is the weather like in Paris today?")));
}

TEST(IntentRecognitionTestCase, TestCalendar1) 
{
    EXPECT_EQ(1, intent_match(std::string("Am I free at 13:00 PM tomorrow?")));
}

TEST(IntentRecognitionTestCase, TestCalendar2) 
{
    EXPECT_EQ(1, intent_match(std::string("Am I free at 15:30 PM tomorrow?")));
}

TEST(IntentRecognitionTestCase, TestCalendar3) 
{
    EXPECT_EQ(0, intent_match(std::string("Am I free at 15:75 PM tomorrow?")));
}

TEST(IntentRecognitionTestCase, TestFact) 
{
    EXPECT_EQ(1, intent_match(std::string("Tell me an interesting fact.")));
}

GTEST_API_ int main(int argc, char **argv) 
{
    std::cout << "Running main() from" <<  __FILE__ << "\n";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

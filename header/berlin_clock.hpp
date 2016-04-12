#ifndef BERLIN_CLOCK_HPP_DEFINED
#define BERLIN_CLOCK_HPP_DEFINED

#include <string>
#include <ctime>


enum class LightsRow : uint32_t
{
   SINGLE_MINUTES = 0,
   FIVE_MINUTE_BLOCKS,
   ONE_HOUR_BLOCKS,
   FIVE_HOUR_BLOCKS,
   SECONDS_BLOCK
};

class BerlinClock
{
public:
   BerlinClock();

   bool AssignTime(std::string const& CurrentTime);

   std::string RetrieveLampRow(LightsRow vLampRow);

private:
   std::tm mCurrentTime;
   bool mValidTime;

   std::string CalculateLamps(LightsRow vLampRow, bool UseRemainder = true,
                              bool HasMixedColors = false);

   bool ConvertStrToTime(std::string const& vTime);

};


#endif //BERLIN_CLOCK_HPP_DEFINED

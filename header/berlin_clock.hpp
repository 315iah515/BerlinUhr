#ifndef BERLIN_CLOCK_HPP_DEFINED
#define BERLIN_CLOCK_HPP_DEFINED

#include <string>
#include <vector>
#include <ctime>

#include "rgba.hpp"

enum class LampRow : uint32_t
{
   SINGLE_MINUTES = 0,
   FIVE_MINUTE_BLOCKS,
   ONE_HOUR_BLOCKS,
   FIVE_HOUR_BLOCKS,
   SECONDS_BLOCK
};

//--------------------------------------------------------------------------------------------------
//  Class:
//      BerlinClock
//
//  Summary:
//      Provides all of the logic for the Mengenlehreclock
//
//
//  Remarks:
//      {Optional...}
//
//  See Also:
//      {Optional...}
//--------------------------------------------------------------------------------------------------
//
class BerlinClock
{
public:
   using LampColors = std::vector<Rgba>;

   BerlinClock();

   LampColors RetrieveLampRow(LampRow vLampRow);

private:
   std::tm *mpCurrentTime;

   LampColors CalculateLamps(LampRow vLampRow, bool UseRemainder = true, bool HasMixedColors = false);
   bool ConvertStrToTime(std::string const& vTime);

};


#endif //BERLIN_CLOCK_HPP_DEFINED

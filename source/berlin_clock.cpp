#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <array>
#include "berlin_clock.hpp"


namespace
{
   using LampPair = std::pair<unsigned int, unsigned int>;

   std::array<LampPair, 5> sNumLampsPerRow = {
      std::make_pair(4, 'Y'),
      std::make_pair(11, 'Y'),
      std::make_pair(4, 'R'),
      std::make_pair(4, 'R'),
      std::make_pair(1, 'R')
   };

}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      BerlinClock()
//
//  Summary:
//      Slot - Does...
//
//
//
//  Exceptions:
//      {Optional...}
//
//  Remarks:
//
//
//  See Also:
//      {Optional...}
//--------------------------------------------------------------------------------------------------
//
BerlinClock::BerlinClock()
   : mpCurrentTime(nullptr)
{
}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      RetrieveLampRow()
//
//  Summary:
//      Slot - Does...
//
//
//
//  Exceptions:
//      {Optional...}
//
//  Remarks:
//
//
//  See Also:
//      {Optional...}
//--------------------------------------------------------------------------------------------------
//
BerlinClock::LampColors
BerlinClock::RetrieveLampRow(LampRow vLampRow)
{
    LampColors LampResult;

    time_t now = time(nullptr);
    mpCurrentTime = std::localtime(&now);

//    switch (vLampRow)
//    {
//    case LampRow::SINGLE_MINUTES: LampResult = CalculateLamps(vLampRow);
//        break;

//    case LampRow::FIVE_MINUTE_BLOCKS: LampResult = CalculateLamps(vLampRow, false, true);
//        break;

//    case LampRow::ONE_HOUR_BLOCKS: LampResult = CalculateLamps(vLampRow);
//        break;

//    case LampRow::FIVE_HOUR_BLOCKS: LampResult = CalculateLamps(vLampRow, false);
//        break;

//    case LampRow::SECONDS_BLOCK: LampResult = CalculateLamps(vLampRow);
//        break;
//    }


    return LampResult;
}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      RetrieveLampRow()
//
//  Summary:
//      Does...
//
//
//
//  Exceptions:
//      {Optional...}
//
//  Remarks:
//
//
//  See Also:
//      {Optional...}
//--------------------------------------------------------------------------------------------------
//
std::string 
BerlinClock::CalculateLamps(LampRow vLampRow, bool UseRemainder, bool HasMixedColors)
{
   std::string Lamps;

   std::div_t Result{};

   if (vLampRow == LampRow::SINGLE_MINUTES || vLampRow == LampRow::FIVE_MINUTE_BLOCKS)
   {
      Result = std::div(mpCurrentTime->tm_min, 5);
   }
   else if (vLampRow == LampRow::ONE_HOUR_BLOCKS || vLampRow == LampRow::FIVE_HOUR_BLOCKS)
   {
      Result = std::div(mpCurrentTime->tm_hour, 5);
   }
   else
   //- A bit of a kluge but for all other time components the quotient or remainder is
   // the number of lights on, except for seconds where the reminder is used to determine
   // if the number of seconds is even. The light is On for even seconds or off otherwise. 
   {
      Result = std::div(mpCurrentTime->tm_sec, 2);
      Result.rem = Result.rem == 0 ? 1 : 0;
   }

   unsigned int total_lamps = sNumLampsPerRow[(uint32_t)vLampRow].first;

   unsigned int number_of_lamps_on = (UseRemainder ? Result.rem : Result.quot);
   unsigned int number_of_lamps_off = total_lamps - number_of_lamps_on;

   //- For LampRow::FIVE_MINUTE_BLOCKS where yellow and red are used
   if (HasMixedColors)
   {
      for (std::size_t i = 0; i < number_of_lamps_on; ++i)
      {
         if ((i + 1) % 3 == 0)
         {
            Lamps.append(1, 'R');
         }
         else
         {
            Lamps.append(1, sNumLampsPerRow[(uint32_t)vLampRow].second);
         }
      }
   }
   else
   {
      Lamps.append(number_of_lamps_on, sNumLampsPerRow[(uint32_t)vLampRow].second);
   }
   
   Lamps.append(number_of_lamps_off, 'O');

   return Lamps;
}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      ConvertStrToTime()
//
//  Summary:
//      Does...
//
//
//
//  Exceptions:
//      {Optional...}
//
//  Remarks:
//
//
//  See Also:
//      {Optional...}
//--------------------------------------------------------------------------------------------------
//
bool
BerlinClock::ConvertStrToTime(std::string const & vTime)
{
   bool Result = false;
   std::istringstream Ss(vTime);
   Ss >> std::get_time(mpCurrentTime, "%H:%M:%S");

   if (!Ss.fail())
   {
      Result = true;
      //std::cout << std::put_time(&mpCurrentTime, "%T") << std::endl;
   }

   return Result;
}

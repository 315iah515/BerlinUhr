//========================================================================================
//  File Name:
//      berlin_clock.cpp
//
//
//  Authors:
//      Ian Heaton
//
//========================================================================================
//
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <array>
#include <tuple>
#include "berlin_clock.hpp"


namespace
{
   const Rgba sRedOn(255, 39, 0);
   const Rgba sRedOff(117, 41, 38);
   const Rgba sYellowOn(252, 249, 0);
   const Rgba sYellowOff(116, 108, 12);

   using LampTuple = std::tuple<unsigned int, Rgba, Rgba>;

   std::array<LampTuple, 5> sNumLampsPerRow = {
      std::make_tuple(4, sYellowOn, sYellowOff),
      std::make_tuple(11, sYellowOn, sYellowOff),
      std::make_tuple(4, sRedOn, sRedOff),
      std::make_tuple(4, sRedOn, sRedOff),
      std::make_tuple(1, sYellowOn, sYellowOff)
   };


}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      BerlinClock()
//
//  Summary:
//     Constructor for Berlin Clock
//
//
//  Remarks:
//
//
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
//      Determines the number of lamps on and off for a particular row and the current time.
//
//   Parameters:
//      vLampRow -
//          [in] Enumeration that specifies the desired lamp row
//
//  Remarks:
//
//--------------------------------------------------------------------------------------------------
//
BerlinClock::LampColors
BerlinClock::RetrieveLampRow(LampRow vLampRow)
{
    LampColors LampResult;

    time_t now = time(nullptr);
    mpCurrentTime = std::localtime(&now);

    switch (vLampRow)
    {
    case LampRow::SINGLE_MINUTES: LampResult = CalculateLamps(vLampRow);
        break;

    case LampRow::FIVE_MINUTE_BLOCKS: LampResult = CalculateLamps(vLampRow, false, true);
        break;

    case LampRow::ONE_HOUR_BLOCKS: LampResult = CalculateLamps(vLampRow);
        break;

    case LampRow::FIVE_HOUR_BLOCKS: LampResult = CalculateLamps(vLampRow, false);
        break;

    case LampRow::SECONDS_BLOCK: LampResult = CalculateLamps(vLampRow);
        break;
    }


    return LampResult;
}


//--------------------------------------------------------------------------------------------------
//  Member Function:
//      CalculateLamps()
//
//  Summary:
//     Performs all of the heavy lifting in computing which lamps are on vs off.
//
//  Parameters:
//      vLampRow -
//          [in] The lamp row desired.
//      UseRemainder -
//          [in] Some rows will use the remainder from the division of the current hour and the
//          value 5 to determine the number of lamps in the on state.
//      HasMixedColors -
//          [in] Determines if two different colors are to be used for painting those lamps
//          that are on.
//
//--------------------------------------------------------------------------------------------------
//
BerlinClock::LampColors
BerlinClock::CalculateLamps(LampRow vLampRow, bool UseRemainder, bool HasMixedColors)
{
   LampColors LampResult;
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

   unsigned int total_lamps = std::get<0>(sNumLampsPerRow[(uint32_t)vLampRow]);
   unsigned int number_of_lamps_on = (UseRemainder ? Result.rem : Result.quot);
   unsigned int number_of_lamps_off = total_lamps - number_of_lamps_on;

   //- For LampRow::FIVE_MINUTE_BLOCKS where yellow and red are used
   if (HasMixedColors)
   {
      for (std::size_t i = 0; i < number_of_lamps_on; ++i)
      {
         if ((i + 1) % 3 == 0)
         {
            LampResult.push_back(sRedOn);
         }
         else
         {
            LampResult.push_back(std::get<1>(sNumLampsPerRow[(uint32_t)vLampRow]));
         }
      }
   }
   //- All other rows
   else
   {
      for (int i = 0; i < number_of_lamps_on; ++i)
      {
          LampResult.push_back(std::get<1>(sNumLampsPerRow[(uint32_t)vLampRow]));
      }

   }

   //- Now we handle all the lamps that are not turned on
   for (int i = 0; i < number_of_lamps_off; ++i)
   {
        LampResult.push_back(std::get<2>(sNumLampsPerRow[(uint32_t)vLampRow]));
   }
   
   return LampResult;
}

//--------------------------------------------------------------------------------------------------
//  Member Function:
//      ConvertStrToTime()
//
//  Summary:
//      Utility method that converts a string to a time structure housing the date and time;
//      used for testing
//
//   Parameters:
//      vTime -
//          [in] Immutable string housing the time to test.
//
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

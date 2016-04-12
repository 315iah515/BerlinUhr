#include <iomanip>
#include <sstream>
#include <iostream>
#include  <cstdlib>
#include <array>
#include "berlin_clock.hpp"


namespace
{
   using LampPair = std::pair<unsigned int, char>;

   std::array<LampPair, 5> sNumLampsPerRow = {
      std::make_pair(4, 'Y'),
      std::make_pair(11, 'Y'),
      std::make_pair(4, 'R'),
      std::make_pair(4, 'R'),
      std::make_pair(1, 'R')
   };

}


BerlinClock::BerlinClock()
   : mCurrentTime(),
     mValidTime(false)
{
}

bool 
BerlinClock::AssignTime(std::string const & CurrentTime)
{
   mValidTime = ConvertStrToTime(CurrentTime);

   if (!mValidTime)
   {
      std::cout << "Parsing of input string failed, please use hh:mm:ss format." << std::endl;
   }
   
   return mValidTime;
}

std::string
BerlinClock::RetrieveLampRow(LightsRow vLampRow)
{
   std::string LampResult;

   if (mValidTime)
   {
      switch (vLampRow)
      {
      case LightsRow::SINGLE_MINUTES: LampResult = CalculateLamps(vLampRow);
         break;

      case LightsRow::FIVE_MINUTE_BLOCKS: LampResult = CalculateLamps(vLampRow, false, true);
         break;

      case LightsRow::ONE_HOUR_BLOCKS: LampResult = CalculateLamps(vLampRow);
         break;

      case LightsRow::FIVE_HOUR_BLOCKS: LampResult = CalculateLamps(vLampRow, false);
         break;

      case LightsRow::SECONDS_BLOCK: LampResult = CalculateLamps(vLampRow);
         break;
      }
   }

   return LampResult;
}



std::string 
BerlinClock::CalculateLamps(LightsRow vLampRow, bool UseRemainder, bool HasMixedColors)
{
   std::string Lamps;

   std::div_t Result{};

   if (vLampRow == LightsRow::SINGLE_MINUTES || vLampRow == LightsRow::FIVE_MINUTE_BLOCKS)
   {
      Result = std::div(mCurrentTime.tm_min, 5);
   }
   else if (vLampRow == LightsRow::ONE_HOUR_BLOCKS || vLampRow == LightsRow::FIVE_HOUR_BLOCKS)
   {
      Result = std::div(mCurrentTime.tm_hour, 5);
   }
   else
   //- A bit of a kluge but for all other time components the quotient or remainder is
   // the number of lights on, except for seconds where the reminder is used to determine
   // if the number of seconds is even. The light is On for even seconds or off otherwise. 
   {
      Result = std::div(mCurrentTime.tm_sec, 2);
      Result.rem = Result.rem == 0 ? 1 : 0;
   }

   unsigned int total_lamps = sNumLampsPerRow[(uint32_t)vLampRow].first;

   unsigned int number_of_lamps_on = (UseRemainder ? Result.rem : Result.quot);
   unsigned int number_of_lamps_off = total_lamps - number_of_lamps_on;

   //- For LightsRow::FIVE_MINUTE_BLOCKS where yellow and red are used
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


bool
BerlinClock::ConvertStrToTime(std::string const & vTime)
{
   bool Result = false;
   std::istringstream Ss(vTime);
   Ss >> std::get_time(&mCurrentTime, "%H:%M:%S");

   if (!Ss.fail())
   {
      Result = true;
      //std::cout << std::put_time(&mCurrentTime, "%T") << std::endl;
   }

   return Result;
}

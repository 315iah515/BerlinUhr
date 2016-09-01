#include <cassert>
#include "berlin_clock.hpp"
#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
   BerlinClock Bc;

    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    w.show();

    return a.exec();

   // Tests for single minute lamps
//   std::string MinuteResultLamps;
//   std::string FiveMinuteBlock;
//   std::string OneHourBlock;
//   std::string FiveHourBlock;
//   std::string OneSecondBlock;

//   Bc.AssignTime("00:00:00");
//   MinuteResultLamps = Bc.RetrieveLampRow(LightsRow::SINGLE_MINUTES);
//   FiveMinuteBlock = Bc.RetrieveLampRow(LightsRow::FIVE_MINUTE_BLOCKS);
//   OneHourBlock = Bc.RetrieveLampRow(LightsRow::ONE_HOUR_BLOCKS);
//   FiveHourBlock = Bc.RetrieveLampRow(LightsRow::FIVE_HOUR_BLOCKS);
//   OneSecondBlock = Bc.RetrieveLampRow(LightsRow::SECONDS_BLOCK);
//   assert(MinuteResultLamps == "OOOO");
//   assert(FiveMinuteBlock == "OOOOOOOOOOO");
//   assert(OneHourBlock == "OOOO");
//   assert(FiveHourBlock == "OOOO");
//   assert(OneSecondBlock == "R");

//   Bc.AssignTime("23:59:59");
//   MinuteResultLamps = Bc.RetrieveLampRow(LightsRow::SINGLE_MINUTES);
//   FiveMinuteBlock = Bc.RetrieveLampRow(LightsRow::FIVE_MINUTE_BLOCKS);
//   OneHourBlock = Bc.RetrieveLampRow(LightsRow::ONE_HOUR_BLOCKS);
//   FiveHourBlock = Bc.RetrieveLampRow(LightsRow::FIVE_HOUR_BLOCKS);
//   OneSecondBlock = Bc.RetrieveLampRow(LightsRow::SECONDS_BLOCK);
//   assert(MinuteResultLamps == "YYYY");
//   assert(FiveMinuteBlock == "YYRYYRYYRYY");
//   assert(OneHourBlock == "RRRO");
//   assert(FiveHourBlock == "RRRR");
//   assert(OneSecondBlock == "O");

//   Bc.AssignTime("12:32:00");
//   MinuteResultLamps = Bc.RetrieveLampRow(LightsRow::SINGLE_MINUTES);
//   assert(MinuteResultLamps ==  "YYOO");

//   Bc.AssignTime("12:34:00");
//   MinuteResultLamps = Bc.RetrieveLampRow(LightsRow::SINGLE_MINUTES);
//   assert(MinuteResultLamps ==  "YYYY");

//   Bc.AssignTime("12:35:00");
//   MinuteResultLamps = Bc.RetrieveLampRow(LightsRow::SINGLE_MINUTES);
//   FiveMinuteBlock = Bc.RetrieveLampRow(LightsRow::FIVE_MINUTE_BLOCKS);
//   assert(MinuteResultLamps ==  "OOOO");
//   assert(FiveMinuteBlock == "YYRYYRYOOOO");

//   Bc.AssignTime("22:13:34");
//   MinuteResultLamps = Bc.RetrieveLampRow(LightsRow::SINGLE_MINUTES);
//   OneSecondBlock = Bc.RetrieveLampRow(LightsRow::SECONDS_BLOCK);
//   assert(MinuteResultLamps == "YYYO");
//   assert(OneSecondBlock == "R");


//   // Only five minute block tests
//   Bc.AssignTime("12:04:00");
//   FiveMinuteBlock = Bc.RetrieveLampRow(LightsRow::FIVE_MINUTE_BLOCKS);
//   assert(FiveMinuteBlock == "OOOOOOOOOOO");

//   Bc.AssignTime("12:23:00");
//   FiveMinuteBlock = Bc.RetrieveLampRow(LightsRow::FIVE_MINUTE_BLOCKS);
//   assert(FiveMinuteBlock == "YYRYOOOOOOO");

//   // One Hour block tests
//   Bc.AssignTime("02:04:00");
//   OneHourBlock = Bc.RetrieveLampRow(LightsRow::ONE_HOUR_BLOCKS);
//   FiveHourBlock = Bc.RetrieveLampRow(LightsRow::FIVE_HOUR_BLOCKS);
//   assert(OneHourBlock == "RROO");
//   assert(FiveHourBlock == "OOOO");


//   Bc.AssignTime("08:23:00");
//   OneHourBlock = Bc.RetrieveLampRow(LightsRow::ONE_HOUR_BLOCKS);
//   FiveHourBlock = Bc.RetrieveLampRow(LightsRow::FIVE_HOUR_BLOCKS);
//   assert(OneHourBlock == "RRRO");
//   assert(FiveHourBlock == "ROOO");

//   Bc.AssignTime("14:35:00");
//   OneHourBlock = Bc.RetrieveLampRow(LightsRow::ONE_HOUR_BLOCKS);
//   assert(OneHourBlock == "RRRR");

//   Bc.AssignTime("05:00:00");
//   OneHourBlock = Bc.RetrieveLampRow(LightsRow::ONE_HOUR_BLOCKS);
//   assert(OneHourBlock == "OOOO");

//   // Five Hour block tests
//   Bc.AssignTime("16:35:00");
//   FiveHourBlock = Bc.RetrieveLampRow(LightsRow::FIVE_HOUR_BLOCKS);
//   assert(FiveHourBlock == "RRRO");

//   return 0;
}


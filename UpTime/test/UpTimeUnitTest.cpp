#include "../include/acutest.h"
#include "../include/pch.h"



		void testConvertionCase1(void){
			std::string startServer = "up 5 min";
			std::string inActivity = "idle 5 min";

			Duration testedDuration = converstion(5 * 60, 5 * 60);
			
			
			TEST_ASSERT( 
				( 
					startServer == (testedDuration.startServer.erase(0, testedDuration.startServer.find(" ") + 1) )
					&& ( inActivity == (testedDuration.inActivity.erase(0, testedDuration.inActivity.find(" ") + 1) ) )  
					  
				) );
		}

		void testConvertionCase2(void)
		{
			std::string startServer = "up 16:05";
			std::string inActivity = "idle 16:05";

			Duration testedDuration = converstion(5 * 60 + 16 * 3600, 5 * 60 + 16 * 3600);

			TEST_ASSERT( 
				( 
					startServer == (testedDuration.startServer.erase(0, testedDuration.startServer.find(" ") + 1) )
					&& ( inActivity == (testedDuration.inActivity.erase(0, testedDuration.inActivity.find(" ") + 1) ) )  
					  
				) );
		}
		void testConvertionCase3(void)
		{
			std::string startServer = "up 1 day, 5 min";
			std::string inActivity = "idle 1 day, 5 min";

			Duration testedDuration = converstion(5 * 60 + 24 * 3600, 5 * 60 + 24 * 3600);

			TEST_ASSERT( 
				( 
					startServer == (testedDuration.startServer.erase(0, testedDuration.startServer.find(" ") + 1) )
					&& ( inActivity == (testedDuration.inActivity.erase(0, testedDuration.inActivity.find(" ") + 1) ) )  
					  
				) );
		}

		void testConvertionCase4(void)
		{
			std::string startServer = "up 1 day, 16:05";
			std::string inActivity = "idle 1 day, 16:05";

			Duration testedDuration = converstion(5 * 60 + 16 * 3600 + 24 * 3600, 5 * 60 + 16 * 3600 + 24 * 3600);

			TEST_ASSERT( 
				( 
					startServer == (testedDuration.startServer.erase(0, testedDuration.startServer.find(" ") + 1) )
					&& ( inActivity == (testedDuration.inActivity.erase(0, testedDuration.inActivity.find(" ") + 1) ) )  
					  
				) );
		}

		void testConvertionCase5(void)
		{
			std::string startServer = "up 178 days, 5 min";
			std::string inActivity = "idle 178 days, 5 min";

			Duration testedDuration = converstion(178 * 24 * 3600 + 5 * 60, 178 * 24 * 3600 + 5 * 60);

			TEST_ASSERT( 
				( 
					startServer == (testedDuration.startServer.erase(0, testedDuration.startServer.find(" ") + 1) )
					&& ( inActivity == (testedDuration.inActivity.erase(0, testedDuration.inActivity.find(" ") + 1) ) )  
					  
				) );
		}

		void testConvertionCase6(void)
		{
			std::string startServer = "up 178 days, 16:05";
			std::string inActivity = "idle 178 days, 16:05";

			Duration testedDuration = converstion(178 * 24 * 3600 + 5 * 60 + 16 * 3600, 178 * 24 * 3600 + 5 * 60 + 16 * 3600);

			TEST_ASSERT( 
				( 
					startServer == (testedDuration.startServer.erase(0, testedDuration.startServer.find(" ") + 1) )
					&& ( inActivity == (testedDuration.inActivity.erase(0, testedDuration.inActivity.find(" ") + 1) ) )  
					  
				) );
		}

		void testConvertFromSecond(void)
		{
			Result res = Result();
			res.days = 173;
			res.hours = 16;
			res.minutes = 5;

			Result testedConvertion = convertFromSecond(15005117.05);

			TEST_ASSERT( (res.days == testedConvertion.days && res.hours == testedConvertion.hours && res.minutes == testedConvertion.minutes ) );
		}

		TEST_LIST = {
			{"1 converstion(300, 300) ? 5 min",testConvertionCase1},
			{"2 converstion(57900, 57900) ? 16h, 5 min",testConvertionCase2},
			{"3 converstion(86700, 86700) ? 1 day, 5 min",testConvertionCase3},
			{"4 converstion(144300, 144300) ? 1 day, 16h, 5 min",testConvertionCase4},
			{"5 converstion(15379500, 15379500) ? 178 days, 5 min",testConvertionCase5},
			{"6 converstion(15437100, 15437100) ? 178 days, 16, 5 min",testConvertionCase6},
			{"7 convertFromSecond(15005117.05) ? 173 days, 16, 5 min",testConvertFromSecond},
			{0,0}
		};

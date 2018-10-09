#ifndef PAGERULES_h
#define PAGERULES_h

struct BankRules{
  const int primaryMidiControll;
  const int secondaryMidiControll;
  const bool flip;
  const bool doubleClick;

  const int expressionControll;
};

struct PageRules{

  const String title;
  const BankRules bankRules[4];

};

int currentPage = 0;

const PageRules PAGERULES[10] = {

	{
		//	==============
		//	   PAGE 0   
		//	==============

		"Home",	//Display Letters
		{	//ControllBanks
			{
				//	==============
				//	   BANK 0   
				//	==============

				0,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				1,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 1   
				//	==============

				2,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				3,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 2   
				//	==============

				4,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				5,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 3   
				//	==============

				6,	//Primary midi control
				80,	//Secondary midi control
				false,	//Flip
				true,	//DoubleClick

				7,	//Expression midi controll
			},
		}
	},

	{
		//	==============
		//	   PAGE 1   
		//	==============

		"Lop1",	//Display Letters
		{	//ControllBanks
			{
				//	==============
				//	   BANK 4   
				//	==============

				8,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				9,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 5   
				//	==============

				10,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				11,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 6   
				//	==============

				12,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				13,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 7   
				//	==============

				14,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				15,	//Expression midi controll
			},
		}
	},

	{
		//	==============
		//	   PAGE 2   
		//	==============

		"Lop2",	//Display Letters
		{	//ControllBanks
			{
				//	==============
				//	   BANK 8   
				//	==============

				16,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				17,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 9   
				//	==============

				18,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				19,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 10   
				//	==============

				20,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				21,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 11   
				//	==============

				22,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				23,	//Expression midi controll
			},
		}
	},

	{
		//	==============
		//	   PAGE 3   
		//	==============

		"Move",	//Display Letters
		{	//ControllBanks
			{
				//	==============
				//	   BANK 12   
				//	==============

				24,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				25,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 13   
				//	==============

				26,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				27,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 14   
				//	==============

				28,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				29,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 15   
				//	==============

				30,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				31,	//Expression midi controll
			},
		}
	},

	{
		//	==============
		//	   PAGE 4   
		//	==============

		"Pg 1",	//Display Letters
		{	//ControllBanks
			{
				//	==============
				//	   BANK 16   
				//	==============

				32,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				33,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 17   
				//	==============

				34,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				35,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 18   
				//	==============

				36,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				37,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 19   
				//	==============

				38,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				39,	//Expression midi controll
			},
		}
	},

	{
		//	==============
		//	   PAGE 5   
		//	==============

		"Pg 2",	//Display Letters
		{	//ControllBanks
			{
				//	==============
				//	   BANK 20   
				//	==============

				40,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				41,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 21   
				//	==============

				42,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				43,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 22   
				//	==============

				44,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				45,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 23   
				//	==============

				46,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				47,	//Expression midi controll
			},
		}
	},

	{
		//	==============
		//	   PAGE 6   
		//	==============

		"Pg 3",	//Display Letters
		{	//ControllBanks
			{
				//	==============
				//	   BANK 24   
				//	==============

				48,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				49,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 25   
				//	==============

				50,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				51,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 26   
				//	==============

				52,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				53,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 27   
				//	==============

				54,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				55,	//Expression midi controll
			},
		}
	},

	{
		//	==============
		//	   PAGE 7   
		//	==============

		"Pg 4",	//Display Letters
		{	//ControllBanks
			{
				//	==============
				//	   BANK 28   
				//	==============

				56,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				57,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 29   
				//	==============

				58,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				59,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 30   
				//	==============

				60,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				61,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 31   
				//	==============

				62,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				63,	//Expression midi controll
			},
		}
	},

	{
		//	==============
		//	   PAGE 8   
		//	==============

		"Pg 5",	//Display Letters
		{	//ControllBanks
			{
				//	==============
				//	   BANK 32   
				//	==============

				64,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				65,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 33   
				//	==============

				66,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				67,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 34   
				//	==============

				68,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				69,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 35   
				//	==============

				70,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				71,	//Expression midi controll
			},
		}
	},

	{
		//	==============
		//	   PAGE 9   
		//	==============

		"Pg 6",	//Display Letters
		{	//ControllBanks
			{
				//	==============
				//	   BANK 36   
				//	==============

				72,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				73,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 37   
				//	==============

				74,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				75,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 38   
				//	==============

				76,	//Primary midi control
				-1,	//Secondary midi control
				true,	//Flip
				false,	//DoubleClick

				77,	//Expression midi controll
			},
			{
				//	==============
				//	   BANK 39   
				//	==============

				78,	//Primary midi control
				-1,	//Secondary midi control
				false,	//Flip
				false,	//DoubleClick

				79,	//Expression midi controll
			},
		}
	}

};



#endif
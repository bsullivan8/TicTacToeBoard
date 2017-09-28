/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
#include <string.h>
//TESTING PLACE PIECE FUNCTIONALITY///
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

 /*
Bug: Places a piece (X,O) on the board determined by the variable BOARDSIZE and changes turn so the other player
	can place their piece. If you Place a piece Exactly Equal to BOARDSIZE the program seg faults.
*/
TEST(TicTacToeBoardTest, Invalid_Col)
{
	char x;
	TicTacToeBoard test;
	x = test.placePiece(0,BOARDSIZE);
	ASSERT_EQ(x,Invalid);
}
TEST(TicTacToeBoardTest, Invalid_Row)
{
	char x;
	TicTacToeBoard test;
	x = test.placePiece(BOARDSIZE,0);
	ASSERT_EQ(x,Invalid);
}
TEST(TicTacToeBoardTest, valid_Col)
{
	char x;
	TicTacToeBoard test;
	x = test.placePiece(0,BOARDSIZE-1);
	ASSERT_NE(x,Blank);
}
TEST(TicTacToeBoardTest, valid_Row)
{
	char x;
	TicTacToeBoard test;
	x = test.placePiece(BOARDSIZE-1,0);
	ASSERT_NE(x,Blank);
}
TEST(TicTacToeBoardTest, Check_Blank)
{
	char x;
	TicTacToeBoard test;
	x = test.placePiece(0,0);
	ASSERT_EQ(x,Blank);
}
TEST(TicTacToeBoardTest, Place_Piece_Nonempty)
{
	char x;
	char y;
	TicTacToeBoard test;
	y=test.placePiece(0,0);
	x = test.placePiece(0,0);
	ASSERT_EQ(x,y);
}
TEST(TicTacToeBoardTest, Check_Board_Filled)
{
	char x;
	TicTacToeBoard test;
	for(int i = 0; i<BOARDSIZE; i++)
	{
		for(int j = 0; j<BOARDSIZE; j++)
		{
			x = test.placePiece(i,j);
			ASSERT_NE(x,Blank);
		}
	}
}
/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/

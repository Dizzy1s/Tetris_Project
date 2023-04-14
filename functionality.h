/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */
//---Piece Starts to Fall When Game Starts---//
//#include <iostream>
#include <fstream> // FOR FILE HANDLING

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

/////////////////////////////////////////////
	bool ceiling()
	{
		bool ending = false;
		int counter = 0;
		for (int loop = 0; loop <10; loop++)
			for (int i = 0; i<10; i++)
				if (gameGrid[0][i] || gameGrid[-1][i] || gameGrid[1][i])
				{
					counter++;	// increases in counter if there is a block at the start at the end
				}
			if (counter != 0)	// increase in counter ends the game (temporarily)
			{
			 ending = true;
			}
		return ending;
	}
	
/////////////////////////////////////////////
int row_displacement(int & lines_gone)
	{
	int ro = 0;
	int do_it = 0;
	//for (int row = 0; row<20; row++)
	//for (int col =0; col <10; col++)
	//std :: cout <<"Position: " <<row <<" " << col << ": "  << gameGrid[row][col] << std :: endl; //to show on terminal where the point is stored
	ro = 19;  // Total indexes of the rows ( Vertical tiles)
	for(int row = M-1; row>=0; row--)
	{
		do_it = 0;		// instead of using an array we check for every line if there is a block and intialise to zero again
		for(int col =0; col <N; col++)
		{
			if (gameGrid[row][col])	// if block exists in the row then add 1 in the variable (do_it) which marks all blocks
			{
				do_it++;
			}
			gameGrid[ro][col] = gameGrid[row][col]; // if the block exists it should move to the bottom row intially if not all blocks are present in the row it should move to the row above, to go above we minus from the bottom row since rows increase downwards and coloumns increase towards right.
		}
		if (do_it >= N)
		{
			lines_gone++;
		}
		if (do_it < N)
		{
			ro--;       // if blocks arent all present in the row move towards the above row and check if there are blocks present there
		}	    
	}	   
	return lines_gone;
	}
////////////////////////////////////////
int game_level(int& lines_gone,float& delay,int& leveling)
{
	int difficulty = 0;
	if (lines_gone <= 5)
	{
		delay = 0.3;				// starting with a slow pace and only 4 basic shapes
		difficulty = rand()% 4;	// if the user is just starting it starts with easy level .
		leveling = 1;
	}
	if (lines_gone > 5)	// if the user is done with 5 rows then it shifts to the hard level.
	{
		difficulty = rand()% 7;	// when moved on to advanced level the pace increases and and total shapes become 7
		delay = 0.175;
		leveling = 2;
	}
	return difficulty;
}
//////////////////////////////////////////
 void fallingPiece(float& timer, float& delay, int& colorNum,int lines_gone,int& leveling)
 {
		int n = 0;
		int lines = row_displacement(lines_gone); 		// returning number of lines destroyed yet.
		if (timer>delay)
		{
				for (int i=0;i<4;i++)
				{
				    point_2[i][0]=point_1[i][0];
				    point_2[i][1]=point_1[i][1];
				    point_1[i][1]+=1;                   //How much units downward the falling block moves
				}
				
				if (!anamoly())
				{
				    for (int i = 0; i < 4; i++)
				    {
				   		 gameGrid[point_2[i][1]][point_2[i][0]] = colorNum;
				    }
				    colorNum = 1 + rand() % 7;				// random colors
				    n = game_level(lines,delay,leveling);	// Deciding how many blocks should be placed according to the level
				    			//--- BLOCKS---//
				    
				    for (int i=0;i<4;i++)
				    {
				          point_1[i][0] = BLOCKS[n][i] % 2;
				          point_1[i][1] = BLOCKS[n][i] / 2;		// making the shapes
				    }
				    
			   }
			   
				timer=0;
	   }
		  delay = 0.3;
 }

// Note to self: point_1[i][0] is for x-axis;
//	       : point_1[i][1] is for y-axis; ==> DO NOT MESS WITH THIS


	void move_x(int delta_x)
	{
		for (int i=0;i<4;i++)
		{
				point_2[i][0]=point_1[i][0];
		        point_2[i][1]=point_1[i][1];		// Storing previous positions in the point_2 array
				point_1[i][0] += delta_x;			// Depending on what key is pressed the horizontal axis are summed or subtracted
		}	
		delta_x = 0;
		if (!anamoly())
		{
			for (int i=0;i<4;i++)
			{
				point_1[i][0] = point_2[i][0];	// if there is an anamoly meaning undesireble outcome then return to the previos points
			}
		}	
	}

	
/////////////////////////////////////////////

void rotating_pieces(bool &rotate)
{ 	
	int center_position_row = 0;		 // Rows deal with The y-axis co-ordinates
	int center_position_col = 0;		//  Coloumns deal with The x-axis co-ordinates 	
	int new_position_row = 0;	// points to hold off-set ===> Horizontal
	int new_position_col = 0;	// points to hold off-set ===> Vertical
	if (rotate == true)
	{
			center_position_row = point_1[1][1];			// for every single shape the 2nd co-ordinate can be the center of rotation as it is very easy to make offset co-ordinates of each particular piece and implenment them in the point_1 array to hold the co-oridnates
			center_position_col = point_1[1][0];		
			for (int i = 0 ; i < 4 ; i++)
			{
				new_position_col = point_1[i][1] - center_position_row;	// shifting y-axis offsets to x-axis
				new_position_row = point_1[i][0] - center_position_col;   	// shifting x-axis offsets to y-axis
				point_1[i][0] = center_position_col - new_position_col;
				point_1[i][1] = center_position_row + new_position_row;	 	
				   // Holding the offset notations in a matrix . i.e your new shape after rotations of constant 90 degress on a singular point providing 4 different rotations around the center position
			}							 
			
			if (!anamoly())
			{
				for (int i=0;i<4;i++)
				{
					point_1[i][0] = point_2[i][0];
					point_1[i][1] = point_2[i][1];
				}
			}
			
	 }
			rotate = false;
}

/////////////////////////////////////////////

void shadow_below()
{
	for (int i = 0; i <4; i++)
	{
		shadow[i][1] = point_1[i][1];
		shadow[i][0] = point_1[i][0];			// Giving the co-ordinates of the shape to the shadow
	}
	while (shadow_anamoly())
	{
		for (int i = 0; i < 4; i++)
		{
			shadow[i][1]++;						// incrementing in the shadow till an undesireble outcome i.e an anamoly is reached which means incremnting till the shadow either reaches the bottom frame or another block
		}
	}
}
/////////////////////////////////////////////
void bomby(float& timer, float& delay, int& colorNum, bool& bomb_fall, int& bomb_count_num)
{
	if (bomb_fall == true)
	{
		if (timer>delay)
		{										// same as the falling function
		    for (int i=0;i<4;i++)
		    {	
		        bomb_2[i][1] = bomb[i][1];
		        bomb_2[i][0] = bomb[i][0];
		        bomb[i][1]+=1;                   //How much units downward the bomb moves
		    }
		    if (!bomb_anamoly())
		    {
		        for (int i = 0; i < 4; i++)
		        {
		        	gameGrid[bomb[i][1]][bomb[i][0]] = colorNum;	// giving a color where the bomb lands 
		        }
		        bomb_count_num++;	// incrementing so that the fall command for the bomb only runs once
		        for (int i=0;i<4;i++)
		    	{	
		        	bomb_2[i][1] = 0;
		       		bomb_2[i][0] = 0;     	// ERASING PREVIOUS COORDINATES        
		    	}
		    	bomb_fall = false;
		   }
		    timer=0;
		}
		  delay = 0.3;
	}

}
/////////////////////////////////////////////
void instant_jump(bool& jump)
{
	if (jump == true)
	{
		for (int i = 0; i < 4; i++)
		{
			point_1[i][0] = shadow[i][0];		// Giving Co-ordinates of shadow to the block shape
			point_1[i][1] = shadow[i][1];
		}
	}
	jump = false;
	if (!anamoly())
	{
		for (int i=0;i<4;i++)
		{
			point_1[i][0] = point_2[i][0];
			point_1[i][1] = point_2[i][1];		// if there is an error return the blocks to their original position
		}
	}
}
/////////////////////////////////////////////
void scoring(int lines_gone,int& line_counter)
{
	int score = 0;
	int max = 0;
	score = 10 * lines_gone;		// Calculating Score
	std::fstream myFile;
		myFile.open("scores.txt", std::ios::out);	// Outputing Final score to a file
		myFile << score << std:: endl;
		myFile.close();
}
/////////////////////////////////////////////
int reading_scores()
{
	int temp_max = 0;
	
	std::ifstream score("scores.txt", std::ios::in);
	{

		score >> temp_max;		// Read the Score and send it to main

	}
	score.close();
	return temp_max;
}

/////////////////////////////////////////////
void high_score(int score,bool game_end)
{
	if (game_end == true)
	{
		int max = score;
		std::fstream new_File;
			new_File.open("high_scores.txt", std::ios::app);	// storing the all scores in a file
			new_File << max << std:: endl;
			new_File.close();
	}
}
/////////////////////////////////////////////
int reading_high_score()
{
	int highest = 0;
	int scoring = 0;
	std::ifstream file("high_scores.txt" , std::ios::app);
	while (!file.eof())
	{
		file >> scoring;
		if (scoring > highest)		// Reading the Highest Score
		{
			highest = scoring;
		}
	}
	//std:: cout << highest << std::endl;
	return highest;
}
/////////////////////////////////////////////
void bomb_working(int& counter_bomb, bool& bomb_row)
{
	if (bomb_row == true)
	{
		counter_bomb++;
		for (int i = 0; i < 4; i++)
		{
			for (int loop = 0; loop < 10; loop++)
			{
				gameGrid[bomb[i][1]][loop] = 0;
			}
		}
		bomb_row = false;
	}

}
/////////////////////////////////////////////
void next_block(int& next_block)
{
			
		for (int i = 0; i < 4; i++)
		{
			next[i][0]  = BLOCKS[next_block][i] % 2;
			next[i][1]	= BLOCKS[next_block][i] / 2;
		}	
		for (int i =0; i <4; i++)
		{
			next[i][0] += 13;
			next[i][1] += 18;
		}	
}
/////////////////////////////////////////////
///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////

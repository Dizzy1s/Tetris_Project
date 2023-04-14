/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */
//#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
using namespace sf;

int main(){
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int bomb_count_num = 0;
	int highest_1 = 0;
	int scoring_1 = 0;
	const int size = 1000;					// initialisations that are needed outside the main window loop //
	int arr_count = 0;
	int highest_arr[size] = {0};
	bool bomb_fall = false;
	int line_counter = 0;
	int counter_bomb = 0;
	bool bomb_row = false;
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::ifstream file("high_scores.txt" , std::ios::app);
	while (!file.eof())
	{
		file >> scoring_1;
		if (scoring_1 > highest_1)	// For highest
		 {
			highest_1 = scoring_1;										//------- Reading high scores from file ---------//
		 }
		if (scoring_1 > highest_arr[arr_count])
		 {
			highest_arr[arr_count] = scoring_1;	// For Top 5.
			arr_count++;
		 }
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int temp = 0;
	for (int loop = 0; loop <= arr_count; loop++)
	for (int loop = 0; loop <= arr_count; loop++)
	for (int loop = 0; loop <= arr_count; loop++)
	{
		if (highest_arr[loop] < highest_arr[loop+1])		// Bubble sorting the array in desceding order
		{
			temp = highest_arr[loop];
			highest_arr[loop] = highest_arr[loop+1];
			highest_arr[loop+1] = temp;
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int array_count = 0;
	int new_array[size] = {0};
	for (int loop = 0; loop <= arr_count; loop++)
	{
		if (highest_arr[loop] != highest_arr[loop+1])
		{
			new_array[array_count] = highest_arr[loop];			// Removing Repeating scores
			array_count++;
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	std::string high_score_1 = std::to_string(highest_1);
	std::string second_high = std::to_string(new_array[1]);
	std::string third_high = std::to_string(new_array[2]);			// converting integer values to strings to display in the game
	std::string fourth_high = std::to_string(new_array[3]);
	std::string fifth_high = std::to_string(new_array[4]);
////////////////////////////////////////////////////////////////////////////////////////////////////////////
	    int first = 0;
	    int score = 0;
	    srand(time(0));
	    Texture XD;
	    XD.loadFromFile("img/menu.jpg");
	    Sprite back(XD);
	    RenderWindow window1(VideoMode(320, 480), title);			//------  RENDERING THE MENU --------//
	    
  ///////////////////////////////////////////////////  			/*    {		*/
  																/* 			*/
	    Music music;											/*	  | 	*/           //////////////
	    music.openFromFile("music/Music_tet.flac");				/*    \		*/		//   Playing Music   //
	    music.play();											/*	  \		*/			///////////////
	    														/*			*/
  //////////////////////////////////////////////////			/*	  }		*/
  
	     while (window1.isOpen()){
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		      if (Keyboard::isKeyPressed(Keyboard::Escape))
			 {
			 	return 0;					// Press Esc to exit the Game; 
			 }
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		      if (Keyboard::isKeyPressed(Keyboard::H))
		      {
			      window1.close();		
			      
			      		//////////////////// H E L P - M E N U //////////////////////////////  
			      																								   
	//////////////////////////////////////////////////////////////////////////////////////////////////////    
	/* { */		  
	/*   */		      Texture Help_me_please_i_dont_want_to_do_this_anymore;
	/* \ */
	/* \ */		      Help_me_please_i_dont_want_to_do_this_anymore.loadFromFile("img/help.jpg");
	/* \ */
	/* \ */		      Sprite help_me(Help_me_please_i_dont_want_to_do_this_anymore);
	/* \ */
	/* \ */		      RenderWindow window5(VideoMode(320, 480), title);
	/* \ */
	/* \ */		      while(window5.isOpen())									// help menu
	/* \ */		      {
	/* \ */			      	window5.clear(Color::Black);
	/* \ */			      	Event e;
	/* \ */			      	while (window5.pollEvent(e))
	/* \ */					{ 							                   //Event is occurring - until the game is in running state
	/* \ */				   		 if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
	/* \ */								window5.close(); 
	/* \ */					}
	/* \ */			      
	/* \ */		      
	/* \ */		       if (Keyboard::isKeyPressed(Keyboard::Enter))
	/* \ */		     					window5.close();
	/* \ */
	/* \ */		     	window5.draw(help_me);
	/*   */		     	window5.display();
	/* } */		      }
	////////////////////////////////////////////////////////////////////////////////////////////////////////
		      }
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		     if (Keyboard::isKeyPressed(Keyboard::Enter))		
		     		{
		     				window1.close();		// Close Menu and Start Game if enter is pressed		
		     		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		     if (Keyboard::isKeyPressed(Keyboard::Space))
		     {
		     			  Texture XF;
		     			  XF.loadFromFile("img/high.jpg");
		     			  Sprite high(XF);
						  window1.close();
						  RenderWindow window3(VideoMode(320, 480), title);			// Opening  THe High Score Menu
						  while(window3.isOpen()){
						   		window3.clear(Color::Black);
						   		
						   		window3.draw(high);
						   
					/*-----------------------------------------------------------------------------*/
					
					   sf::Font font;
					font.loadFromFile("arial.ttf");
					sf::Text text(high_score_1, font);								//  Showing the highest score
					text.setCharacterSize(24);
					text.setStyle(sf::Text::Bold);
					text.setFillColor(sf::Color::Red);
					text.setPosition(40.f,30.f);
					window3.draw(text);
					
					/*-----------------------------------------------------------------------------*/
					
					sf::Font font4;
					font4.loadFromFile("arial.ttf");
					sf::Text text5(second_high, font);
					text5.setCharacterSize(24);									// Showing Second Highest Score
					text5.setStyle(sf::Text::Bold);
					text5.setFillColor(sf::Color::Red);
					text5.setPosition(40.f,60.f);
					window3.draw(text5);

					/*-----------------------------------------------------------------------------*/
					
					sf::Font fonti;
					fonti.loadFromFile("arial.ttf");
					sf::Text texti(third_high, fonti);
					texti.setCharacterSize(24);
					texti.setStyle(sf::Text::Bold);								// Showing Third Highest Score
					texti.setFillColor(sf::Color::Red);
					texti.setPosition(40.f,90.f);
					window3.draw(texti);
					
					/*-----------------------------------------------------------------------------*/

					sf::Font fontia;
					fontia.loadFromFile("arial.ttf");
					sf::Text textia(fourth_high, fontia);
					textia.setCharacterSize(24);								// Showing Fourth Highest Score
					textia.setStyle(sf::Text::Bold);
					textia.setFillColor(sf::Color::Red);
					textia.setPosition(40.f,120.f);
					window3.draw(textia);
					
					/*-----------------------------------------------------------------------------*/

					sf::Font fontiar;
					fontiar.loadFromFile("arial.ttf");
					sf::Text textiar(fifth_high, fontiar);
					textiar.setCharacterSize(24);
					textiar.setStyle(sf::Text::Bold);							// Showing Fifth Highest ScoreS
					textiar.setFillColor(sf::Color::Red);
					textiar.setPosition(40.f,150.f);
					window3.draw(textiar);
					
					/*-----------------------------------------------------------------------------*/	  
				
				/*______________________________________________________________________________________*/		  
						  
					Event e;
					while (window3.pollEvent(e))
					 { 								                   //Event is occurring - until the game is in running state
							if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
									window3.close(); 
			   		 }
					 if (Keyboard::isKeyPressed(Keyboard::Enter))
					 {		
					 		window3.close();
					 }
							 		 
					window3.display();
					 }
					 
			 	/*______________________________________________________________________________________*/	
			 
	 		 } 
////////////////////////////////////////////////////////////////////////////////////////////////////////////		 
				 
				window1.clear(Color::Black);
				Event e;
				while (window1.pollEvent(e))
				{								                    //Event is occurring - until the game is in running state
				   	 if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
							window1.close(); 
				}
				window1.draw(back);
				first++;
				if (first != 0)
				    window1.display();
				}
	    //////////////////////////////////////////////////////////////////////////////////////////////////
	    
	    RenderWindow window(VideoMode(320, 480), title);
	    Texture obj1, obj2, obj3, obj4, obj5,obj6;
	    obj1.loadFromFile("img/tiles.png");
	    obj2.loadFromFile("img/background.png");			// RENDERING THE PLAY AREA OF THE GAME
	    obj3.loadFromFile("img/frame.png");
	    obj4.loadFromFile("img/shadow.jpg");	
	    obj5.loadFromFile("img/bomb.png");
	    obj6.loadFromFile("img/tiles.png");
	    Sprite sprite(obj1), background(obj2), frame(obj3), shadow1(obj4), bomb1(obj5), next1(obj6);
	    int delta_x=0 , colorNum= 1;
	    float timer=0, delay=0.3;
	    bool rotate=0;
	    int bomb_color = 0;
	    bool jump = false;
	    int lines_gone = 0;
	    Clock clock;
	    while (window.isOpen()){
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer+=time;
		delta_x = 0;
		
		//////////////////////////////////////////////////////////////////////////////////////////////////
		
		//---Event Listening Part---//
		Event e;
		while (window.pollEvent(e))
	    { 						     	                       //Event is occurring - until the game is in running state
				if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
				   	{	window.close();   }                    //Opened window disposes
				if (e.type == Event::KeyPressed)
				 {      								       //If any other key (not cross) is pressed
						if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
							    	{	rotate = true;     }                    //Rotation gets on
						else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
						    		{	delta_x = -1;      }                   //Change in X-Axis - Negative
						else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
						    		{	delta_x = 1;       }                    //Change in X-Axis - Positive
					  	else if (e.key.code == Keyboard::Space)    // Check if the other key pressed is SPACE BAR
						    		{	jump = true;       }		//    	set JUMP to true;
				 }
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////
		
		if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
		    {	delay=0.05;   }                                //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
		    
		bool game_end = false;
		int level = 0;
		int highest = 0;
		int leveling = 0;
		
		if (Keyboard::isKeyPressed(Keyboard::T))		// Making the BOMB FALL 
		{
		
			if (bomb_count_num == 0);
			    { 
			    	bomb_fall = true;
			    }
			
			if (counter_bomb == 0 || counter_bomb == 1 || counter_bomb == 2 || counter_bomb == 3 || counter_bomb == 4  )
			{
				bomb_row = true;
			}
			  
		} 
		///////////////////////////////////////////////
		///*** START CALLING YOUR FUNCTIONS HERE ***///
			int new_block = 0;
		  ////////////////////////////////////////////////////////////////////
		  
			if (bomb_fall == true)  // only run if the T key is pressed (T for TNT)
	  		{ 
	  /*1*/ 	 bomby(timer, delay,colorNum,bomb_fall, bomb_count_num); 
	  		}
	  		
	  	  ///////////////////////////////////////////////////////////////////	
	  	  
	  		if (bomb_fall == false)
	  		{
	  /*2*/   	 fallingPiece(timer, delay, colorNum,lines_gone,leveling);        
	  /*3*/   	 move_x(delta_x);
	  		}
	  		
	  	  ///////////////////////////////////////////////////////////////////	
	  	  
	  /*4*/   game_end = ceiling();
	  /*5*/   level = row_displacement(lines_gone);
	  /*6*/   rotating_pieces(rotate);
	  
	  	 ///////////////////////////////////////////////////////////////////
	  	 
	  		if (bomb_fall == false)
	  		{
	  /*7*/ 	 shadow_below();
	  /*8*/   	 instant_jump(jump);
	  		}
	  	///////////////////////////////////////////////////////////////////
	  	
	  /*9*/   new_block = game_level(level,delay, leveling);
	/* 10 */  scoring(lines_gone,line_counter);
	/* 11 */  score = reading_scores();
	/* 12 */  high_score(score,game_end);
	/* 13 */  highest = reading_high_score();
			  if (bomb_row == true)
	/* 14 */  bomb_working(counter_bomb,bomb_row);
	/* 15 */  next_block(new_block);
	
		///////////////////////////////////////////////////////////////////
			
		 // std:: cout << highest << std:: endl;
		 
		 ///*** YOUR CALLING STATEMENTS END HERE ***///
		//////////////////////////////////////////////

		 
		 ////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 
		 						////// G A M E _____ O V E R ///////
		 					
		 	/*-------------------------------------------------------------------------------*/			
		 					
	  	  if (game_end == true)
	  	  {
			 		window.close();
	 	            Texture Over;
					Over.loadFromFile("img/game_over.jpg");
				    Sprite game_over(Over);
					RenderWindow window2(VideoMode(320, 480), title);		// RENDERING THE GAME OVER SCREEN
					while (window2.isOpen())
					{
						if (Keyboard::isKeyPressed(Keyboard::Enter))
						 	 		{	window2.close();	}
						 	 		
						window2.clear(Color::Black);
						window2.draw(game_over);
						Event e;
						while (window2.pollEvent(e))
						{						                    //Event is occurring - until the game is in running state
							if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
									window2.close(); 
						}
						window2.display();
					}
		   }
		   
		    	/*-------------------------------------------------------------------------------*/
		   
		  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
		  
			/*-------------------------------------------------------------------------------*/

		window.clear(Color::Black);
		window.draw(background);
		for (int i=0; i<M; i++)
		{
			for (int j=0; j<N; j++)
			{
		        if (gameGrid[i][j]==0)											// SETTING THE GAME PLAY AREAD ( GAME GRID )
		        	{   continue;   }
		        sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
		        sprite.setPosition(j*18,i*18);
		        sprite.move(28,31); //offset
		        window.draw(sprite);
		    }
		}
		
			/*-------------------------------------------------------------------------------*/		
		
		for (int i=0; i<4; i++)
		{
				sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
				shadow1.setTextureRect(IntRect(1*18,0,18,18));
				bomb1.setTextureRect(IntRect(colorNum*18,0,18,18));
				next1.setTextureRect(IntRect(colorNum*18,0,18,18));
				sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);			// Setting Sprites for bomb, shadow and blocks
				shadow1.setPosition(shadow[i][0]*18,shadow[i][1]*18);
				bomb1.setPosition(bomb[i][0]*18,bomb[i][1]*18);
				next1.setPosition(next[i][0]*18,next[i][1]*18);
				sprite.move(28,31);
				shadow1.move(28,31);
				bomb1.move(28,31);
				next1.move(28,31);
				window.draw(shadow1);
				window.draw(sprite);
				window.draw(bomb1);
				window.draw(next1);
		}
		  //////////////////////////////////////////////////////////////////////////////////////////////////////////
		  
		  
		  										///// P A U S E - M E N U ///////
		  					
		   if (Keyboard::isKeyPressed(Keyboard::P))
		   { 
		   
		    Texture pause;
		    pause.loadFromFile("img/pause.jpg");			
		    Sprite pause_menu(pause);					// RENDERING THE PAUSE MENU
		   
		  	RenderWindow window_pause(VideoMode(320, 480), title);
		  
		  
		  while (window_pause.isOpen()){
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
		  /////////////////////////////////////////////////////////////////////////////////////
			     if (Keyboard::isKeyPressed(Keyboard::Enter)) // CONTINUE GAME
			     		{window_pause.close();}
		  /////////////////////////////////////////////////////////////////////////////////////
		  	     if (Keyboard::isKeyPressed(Keyboard::N))
		  	     {
			  	     window_pause.close();			// START A NEW GAME;
			  	     ///////////////////////////////
			  	     score = 0;
			  	     level = 0;
			  	     lines_gone - 0;					// RESETING VARIABLES
			  	     leveling = 0;
			  	     ///////////////////////////////
			  	     for (int row = M-1; row >= 0; row--)
			  	     {
			  	     	for (int col = 0; col < N; col++)
			  	     	{
			  	     		gameGrid[row][col] = 0;
			  	     	}
			  	     }
			  	     ///////////////////////////////		// RESTARTING THE GAME by Resetting all varaibles;
			  	     for (int i = 0; i < 4; i++)
			  	     { 
			  	      	   point_1[i][0] = 0;
			  	      	   point_1[i][1] = 0;
			  	      	   point_2[i][0] = 0;
			  	      	   point_2[i][0] = 0;
			  	      	   bomb[i][1] = 0;
			  	      	   bomb[i][0] = 0;
			  	      	   bomb_2[i][0] = 0;
			  	      	   bomb_2[i][1] = 0;
			  	     }
			  	     ///////////////////////////////
		  	     
		  	     }	     
		  ////////////////////////////////////////////////////////////////////////////////////////////////////
		  		if (Keyboard::isKeyPressed(Keyboard::K))
		  			{
		  		////////////////////////////////////////////////////////////
		  			Texture XP;
		     		XP.loadFromFile("img/high.jpg");
		     		Sprite high_12(XP);
		  				
		  			RenderWindow window9(VideoMode(320, 480), title);
		  			
		  			//////////////////////////////////////////////////////////////////////////////////////////
		  			
					      while(window9.isOpen())
					      {
									  
						/*---------------------------------------------------------------------------------------------*/				  
									  
								window9.clear(Color::Black);
								
								window9.draw(high_12);
								
								/*-----------------------------------------------------------------------------*/
									   
								sf::Font font0;
								font0.loadFromFile("arial.ttf");
								sf::Text text0(high_score_1, font0);
								text0.setCharacterSize(24);									// Showing the Highest Score
								text0.setStyle(sf::Text::Bold);
								text0.setFillColor(sf::Color::Red);
								text0.setPosition(40.f,30.f);
								window9.draw(text0);
								
								/*-----------------------------------------------------------------------------*/
								
								sf::Font font40;
								font40.loadFromFile("arial.ttf");
								sf::Text text50(second_high, font40);						// Showing the Second Highest Score
								text50.setCharacterSize(24);
								text50.setStyle(sf::Text::Bold);
								text50.setFillColor(sf::Color::Red);
								text50.setPosition(40.f,60.f);
								window9.draw(text50);
								
								/*-----------------------------------------------------------------------------*/
					
								sf::Font fonti1;
								fonti1.loadFromFile("arial.ttf");
								sf::Text texti1(third_high, fonti1);
								texti1.setCharacterSize(24);
								texti1.setStyle(sf::Text::Bold);								// Showing Third Highest Score
								texti1.setFillColor(sf::Color::Red);
								texti1.setPosition(40.f,90.f);
								window9.draw(texti1);
								
								/*-----------------------------------------------------------------------------*/

								sf::Font fontia1;
								fontia1.loadFromFile("arial.ttf");
								sf::Text textia1(fourth_high, fontia1);
								textia1.setCharacterSize(24);								// Showing Fourth Highest Score
								textia1.setStyle(sf::Text::Bold);
								textia1.setFillColor(sf::Color::Red);
								textia1.setPosition(40.f,120.f);
								window9.draw(textia1);
								
								/*-----------------------------------------------------------------------------*/

								sf::Font fontiar1;
								fontiar1.loadFromFile("arial.ttf");
								sf::Text textiar1(fifth_high, fontiar1);
								textiar1.setCharacterSize(24);
								textiar1.setStyle(sf::Text::Bold);							// Showing Fifth Highest ScoreS
								textiar1.setFillColor(sf::Color::Red);
								textiar1.setPosition(40.f,150.f);
								window9.draw(textiar1);
								
								/*-----------------------------------------------------------------------------*/	 
								
								sf::Font fonty;
								fonty.loadFromFile("arial.ttf");
								// Create a text
								sf::Text texty("Press I to close this menu", fonty);	// To close the menu
								texty.setCharacterSize(24);
								texty.setStyle(sf::Text::Bold);
								texty.setFillColor(sf::Color::White);
								texty.setPosition(5.f,250.f);
								// Draw it
								window9.draw(texty);
								
								/*-----------------------------------------------------------------------------*/	
								
									  
						/*---------------------------------------------------------------------------------------------*/			  
									  
								 Event e;
								 while (window9.pollEvent(e))
								 {							             //Event is occurring - until the game is in running state
								 	if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
										{	window9.close();  }
								 }
								 if (Keyboard::isKeyPressed(Keyboard::I))
								 {
								 	window9.close();
								 }
								 window9.display();
							}
		  
		  		//////////////////////////////////////////////////////////////////////////////////////////
		  		
		  			}
		  /////////////////////////////////////////////////////////////////////////////////////////////////////////////	     
		  
				  if (Keyboard::isKeyPressed(Keyboard::H))
				  {
						  Texture Help_me_please_i_dont_want_to_do_this_anymore_1;
						  Help_me_please_i_dont_want_to_do_this_anymore_1.loadFromFile("img/help.jpg");
						  Sprite help_me_1(Help_me_please_i_dont_want_to_do_this_anymore_1);
						  RenderWindow window69(VideoMode(320, 480), title);
						  while(window69.isOpen())
						  {
							  window69.clear(Color::Black);
							  Event e;
							  while (window69.pollEvent(e))
							  {								                    //Event is occurring - until the game is in running state
								if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
									{   window69.close(); 	}
							  }
							  
							  if (Keyboard::isKeyPressed(Keyboard::Enter))
							 		{	window69.close();	}
							 
							 window69.draw(help_me_1);
							 window69.display();
						  }
				  }
		  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				   if (Keyboard::isKeyPressed(Keyboard::Escape))
				   {
					 return 0;				// Press Escape to Exit the Game
				   }
		  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			     
			    window_pause.clear(Color::Black);
			    
			    Event e;
			    
				while (window_pause.pollEvent(e))
				{ 								                   //Event is occurring - until the game is in running state
		    		if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
		        		window_pause.close(); 
		        }
		         
		        window_pause.draw(pause_menu);
		        
			    window_pause.display();
		  
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////         
		  }	// Ending of THE PAUSE MENU
		  
		  } // Ending of the if statement which detectes the letter P
		  
		  
		  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
		  
		  	/*---------------------------------------------------------------------------------------------*/	
		  
		  			/*-----------------------------------------------------------------------------*/		
		  
		            sf::Font font6;
					font6.loadFromFile("arial.ttf");
					sf::Text text6("Score:", font6);
					text6.setCharacterSize(20);
					text6.setStyle(sf::Text::Bold);
					text6.setFillColor(sf::Color::White);		// OUTPUTING SCORE: ON MAIN SCREEN
					text6.setPosition(152.f,100.f);
					text6.move(95.f, 100.f);
					window.draw(text6);
		  			
		  			/*-----------------------------------------------------------------------------*/		
		  
		 			 std::string c_score_1 = std::to_string(score);
		  
		 			 sf::Font font7;
					 font7.loadFromFile("arial.ttf");
					 sf::Text text7(c_score_1, font7);		 	// Outputting Current score on Main screen
					 text7.setCharacterSize(30);
					 text7.setStyle(sf::Text::Bold);
					 text7.setFillColor(sf::Color::White);
					 text7.setPosition(162.f,115.f);
					 text7.move(105.f, 115.f);
					 window.draw(text7);
		  		
		  			/*-----------------------------------------------------------------------------*/	
		  
		 			 std::string game_level = std::to_string(leveling);
		  
		             sf::Font font8;
					 font8.loadFromFile("arial.ttf");
					 sf::Text text8("Level: ", font8);			// Output The Level: on the Screen
					 text8.setCharacterSize(20);
					 text8.setStyle(sf::Text::Bold);
					 text8.setFillColor(sf::Color::White);
					 text8.setPosition(152.f,135.f);
					 text8.move(95.f, 135.f);
					 window.draw(text8);
						  
		  			/*-----------------------------------------------------------------------------*/	
		  
		             sf::Font font9;
					 font9.loadFromFile("arial.ttf");
					 sf::Text text9(game_level, font9);
					 text9.setCharacterSize(30);				// Outputting the Current Level on the Screen
					 text9.setStyle(sf::Text::Bold);
					 text9.setFillColor(sf::Color::White);
					 text9.setPosition(162.f,155.f);
					 text9.move(105.f, 155.f);
					 window.draw(text9);
					 
		  			/*-----------------------------------------------------------------------------*/
		  				
				     sf::Font font3;
					 font3.loadFromFile("arial.ttf");
 					 sf::Text text2("High Score:", font3);  	// Outputting High Score: on the main screen
					 text2.setCharacterSize(15);
					 text2.setStyle(sf::Text::Bold);
					 text2.setFillColor(sf::Color::White);
					 text2.setPosition(139.f,65.f);
					 text2.move(86.f, 65.f);
					 window.draw(text2);
	
					/*-----------------------------------------------------------------------------*/	
	
				   	 sf::Font font2;
					 font2.loadFromFile("arial.ttf");
					 sf::Text text1(high_score_1, font2);
					 text1.setCharacterSize(30);
					 text1.setStyle(sf::Text::Bold);
					 text1.setFillColor(sf::Color::White);		// Outputting the current High Score on the Main Screen
					 text1.setPosition(149.f,75.f);
					 text1.move(99.f, 75.f);
					 window.draw(text1);

					/*-----------------------------------------------------------------------------*/	

				/*---------------------------------------------------------------------------------------------*/	
				
	 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//---The Final on Which Everything is Drawn Over is Loaded---//
		window.draw(frame);
		//---The Window that now Contains the Frame is Displayed---//
		window.display();
	    }
	    return 0;
	}		// ENDING OF CODE

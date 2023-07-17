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

#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
using namespace sf;
   
char startOption; 
char exitOption;
char instructionOption;	
char highsocre;
char Name;
char UNI;

int main()
{
    srand(time(0));
    RenderWindow window(VideoMode(320, 480),"Tetris Game!");
    Texture obj1,obj2,obj3,obj4,obj5,obj6;
 	   
    /* <-- This is for background colors and pictures--> */
   
    obj1.loadFromFile("img/tiles.png");   
    obj2.loadFromFile("img/background.png");                   
    obj3.loadFromFile("img/frame.png");
    obj4.loadFromFile("img/tiles.png");     
    Sprite sprite(obj1), background(obj2), frame(obj3), shadow(obj4);
 				
 				//------------------Menu & display-----------------//
    
    
    Sprite instructionOption;
    Sprite exitOption;
    Sprite startOption;
    Sprite menu;
    Sprite highscore;
    Sprite Name;
    Sprite UNI;
    
    Texture mu_texture;
    bool menu_checker = true;
    int selected_option;    

    
    //Declares the Variables
    
    
    int delta_x=0, colorNum=1;
    float timer=0, delay=0.5;
    bool rotate=0;              //Rotation purpose
    int score=0;                //For calculate the scoring
    int level = 1;		 //For Calculating the level
    bool game=true;             //Once time in which game are false then one line removed
    bool start_game = false; 
    bool game_over=0;            
    int shadow1[4][2];          // For shadows (array)
    
    sf::Font font;
    font.loadFromFile("img/YagiUhfNo2.otf");    //Scoring FOnt
    
    Clock clock;
    
    while (window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
	
	Event e;

				//---------Menu Display------//
				

if(menu_checker)
{
      
         
   	sf::Font font;
    	font.loadFromFile("img/YagiUhfNo2.otf");    //
        
        mu_texture.loadFromFile("img/background7.jpg");
        menu.setTexture(mu_texture);
        menu.setScale(0.5, 0.5);
        
        
        sf::Text title;
        title.setFont(font);
        title.setString("TETRIS");
        title.setCharacterSize(50);
        title.setFillColor(sf::Color::White);
        title.setStyle(sf::Text::Bold);
        title.setPosition(90.f, 50.f);

        sf::Text startOption;
        startOption.setFont(font);
        startOption.setString("Start ");
        startOption.setCharacterSize(25);
        startOption.setFillColor(sf::Color::White);
        startOption.setPosition(30.f, 150.f);
        
        sf::Text instructionOption;
        instructionOption.setFont(font);
        instructionOption.setString("Options");
        instructionOption.setCharacterSize(25);
        instructionOption.setFillColor(sf::Color::White);
        instructionOption.setPosition(30.f, 220.f);
        
        
         sf::Text HighestScore;
         HighestScore.setFont(font);
         HighestScore.setString("High Score");
         HighestScore.setCharacterSize(25);
         HighestScore.setFillColor(sf::Color::White);
         HighestScore.setPosition(180.f, 150.f);  
        
                     
        sf::Text exitOption;
        exitOption.setFont(font);
        exitOption.setString("Exit");
        exitOption.setCharacterSize(25);
        exitOption.setFillColor(sf::Color::White);
        exitOption.setPosition(220.f, 220.f);
          
          
        sf::Text Name;
        Name.setFont(font);
        Name.setString("Hammad Shabbir");
        Name.setCharacterSize(12);
        Name.setFillColor(sf::Color::White);
        Name.setPosition(15.f, 450.f);  
        
                  
        sf::Text UNI;
        UNI.setFont(font);
        UNI.setString("CS");
        UNI.setCharacterSize(12);
        UNI.setFillColor(sf::Color::White);
        UNI.setPosition(280.f, 450.f); 
        
        
        if (Keyboard::isKeyPressed(Keyboard::Enter)) //If left key is pressed
           menu_checker = false;
            
        if (Keyboard::isKeyPressed(Keyboard::S)){ // If S key is pressed
          
          startOption.setFillColor(sf::Color::Red);
    	  exitOption.setFillColor(sf::Color::White);
    	  instructionOption.setFillColor(sf::Color::White); }
        
        if (Keyboard::isKeyPressed(Keyboard::H)){ //If H key is pressed
                       
             startOption.setFillColor(sf::Color::White);
    	     HighestScore.setFillColor(sf::Color::Red);
    	     exitOption.setFillColor(sf::Color::White);
    	     instructionOption.setFillColor(sf::Color::White); }
	 
	 if (Keyboard::isKeyPressed(Keyboard::O)){ //If O key is pressed
	         
	     startOption.setFillColor(sf::Color::White);
    	     exitOption.setFillColor(sf::Color::White);
    	     instructionOption.setFillColor(sf::Color::Red); }
	 
	  if (Keyboard::isKeyPressed(Keyboard::E)){ //If E key is pressed
                 
             startOption.setFillColor(sf::Color::White);
    	     exitOption.setFillColor(sf::Color::Red);
    	     instructionOption.setFillColor(sf::Color::White); }
       
	             
        	window.draw(menu);      
       	window.draw(title);
        	window.draw(startOption);
        	window.draw(exitOption);
        	window.draw(instructionOption);
       	window.draw(HighestScore);
        	window.draw(Name);
        	window.draw(UNI);
        
        
 
}				
        //---Event Listening Part---//
        
else{   
      
        while (window.pollEvent(e)){                       //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                {  
                    rotate = true;}                        //Rotation gets on
                else if (e.key.code == Keyboard::Left){    //Check if the other key pressed is LEFT key
                    delta_x = -1;  }                       //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right){   //Check if the other key pressed is RIGHT key
                    delta_x = 1;}    
                else if(e.key.code == Keyboard::Space){    //Check if the spacebar pressed blocks falling quikly       
                 
                 spacefunction(shadow1);  }                //Change in X-Axis - Positon   
           }
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Down))         //Just another way to detect key presses without event listener
            delay=0.05;                                     //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05

         if(game_over)
         {
           game_over=false; 
           break;
         }  
           
        ///////////////////////////////////////////////
        ///*** CALLING THE FUNCTIONAS ***///
        
        fallingPiece(timer,delay,colorNum);                   //Example: fallingPiece() function is called here
        Blocksmoving(delta_x);                                //Blocks Movement
        Rotation_Blocks(rotate);                              //Blocks Rotation
        line_remove(score,level);                             //One line is filled with blocks then they are reamoved (line clearing)
        shadowfunction(shadow1);                              //For shadows of blocks
        Gameover(game_over);                                  //Once the blocks are filled top of the window screen closed
        delay=0.3;delta_x=0;rotate=false;                     //Reset the variables
                        
        /////*** Ending the function  ***///
        //////////////////////////////////////////////
          
        
        window.clear(Color::Black);
        window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31);              //offset
                window.draw(sprite);
            }
        }
        
        for (int i=0; i<4; i++)
        {
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);        //offset
        }
          
        for(int i=0;i<4;i++)
        {
            shadow.setTextureRect(IntRect(colorNum*18,0,18,18));
            shadow.setPosition(shadow1[i][0]*18,shadow1[i][1]*18);
            shadow.move(28,31);
            shadow.setColor((Color(255,255,255,50)));
            window.draw(shadow);
        }
          
            sf::Text score_display("Score:", font); 	                      //for Displaying the score on window
            score_display.setCharacterSize(25);
            score_display.setPosition(230,100);                            //Postion setting 
           
                                      
            sf:: Text update_score(std::to_string (score) , font);      //Score marks 
            update_score.setPosition(240,140);                              
           
               
            sf::Text level_display("Level: ", font);                       //for Displaying the Levels on window	
            level_display.setCharacterSize(25);
            level_display.setFillColor(sf::Color::White);
            level_display.setPosition(240,200);                            //Postion setting 
           
            sf:: Text update_level(std::to_string (level) , font);      //Levels
            update_level.setPosition(250,240);   
      
       //---The Final on Which Everything is Drawn Over is Loaded---//
         
          window.draw(frame);
          window.draw(score_display);	//Score
          window.draw(update_score);	//Incrementing Scores
          window.draw(level_display);	//Levels
          window.draw(update_level);   //Incrementing Levels
        
       
    }
  //---The Window that now Contains the Frame is Displayed---//
         window.display();
}
    
    return 0;


}


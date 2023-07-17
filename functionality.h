/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Falling of Pieces---//

void fallingPiece(float& timer, float& delay,int &colorNum){
    if (timer>delay)
    {
       for (int i=0;i<4;i++)
       {  
           point_2[i][0]=point_1[i][0];
           point_2[i][1]=point_1[i][1];
           point_1[i][1]+=1;               //How much units downward
            
                             
        }
        
     if (!anamoly())
     {
        for(int i=0;i<4;i++)
              
             gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
             colorNum=1+rand()%7;                                  //Generate Different colors 
             int n=rand()%7;                                       // Blocks
              
        for (int i=0;i<4;i++)
        {  
             point_1[i][0] = BLOCKS[n][i] % 2;  
             point_1[i][1] = BLOCKS[n][i] / 2;   
              
        }
            
      }
        
        timer=0;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
                              
//*1*//

//Blocks movement and Anamoly checker

void Blocksmoving(int delta_x)
{
       int i=0; 
       while(i<4) 
       {   
           point_2[i][0]=point_1[i][0];                    
           point_2[i][1]=point_1[i][1]; 
           point_1[i][0]+=delta_x;                      //FOr left right purposes  
           i++;                                                      
       }  
         
       if(!anamoly())                                  //For Game Gird (outside the Grid checker)

          for(int i=0;i<4;i++)
          {
             point_1[i][0]=point_2[i][0];             //Coordinates are equal
             point_1[i][1]=point_2[i][1];
          }                                                    
}

//****************************************************************************************************************************//

//*2*//

//Blocks Rotation

void Rotation_Blocks(bool rotate)
{ 
         if(rotate)
            {
                  int px=point_1[1][0];
                  int py=point_1[1][1];
                  int i=0;
                  while(i<4)
                  {
                     int x=point_1[i][1]-py;
                     int y=point_1[i][0]-px;
                     point_1[i][0]=px-x;
                     point_1[i][1]=py+y;
                     i++;
                  }
                  
                if(!anamoly())
                  {
                        for(int i=0;i<4;i++)
                        {
                          point_1[i][0]=point_2[i][0];
                          point_1[i][1]=point_2[i][1];                       //Coordinates equality
                        }
                              
                  }
                                  
            }
            
}

//******************************************************************************************************************************//

//*3*//
       
//Removing of line

void line_remove(int &score, int &level)
{
  int count=0;
  int row=0;
  int temp=0;
  
    for(int i=0;i<M;i++)
    {
       temp=0;
       for(int j=0;j<N;j++)
       {
         if (gameGrid[i][j]!=0)                     //IF (blocks) are not full then count add ho ga  (row) 
          {
             count++;
          }   
         if(count==N)                               //if count equal to Number of coloumns then k is reset 
         {    
             int k=0;        
             while(k<N)
             {
                gameGrid[i][k]=0;                  //Grid ko zero kry ga
                k++;
             }
             
          row=i;
          temp++;                                  //Adding everytime
         }
         
       for(int x=row-1;x>0;x--)
       {
          int y=0;      
          while(y<N)
          { 
              gameGrid[x+1][y] = gameGrid[x][y];
              y++;
          }
          
       }
       
          
       row=0;
       
       //For scoring every line remove
       
      if(temp==1)
      {
         score+=10;
         break;
      }
      else if(temp==2)
      {
        score+=30;
       break; 
      }   
      else if(temp==3)
      {
        score+=60;
        break;
      }
      else if(temp==4)
      {
        score+=100;
        break;
      }
      
      if(score == 70){
        level = 2;} 
      else if(score == 130){
        level = 3;}  
      else if(score == 200){
        level = 4;}  
      else if(score == 300){
        level = 5;}          
    }
 count=0;}
}
                                                            
//*******************************************************************************************************************************//

//*4*//

//Shadows occuring

void shadowfunction(int shadow1[][2])
{
  int checker=0;
  int i=0;
  while(i<4)
  {
    if(point_1[i][1]==19)
    checker=1;
    i++;
  }
   if(checker==0)
   {
     for(int j=0;j<4;j++)
     {
        shadow1[j][0]=point_1[j][0];                        //where shadow is fomred then Point_1 coordinates are equal to that shadow
        shadow1[j][1]=point_1[j][1];
      }
      
      int x1=0;
      while(x1==0)
      {
        for(int i=0;i<4;i++)
        {
           ++shadow1[i][1];
           
        if(shadow1[i][1]>18)
          x1=1;
        if(gameGrid[shadow1[i][1]+1][shadow1[i][0]]!=0)
          x1=1;
           
        }
      }
       
   }
}    

//*****************************************************************************************************************************//

//*5*//

//Space function 

void spacefunction(int shadow1[][2])
{
  for(int i=0;i<4;i++)
  {
  point_1[i][0]=shadow1[i][0];                  //  Shadows and Point_1 coordinares are equal 
  point_1[i][1]=shadow1[i][1];                  //  Whereas the shadows of blocks occur blocks falling for this shadow using spacebar
  }
  
}

//*******************************************************************************************************************************//

//*6*//
/*
void duplicate(float& timer, float& delay,int &colorNum){
    if (timer>delay)
    {
       for (int i=0;i<4;i++)
       {  
           point_2[i][0]=point_1[i][0];
           point_2[i][1]=point_1[i][1];
           point_1[i][1]+=1;               //How much units downward
            
                             
        }
        
     if (!anamoly())
     {
        for(int i=0;i<4;i++)
              
             gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
             colorNum=1+rand()%7;
             int nextpick=rand()%7;
             int n1=nextpick;
                 
        for (int i=0;i<4;i++)
        {  
             point_1[i][0] = BLOCKS[n1][i] % 2;  
             point_1[i][1] = BLOCKS[n1][i] / 2;   
              
        }
            
      }
        
        timer=0;
    }
} 

*/

//***********************************************************************************************************************************//
///*6*//

//Game Over

void Gameover(bool &game_over)
{

   if(gameGrid[0][0]!=0 || gameGrid[0][1]!=0)
   game_over=true;
 }
 
 
///*** YOUR FUNCTI ONS END HERE ***///
/////////////////////////////////////

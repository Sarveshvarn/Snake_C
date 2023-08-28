#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
int i, j, height = 20, width = 20, gameOver, score;
int x, y, fruitX, fruitY, flag;

/*Function to generate Fruit
	within the Boundary */
void setup() {
    gameOver = 0;
    
    //Stores height and width
    x = height / 2;
    y = width / 2;
    
label1:
	fruitX = rand() % 20;
    if (fruitX == 0) {
        goto label1;
    }
label2:
	fruitY = rand() % 20;
    if (fruitY == 0) {
    	   goto label2;
    }
   	score = 0;
}

//Function to draw boundary
void draw()
{
    //system("cls")
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1) {
                printf("#");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    // Print the score after the
    // game ends
    printf("score = %d", score);
    printf("\n");
    printf("press X to quit the game");
}

//Function to take the input
void input() {
	if (kbhit()) {
    	switch(getch()) {
        case 'a':
        	flag = 1;
            break;
        case 's':
        	flag = 2;
            break;
        case 'd':
        	flag = 3;
            break;
        case 'w':
        	flag = 4;
            break;
        case 'x':
        	gameOver = 1;
            break;
        }
    }
}

//Function for the logic
void logic() {
	   sleep(0.01);
    switch (flag) {
   	 case 1:
    	    y--;
        break;
     case 2:
         x++;
        break;
    case 3:
    	y++;
        break;
    case 4:
    	x--;
        break;
    default:
    	break;
    }
    
    //If the game is over
    if (x < 0 || x > height || y < 0 || y > width) {
    	gameOver = 1;
    }
   	//If snake reaches the fruit then update score
    if (x == fruitX && y == fruitY) {
    label3:
    	fruitX = rand() % 20;
    	if (fruitX == 0) {
    		goto label3;
    	}
    label4:
    	fruitY= rand() % 20;
    	if (fruitY== 0) {
    		goto label4;
    	}
        score += 10;
    }
}

//Driver Code
int main()
{
  
    // Generate boundary
    setup();
  
    // Until the game is over
    while (!gameOver) {
  
        // Function Call
        draw();
        input();
        logic();
    }
    
    return 0;
    
}

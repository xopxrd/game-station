#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection{STOP = 0 , LEFT, RIGHT, UP, DOWN};
eDirection dir;

void setup(){
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void draw(){
    system("cls");
    // pager atas
    for(int i = 0; i < width+2; i++)
        cout << "#"; 
    cout << endl;
	
	for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
			// pager kiri
            if(j == 0)
                cout << "#";
            // kepala uler
			if (i == y && j == x)
				cout << "O";
			// makanan
			else if(i == fruitY && j == fruitX)
				cout << "P";
			else
			{
				// buntut
				bool print = false;
				for(int k = 0; k < nTail; k++){
					if(tailX[k] == j && tailY[k] == i){
						cout << "o";
						print = true;
					}
				}
				// print map kosong
				if(!print)
                cout << " ";
			}
			// pagerkanan
            if (j == width-1)
                cout << "#";
        }
        cout << endl;
    }
    
    // pager bawah
    for (int i = 0; i < width+2; i++)
    cout << "#";
    cout << endl;
    cout << "score: " << score << endl;

}

void input(){
	if (kbhit()){
		switch (getch()){
		case 'a':
			dir = LEFT;
				break;
		case 'd':
			dir = RIGHT;
				break;
		case 'w':
			dir = UP;
				break;
		case 's':
			dir = DOWN;
				break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void logic(int level){
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for(int i = 1; i < nTail; i++){
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	
	switch(dir){
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	// nabrak tembok
	if(level == 4){
		Sleep(0);
		if(x > width-1 || x < 0 || y > height-1 || y < 0)
		gameOver = true;
	}else if(level == 3){
		Sleep(20);
	}else if(level == 2){
		Sleep(50);
	}else if(level == 1){
		Sleep(100);
	}
	
	// ga nabrak
	if(x >= width) x = 0; else if (x < 0) x = width - 1;
	if(y >= height) y = 0; else if (y < 0) y = height - 1;
		
	for(int i = 0; i < nTail; i++)
	if(tailX[i] == x && tailY[i] == y)
		gameOver = true;
	
	if(x == fruitX && y == fruitY){
	score += 1;
	fruitX = rand() % width;
    fruitY = rand() % height;
    nTail++;
	}
}

void instructions();

void play(){
	int num, difficulty;
	cout << "welcome to the snake game" << endl;
	cout << "1. play\n";
	cout << "2. instructions\n";
	cout << "3. exit\n";
	cout << "input number to choose: "; choose: cin >> num;
	if(num == 1){
		system("cls");
		cout << "selesct difficulty: \n";
		cout << "1. Easy, 2. Normal, 3. Difficult, 4. Insane\n";
		difficulty:
		cin >> difficulty;
		if(difficulty == 4){
			cout << "only this difficulty if you hit the wall you also died\n";
			cout << "press any key to continue";
			getch();
		}else if(difficulty == 3 || difficulty == 2 || difficulty == 1){
			cout << "press any key to continue";
			getch();
		}else{
			cout << "input the right number!"; goto difficulty;
		}
		setup();
		while (!gameOver)
		{
			draw();
			input();
			logic(difficulty);
		}
    }else if(num == 2){
		instructions();
	}else if(num == 3){
		gameOver = true;
	}else{
		cout << "input the right number!" << endl;
		goto choose;
	}
}

void instructions(){
	system ("cls");
	cout << "====================instructions===================\n";
	cout << "use 'w' 'a' 's' 'd' to change directons\n";
	cout << "w for top, a for left, d for right and s for bottom\n";
	cout << "use 'x' to exit the game\n";
	cout << "press any key to back to menu";
	getch();
	system ("cls");
	play();
}

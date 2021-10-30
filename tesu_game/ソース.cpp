#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>
#define FIELD_WIDTH (256)
#define FIELD_HEIGHT (16)
#define SCREEN_WIDTH (16)
#define SCREEN_HEIGHT (16)
#define UPDATRE_FPS (60)
#define UPDATE_INTERVAL (1000/UPDATRE_FPS)
#define DRAW_FPS (10)
#define DRAW_INTERVAL (1000/DRAW_FPS )


typedef struct {
	float x, y;
} VEC2;
typedef struct {
	VEC2 position;
	VEC2 velocity;
	bool jumping;
}PLAYER;

char course[FIELD_HEIGHT][FIELD_WIDTH] = {                                                                                                                                                                                                                         
"                                                                                                                                                                                                                         ",
"                                                                                                                                                                                         ccccc                           ",
"                                                                                                                                                                        ccc      ccccc    cccc                           ",
"                ccc               cccc                   ccc      ccc                cccc                    ccc             cccc                            ccc        ccc      ccccc    cccc             g ccc         ",
"                ccc      ccccc    cccc                   ccc      ccc                cccc                    ccc    ccccc    cccc                            ccc                                           g ccc         ",
"                         ccccc                                                                                      ccccc                                                                                  g             ",
"                     q                                                           bbbbbbbb   bbbq                                                                                                 bb        g             ",
"                                                                                                                                                                                                bbb        g             ",
"                                                                                                                                                                                               bbbb        g             ",
"                                                                                                                                                                                              bbbbb        g    fff      ",
"                q   bqbqb                     pp         pp                  bqb                b       bb    q  q  q     b         bb       b  b           bb  b            bbqb            bbbbbb        g    fff      ",
"  m                                   pp      pp  m                                                 m                                       bb  bb    m    bbb  bb                          bbbbbbb    m   g   fffff     ",
" mmm                        pp        pp      pp mmm     pp      m                                 mmm              m                      bbb  bb   mmm  bbbb  bbb   m pp              pp bbbbbbbb   mmm  g   fffff  m  ",
"mmmmm      tttttmmm    ttt  pp        pp tttt ppmmmmm    pptttttmmm     ttt                tttt   mmmmm       tttttmmm     ttt            bbbbttbbbbmmmmmbbbbb  bbbbtmmmpp  ttt         ppbbbbbbbbb  mmmmm b   ffffftmmm ",
"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb  bbbbbbbbbbbbbbb    bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb  bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb  bbbbbbbbbbbbbbb    bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb  bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
};


char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
char aa[256][2 + 1];
PLAYER player;
bool keyPressed[256];

void DrawScreen() {
	int scrollX = (int)roundf(player.position.x)- SCREEN_WIDTH/2;
	if (scrollX < 0)
		scrollX = 0;


	for (int y = 0; y < SCREEN_HEIGHT; y++) 
		for (int x = 0; x < SCREEN_WIDTH; x++)
			screen[y][x] = course[y][scrollX + x];
	
	{
		int x = (int)roundf(player.position.x) - scrollX;
		int y = (int)roundf(player.position.y);

		if(x>=0 && x<SCREEN_WIDTH && y>=0 && y< SCREEN_HEIGHT)
		screen[y][x] = '@';
	}
	system("cls");
	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++)
			printf("%s",aa[screen[y][x]]);  
		printf("\n");
	}
}

void Init() {
	player.velocity = {};
	player.jumping = false;
	player.position = { SCREEN_WIDTH / 2,13 };
	memset(keyPressed, 0, sizeof keyPressed);
	DrawScreen();

}
bool IntersectCourse(VEC2 _v) {
	int x = (int)_v.x;
	int y = (int)_v.y;
	switch (course[y][x]) {
	case 'b':
	case 'p':
	case 'q':
		return true;
	}
	return false;
}

int main() {
	sprintf_s(aa[0], "~");
	sprintf_s(aa[' '], "@");
	sprintf_s(aa['b'], "¡");
	sprintf_s(aa['m'], "‚Ö");
	sprintf_s(aa['t'], "Y");
	sprintf_s(aa['p'], " "); 
	sprintf_s(aa['q'], "H");
	sprintf_s(aa['c'], "`");
	sprintf_s(aa['g'], "b");
	sprintf_s(aa['f'], "“c");
	sprintf_s(aa['@'], "š");
	
	Init();

	clock_t lastUpdateClock = clock();
	clock_t lastDrawClock = clock();
	while(1) {
		clock_t nowClock = clock();
		if (nowClock >= lastUpdateClock + UPDATE_INTERVAL) {
			lastUpdateClock = nowClock;
			float accelsration = 0.005f;
			if (keyPressed['d'])
				player.velocity.x += accelsration;

			if (keyPressed['a'])
				player.velocity.x -= accelsration;

			player.velocity.y += 0.005f;
			player.velocity.x *= 0.95f;

			player.position.x += player.velocity.x;
			player.position.y += player.velocity.y;

			VEC2 left = {
				player.position.x,
				player.position.y + 0.5f };
			if (IntersectCourse(left)) {
				player.position.x = floorf(player.position.x) + 1.0f;
				player.velocity.x = 0;
			}
			VEC2 right = {
				player.position.x + 1.0f,
				player.position.y + 0.5f };
			if (IntersectCourse(right)) {
				player.position.x = floorf(player.position.x);
				player.velocity.x = 0;
			}
			
			VEC2 up = {
				player.position.x + 0.5f,
				player.position.y};
			if (IntersectCourse(up)) {
				player.position.y = floorf(player.position.y) + 1.0f;
				player.velocity.y = 0;
			}
			else
				player.jumping = true;
			VEC2 down = {
				player.position.x + 0.5f,
				player.position.y + 1.0f };
			if (IntersectCourse(down)) {
				player.position.y = floorf(player.position.y);
				player.velocity.y = 0;
				player.jumping = false;
			}


		
			
		}
		if (nowClock >= lastDrawClock + DRAW_INTERVAL) {
			lastDrawClock = nowClock;
			
			DrawScreen();
		}
		if (_kbhit()) {
			switch (_getch()) {
			case 'a':
				if (keyPressed['d'])
					keyPressed['d'] = false;
				else
					keyPressed['a'] = true;
				break;
			case 'd':
				if (keyPressed['a'])
					keyPressed['a'] = false;
				else
					keyPressed['d'] = true;
				break;
			default:
				if(!player.jumping)
				player.velocity.y = -0.20f;
				break;

			}
		}
	}

}
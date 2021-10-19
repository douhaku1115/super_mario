#include<conio.h>
#include<stdio.h>
#include<math.h>
#define FIELD_WIDTH (256)
#define FIELD_HEIGHT (16)
#define SCREEN_WIDTH (16)
#define SCREEN_HEIGHT (16)

typedef struct {
	float x, y;
} VEC2;
typedef struct {
	VEC2 position;
	VEC2 velocity;
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

void DrawScreen() {
	for (int y = 0; y < SCREEN_HEIGHT; y++) 
		for (int x = 0; x < SCREEN_WIDTH; x++)
			screen[y][x] = course[y][x];
	
	{
		int x = (int)roundf(player.position.x);
		int y = (int)roundf(player.position.y);
		screen[y][x] = '@';

	}
	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++)
			printf("%s",aa[screen[y][x]]);  
		printf("\n");
	}
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
	/*for (int x = 0; x<FIELD_HEIGHT; x++) {
		for (int x = 0; x < FIELD_WIDTH; x++)
	printf(".");
		printf("\n");

	} */
	DrawScreen();
	_getch();

}
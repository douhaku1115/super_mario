#include<conio.h>
#include<stdio.h>
#define FIELD_WIDTH (256)
#define FIELD_HEIGHT (16)
#define SCREEN_WIDTH (16)
#define SCREEN_HEIGHT (16)
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


char svreen[SCREEN_HEIGHT][SCREEN_WIDTH];

void DrawScreen() {
	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++)
			printf(" ");
		printf("\n");
	}
}

int main() {
	
	DrawScreen();
	/*for (int x = 0; x<FIELD_HEIGHT; x++) {
		for (int x = 0; x < FIELD_WIDTH; x++)
	printf(".");
		printf("\n");

	} */
	_getch();

}
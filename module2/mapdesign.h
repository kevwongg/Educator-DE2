/*
 * mapdesign.h
 *
 *  Created on: 2017-03-12
 *      Author: ahboo
 */

/*
 * Each character represents a 50px by 50px square in the screen.
 */



// Map Dimensions
#define MAX_AREAS 3
#define MAX_HORI_SQUARES 16
#define MAX_VERT_SQUARES 8
#define SQUARE_WIDTH 50
#define SQUARE_HEIGHT 50
#define NUM_STORY_LINES 27
#define MAX_ENEMY 4
#define ENEMY_DEAD 1

// Character definitions
#define WALL 35					// 35 = #
#define SPACE 79				// 79 = O
#define FINISH 36				// 36 = $
#define ENEMY 88				// 88 = X
#define PLAYER 80				// 80 = P
#define DOOR 68                 // 68 = D

// Player's current position in terms of the character map below. For example, these two values would initialize to
// 1 and 7 respectively (according to the position of 'P' in map[0].
int player_current_x_pos;
int player_current_y_pos;

static int startPos [MAX_AREAS][2] =
{
		{ 1, 7 },
		{ 1, 7 },
		{ 1, 7 }
};

static int doorPos [MAX_AREAS][2] =
{
		{ 12, 1 },
		{ 12, 1 },
		{ 12, 1 }
};

static int enemyPos_init [MAX_AREAS][MAX_ENEMY][4] =
{
		{
				{ 6, 4, 0, 0},
				{ 3, 6, 0, 0},
				{ 4, 9, 0, 0},
				{ 1, 13, 0, 0}
		},
		{
				{ 6, 4, 0, 0},
				{ 3, 6, 0, 0},
				{ 4, 9, 0, 0},
				{ 1, 13, 0, 0}
		},
		{
				{ 6, 4, 0, 0},
				{ 3, 6, 0, 0},
				{ 4, 9, 0, 0},
				{ 1, 13, 0, 0}
		}
};

static char map_init [MAX_AREAS][MAX_VERT_SQUARES][MAX_HORI_SQUARES] =
{
		{
				{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
				{'#','#','#','#','#','#','#','O','O','O','#','#','D','X','O','$'},
				{'#','O','#','#','O','O','#','O','#','O','#','#','O','#','O','O'},
				{'#','O','#','#','O','O','X','O','#','O','#','#','O','#','#','#'},
				{'#','O','#','#','O','#','#','#','#','X','O','O','O','#','#','#'},
				{'#','O','#','#','O','#','#','#','#','O','#','#','O','#','#','O'},
				{'#','O','O','O','X','#','#','#','#','O','#','#','O','#','#','O'},
				{'#','O','#','#','#','#','#','#','#','O','#','#','O','O','O','O'}
		},
		{
				{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
				{'#','#','#','#','#','#','#','O','O','O','#','#','D','X','O','$'},
				{'#','O','#','#','O','O','#','O','#','O','#','#','O','#','O','O'},
				{'#','O','#','#','O','O','X','O','#','O','#','#','O','#','#','#'},
				{'#','O','#','#','O','#','#','#','#','X','O','O','O','#','#','#'},
				{'#','O','#','#','O','#','#','#','#','O','#','#','O','#','#','O'},
				{'#','O','O','O','X','#','#','#','#','O','#','#','O','#','#','O'},
				{'#','O','#','#','#','#','#','#','#','O','#','#','O','O','O','O'}
		},
		{
				{'#','#','#','#','#','#','#','#','#','#','#','O','O','O','O','$'},
				{'#','#','#','#','#','#','#','O','O','X','#','O','O','O','O','O'},
				{'#','O','#','#','O','O','#','O','#','O','#','O','#','#','#','#'},
				{'#','O','#','#','O','O','O','O','#','O','#','O','O','O','#','#'},
				{'#','O','#','#','O','#','#','#','#','O','O','O','O','O','#','X'},
				{'#','O','#','#','O','#','#','#','#','O','#','#','#','O','#','$'},
				{'#','O','O','O','O','#','#','#','#','O','#','#','#','X','#','$'},
				{'#','O','#','#','#','#','O','O','O','O','#','#','#','O','O','$'}
		}
};

#ifdef  MAIN_FILE

int key_flag = 0;

char map [MAX_AREAS][MAX_VERT_SQUARES][MAX_HORI_SQUARES] =
{
		{
				{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
				{'#','#','#','#','#','#','#','O','O','O','#','#','D','X','O','$'},
				{'#','O','#','#','O','O','#','O','#','O','#','#','O','#','O','O'},
				{'#','O','#','#','O','O','X','O','#','O','#','#','O','#','#','#'},
				{'#','O','#','#','O','#','#','#','#','X','O','O','O','#','#','#'},
				{'#','O','#','#','O','#','#','#','#','O','#','#','O','#','#','O'},
				{'#','O','O','O','X','#','#','#','#','O','#','#','O','#','#','O'},
				{'#','O','#','#','#','#','#','#','#','O','#','#','O','O','O','O'}
		},
		{
				{'#','#','#','#','#','#','#','#','#','#','#','O','O','O','O','$'},
				{'#','#','#','#','#','#','#','O','O','X','#','O','O','O','O','O'},
				{'#','O','#','#','O','O','#','O','#','O','#','D','#','#','#','#'},
				{'#','O','#','#','O','O','O','O','#','O','#','O','O','O','#','#'},
				{'#','O','#','#','O','#','#','#','#','O','O','O','O','O','#','X'},
				{'#','O','#','#','O','#','#','#','#','O','#','#','#','O','#','$'},
				{'#','O','O','O','O','#','#','#','#','O','#','#','#','X','#','$'},
				{'#','O','#','#','#','#','O','O','O','O','#','#','#','O','O','$'}
		},
		{
				{'#','#','#','#','#','#','#','#','#','#','#','O','O','O','O','$'},
				{'#','#','#','#','#','#','#','O','O','X','#','O','O','O','O','O'},
				{'#','O','#','#','O','O','#','O','#','O','#','O','#','#','#','#'},
				{'#','O','#','#','O','O','O','O','#','O','#','O','O','O','#','#'},
				{'#','O','#','#','O','#','#','#','#','O','O','O','O','O','#','X'},
				{'#','O','#','#','O','#','#','#','#','O','#','#','#','O','#','$'},
				{'#','O','O','O','O','#','#','#','#','O','#','#','#','X','#','$'},
				{'#','O','#','#','#','#','O','O','O','O','#','#','#','O','O','$'}
		}
};

char *story [NUM_STORY_LINES] =
{
		"Once upon a time, in a land far far away.",
		"there lives a man Ness who is the smartest",
		"philosopher in his town. ",
		"",
		"ONE DAY... The King's youngest princess,",
		"Cinderella, is kidnapped by the evil ",
		"Doctor Zoidberg threatening to kill her",
		"if the King does not accept his challenge.",
		"",
		"The challenge is a game of brains. ",
		"Whoever is smarter wins!",
		"",
		"The King is really scared and panicking.",
		"He orders his servants to find the smartest ",
		"civilian in town to help him.",
		"",
		"His servants return hours later with Ness ",
		"and the King pleads for his help.",
		"",
		"Ness agrees to help the King and head towards",
		" the dungeon where the princess is locked up.",
		"",
		"Your mission is to eliminate enemy objects by ",
		"walking up to them and out-smarting them by ",
		"answering their question!",
		"",
		"Good luck!"
};

int enemyPos [MAX_AREAS][MAX_ENEMY][4] =
{
		{
				{ 6, 4, 0, 0},
				{ 3, 6, 0, 0},
				{ 4, 9, 0, 0},
				{ 1, 13, 0, 0}
		},
		{
				{ 6, 4, 0, 0},
				{ 3, 6, 0, 0},
				{ 4, 9, 0, 0},
				{ 1, 13, 0, 0}
		},
		{
				{ 6, 4, 0, 0},
				{ 3, 6, 0, 0},
				{ 4, 9, 0, 0},
				{ 1, 13, 0, 0}
		}
};

#else
extern char map [MAX_AREAS][MAX_VERT_SQUARES][MAX_HORI_SQUARES];
extern char map [MAX_AREAS][MAX_VERT_SQUARES][MAX_HORI_SQUARES];
extern char *story [NUM_STORY_LINES];
extern int enemyPos [MAX_AREAS][MAX_ENEMY][4];
extern int key_flag;
#endif



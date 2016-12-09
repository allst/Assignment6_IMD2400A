#include "Main.h"

//global variable for display
ALLEGRO_DISPLAY* display = NULL; //ALLEGRO_DISPLAY is a "user defined type" in Allegro. * shows a pointer

								 //global variable for font
ALLEGRO_FONT *font;

//initialzie Allegro components
void InitAllegro(int W, int H)
{

	//initialize allegro
	if (!al_init())
	{
		printf("failed to initialize allegro!\n");
	}

	//initialize display screen
	display = al_create_display(W, H);
	if (!display)
	{
		printf("failed to create display!\n");
		exit(0);
	}
	else
	{
		printf("ok");
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	//initialize keyboard
	if (!al_install_keyboard())
	{
		printf("failed to install keyboard!\n");
		exit(0);
	}

	//initialize image addon
	if (!al_init_image_addon())
	{
		printf("failed to initialize image addon!\n");
		exit(0);
	}

	//initialize mouse
	if (!al_install_mouse())
	{
		printf("failed to install mouse!\n");
		exit(0);
	}
	//initialize primitive shapes
	if (!al_init_primitives_addon())
	{
		printf("failed to initialize primitives!\n");
		exit(0);
	}
	//initialize font
	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon	 (get fonts here: http://www.1001freefonts.com/)
	font = al_load_ttf_font("uchiyama.ttf", 12, 0); //secodn variable is size
													//font = al_load_font("a4_font.tga", 0, 0); //size variable doesn't matter becasue the font is fixed-size 
	if (!font)
	{
		printf("failed to create font!\n");
		exit(0);
	}
}

//End and clean up Allegro components
void EndAllegro()
{
	al_destroy_display(display);
}

ALLEGRO_KEYBOARD_STATE key_state;

//main function
void main()
{
	
	
	ALLEGRO_BITMAP* pic;
	//BOOL WINAPI GetOpenFileName(_Inout_ LPOPENFILENAME lpofn);
	//int fhand2;
	//_sopen_s(&fhand2, "xd.bmp", _O_WRONLY | _O_CREAT, _SH_DENYNO, _S_IREAD | _S_IWRITE);

	//ofstream output;


/*
	string str;

	printf_s("Paste your file directory here (eg: c:/program files/ayylmao.bmp)\n");
	getline(cin, str);

	cout << str;
	const char * input = str.c_str();

	pic = al_load_bitmap(input);

	*/
	ALLEGRO_BITMAP* temp = al_load_bitmap("xd.bmp");
	///////////////////////////////////
	// INITIALIZE
	///////////////////////////////////

	//initialize allegro
	int sw = 640;
	int sh = 480;
	InitAllegro(sw, sh);

	//create main object

	bool end = false;
	

	while (end == false) {

		al_get_keyboard_state(&key_state);

		if (al_key_down(&key_state, ALLEGRO_KEY_ESCAPE)) //al_key_down checks the status of a key in the key_state structure
		{
			end = true;
		}

		al_draw_bitmap(temp, 0, 0, 0);
		al_flip_display();
		al_rest(0.1);
	}
	///////////////////////////////////
	// LOOP (includes update and draw)
	///////////////////////////////////
	
	//clean up
	EndAllegro();
}

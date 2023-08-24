#include "raylib.h"
#include "raymath.h"
#include <string>
#define NUM_FRAMES  2
#define pixelsy 2.7588
#define pixelsx 1.6568
#include<iostream>
class buttonNum{
    public:
        int integer;
        Texture2D button=LoadTexture("Image/button1.png");      //Load the button
        Texture2D button1=LoadTexture("Image/button2.png");
        Sound fxButton = LoadSound("buttonfx.wav");       //Load the button sound
        Rectangle btnBounds;
        float frameHeight;// = (float)button.height/NUM_FRAMES;    //Individual frame height to switch
        float frameHeight1;// = (float)button1.height/NUM_FRAMES;
        Rectangle sourceRec;// = { 0, 0, (float)button.width, frameHeight };   //Part of button to show
        Rectangle sourceRec1;// = { 0, 0, (float)button1.width, frameHeight1 };

    public:
    buttonNum()
    {
        frameHeight = (float)button.height/NUM_FRAMES;
        frameHeight1 = (float)button1.height/NUM_FRAMES;
        sourceRec = { 0, 0, (float)button.width, frameHeight };
        sourceRec1 = { 0, 0, (float)button1.width, frameHeight1 };

    }
        void draw(char const *display,int btnState)
        {
            float widthbutton=50*pixelsx;                           //width of button
            float heightbutton=17*pixelsy;                          //height of button           
            float textsize=17*pixelsy;                              //Text size in button
            float positionx,positiony;
            int shiftx,shifty;
            float textx,texty;
            char a=display[0];
            switch(a)
            {
            case '0':
                textx=50*pixelsx;
                texty=330*pixelsy;
                positionx=31*pixelsx;                            //position of x and y to load button
                positiony=327*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '.':
                textsize=24*pixelsy;
                shiftx=60.7;
                shifty=0;
                positionx=(31+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(50+shiftx)*pixelsx+8;
                texty=(330+shifty)*pixelsy-28;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case 'i':
                textsize=11.5*pixelsy;
                display="*10x";
                shiftx=61*2;
                shifty=0;
                positionx=(31+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(50+shiftx)*pixelsx-22;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case 'A':
                textsize=11.5*pixelsy;
                display="Ans";
                shiftx=61.5*3;
                shifty=0;
                positionx=(31+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(35+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case 'E':
                textsize=18.5*pixelsy;
                display="=";
                shiftx=61.2*4;
                shifty=0;
                positionx=(31.9+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(50+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '1':
                shiftx=0;
                shifty=-26;
                positionx=(30.3+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(50+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '2':
                shiftx=63;
                shifty=-26;
                positionx=(31+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(50+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '3':
                shiftx=61.6*2;
                shifty=-26;
                positionx=(31.3+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(50+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '+':
                textsize=18.5*pixelsy;
                shiftx=62.5*3;
                shifty=-26;
                positionx=(28.3+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(45+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '-':
                textsize=19*pixelsy;
                shiftx=61.6*4;
                shifty=-26;
                positionx=(30+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(46+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '4':
                shiftx=0;
                shifty=-27*2;
                positionx=(31+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(47+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '5':
                shiftx=61.4;
                shifty=-27*2;
                positionx=(31.3+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(50+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '6':
                shiftx=61.6*2;
                shifty=-27*2;
                positionx=(30.6+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(50+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '*':
                textsize=18.5*pixelsy;
                shiftx=62.5*3;
                shifty=-27*2;
                positionx=(28+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(45+shiftx)*pixelsx;
                texty=(327+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '/':
                textsize=19*pixelsy;
                shiftx=61.6*4;
                shifty=-27*2;
                positionx=(30+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(46+shiftx)*pixelsx;
                texty=(328+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '7':
                shiftx=0;
                shifty=-27*3;
                positionx=(30+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(46+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '8':
                shiftx=61.4;
                shifty=-27*3;
                positionx=(31+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327+shifty)*pixelsy;
                textx=(50+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case '9':
                shiftx=61.3*2;
                shifty=-27*3;
                positionx=(31+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(327.3+shifty)*pixelsy;
                textx=(50+shiftx)*pixelsx;
                texty=(330+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case 'D':
                textsize=11.4*pixelsy;
                display="DEL";
                shiftx=61.2*3;
                shifty=-27*3;
                positionx=(29+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(328+shifty)*pixelsy;
                textx=(39.8+shiftx)*pixelsx;
                texty=(333+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec1.y = btnState*frameHeight1;
                DrawTextureRec(button1, sourceRec1, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            case 'C':
                textsize=11.4*pixelsy;
                display="AC";
                shiftx=61.2*4;
                shifty=-27*3;
                positionx=(29+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(328+shifty)*pixelsy;
                textx=(39.8+shiftx)*pixelsx;
                texty=(333+shifty)*pixelsy;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec1.y = btnState*frameHeight1;
                DrawTextureRec(button1, sourceRec1, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display,textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            default:
                break;
            }
        }
    ~buttonNum()
    {
        UnloadTexture(button);
        UnloadTexture(button1);
        UnloadSound(fxButton);
    }
};
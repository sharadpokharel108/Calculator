#include "raylib.h"
#include "raymath.h"
#include <string>
#define NUM_FRAMES  2
#define pixelsy 2.7588
#define pixelsx 1.6568
#include<iostream>
class buttonChar{
    public:
        int integer;
        std::string display;
        Texture2D button=LoadTexture("Image/button3.png");      //Load the button
        Sound fxButton = LoadSound("buttonfx.wav");       //Load the button sound
        Rectangle btnBounds;
        float frameHeight;// = (float)button.height/NUM_FRAMES;    //Individual frame height to switch
        Rectangle sourceRec;// = { 0, 0, (float)button.width, frameHeight };   //Part of button to show

        buttonChar()
        {
            frameHeight = (float)button.height/NUM_FRAMES;
            sourceRec = { 0, 0, (float)button.width, frameHeight };
        }


        void draw(int check,int btnState)
        {
            float widthbutton=44*pixelsx;                           //width of button
            float heightbutton=16.*pixelsy;                          //height of button           
            float textsize=17*pixelsy;                              //Text size in button
            float positionx,positiony;
            int shiftx,shifty;
            float textx,texty;
            switch(check)
            {
            case 0:
                textsize=10*pixelsy;
                display="sinh";
                shiftx=0;
                shifty=0;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            
            case 1:
                textsize=10*pixelsy;
                display="cosh";
                shiftx=50.8;
                shifty=0;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;

            case 2:
                textsize=10*pixelsy;
                display="tanh";
                shiftx=51*2;
                shifty=0;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            
            case 3:
                textsize=11.5*pixelsy;
                display="(";
                shiftx=51*3;
                shifty=0;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            

            case 4:
                textsize=11.5*pixelsy;
                display=")";
                shiftx=51*4;
                shifty=0;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            

            case 5:
                textsize=10*pixelsy;
                display="S<->D";
                shiftx=51*5;
                shifty=0;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;

            case 6:
                textsize=11.5*pixelsy;
                display="LCM";
                shiftx=0;
                shifty=-26;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            
            case 7:
                textsize=11.5*pixelsy;
                display="HCF";
                shiftx=50.8;
                shifty=-26;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;

            case 8:
                textsize=11.5*pixelsy;
                display=",";
                shiftx=51*2;
                shifty=-26;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            
            case 9:
                textsize=11.5*pixelsy;
                display="sin";
                shiftx=50.7*3;
                shifty=-26;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            

            case 10:
                textsize=11.5*pixelsy;
                display="cos";
                shiftx=50.7*4;
                shifty=-26;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            

            case 11:
                textsize=11.5*pixelsy;
                display="tan";
                shiftx=50.7*5;
                shifty=-26;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;


            case 12:
                textsize=11.5*pixelsy;
                display="logb";
                shiftx=0;
                shifty=-26.1*2;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            
            case 13:
                textsize=10.5*pixelsy;
                display="sqrt";
                shiftx=50.8;
                shifty=-26.1*2;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;

            case 14:
                textsize=11.5*pixelsy;
                display="x^2";
                shiftx=50.6*2;
                shifty=-26.2*2;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            
            case 15:
                textsize=11.5*pixelsy;
                display="x^";
                shiftx=50.6*3;
                shifty=-26.2*2;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            

            case 16:
                textsize=11.5*pixelsy;
                display="log";
                shiftx=50.4*4;
                shifty=-26*2;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            

            case 17:
                textsize=11.5*pixelsy;
                display="ln";
                shiftx=50.5*5;
                shifty=-26.2*2;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;


            case 18:
                textsize=11.5*pixelsy;
                display="QR";
                shiftx=0;
                shifty=-26.8*3;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;

            case 19:
                textsize=11.5*pixelsy;
                display="root";
                shiftx=51;
                shifty=-26.8*3;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;
            
            case 20:
                textsize=11.5*pixelsy;
                display="in";
                shiftx=50.2*4;
                shifty=-27*3;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;


            case 21:
                textsize=10*pixelsy;
                display="fact";
                shiftx=50.54*5;
                shifty=-27*3;
                positionx=(24.2+shiftx)*pixelsx;                            //position of x and y to load button
                positiony=(213.4+shifty)*pixelsy;
                textx=((positionx)+(widthbutton)/2)-(MeasureText(display.c_str(),textsize)/2);
                texty=positiony+heightbutton/2-10;
                btnBounds= {positionx,positiony,widthbutton,heightbutton};
                sourceRec.y = btnState*frameHeight;
                DrawTextureRec(button, sourceRec, (Vector2){ btnBounds.x, btnBounds.y }, WHITE);            //Displaying button
                DrawText(display.c_str(),textx,texty,textsize,BLACK);                                    //Writing number in button
                break;

            default:
                break;
            }
        }
};
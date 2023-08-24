#include "buttonnum.cpp"
#include"buttonchar.cpp"
#include<string.h>
#include <cstring>
#include"evaluation.cpp"
#include"fraction.cpp"

void replaceSubstring(char* str, const char* search, const char* replace) {
    char* found = std::strstr(str, search);
    if (found) {
        size_t searchLength = std::strlen(search);
        size_t replaceLength = std::strlen(replace);

        if (searchLength != replaceLength) {
            size_t tailLength = std::strlen(found + searchLength);
            std::memmove(found + replaceLength, found + searchLength, tailLength + 1);
        }

        std::memcpy(found, replace, replaceLength);
    }
}
void insertCharArray(char* destination, int index, const char* source) {
    int destLength = strlen(destination);
    int sourceLength = strlen(source);

    if (index >= 0 && index <= destLength) {
        // Make space for the source string in the destination array
        for (int i = destLength + sourceLength; i >= index + sourceLength; i--) {
            destination[i] = destination[i - sourceLength];
        }

        // Copy the source string into the destination array
        for (int i = 0; i < sourceLength; i++) {
            destination[index + i] = source[i];
        }
    }
}
void deleteCharAtIndex(char* str, int index) {
    int length = strlen(str);

    if (index >= 0 && index < length) {
        for (int i = index; i < length - 1; i++) {
            str[i] = str[i + 1];
        }
        str[length - 1] = '\0';
    }
}
void removeSubstring(char* str, const char* substring) {
    char* found = strstr(str, substring);

    if (found != nullptr) {
        int substringLength = strlen(substring);
        int remainingLength = strlen(found + substringLength);

        memmove(found, found + substringLength, remainingLength + 1);
    }
}
Color t1Color = BLUE;
Color t2Color = BLUE;
Color t3Color = BLUE;
Color t4Color = BLUE;
Color shiftcolor=GRAY;
void equalpressed();
void onestepback();
void onestepfront();
void delleft();
void delright();
void del();
int back=0,clicked=0;
int fraction=0;
bool qr_state=false,cursor=false;
float triheight=43.3,trilength=50,tripositionx=283,tripositiony=282;
int tridistance=58;
int shifton;
Vector2 mousePoint = { 0.0f, 0.0f };
Vector2 t1v1={tripositionx,tripositiony},t1v2={t1v1.x-(trilength/2),t1v1.y+triheight},t1v3={t1v1.x+(trilength/2),t1v1.y+triheight};
Vector2 t2v1={t1v2.x-triheight,t1v2.y+(tridistance)/2},t2v2={t1v2.x,t2v1.y+(trilength/2)},t2v3={t1v2.x,t2v1.y-(trilength/2)};
Vector2 t3v1={t1v1.x,t1v1.y+2*triheight+tridistance},t3v2={t1v3.x,t1v2.y+tridistance},t3v3={t1v2.x,t1v2.y+tridistance};
Vector2 t4v1={t2v1.x+2*triheight+trilength,t2v1.y},t4v2={t1v3.x,t2v3.y},t4v3={t4v2.x,t2v2.y};

int btnStateNum[20] = {0};
int btnStateChar[30]={0};  
int shift=0;
char displaycharacter[100]="\0",result[100];
int deleteindex;
std::string storeresult="0",storedisplay[100];
char addNum[20][10]={"0",".","*10^","Ans","=","1","2","3","+","-","4","5","6","*","/","7","8","9","DEL","AC"};
char addChar[25][10]={"sinh(","cosh(","tanh(","(",")","f","lcm(","hcf(",",","sin(","cos(","tan(","logb(","sqrt(","^2","^","log(","ln(","s","root(","in(","fact("};
char shiftChar[25][10]={"sinh~","cosh~(","tanh~(","%","Matrix(","sin~(","cos~(","tan~(","DEC(","HEX(","BIN(","OCT(","Quad(","Cubic(","Eqn2(","Eqn3(","~"};

void isarrowclicked(Sound fxbutton);

void isclickednum(Sound fxButton, Rectangle button1,char check)
{
    int n;
        switch(check)
        {
            case '0':
                n=0;
                break;
            case '.':
                n=1;
                break;
            case 'i':
                n=2 ;
                break;
            case 'A':
                n=3 ;
                break;
            case 'E':
                n=4 ;
                break;
            case '1':
                n=5 ;
                break;
            case '2':
                n=6 ;
                break;
            case '3':
                n=7 ;
                break;
            case '+':
                n=8 ;
                break;
            case '-':
                n=9 ;
                break;
            case '4':
                n=10 ;
                break;
            case '5':
                n=11 ;
                break;
            case '6':
                n=12 ;
                break;
            case '*':
                n=13 ;
                break;
            case '/':
                n=14 ;
                break;
            case '7':
                n=15 ;
                break;
            case '8':
                n=16 ;
                break;
            case '9':
                n=17 ;
                break;
            case 'D':
                n=18 ;
                break;
            case 'C':
                n=19 ;
                break;
            default:
                break;
        }
        bool btnAction = false;  
        mousePoint = GetMousePosition();
            // Check button state
        if (CheckCollisionPointRec(mousePoint, button1))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
            {
            btnStateNum[n] = 2;
            }
            else btnStateNum[n] = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnStateNum[n] = 0;

        if (btnAction)
        {
            if(n==18)
            {
                del();

            }
            else if(n==19)
            {
                displaycharacter[0]='\0';                   // Used for AC
                result[0]='\0';
                fraction=0;
                qr_state=false;
                cursor=false;
                shift=0;
                clicked=0;
            }
            else if(n==4)
                {
                    equalpressed();
                }
            else
            {
                //strcat(displaycharacter,addNum[n]);
                insertCharArray(displaycharacter, deleteindex+1, addNum[n]);
                delright();
                shift=0;
            }
            PlaySound(fxButton);

            // TODO: Any desired action
        }
}



void isclickedchar(Sound fxButton, Rectangle button1,int check)
{
    int n,x;
        switch(check)
        {
            case 0:
                n=0;
                x=0;
                break;
            case 1:
                n=1;
                x=1;
                break;
            case 2:
                n=2 ;
                x=2;
                break;
            case 3:
                n=3;
                x=3;
                break;
            case 4:
                n=4 ;
                x=16;
                break;
            case 5:
                n=5 ;
                x=100;
                break;
            case 6:
                n=6 ;
                x=14;
                break;
            case 7:
                n=7 ;
                x=15;
                break;
            case 8:
                n=8 ;
                x=4;
                break;
            case 9:
                n=9 ;
                x=5;
                break;
            case 10:
                n=10 ;
                x=6;
                break;
            case 11:
                n=11 ;
                x=7;
                break;
            case 12:
                n=12;
                x=12;
                break;
            case 13:
                n=13 ;
                x=13;
                break;
            case 14:
                n=14 ;
                x=8;
                break;
            case 15:
                n=15 ;
                x=9;
                break;
            case 16:
                n=16 ;
                x=10;
                break;
            case 17:
                n=17 ;
                x=11;
                break;
            case 18:
                n=18 ;
                x=100;
                break;
            case 19:
                n=19 ;
                x=100;
                break;
            case 20:
                n=20 ;
                x=100;
                break;
            case 21:
                n=21 ;
                x=100;
                break;
            default:
                break;
        }
        bool btnAction = false;  
        mousePoint = GetMousePosition();
            // Check button state
        if (CheckCollisionPointRec(mousePoint, button1))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) 
            {
            btnStateChar[n] = 2;
            }
            else btnStateChar[n] = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
        }
        else btnStateChar[n] = 0;

        if (btnAction)
        {
            if(n==5)
            {
                if (strcmp(displaycharacter, "\0") != 0)
                {
                fraction+=1;
                result[0]='\0';
                if((fraction%2)==1)
                    if (equalsto(displaycharacter,15)=="Syntax error")
                            strcat(result,"Syntax error");
                    else if(equalsto(displaycharacter,15)=="Invalid input format.")
                        strcat(result,"Invalid input format.");
                    else if(equalsto(displaycharacter,15)=="Infinite solutions")
                        strcat(result,"Infinite solutions");
                    else
                        strcat(result,fraction_repeating(equalsto(displaycharacter,23)).c_str());
                else
                    strcat(result,equalsto(displaycharacter).c_str());
                }
            }
            else if(n==18)
            {
                qr_state=true;
            }
            else
            {
                //strcat(displaycharacter,addChar[n]);
                if ((shift%2)==0 || x==100)
                {
                    insertCharArray(displaycharacter, deleteindex+1, addChar[n]);
                    shift=0;
                }
                else{
                    if(x==4||x==8||x==9||x==10||x==11||x==12||x==13||x==14||x==15)
                    {
                        displaycharacter[0]='\0';
                        deleteindex=-1;
                    }
                    insertCharArray(displaycharacter, deleteindex+1, shiftChar[x]);
                    x=100;
                    shift=0;
                }
                delright();
            }
            PlaySound(fxButton);

            // TODO: Any desired action
        }
}



int main(void)
{

    const int screenWidth = 574;
    const int screenHeight = 994;

    InitWindow(screenWidth, screenHeight, "CALCULATOR");
    InitAudioDevice();      // Initialize audio device
    Texture2D calc=LoadTexture("Image/Calculator.png");
    Image qr = LoadImage("Image/qr_code.png");
    int newWidth = 160; // New width after resizing
    int newHeight = 135; // New height after resizing
    ImageResize(&qr, newWidth, newHeight);

    // Create a texture from the resized image
    Texture2D texture = LoadTextureFromImage(qr);

    // Unload the original image
    UnloadImage(qr);
    buttonNum num[20];
    buttonChar character[30];
    
    bool btnAction = false;         // Button action should be activated
    Sound fxButton = LoadSound("buttonfx.wav");   // Load button sound

    while (!WindowShouldClose())    
    {   
        if(cursor==false)
    {

        deleteindex=strlen(displaycharacter)-1;
    }
    if ((strcmp(displaycharacter, "\0") == false))
    {
        cursor=false;
    }

        float displayx=36*pixelsx;
        float displayy=48*pixelsy;
        float displayresultx=308*pixelsx;
        float displayresulty=84*pixelsy;
        BeginDrawing();
        DrawTexture(calc, 0, 0, WHITE);
        DrawTriangle(t1v1,t1v2,t1v3,t1Color);
        DrawTriangle(t2v1,t2v2,t2v3,t2Color);
        DrawTriangle(t3v1,t3v2,t3v3,t3Color);
        DrawTriangle(t4v1,t4v2,t4v3,t4Color);
        DrawCircle(69,319,23,shiftcolor);
        if((shift%2)==0)
            shifton=0;
        else
            shifton=10;
        DrawCircle(69,319,shifton,RED);
        DrawText("Shift",48,272,22,RED);
        num[0].draw("0",btnStateNum[0]);
        num[1].draw(".",btnStateNum[1]);
        num[2].draw("i",btnStateNum[2]);
        num[3].draw("A",btnStateNum[3]);
        num[4].draw("E",btnStateNum[4]);
        num[5].draw("1",btnStateNum[5]);
        num[6].draw("2",btnStateNum[6]);
        num[7].draw("3",btnStateNum[7]);
        num[8].draw("+",btnStateNum[8]);
        num[9].draw("-",btnStateNum[9]);                       //Displaying the numbers
        num[10].draw("4",btnStateNum[10]);
        num[11].draw("5",btnStateNum[11]);
        num[12].draw("6",btnStateNum[12]);
        num[13].draw("*",btnStateNum[13]);
        num[14].draw("/",btnStateNum[14]);
        num[15].draw("7",btnStateNum[15]);
        num[16].draw("8",btnStateNum[16]);
        num[17].draw("9",btnStateNum[17]);
        num[18].draw("D",btnStateNum[18]);
        num[19].draw("C",btnStateNum[19]);

        isarrowclicked(fxButton);
        isclickednum(fxButton,num[0].btnBounds,'0');
        isclickednum(fxButton,num[1].btnBounds,'.');
        isclickednum(fxButton,num[2].btnBounds,'i');
        isclickednum(fxButton,num[3].btnBounds,'A');
        isclickednum(fxButton,num[4].btnBounds,'E');
        isclickednum(fxButton,num[5].btnBounds,'1');
        isclickednum(fxButton,num[6].btnBounds,'2');
        isclickednum(fxButton,num[7].btnBounds,'3');
        isclickednum(fxButton,num[8].btnBounds,'+');
        isclickednum(fxButton,num[9].btnBounds,'-');
        isclickednum(fxButton,num[10].btnBounds,'4');
        isclickednum(fxButton,num[11].btnBounds,'5');
        isclickednum(fxButton,num[12].btnBounds,'6');
        isclickednum(fxButton,num[13].btnBounds,'*');
        isclickednum(fxButton,num[14].btnBounds,'/');                   //Checking if the numbers are pressed
        isclickednum(fxButton,num[15].btnBounds,'7');
        isclickednum(fxButton,num[16].btnBounds,'8');
        isclickednum(fxButton,num[17].btnBounds,'9');
        isclickednum(fxButton,num[18].btnBounds,'D');
        isclickednum(fxButton,num[19].btnBounds,'C');


        character[0].draw(0,btnStateChar[0]);
        character[1].draw(1,btnStateChar[1]);
        character[2].draw(2,btnStateChar[2]);
        character[3].draw(3,btnStateChar[3]);
        character[4].draw(4,btnStateChar[4]);
        character[5].draw(5,btnStateChar[5]);
        character[6].draw(6,btnStateChar[6]);
        character[7].draw(7,btnStateChar[7]);
        character[8].draw(8,btnStateChar[8]);
        character[9].draw(9,btnStateChar[9]);
        character[10].draw(10,btnStateChar[10]);
        character[11].draw(11,btnStateChar[11]);
        character[12].draw(12,btnStateChar[12]);
        character[13].draw(13,btnStateChar[13]);
        character[14].draw(14,btnStateChar[14]);
        character[15].draw(15,btnStateChar[15]);
        character[16].draw(16,btnStateChar[16]);
        character[17].draw(17,btnStateChar[17]);
        character[18].draw(18,btnStateChar[18]);
        character[19].draw(19,btnStateChar[19]);
        character[20].draw(20,btnStateChar[20]);
        character[21].draw(21,btnStateChar[21]);

        isclickedchar(fxButton,character[0].btnBounds,0);
        isclickedchar(fxButton,character[1].btnBounds,1);
        isclickedchar(fxButton,character[2].btnBounds,2);
        isclickedchar(fxButton,character[3].btnBounds,3);
        isclickedchar(fxButton,character[4].btnBounds,4);
        isclickedchar(fxButton,character[5].btnBounds,5);
        isclickedchar(fxButton,character[6].btnBounds,6);
        isclickedchar(fxButton,character[7].btnBounds,7);
        isclickedchar(fxButton,character[8].btnBounds,8);
        isclickedchar(fxButton,character[9].btnBounds,9);
        isclickedchar(fxButton,character[10].btnBounds,10);
        isclickedchar(fxButton,character[11].btnBounds,11);
        isclickedchar(fxButton,character[12].btnBounds,12);
        isclickedchar(fxButton,character[13].btnBounds,13);
        isclickedchar(fxButton,character[14].btnBounds,14);
        isclickedchar(fxButton,character[15].btnBounds,15);
        isclickedchar(fxButton,character[16].btnBounds,16);
        isclickedchar(fxButton,character[17].btnBounds,17);
        isclickedchar(fxButton,character[18].btnBounds,18);
        isclickedchar(fxButton,character[19].btnBounds,19);
        isclickedchar(fxButton,character[20].btnBounds,20);
        isclickedchar(fxButton,character[21].btnBounds,21);
        for (int i = KEY_ZERO; i <= KEY_NINE; i++) {
            if (IsKeyPressed(i)) {
                std::string myString(1, (char)(i - KEY_ZERO + '0'));
                //strcat(displaycharacter,myString.c_str()); // Convert the key constant to the corresponding character
                insertCharArray(displaycharacter, deleteindex+1, myString.c_str());
                delright();
            }
        }


        if (IsKeyPressed(KEY_KP_ADD))
        {
            insertCharArray(displaycharacter, deleteindex+1, "+");
            delright();
    }
        else if (IsKeyPressed(KEY_KP_SUBTRACT))
        {
            //strcat(displaycharacter,"-");
            insertCharArray(displaycharacter, deleteindex+1, "-");
            delright();
        }
        else if (IsKeyPressed(KEY_KP_MULTIPLY)) 
        {
            insertCharArray(displaycharacter, deleteindex+1, "*");
            delright();
        }
        else if (IsKeyPressed(KEY_KP_DIVIDE)) 
        {
            insertCharArray(displaycharacter, deleteindex+1, "/");
            delright();
        }
        else if (IsKeyPressed(KEY_KP_DECIMAL))
        {
            insertCharArray(displaycharacter, deleteindex+1, ".");
            delright();
            }
        else if (IsKeyPressed(KEY_GRAVE)) 
        {
            insertCharArray(displaycharacter, deleteindex+1, "~");
            delright();
        }
        else if (IsKeyPressed(KEY_COMMA)) 
        {
            insertCharArray(displaycharacter, deleteindex+1, ",");
            delright();
        }
        else if (IsKeyPressed(KEY_BACKSPACE)) 
        {
            del();
        }
        else if(IsKeyPressed(KEY_DELETE))
        {
            displaycharacter[0]='\0';                   // Used for AC
            result[0]='\0';
            fraction=0;
            qr_state=false;
            cursor=false;
            shift=0;
            clicked=0;
        }
        else if (IsKeyPressed(KEY_LEFT_BRACKET)) 
        {
            insertCharArray(displaycharacter, deleteindex+1, "(");
            delright();
        }
        else if (IsKeyPressed(KEY_RIGHT_BRACKET)) 
        {
            insertCharArray(displaycharacter, deleteindex+1, ")");
            delright();
        }
        else if (IsKeyPressed(KEY_S)) 
        {
            insertCharArray(displaycharacter, deleteindex+1, "sin(");
            for(int i=0;i<strlen("sin(");i++)
                delright();
        }
        else if (IsKeyPressed(KEY_C)) 
        {
            insertCharArray(displaycharacter, deleteindex+1, "cos(");
            for(int i=0;i<strlen("cos(");i++)
                delright();        }
        else if (IsKeyPressed(KEY_T)) 
        {
            insertCharArray(displaycharacter, deleteindex+1, "tan(");
            for(int i=0;i<strlen("tan(");i++)
                delright();
        }
        else if (IsKeyPressed(KEY_E)) 
        {
            displaycharacter[0]='\0';
            deleteindex=-1;
            insertCharArray(displaycharacter, deleteindex+1, "Eqn2(");
            for(int i=0;i<strlen("Eqn2(");i++)
                delright();
        }
        else if (IsKeyPressed(KEY_F)) 
        {
            displaycharacter[0]='\0';
            deleteindex=-1;
            insertCharArray(displaycharacter, deleteindex+1, "Eqn3(");
            for(int i=0;i<strlen("Eqn3(");i++)
                delright();
        }
        else if (IsKeyPressed(KEY_M)) 
        {
            displaycharacter[0]='\0';
            deleteindex=-1;
            insertCharArray(displaycharacter, deleteindex+1, "Matrix(");
            for(int i=0;i<strlen("Matrix(");i++)
                delright();
        }
        else if (IsKeyPressed(KEY_L)) 
        {
            insertCharArray(displaycharacter, deleteindex+1, "lcm(");
            for(int i=0;i<strlen("lcm(");i++)
                delright();
        }
        else if (IsKeyPressed(KEY_H)) 
        {
            insertCharArray(displaycharacter, deleteindex+1, "hcf(");
            for(int i=0;i<strlen("hcf(");i++)
                delright();
        }
        else if (IsKeyPressed(KEY_B)) 
        {
            displaycharacter[0]='\0';
            deleteindex=-1;
            insertCharArray(displaycharacter, deleteindex+1, "BIN(");
            for(int i=0;i<strlen("BIN(");i++)
                delright();
        }
        else if (IsKeyPressed(KEY_D)) 
        {
            displaycharacter[0]='\0';
            deleteindex=-1;
            insertCharArray(displaycharacter, deleteindex+1, "DEC(");
            for(int i=0;i<strlen("DEC(");i++)
                delright();
        }
        else if (IsKeyPressed(KEY_O)) 
        {
            displaycharacter[0]='\0';
            deleteindex=-1;
            insertCharArray(displaycharacter, deleteindex+1, "OCT(");
            for(int i=0;i<strlen("OCT(");i++)
                delright();
        }
        else if (IsKeyPressed(KEY_H)) 
        {
            displaycharacter[0]='\0';
            deleteindex=-1;
            insertCharArray(displaycharacter, deleteindex+1, "HEX(");
            for(int i=0;i<strlen("HEX(");i++)
                delright();
        }
        else if (IsKeyPressed(KEY_Q)) 
        {
            displaycharacter[0]='\0';
            deleteindex=-1;
            insertCharArray(displaycharacter, deleteindex+1, "Quad(");
            for(int i=0;i<strlen("Quad(");i++)
                delright();
        }
        else if (IsKeyPressed(KEY_ENTER)) 
            equalpressed();
        else if (IsKeyPressed(KEY_UP)) 
            onestepback();
        else if (IsKeyPressed(KEY_DOWN)) 
            onestepfront();
        else if(IsKeyPressed(KEY_LEFT))
        {
            delleft();
        }
        else if(IsKeyPressed(KEY_RIGHT))
        {
            delright();
        }



        if(qr_state)
            DrawTexture(texture, 208, 125, WHITE);
        else
        {
        insertCharArray(displaycharacter, deleteindex+1, "!");
        DrawText(displaycharacter,displayx,displayy,30,BLACK);
        removeSubstring(displaycharacter,"!");
        if (!((std::strlen(result) >= 11) && (std::strncmp(result, "Determinant", 11) == 0)))
         {
            DrawText(result,displayresultx-MeasureText(result,30),displayresulty,30,BLACK);
        }
        else{
            displaycharacter[0]='\0';
            DrawText(result,displayx,displayy-10,27,BLACK);
        }
        }
        EndDrawing();
    }
     UnloadTexture(calc);  // Unload button texture
     UnloadTexture(texture);
    CloseAudioDevice();     
    CloseWindow();  

    return 0;
}

void equalpressed()
{
    if(displaycharacter[0]!='\0')
        {
        clicked=0;
        result[0]='\0';
        storedisplay[back]=displaycharacter;
        back+=1;
        if(storeresult!="\0")
            {
                replaceSubstring(displaycharacter, "Ans", storeresult.c_str());
            }
        if((fraction%2)==1)
            if (equalsto(displaycharacter,15)=="Syntax error")
                strcat(result,"Syntax error");
            else if(equalsto(displaycharacter,15)=="Invalid input format.")
                strcat(result,"Invalid input format.");
            else if(equalsto(displaycharacter,15)=="Infinite solutions")
                strcat(result,"Infinite solutions");
            else
            {
                storeresult=fraction_repeating(equalsto(displaycharacter,23));
                strcat(result,fraction_repeating(equalsto(displaycharacter,23)).c_str());
            }
        else
        {
            storeresult=equalsto(displaycharacter);
            strcat(result,equalsto(displaycharacter).c_str());
        }
        }
}
void onestepback()
{   if (clicked<back)
        clicked+=1;
    displaycharacter[0]='\0';
    result[0]='\0';
    if(back-clicked>=0)
    {
        strcat(displaycharacter,storedisplay[back-clicked].c_str());
        cursor=false;
        }
}
void onestepfront()
{
    if ((clicked<back+1) and (clicked>=0))
        clicked=clicked-1;
    displaycharacter[0]='\0';
    result[0]='\0';
    if(clicked>-1)
    {
        strcat(displaycharacter,storedisplay[back-clicked].c_str());
        cursor=false;
    }
}
void delleft()
{
    cursor=true;
    if((deleteindex-1)>=-1)
        deleteindex-=1;
    std::cout<<deleteindex;
}
void delright()
{
    if((deleteindex+1)<=strlen(displaycharacter)-1)
        deleteindex+=1;
}

void isarrowclicked(Sound fxButton){
    if(CheckCollisionPointTriangle(mousePoint, t1v1,t1v2,t1v3))
    {
        t1Color=GREEN;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                onestepback();
                PlaySound(fxButton);
            }
    }
    else
     t1Color=BLUE;
    if(CheckCollisionPointTriangle(mousePoint, t2v1,t2v2,t2v3))
    {
        t2Color=GREEN;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                delleft();
                PlaySound(fxButton);
            }
    }
    else
     t2Color=BLUE;

    if(CheckCollisionPointTriangle(mousePoint, t3v1,t3v2,t3v3))
    {
        t3Color=GREEN;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                onestepfront();
                PlaySound(fxButton);
            }
    }
    else
     t3Color=BLUE;

    if(CheckCollisionPointTriangle(mousePoint, t4v1,t4v2,t4v3))
    {
        t4Color=GREEN;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                delright();
                PlaySound(fxButton);
            }
    }
    else
     t4Color=BLUE;
    if(CheckCollisionPointCircle(mousePoint, {69,319},23))
    {
        shiftcolor=WHITE;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                shift+=1;
                PlaySound(fxButton);
            }
    }
    else
     shiftcolor=GRAY;
    
}
void del()
{
    result[0]='\0';
                //displaycharacter[strlen(displaycharacter)-1] = '\0';     //Used for del
                deleteCharAtIndex(displaycharacter,deleteindex);
                if(cursor)
                { if((deleteindex-1)>=-1)
                        deleteindex-=1;
                }
}
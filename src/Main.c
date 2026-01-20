#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"

void Setup(AlxWindow* w){
    
}
void Update(AlxWindow* w){
    if(Stroke(ALX_MOUSE_L).DOWN){
        int index = window.MouseY * window.Width + window.MouseX;
        if(index>=0 && index<window.Width * window.Height){
            window.Buffer[index] = WHITE;
        }
        //printf("X:%d Y:%d W:%d\n",window.MouseX,window.MouseY,window.Width);
    }
    
    Clear(BLACK);
    
    RenderCStr("Hello World",10,10,BLUE);
}
void Delete(AlxWindow* w){

}

int main() {
    if(Create("Wayland Test",1000,1000,1,1,Setup,Update,Delete)){
        Start();
    }
    return 0;
}

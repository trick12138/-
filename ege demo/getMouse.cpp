#include <graphics.h>
#include <stdio.h>
 
int main()
{
    initgraph(960, 640);
    setrendermode(RENDER_MANUAL); //��ʹ���Զ�ˢ�£�������˸ 
    setfont(18, 0, "����");
    mouse_msg msg = {0};
    for ( ; is_run(); delay_fps(60))
    {
        //��ȡ�����Ϣ���˺�������ȴ������к����������
        while (mousemsg())
        {
            msg = getmouse();
        }
        cleardevice();
        xyprintf(0, 0, "x = %10d  y = %10d",
                msg.x, msg.y);
        xyprintf(0, 20, "move  = %d down  = %d up    = %d",
                (int)msg.is_move(),
                (int)msg.is_down(),
                (int)msg.is_up());
        xyprintf(0, 40, "left  = %d mid   = %d right = %d",
                (int)msg.is_left(),
                (int)msg.is_mid(),
                (int)msg.is_right());
        xyprintf(0, 60, "wheel = %d  wheel rotate = %d",
                (int)msg.is_wheel(),
                msg.wheel);
    }
    closegraph();
    return 0;
}

if( RIGHT_BUTTON_DOWN )
{
    
}
//-------------------------------------------------------------------------------------
if( MIDDLE_BUTTON_DOWN && !KEY_CTRL_L  && !KEY_SHIFT_L)
{
    //Pass_MIDDLE_Mouse[1] -= (ptMouseCurrent.x - ptMousePrev.x)   * .3;
    //Pass_MIDDLE_Mouse[0] += (ptMouseCurrent.y - ptMousePrev.y)   * .3;
}
//-------------------------------------------------------------------------------------
if( MIDDLE_BUTTON_DOWN && KEY_CTRL_L)
{
    //Pass_MIDDLE_CONTROL_Mouse += (ptMouseCurrent.y - ptMousePrev.y)   * .1;
}
//-------------------------------------------------------------------------------------
if( MIDDLE_BUTTON_DOWN && KEY_SHIFT_L)
{
    //Pass_MIDDLE_SHIFT_Mouse[0] += (ptMouseCurrent.x - ptMousePrev.x)   * .02;
    //Pass_MIDDLE_SHIFT_Mouse[1] -= (ptMouseCurrent.y - ptMousePrev.y)   * .02;
}
//-------------------------------------------------------------------------------------
if(LEFT_BUTTON_DOWN && !KEY_CTRL_L  && !KEY_SHIFT_L)
{
    Pass_MIDDLE_Mouse[1] -= (ptMouseCurrent.x - ptMousePrev.x);
    Pass_MIDDLE_Mouse[0] += (ptMouseCurrent.y - ptMousePrev.y);
}
//-------------------------------------------------------------------------------------
if(LEFT_BUTTON_DOWN && KEY_CTRL_L)
{
    Pass_MIDDLE_CONTROL_Mouse += (ptMouseCurrent.y - ptMousePrev.y);
}
//-------------------------------------------------------------------------------------
if(LEFT_BUTTON_DOWN && KEY_SHIFT_L)
{
    Pass_MIDDLE_SHIFT_Mouse[0] += (ptMouseCurrent.x - ptMousePrev.x);
    Pass_MIDDLE_SHIFT_Mouse[1] -= (ptMouseCurrent.y - ptMousePrev.y);
}
//-------------------------------------------------------------------------------------


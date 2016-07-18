
if(basic_LIGHT0_POS[0] <= -50)
{
    basic_LIGHT0_DIRECTION[0] = 1;
}
if(basic_LIGHT0_POS[0] >=  50)
{
    basic_LIGHT0_DIRECTION[0] = 0;
}
if(basic_LIGHT0_DIRECTION[0] == 1)
{
    basic_LIGHT0_POS[0] += .32;
}
    if(basic_LIGHT0_DIRECTION[0] == 0)
{
    basic_LIGHT0_POS[0] -= .27;
}
//---------------------------------

if(basic_LIGHT0_POS[1] <= -23)
{
    basic_LIGHT0_DIRECTION[1] = 1;
}
if(basic_LIGHT0_POS[1] >=  23)
{
    basic_LIGHT0_DIRECTION[1] = 0;
}
if(basic_LIGHT0_DIRECTION[1] == 1)
{
    basic_LIGHT0_POS[1] += .3;
}
    if(basic_LIGHT0_DIRECTION[1] == 0)
{
    basic_LIGHT0_POS[1] -= .25;
}   
//---------------------------------
if(basic_LIGHT0_POS[2] <= -60)
{
    basic_LIGHT0_DIRECTION[2] = 1;
}
if(basic_LIGHT0_POS[2] >=  60)
{
    basic_LIGHT0_DIRECTION[2] = 0;
}
if(basic_LIGHT0_DIRECTION[2] == 1)
{
    basic_LIGHT0_POS[2] += .15;
}
    if(basic_LIGHT0_DIRECTION[2] == 0)
{
    basic_LIGHT0_POS[2] -= .11;
}   

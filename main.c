#include <kipr/botball.h>

void foward(int dist);
void left(int dist);
void right(int dist);
void back(int dist);
void close_water();
void open_water();
void close_puff();
void arm_down();
void front_back();
void open_puff();
void foward2();
void right2();
int claw =0;
int arm=1;
int mini=2;
int open=1131;
int openB=1024;
int close=1860;
int up=5;
int downB=1950;
int downC=1916;
int down=1985;
int upp=801;
int mini_close=645;
int mini_open=1756;
int main()


{
    
    
    //get out of startbox
    create_connect();
    create_full();

    set_servo_position(arm,5);
    set_servo_position(mini,mini_open);
    set_servo_position(claw,close);

    enable_servos();
    //pause for jamie to get out 
     msleep(4000);

    //left out of start box
    left(180);//og 180, other option 160

    //backward till line up with water container
    back(700);
    // to line up with container and to line up to puffs
    left(150);//og 160 option 2: 130 option 3: 140 option 4:150
    //grab the container
    back (170);
     //grab the container
    close_water();

    //forward to get past blocks
    foward(220); //og225 

    //claw open
    set_servo_position(claw,open);
    msleep(300);
    //arm down to pick up first pile
    arm_down();

    //forward to pick up first pile
    foward(170);//og 170

    //close on 1st pile
    close_puff();
    //put first pile in bin
    front_back();
    //open claw to put puffs
    open_puff();
    //move right to face 2nd pile
    right(52);//og 54 
    //arm down to line up with 2nd puff pile
    arm_down();
    //move foward to 2nd pile
    foward(150);//og 190
    //close claw to grab 2nd pile
    close_puff();
    //lift arm up to put pile into bucket 
    front_back();
    // open claw to drop puffs 
    open_puff();
    //turn to food&med supplied
    right(60);
    //open claw wider to get F&W supplies
    set_servo_position(claw,openB);
    msleep(300);
    //put arm down to push food
    arm_down();
    //go foward to get food&med supplies
    foward(240);
    //turn left to allight with 2nd pile of f&m supplies
    left(20);
    //lift claw small amount off ground
    set_servo_position(arm,downB);
    msleep(300);
    //go foward to get 2nd pile
    foward(780);  
    //put claw closer to floor
    set_servo_position(arm,1958);
    msleep(300);
    //close claw to get F&W (slow servo)
    while(get_servo_position(claw) < 1580)

    {
        set_servo_position(claw,get_servo_position(claw) +30);
        msleep(50);
    }
    //turn right to put F&W S. in box
    right2(50,50,115);
    //push F&W into box 
    foward(340);
    //open claw
    set_servo_position(claw,open);
    msleep(300);
    //lift claw up to not trap puffs
    front_back();
    //back out of box
    back(300);
    //turn to 3rd pile
    right2(50,50,105);
    //move up to get 3rd pile
    foward(170);
    //put claw down to get 3rd pile
    arm_down();
    //lift claw a small amount
    set_servo_position(arm, downC);
    msleep(300);
    //close claw
    close_puff();
   //move arm up to put puffs in container
    front_back();
    //open the claw
    open_puff();
    //go back to allign with 4th pile
    back(50);
    //turn to allign with 4th pile
    right(45);
   
    


    return 0;   
}


void back(int dist)
{
    set_create_distance(0);
    while (get_create_distance()>-dist)
    {
        create_drive_direct(-150,-150);
    }
    create_stop();

}



void foward(int dist)
{
    set_create_distance(0);
    while (get_create_distance()<dist)
    {
        create_drive_direct(150,150);
    }
    create_stop();
}


void right(int dist)
{
    set_create_total_angle(0);
    while (get_create_total_angle()> -dist)
    {
        create_drive_direct(200,-200);

    } 

    create_stop();
}

void left(int dist)
{
    set_create_total_angle(0);
    while (get_create_total_angle() < dist)
    {
        create_drive_direct(-200,200);

    } 
    create_stop();
}
void close_water()
{
    set_servo_position(mini,mini_close);
    msleep(300);
}

void open_water()

{
    set_servo_position(mini,mini_open);
    msleep(300); 

}
void close_puff()
{
    while(get_servo_position(claw) < close)

    {
        set_servo_position(claw,get_servo_position(claw) +30);
        msleep(50);
    }
}



//slow servo function

//go down
/*
while(get_servo_position(arm) < 2018)

	{
	set_servo_position(arm,get_servo_position(arm) +10);
    msleep(15);
	}
*/

void arm_down()
{


    while(get_servo_position(arm) < 1800)

    {
        set_servo_position(arm,get_servo_position(arm) +20);
        msleep(50);
    }
    set_servo_position(arm,down);
    msleep(300);



}
void front_back()
{
    //front arm down
    while(get_servo_position(arm)>100)

    {
        set_servo_position(arm,get_servo_position(arm) -40);
        msleep(30);
    }
    set_servo_position(arm,5);//end position
    msleep(200);
}


void open_puff()
{
    //close 1928
    //open1350

    while(get_servo_position(claw) > 1350)

    {
        set_servo_position(claw,get_servo_position(claw) -10);
        msleep(100);
    }
}

void right2(int ls, int rs, int ang)
{
    set_create_total_angle(0);
    while (get_create_total_angle()>-ang)
    {
        create_drive_direct(ls,-rs);
    }
    create_stop();
}

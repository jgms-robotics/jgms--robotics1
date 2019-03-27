#include <kipr/botball.h>
void foward();
void right();
void left();
void foward2();
int claw =0;
int arm=1;
int mini=2;
int open=1273;
int close=1047;
int up=0;
int down=1991;
int upp=801;
int mini_close=659;
int mini_open=1766;
int main()


{
    //get out of startbox
    create_connect();
    //get water tank
  left();
    set_create_total_angle(0);
    create_drive_direct(-57,-50);
    msleep(1500);
    //turn to grab bucket
    enable_servos();
    set_servo_position(mini,mini_open);
    msleep(300);
    set_create_total_angle(0);
    create_drive_direct(50,50);
    msleep(1500);
    right();
     set_create_total_angle(0);
    create_drive_direct(56,50);
    msleep(9000);
    right();
    
     set_create_total_angle(0);
    create_drive_direct(58,50);
    msleep(9000);
 
        enable_servos();
    set_servo_position(arm,down);
    set_servo_position(claw,open);
    msleep(300);
    
    set_create_total_angle(0);
    create_drive_direct(58,50);
    msleep(100);

    
    
    //drive to pom-poms
    
     
      printf("Angle Value: %d\n",get_create_total_angle());
    printf("Distance Value: %d\n",get_create_distance());
  

    return 0;   
}

void foward(int dist)
{
    set_create_total_angle(0);
    create_drive_direct(210,235);
    msleep(2000);
}


void right(int dist)
{
    set_create_total_angle(0);
    while (get_create_total_angle() > -100)
        {
         create_drive_direct(200,-200);
     
    	}
    create_stop();
}

void left(int dist)
{
    set_create_total_angle(0);
    while (get_create_total_angle() < 100)
        {
         create_drive_direct(-200,200);
     
    	} 
}


#include "mbed.h"

#define WAIT 100ms

bool laufen = true;

InterruptIn taste(PA_1);

DigitalOut pc0(PC_0);
DigitalOut pc1(PC_1);
DigitalOut pc2(PC_2);
DigitalOut pc3(PC_3);
DigitalOut pc4(PC_4);
DigitalOut pc5(PC_5);
DigitalOut pc6(PC_6);
DigitalOut pc7(PC_7);

void abc() {
    if(laufen == true){
        laufen = false;
    }else{
        laufen = true;
    }
}

int main(){

    taste.mode(PullDown);
    taste.rise(&abc);
    taste.enable_irq();

    while (true){
        
        if (laufen) {

            pc0 = 1;
            ThisThread::sleep_for(WAIT);
            pc0 = 0;
            pc2 = 1;
            ThisThread::sleep_for(WAIT);
            pc2 = 0;
            pc4 = 1;
            ThisThread::sleep_for(WAIT);
            pc4 = 0;
            pc6 = 1;
            ThisThread::sleep_for(WAIT);
            pc6 = 0;
            
            pc7 = 1;
            ThisThread::sleep_for(WAIT);
            pc7 = 0;

            pc5 = 1;
            ThisThread::sleep_for(WAIT);
            pc5 = 0;

            pc3 = 1;
            ThisThread::sleep_for(WAIT);
            pc3 = 0;

            pc1 = 1;
            ThisThread::sleep_for(WAIT);
            pc1 = 0;

        }
    }
}


#ifndef cloudSending_shareData_h
#define cloudSending_shareData_h

#pragma once

class SharedData
{
public:
	int counter;
	int lastUpdate;
	ofTrueTypeFont font;
    
    int weight;

	ofVideoGrabber cam;
    
    int qrcodeCamId;
    int weightCamId;
};


#endif

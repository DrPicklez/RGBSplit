#include "ofMain.h"


class Video{
private:
    /* data */
public:
    Video(/* args */);
    ~Video();
    void setup();
    void update();
    void draw();
    void forwardBackward(bool isForward);
    void updatePlayheads(ofVec3f targetPositions);

    typedef struct{
        int forward;
        int backward;
        int middle;
    } Playhead;
    

    ofVideoGrabber camera;
    ofTexture texture;
    ofPixels *camPix;
    ofVbo vbo;
    ofVideoPlayer player;

    bool buffLoc = false;
    bool bufferIsInit = false;

    deque <ofFbo> fboBuffer;
    int bfferN;
    ofVec3f playhead, playheadTarget;
    float speed = 0.01;
    int timeIncMillis = 0;
    int maxBuffers = 200;
    ofShader rgbSplit;
    


};

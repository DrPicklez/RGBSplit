#include "Video.h"

Video::Video(/* args */){

}

Video::~Video(){

}

void Video::setup(){
    rgbSplit.load("rgbSplit.vert", "rgbSplit.frag");
    player.load("/home/william/Videos/Frog.mp4");
    texture.allocate(player.getWidth(), player.getHeight(), GL_RGB);
    ofEnableAlphaBlending();
    player.play();
    player.setSpeed(0.5);   //Nees to be the speed of the buffer filler to get forward 
}
int mod = 0;
void Video::update(){
        player.update();
        if(player.isFrameNew() && (mod % 10 == 0)){
            ofFbo buffer;
            buffer.allocate(player.getWidth(), player.getHeight());
            buffer.begin();
            player.draw(0, 0, buffer.getWidth(), buffer.getHeight());
            buffer.end();
            if(fboBuffer.size() < maxBuffers){
                fboBuffer.push_front(buffer);
            }
            else{
                if(!bufferIsInit){
                    float middle = fboBuffer.size() /2;
                    playhead= ofVec3f(middle, middle, middle);
                    playheadTarget= ofVec3f(middle, middle, middle);
                }
                bufferIsInit = true;
                buffLoc = true;
                fboBuffer.pop_back();
                fboBuffer.push_front(buffer);
                buffLoc = false;
            }

            float middle = fboBuffer.size() /2;
            playhead.interpolate(ofVec3f(middle, middle, middle), 0.05);
        }



    // }
}

void Video::draw(){
    if(fboBuffer.size()){
        rgbSplit.begin();
        // rgbSplit.setUniform2f("u_resolution", ofVec2f(fboBuffer[int(playhead.y)].getWidth(), fboBuffer[int(playhead.y)].getHeight()));
        rgbSplit.setUniform2f("scalar", (fboBuffer[playhead.y].getWidth() / ofGetWidth()), (fboBuffer[playhead.y].getHeight() / ofGetHeight()));    //dont like using this
        rgbSplit.setUniformTexture("sampleRed", fboBuffer[int(ceil(playhead.x))], 1);
        rgbSplit.setUniformTexture("sampleGreen", fboBuffer[int((playhead.y))], 2);
        rgbSplit.setUniformTexture("sampleBlue", fboBuffer[int(floor(playhead.z))], 3);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        // fboBuffer[int(playhead.y)].draw(0, 0);
        // ofDrawRectangle(0, 0, fboBuffer[int(playhead.y)].getWidth(), fboBuffer[int(playhead.y)].getHeight());
        rgbSplit.end();
    }
}
void Video::forwardBackward(bool isForward){
    (isForward) ? playheadTarget.x = 0.0 : playheadTarget.z = fboBuffer.size() - 1;
    playhead.interpolate(playheadTarget, 0.1);
}


// void Video::forwardBackward(bool isForward){
//     if((!buffLoc) && (bufferIsInit)){
//         int position;
//         isForward ? position = playhead + 1 : position = playhead -1;
//         if((position > 0) && (position < fboBuffer.size()-1)){
//             playhead = position;
//         }
//     }
// }

void Video::updatePlayheads(ofVec3f targetPositions){
    // if((!buffLoc) && (bufferIsInit)){
    //     ofVec3f target = targetPositions;
    //     target *=2.;
    //     target -= 1.;
    //     ofVec3f velocity = target - position;
    //     position += (velocity * speed);
    //     positionXI = position + 1.;
    //     positionXI /2.;
        
    //     // position += 1.;
    //     // position /= 2.;

    //     ofVec3f mover;
    //     mover.x = positionXI.x * fboBuffer.size();
    //     mover.y = positionXI.y * fboBuffer.size();
    //     mover.z = positionXI.z * fboBuffer.size();

    //     position.x = ofClamp(position.x, 0., 1.);
    //     position.y = ofClamp(position.y, 0., 1.);
    //     position.z = ofClamp(position.z, 0., 1.);
    //     // playhead = mover;

    //     ((mover.x > 0) && (mover.x < fboBuffer.size())) ? playhead.x = mover.x : playhead.x = playhead.x;
    //     ((mover.y > 0) && (mover.y < fboBuffer.size())) ? playhead.y = mover.y : playhead.y = playhead.y;
    //     ((mover.z > 0) && (mover.z < fboBuffer.size())) ? playhead.z = mover.z : playhead.z = playhead.z;
    // }
}


// void Video::forwardBackward(bool isForward){
//     if((!buffLoc) && (bufferIsInit)){ 
//         if(isForward){
//             int position = int(playhead.z) -1;
//             if(position > 0){
//                 playhead.z = positi
// void Video::forwardBackward(bool isForward){
//     if((!buffLoc) && (bufferIsInit)){ 
//         if(isForward){
//             int position = int(playhead.z) -1;
//             if(position > 0){
//                 playhead.z = position;
//             }
//         }
//         else{
//             int position = int(playhead.x) +1;
//             if(position < fboBuffer.size()){
//                 playhead.x = position;
//             }
//         }
//     }
// }on;
//             }
//         }
//         else{
//             int position = int(playhead.x) +1;
//             if(position < fboBuffer.size()){
//                 playhead.x = position;
//             }
//         }
//     }
// }
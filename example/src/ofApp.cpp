#include "ofApp.h"

#include "LDtkLoader.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofLogToConsole();

    // ofLogNotice("ofApp") << "dst2: " << ofToString(dst2);
    ldtk::Project ldtk_project;
    ldtk_project.loadFromFile(ofToDataPath("level.ldtk", true));

    // get the world
    const auto& world = ldtk_project.getWorld();

    // get the level and the layer we want to render
    const auto& level = world.getLevel("Level");
    const auto& layer = level.getLayer("Ground");
    // get all the tiles in the Ground layer
    const auto& tiles_vector = layer.allTiles();

    for (const auto& tile : tiles_vector) {
        auto tile_position = tile.getPosition();
        auto tile_texture_rect = tile.getTextureRect();
        ofLogNotice("ofApp") << "Tile position: " << tile_position.x << ", " << tile_position.y;
        ofLogNotice("ofApp") << "Tile texture rect: " << tile_texture_rect.x << ", " << tile_texture_rect.y << ", " << tile_texture_rect.width << ", " << tile_texture_rect.height;
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

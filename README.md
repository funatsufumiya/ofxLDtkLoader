# ofxLDtkLoader

[LDtkLoader](https://github.com/Madour/LDtkLoader) for openFrameworks (tested on v0.12.0, LDtkLoader version: 1.5.3.1)

## Usage

See [example](example). (Please use `projectGenerator` before run it)

```cpp
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

// Result:
// [notice ] ofApp: Tile position: 0, 32
// [notice ] ofApp: Tile texture rect: 96, 112, 16, 16
// [notice ] ofApp: Tile position: 16, 32
// [notice ] ofApp: Tile texture rect: 96, 112, 16, 16
// [notice ] ofApp: Tile position: 32, 32
// [notice ] ofApp: Tile texture rect: 96, 112, 16, 16
// ....
```

## LICENSE

- LDtkLoader: [zlib License](https://github.com/Madour/LDtkLoader/blob/master/LICENSE.md)

NOTE: No specific copyright is claimed for this repository changes (for oF binding), but the [Apache License 2.0](LICENSE_APACHE) or [MIT License](LICENSE_MIT) can be applied if necessary.
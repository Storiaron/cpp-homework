#pragma once
#include <string>
#include <map>

std::map<std::string, std::string> userPrompts = {
    {"cellSize", "Enter the size of a cell"},
    {"pictureStartingPointX", "Enter the x coordinate of picture starting point (S)"},
    {"pictureStartingPointY", "Enter the y coordinate of picture starting point (S)"},
    {"pictureWidth", "How many cell width should the picture be"},
    {"pictureHeight", "How many cell tall should the picture be"},
    {"emitterPointX", "Enter the x coordinate of the emitter point (F)"},
    {"emitterPointY", "Enter the y coordinate of the emitter point (F)"},
    {"targetPointX", "Enter the y coordinate of target point D"},
    {"targetPointY", "Enter the y coordinate of target point D"},
    {"additionalTargetPoint", "Do you wish to add more target points? (Y|N)"},
    {"needCustomFilePath", "Do you wish to set a custom output file path? (Y|N)"},
    {"filePath", "Enter the filepath"}
};
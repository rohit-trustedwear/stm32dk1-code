/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/MainWheelBase.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

MainWheelBase::MainWheelBase() :
    changeScreenCallback(0)
{
    setWidth(480);
    setHeight(480);
    flower.setXY(335, 130);
    flower.setBitmap(touchgfx::Bitmap(BITMAP_FLOWER_BLUE0000_ID));
    flower.setWidth(145);
    flower.setHeight(220);
    flower.setBitmapPosition(1.5f, 0.0f);
    flower.setScale(0.0f);
    flower.setCameraDistance(1000.0f);
    flower.setOrigo(145.0f, 110.0f, 1000.0f);
    flower.setCamera(72.5f, 110.0f);
    flower.setAngles(0.0f, 0.0f, 0.0f);
    flower.setRenderingAlgorithm(touchgfx::TextureMapper::BILINEAR_INTERPOLATION);
    add(flower);

    selectedDemoName.setPosition(136, 218, 202, 51);
    selectedDemoName.setColor(touchgfx::Color::getColorFromRGB(226, 246, 255));
    selectedDemoName.setLinespacing(0);
    selectedDemoName.setTypedText(touchgfx::TypedText(T_MAINSELECTEDSUBDEMOEBIKE));
    selectedDemoName.setAlpha(0);
    add(selectedDemoName);
}

MainWheelBase::~MainWheelBase()
{

}

void MainWheelBase::initialize()
{

}

void MainWheelBase::subDemoSelected(uint8_t value)
{
    //SubeDemoSelected
    //When subDemoSelected is called emit changeScreen callback
    //Emit callback
    emitChangeScreenCallback(value);
}
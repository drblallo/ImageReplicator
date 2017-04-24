#include "defaultinputmanager.h"
#include "input.h"
#include "device.h"
#include "camera3d.h"
#include "glwidget.h"
#include <iostream>

using namespace renderer;

//########################################
//##### Constructors and Conversions #####
//########################################
DefaultInputManager::DefaultInputManager() : EngineObject()
{

}

DefaultInputManager::~DefaultInputManager()
{

}

//########################################
//#####           Methods            #####
//########################################
void DefaultInputManager::Update()
{

    Camera3D *m_camera(Device::getGraphicWindow()->getCamera());
    // Camera Transformation
    if (Input::buttonPressed(Qt::RightButton))
    {
      static const float transSpeed = 0.5f;
      static const float rotSpeed   = 0.5f;

      // Handle rotations
      m_camera->rotate(-rotSpeed * Input::mouseDelta().x(), Camera3D::LocalUp);
      m_camera->rotate(-rotSpeed * Input::mouseDelta().y(), m_camera->right());

      // Handle translations
      QVector3D translation;
      if (Input::keyPressed(Qt::Key_W))
    {
        translation += m_camera->forward();
      }
      if (Input::keyPressed(Qt::Key_S))
      {
        translation -= m_camera->forward();
      }
      if (Input::keyPressed(Qt::Key_A))
      {
        translation -= m_camera->right();
      }
      if (Input::keyPressed(Qt::Key_D))
      {
        translation += m_camera->right();
      }
      if (Input::keyPressed(Qt::Key_Q))
      {
        translation -= m_camera->up();
      }
      if (Input::keyPressed(Qt::Key_E))
      {
        translation += m_camera->up();
      }
      m_camera->translate(transSpeed * translation);
    }
}

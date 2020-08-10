#include <galileo/Framework/IScene.h>

namespace galileo
{
  IScene::IScene(const std::string sceneName) : m_SceneName(sceneName)
  {
    ;
  }

  void IScene::drawScene()
  {
    QMetaObject::connectSlotsByName(m_uMainWindow.get());
  }

  void IScene::show() const
  {
    m_uMainWindow->show();
  }

  std::string IScene::getSceneName()
  {
    return m_SceneName;
  }

  void IScene::setWindow(std::unique_ptr<QMainWindow> mainWindow)
  {
    m_uMainWindow = std::move(mainWindow);
  }

  std::unique_ptr<QMainWindow> IScene::getMainWindow()
  {
    return std::move(m_uMainWindow);
  }

  void IScene::setTransientData(std::map<const std::string, const boost::any> transientDataCollection)
  {
    m_TransientDataCollection = std::move(transientDataCollection);
  }

  std::map<const std::string, const boost::any> IScene::getTransientDataCollection()
  {
    return m_TransientDataCollection;
  }

  IScene::~IScene()
  {
    ;
  }
}
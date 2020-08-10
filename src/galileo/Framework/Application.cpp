#include <galileo/Framework/Application.h>
#include <qtimer.h>
#include <memory>

namespace galileo
{
  Application::Application() : 
    m_AppModel(nullptr), 
    m_SceneMachine(nullptr)
  {
    ;
  }

  void Application::start(const std::string av_szApplicationTitile, const unsigned ac_nWidth, const unsigned ac_nHeight)
  {
    m_uMainWindow = std::make_unique<QMainWindow>();
    m_uMainWindow->setWindowTitle(QString::fromUtf8(av_szApplicationTitile.c_str()));
    m_uMainWindow->resize(ac_nWidth, ac_nHeight);

    m_SceneMachine = new CSceneMachine(m_AppModel->getInitialSceneName(), m_AppModel->getScenes(), m_AppModel->getTransientData(), std::move(m_uMainWindow));

  }

  void Application::setApplicationModel(IApplicationModel* av_xAppModel)
  {
    m_AppModel = std::move(av_xAppModel);
    m_AppModel->defineScene();
    m_AppModel->defineTransientData();
    m_AppModel->defineInitialScene();
  }

  Application::~Application()
  {
    m_AppModel = nullptr;
    delete m_SceneMachine;
  }
}

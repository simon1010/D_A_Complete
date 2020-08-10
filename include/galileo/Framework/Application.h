#pragma once
#include <galileo\Framework\global.h>
#include <galileo\Framework\IApplicationModel.h>
#include <galileo\Framework\SceneMachine.h>
#include <QMainWindow>

namespace galileo
{
  typedef std::unique_ptr<QMainWindow> uQWindow;

  class Framework_EXPORT_IMPORT_API Application
  {
  public:
    static Application& getInstance()
    {
      static Application    instance; 
      // Guaranteed to be destroyed.
      // Instantiated on first use.
      return instance;
    }

    void start(const std::string av_szApplicationTitile, 
               const unsigned ac_nWidth, 
               const unsigned ac_nHeight);

    void setApplicationModel(IApplicationModel* av_xAppModel);

    virtual ~Application();

  private:
    Application();

    uQWindow m_uMainWindow;
    IApplicationModel* m_AppModel;
    CSceneMachine* m_SceneMachine;
  };
}

#pragma once
#include <galileo\Framework\global.h>

#include <memory>
#include <map>

#include <boost/any.hpp>

#include <QtCore\qobject.h>
#include <QMainWindow>

namespace galileo
{
  class Framework_EXPORT_IMPORT_API IScene : public QObject
  {
    Q_OBJECT

  signals:
    void SceneChange(const std::string sceneName);

  public:
    explicit IScene(const std::string sceneName);

    virtual void createScene() = 0;
    virtual void release() = 0;

    virtual void drawScene();

    void show() const;

    virtual std::string getSceneName();

    void setWindow(std::unique_ptr<QMainWindow> mainWindow);

    std::unique_ptr<QMainWindow> getMainWindow();

    virtual void setTransientData(std::map<const std::string, const boost::any> transientDataCollection);

    std::map<const std::string, const boost::any> getTransientDataCollection();

    virtual ~IScene();

  public:
    typedef std::shared_ptr<IScene> s_ptr;
    typedef std::unique_ptr<IScene> u_ptr;

  protected:
    std::unique_ptr<QMainWindow> m_uMainWindow;
    std::map<const std::string, const boost::any> m_TransientDataCollection;

  private:
    const std::string m_SceneName;

  };
}

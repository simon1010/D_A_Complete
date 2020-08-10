#pragma once

#include <galileo\Framework\IScene.h>
#include <qobject.h>

namespace galileo
{
  class AppScene : public IScene
  {
    Q_OBJECT

  public:
    AppScene(const std::string& ac_szSceneName);

    void createScene() override;

    void release() override;

    ~AppScene();

  private:
    QWidget* centralWidget;
  };
}

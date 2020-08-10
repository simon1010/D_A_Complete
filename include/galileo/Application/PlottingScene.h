#pragma once

#include <galileo\Framework\IScene.h>
#include <qobject.h>
#include <qcustomplot.h>

namespace galileo
{
  class PlottingScene : public IScene
  {
    Q_OBJECT

  public:
    PlottingScene(const std::string& ac_szSceneName);

    void createScene() override;

    void release() override;

    ~PlottingScene();



  public slots:
    void mp_BackButton();
    void mp_OnPlotButton();

  private:
    void mp_InitPlotters();

    QWidget* centralWidget;
    QCustomPlot* mv_customPlotTime;
    QCustomPlot* mv_customPlotFreq;
    QComboBox* mv_signalComboBox;
  };
}

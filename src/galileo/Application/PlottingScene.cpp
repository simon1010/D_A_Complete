#include <galileo\Application\PlottingScene.h>

#include "ui_plotting_scene.h"
#include "aquila/aquila.h"
#include "Iir.h"

namespace galileo
{
  PlottingScene::PlottingScene(const std::string& ac_szSceneName) : IScene(ac_szSceneName)
  {
  }

  void PlottingScene::createScene()
  {
    // Create the UI
    const auto ui = std::make_shared<Ui_plottingScene>();
    ui->setupUi(m_uMainWindow.get());

    // Connect btn's release signal to defined slot
    QObject::connect(ui->backButton, SIGNAL(released()), this, SLOT(mp_BackButton()));

    // Setting a temporary new title
    m_uMainWindow->setWindowTitle(QString("Plotting Example"));

    mv_customPlotTime = ui->customPlotTime;
    mv_customPlotFreq = ui->customPlotFreq;

    // Connect btn's release signal to defined slot
    QObject::connect(ui->plotButton, SIGNAL(released()), this, SLOT(mp_OnPlotButton()));

    // Setting centralWidget
    centralWidget = ui->centralwidget;

    // Populate combobox
    mv_signalComboBox = ui->SignalComboBox;
    mv_signalComboBox->addItem("Sine");
    mv_signalComboBox->addItem("SineSum");
    mv_signalComboBox->addItem("Square");
    mv_signalComboBox->addItem("Sweep");
    mv_signalComboBox->addItem("Dirac");

    // Initialize plotters
    mp_InitPlotters();
  }

  void PlottingScene::mp_InitPlotters()
  {
    // Time plot
    mv_customPlotTime->setInteraction(QCP::iRangeZoom, true);
    mv_customPlotTime->setInteraction(QCP::iRangeDrag, true);

    mv_customPlotTime->addGraph();
    mv_customPlotTime->graph(0)->setLineStyle(QCPGraph::LineStyle::lsLine);

    mv_customPlotTime->xAxis->setLabel("SAMPLES");
    mv_customPlotTime->yAxis->setLabel("AMPLITUDE");

    // Freq plot
    mv_customPlotFreq->setInteraction(QCP::iRangeZoom, true);
    mv_customPlotFreq->setInteraction(QCP::iRangeDrag, true);

    mv_customPlotFreq->addGraph();
    mv_customPlotFreq->graph(0)->setLineStyle(QCPGraph::LineStyle::lsLine);

    mv_customPlotFreq->xAxis->setLabel("FREQUENCY (Hz)");
    mv_customPlotFreq->yAxis->setLabel("AMPLITUDE");
    mv_customPlotFreq->xAxis->setRange(0, 1000);
    mv_customPlotFreq->yAxis->setRange(-0.2, 2);
  }

  void PlottingScene::release()
  {
    delete centralWidget;
  }

  PlottingScene::~PlottingScene()
  {
  }

  double SineWave(double t, double amplitude, double frequency)
  {
    return amplitude * sin(2 * M_PI * frequency * t);
  }

  void PlottingScene::mp_BackButton()
  {
    const std::string c_szNextSceneName = "Initial scene";
    emit SceneChange(c_szNextSceneName);
  }

  static const unsigned int SAMPLE_RATE = 81920; // Hz
  static const       double PLOT_TIME = 0.1;     // seconds
  static const       double AMPLITUDE = 1;

  static const unsigned int NO_OF_SAMPLES = PLOT_TIME * SAMPLE_RATE;

  void PlottingScene::mp_OnPlotButton()
  {
    QString comboSelection = mv_signalComboBox->currentText();

    // Set xAxis
    QVector<double> y(NO_OF_SAMPLES);
    QVector<double> x(NO_OF_SAMPLES);
    x[0] = 0;
    for (int i = 1; i < NO_OF_SAMPLES; i++)
    {
      x[i] = i;
    }

    if (comboSelection == "Sine")
    {
      // Set yAxis
      for (int i = 0; i < NO_OF_SAMPLES; i++)
      {
        double xval = i / (double)NO_OF_SAMPLES;
        y[i] = SineWave(xval, AMPLITUDE, 20);
      }
    }
    else if (comboSelection == "SineSum")
    {
    }
    else if (comboSelection == "Square")
    {
    }
    else if (comboSelection == "Sweep")
    {
    }
    else if (comboSelection == "Dirac")
    {
    }

    // FFT
    QVector<double> yFFT(NO_OF_SAMPLES);

    auto fft = Aquila::FftFactory::getFft(NO_OF_SAMPLES);
    Aquila::SpectrumType spectrum = fft->fft(y.data());

    for (int i = 0; i < NO_OF_SAMPLES; i++)
    {
      yFFT[i] = std::abs(spectrum[i]) / (NO_OF_SAMPLES / 2);
    }

    mv_customPlotTime->graph(0)->setData(x, y);
    mv_customPlotTime->rescaleAxes();
    mv_customPlotTime->replot();

    mv_customPlotFreq->graph(0)->setData(x, yFFT);
    mv_customPlotFreq->replot();
  }
}
